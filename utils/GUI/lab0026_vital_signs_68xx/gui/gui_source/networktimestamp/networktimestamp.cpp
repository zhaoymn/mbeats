#include "networktimestamp.h"

#include <mutex>
#include <QDateTime>


/////////////ntp server list///////////
// pool.ntp.org
// asia.pool.ntp.org
// cn.ntp.org.cn

// time.windows.com
// time.apple.com
// ntp.ubuntu.com

// europe.pool.ntp.org
// north-america.pool.ntp.org
// south-america.pool.ntp.org
// oceania.pool.ntp.org
//////////////bak server list///////////////
// 0.uk.pool.ntp.org
// 0.us.pool.ntp.org
// africa.pool.ntp.org
// time.nist.gov
// s1a.time.edu.cn
// s1c.time.edu.cn
// time-nw.nist.gov
// time-a.nist.gov
// time-b.nist.gov
// s1b.time.edu.cn
// nist1.aol-ca.truetime.com
//////////////////////////////

NetworkTimestamp *NetworkTimestamp::shareInstance() {
    static NetworkTimestamp *instace = nullptr;
    static std::once_flag onceFlag;
    std::call_once(onceFlag, [](){
        if (!instace)  {
            instace = new NetworkTimestamp();
            instace->_init();
        }
    });

    return instace;
}

// api
qint64 NetworkTimestamp::currentMSTimestamp() {
    // 同步未完成，直接返回当前时间戳
    return QDateTime::currentMSecsSinceEpoch() + (_syncDone ? _offsetTS : 0);
}

////////////////////////////
// impl
NetworkTimestamp::NetworkTimestamp()
    : QObject (nullptr)

    , _daemonThread(nullptr)

    , _syncDone(false)
    , _offsetTS(0)
{

}

NetworkTimestamp::~NetworkTimestamp() {
    if (_daemonThread) {
        _daemonThread->requestInterruption();
        _daemonThread->quit();
        _daemonThread->wait();
        _daemonThread->deleteLater();
        _daemonThread = nullptr;
    }

    qDeleteAll(_ntpClients.keys());
    _ntpClients.clear();
}

void NetworkTimestamp::_init() {
    // ntp server
    _ntpServers.clear();
    _ntpServers.append("pool.ntp.org");
    _ntpServers.append("asia.pool.ntp.org");
    _ntpServers.append("cn.ntp.org.cn");

    _ntpServers.append("time.windows.com");
    _ntpServers.append("time.apple.com");
    _ntpServers.append("ntp.ubuntu.com");

    _ntpServers.append("europe.pool.ntp.org");
    _ntpServers.append("north-america.pool.ntp.org");
    _ntpServers.append("south-america.pool.ntp.org");
    _ntpServers.append("oceania.pool.ntp.org");

    // ntp client
    qDeleteAll(_ntpClients.keys());
    _ntpClients.clear();
    foreach (QString host, _ntpServers) {
        NTPClient *client = new NTPClient(host);
        connect(client, &NTPClient::ntpFinished, this, &NetworkTimestamp::onNTPFinished);
        _ntpClients[client] = false;
    }

    // 启动守护线程
    _daemonThread = new LocalTimeDaemonThread(this);
    connect(_daemonThread, &LocalTimeDaemonThread::localtimeChanged, this, &NetworkTimestamp::onLocaltimeChanged);
    _daemonThread->start();
}

void NetworkTimestamp::onLocaltimeChanged() {
    _syncDone = false;
    _offsetTS = 0;

    _syncTimestamp();
}

void NetworkTimestamp::_syncTimestamp() {
    // qDebug()<<"_syncTimestamp :" << QDateTime::currentMSecsSinceEpoch()<<", "<< QThread::currentThreadId();
    for (QMap<NTPClient *, bool>::iterator i = _ntpClients.begin(); i != _ntpClients.end(); i++) {
        i.value() = false;
        i.key()->start();
    }
}

void NetworkTimestamp::onNTPFinished() {
    NTPClient *ntpSender = qobject_cast<NTPClient*>(sender());
    if (!ntpSender) {
        return;
    }

    if (!_ntpClients.contains(ntpSender)) {
        qDebug()<<"onNTPFinished no this client";
        return;
    }

    _ntpClients[ntpSender] = true;

//    // 遍历所有
//    bool finished = true;
//    for (QMap<NTPClient *, bool>::iterator i = _ntpClients.begin(); i != _ntpClients.end(); i++) {
//        if (!i.value()) {
//            finished = false;
//            break;
//        }
//    }
//    // 等待所有完成
//    _syncDone = finished;

    _syncDone = true;

    // 计算平均偏差
    qint64 totaloffset = 0;
    qint64 maxoffset = 0;
    qint64 minoffset = INT64_MAX;
    qint8 validCount = 0;
    for (QMap<NTPClient *, bool>::iterator i = _ntpClients.begin(); i != _ntpClients.end(); i++) {
        if (!i.value()) {
            continue;
        }
        if (!i.key()->done()) {
            continue;
        }
        qint64 os = i.key()->offset();
        totaloffset += os;

        maxoffset = qMax(maxoffset, os);
        minoffset = qMin(minoffset, os);

        validCount++;
    }

    // 去掉最大值、去掉最小值后再取平均值。10 个全满的话，就剩 8 个，
    if (validCount > 2) {
        totaloffset -= (maxoffset + minoffset);
        validCount -= 2;
    }

    _offsetTS = validCount > 0 ? (validCount == 8 ? (totaloffset >> 3) :  totaloffset / validCount) : 0;
}







