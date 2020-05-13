#ifndef NTPCLIENT_H
#define NTPCLIENT_H
#include <QtCore>
#include <QtNetwork/QUdpSocket>


class NTPPackage {
public:
    NTPPackage();
    ~NTPPackage() {}

    // 发送的包，按协议封包。currentLocalTimestamp 为调用该方法封包的时间。
    QByteArray toByteArray();
    // 收到的包，按协议解包。currentLocalTimestamp 为调用该方法解包的时间。
    void parseByByteArray(const QByteArray bytes);

    // 计算 offset
    qint64 calcOffset();

    // 校验包
    bool checkByOriginTimestamp(QByteArray ots);

public: // ntp protocol data
    quint8 li;
    quint8 vn;
    quint8 mode;

    quint8 stratum;
    quint8 poll;
    qint8 precision;

    qint32 rootdelay;
    qint32 rootDispersion;

    // ntp服务器的id
    quint32 referenceIdentifier;

    // ntp服务器上次同步的本地时间
    qint64 referenceTimestamp;
    // ntp服务器收到的请求中的时间--客户端发起请求时的客户端时间: t0
    qint64 originTimestamp;
    // ntp服务器收到请求时的本地时间: t1
    qint64 receiveTimestamp;
    // ntp服务器发送响应时的本地时间: t2
    qint64 translateTimestamp;

public: // other data
    // ntp客户端发送的时间戳在协议里的 byte，用于校验
    QByteArray requestLocalTimestampByte;

    // 发送、或者受到该包的本地时间戳，发送的包作为t0 、收到的包作为 t3，用于计算时间差
    qint64 currentLocalTimestamp;
};

////////////////////////////////////////////////////////////////
class NTPClient : public QObject
{
    Q_OBJECT
public:
    NTPClient(QString host, quint16 port = 123);
    ~NTPClient();

    // 开始同步时间戳
    void start();

    // 同步是否完成
    inline bool done() {
        return _done;
    }

    // done 后同步到的时间戳
    inline qint64 offset() {
        return _offset;
    }

signals:
    // 同步完成信号
    void ntpFinished();

    // 开始同步信号。 start() 发出，线程安全。
    void _ntpStart();

protected:
    // 异步处理 udp 超时
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

private slots:
    // 开始 ntp 同步时间戳
    void onNTPStart();

    // udp --
    void onNtpConnected();
    void onNtpReadyRead();
    void onNtpError(QAbstractSocket::SocketError);
    // --

private:
    void _cancel();

    NTPPackage _generateRequestPackage();
    NTPPackage _generateResponsePackageFromByte(const QByteArray bytes);

    void _initSocket();
    QByteArray _readSocket();
    void _releaseSocket();

    void _delayResend();

private:
    const QString _ntpServerHost;
    const quint16 _ntpServerPort; // ntp 123

    bool _done;
    QByteArray _originTimestampByte;
    qint64 _offset;
    qint32 _failedTimes;

    QUdpSocket *_udpsocket;
    qint32 _socketTimerID;
    qint32 _delayResnedTimerID;

};


#endif // NTPCLIENT_H
