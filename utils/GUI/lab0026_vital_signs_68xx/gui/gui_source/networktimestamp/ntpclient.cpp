#include "ntpclient.h"
#include <QDateTime>
//#include <mach/mach_time.h>
#include <QTimer>

namespace {
#define MS_JAN_1970            0x20251FE2400L
#define CURRENT_NTP_MILLION_SECOND  (MS_JAN_1970 + QDateTime::currentMSecsSinceEpoch())

//#define MAX_FAILED_TIMES        3
#define UDP_TIMEOUT             30000

#define UDP_RESEND_INTERVAL_COUNT     6
const qint32 gDelayResendIntervals[UDP_RESEND_INTERVAL_COUNT]
    = {2000, 5000, 10000, 15000, 20000, 30000};
}

quint32 byteToUInt32(QByteArray bt) {
    quint32 value = 0;
    for(int i = 0; i < 4; i++) {
        value = (value << 8) + (bt[i] & 0xff);
    }
    return value;
}
qint64 byte64ToMillionSecond(QByteArray bt) {
    quint32 second = byteToUInt32(bt.left(4));
    quint32 millionSecond = byteToUInt32(bt.mid(4, 4));
    qDebug()<<millionSecond;
    return second * 1000LL + millionSecond * 1000L / (1LL << 32);
}
QByteArray millionSecondToByte64(qint64 ms) {
    qint64 second = qint64(ms / 1000);
    qint64 nseond = (ms % 1000 * 1000L) * (1LL << 32) / 1000000L;

    QByteArray result;
    result[0] = char(second >> 24 & 0xff);
    result[1] = char(second >> 16 & 0xff);
    result[2] = char(second >> 8  & 0xff);
    result[3] = char(second       & 0xff);

    result[4] = char(nseond >> 24 & 0xff);
    result[5] = char(nseond >> 16 & 0xff);
    result[6] = char(nseond >> 8  & 0xff);
    result[7] = char(nseond       & 0xff);

    return result;
}


NTPPackage::NTPPackage() {
    li = 0;
    vn = 3;
    mode = 3;

    stratum = 0;

    poll = 4;
    precision = -6;

    rootdelay = 0;
    rootdelay = 0;
    rootDispersion = 0;
    rootDispersion = 0;

    referenceIdentifier = 0;

    referenceTimestamp = 0;
    originTimestamp = 0;
    receiveTimestamp = 0;
    translateTimestamp = 0;

    requestLocalTimestampByte.clear();

    currentLocalTimestamp = 0;
}

QByteArray NTPPackage::toByteArray() {
    QByteArray result(48, 0);

    result[0] = char((li << 6) | (vn <<3) | (mode));
    result[1] = char(stratum & 0xff);

    result[2] = char(poll & 0xff);
    result[3] = char(precision & 0xff);

    // 协议
//    result[4] = char(rootdelay >> 24 & 0xff);
//    result[5] = char(rootdelay >> 16 & 0xff);
//    result[6] = char(rootdelay >> 8  & 0xff);
//    result[7] = char(rootdelay       & 0xff);

//    result[8] = char(rootDispersion >> 24 & 0xff);
//    result[9] = char(rootDispersion >> 16 & 0xff);
//    result[10] = char(rootDispersion >> 8 & 0xff);
//    result[11] = char(rootDispersion      & 0xff);

//    result[12] = char(referenceIdentifier >> 24 & 0xff);
//    result[13] = char(referenceIdentifier >> 12 & 0xff);
//    result[14] = char(referenceIdentifier >> 8 & 0xff);
//    result[15] = char(referenceIdentifier & 0xff);

//    QByteArray rfTs = millionSecondToByte64(referenceTimestamp);
//    result.replace(16, 8, rfTs.data());

//    QByteArray oTs = millionSecondToByte64(originTimestamp);
//    result.replace(24, 8, oTs.data());

//    QByteArray rTs = millionSecondToByte64(receiveTimestamp);
//    result.replace(32, 8, rTs.data());

//    QByteArray tTs = millionSecondToByte64(translateTimestamp);
//    result.replace(40, 8, tTs.data());

    currentLocalTimestamp = CURRENT_NTP_MILLION_SECOND;

    QByteArray tTs = millionSecondToByte64(currentLocalTimestamp);
    result.replace(40, 8, tTs.data());

    requestLocalTimestampByte = tTs;

    return result;
}

void NTPPackage::parseByByteArray(const QByteArray bytes) {
    li = quint8(bytes[0] >> 6 & 0x3);
    vn = quint8(bytes[0] >> 3 & 0x7);
    mode = quint8(bytes[0] & 0x7);
    stratum = quint8(bytes[1]);
    poll = quint8(bytes[2]);
    precision = qint8(bytes[3]);

    rootdelay = qint32(byteToUInt32(bytes.mid(4, 4)));
    rootDispersion = qint32(byteToUInt32(bytes.mid(8, 4)));

    referenceIdentifier = byteToUInt32(bytes.mid(12, 4));

    referenceTimestamp = byte64ToMillionSecond(bytes.mid(16, 8));
    originTimestamp = byte64ToMillionSecond(bytes.mid(24, 8));
    receiveTimestamp = byte64ToMillionSecond(bytes.mid(32, 8));
    translateTimestamp = byte64ToMillionSecond(bytes.mid(40, 8));


    requestLocalTimestampByte = bytes.mid(24, 8);

    currentLocalTimestamp = CURRENT_NTP_MILLION_SECOND;
    return;
}

qint64 NTPPackage::calcOffset() {
    // t0 - client send time    : originTimestamp
    // t1 - server received time: receiveTimestamp
    // t2 - server send time    : translateTimestamp
    // t3 - client received time: currentLocalTimestamp

    // t1 = t0 + offset + delay
    // t3 = t2 - offset + delay
    // offset = ((t1 - t3) - (t0 - t2)) / 2
    //        = (t1 - t0 + t2 - t3) / 2
    return qint64((receiveTimestamp - originTimestamp + translateTimestamp - currentLocalTimestamp) / 2);
}
bool NTPPackage::checkByOriginTimestamp(QByteArray ots) {
    return requestLocalTimestampByte == ots;
}

NTPClient::NTPClient(QString host, quint16 port)
: QObject (nullptr)

, _ntpServerHost(host)
, _ntpServerPort(port)

, _done(false)
, _originTimestampByte()
, _offset(0)
, _failedTimes(0)

, _udpsocket(nullptr)
, _socketTimerID(0)
, _delayResnedTimerID(0)

{
    connect(this, &NTPClient::_ntpStart, this, &NTPClient::onNTPStart);
}
NTPClient::~NTPClient() {
    _releaseSocket();
}

// api
void NTPClient::start() {
    emit _ntpStart();
}

////////////////////////////////////////
// impl

void NTPClient::_initSocket() {
    _udpsocket = new QUdpSocket(this);

    connect(_udpsocket, &QUdpSocket::connected, this, &NTPClient::onNtpConnected);
    connect(_udpsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onNtpError(QAbstractSocket::SocketError)));

    connect(_udpsocket, &QUdpSocket::readyRead, this, &NTPClient::onNtpReadyRead);
}
QByteArray NTPClient::_readSocket() {
    QByteArray data;
    if (!_udpsocket) {
        return data;
    }
    while (_udpsocket->hasPendingDatagrams()) {
        data.clear();
        data.resize(int(_udpsocket->pendingDatagramSize()));
        _udpsocket->readDatagram(data.data(), data.size());
    }

    return data;
}
void NTPClient::_releaseSocket() {
    if (_udpsocket) {
        _udpsocket->disconnectFromHost();
        _udpsocket->close();
        _udpsocket->deleteLater();
        _udpsocket = nullptr;
    }
    if (_socketTimerID != 0) {
        killTimer(_socketTimerID);
        _socketTimerID = 0;
    }
    if (_delayResnedTimerID != 0) {
        killTimer(_delayResnedTimerID);
        _delayResnedTimerID = 0;
    }
}

NTPPackage NTPClient::_generateRequestPackage() {
    NTPPackage pk;
    return pk;
}
NTPPackage NTPClient::_generateResponsePackageFromByte(const QByteArray bytes) {
    NTPPackage pk;
    pk.parseByByteArray(bytes);
    return pk;
}

void NTPClient::onNTPStart() {
    _cancel();

    _initSocket();

    _done = false;
    _offset = 0;
     _udpsocket->connectToHost(_ntpServerHost, _ntpServerPort);

     _socketTimerID = startTimer(UDP_TIMEOUT);
}

void NTPClient::_cancel() {
    _releaseSocket();
}

void NTPClient::_delayResend() {
    _delayResnedTimerID = startTimer(gDelayResendIntervals[qBound(1, _failedTimes, UDP_RESEND_INTERVAL_COUNT) - 1]);
}

void NTPClient::timerEvent(QTimerEvent *event) {
    if (_delayResnedTimerID == 0 && _socketTimerID == 0) {
        return QObject::timerEvent(event);

    }

    if (event->timerId() == _socketTimerID) {
        qDebug()<<"NTPClient::timerEvent timeout:"<<QDateTime::currentMSecsSinceEpoch()<<", for:"<<_ntpServerHost;
        killTimer(_socketTimerID);
        _socketTimerID = 0;
        onNtpError(QAbstractSocket::TemporaryError);
    } else if (event->timerId() == _delayResnedTimerID) {
        qDebug()<<"NTPClient::timerEvent delay resend:"<<QDateTime::currentMSecsSinceEpoch();
        killTimer(_delayResnedTimerID);
        _delayResnedTimerID = 0;
        start();
    } else {
        return QObject::timerEvent(event);
    }
    return;
}

void NTPClient::onNtpConnected() {
    NTPPackage requestPackage = _generateRequestPackage();

    QByteArray bytesToSend = requestPackage.toByteArray();

    // 发出的包的 时间戳 byte 保存一下，用于校验收到的包
    _originTimestampByte = requestPackage.requestLocalTimestampByte;

    _udpsocket->flush();
    _udpsocket->write(bytesToSend, 48);
    _udpsocket->flush();
}
void NTPClient::onNtpError(QAbstractSocket::SocketError error) {
    _failedTimes++;
    _offset = 0;
    _done = false;
    _releaseSocket();

    qDebug()<<"NTPClient::onNtpError: "<< error<<", failed times:"<<_failedTimes;

    _delayResend();

//    if (_failedTimes < MAX_FAILED_TIMES) {
//        _delayResend();
//    } else {
//        emit ntpFinished();
//    }
}
void NTPClient::onNtpReadyRead() {
    QByteArray data = _readSocket();

    if (_socketTimerID != 0) {
        killTimer(_socketTimerID);
        _socketTimerID = 0;
    }

    if (data.size() != 48) {
        qDebug()<<"NTPClient::failed, content error";
        onNtpError(QAbstractSocket::TemporaryError);
        return;
    }

    NTPPackage responsePackage = _generateResponsePackageFromByte(data);

    if (responsePackage.checkByOriginTimestamp(_originTimestampByte)) {
        _failedTimes = 0;
        _offset = responsePackage.calcOffset();
        _done = true;
        _releaseSocket();

        emit ntpFinished();

        qDebug()<<"NTPClient::ntpFinished, offset:"<<_offset<<", for:"<<_ntpServerHost;
    } else {
        qDebug()<<"NTPClient::failed, not match origin:"<<_originTimestampByte.toHex()<<" to :"<<responsePackage.requestLocalTimestampByte.toHex();
        onNtpError(QAbstractSocket::TemporaryError);
    }
}








