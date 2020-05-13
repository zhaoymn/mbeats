#ifndef NETWORKTIMESTAMP_H
#define NETWORKTIMESTAMP_H

#include <QtCore>
#include "localtimedaemon.h"
#include "ntpclient.h"


class NetworkTimestamp : public QObject
{
    Q_OBJECT
public:
    static NetworkTimestamp* shareInstance();
    ~NetworkTimestamp();

    qint64 currentMSTimestamp();

private:
    NetworkTimestamp();

    void _init();

    void _syncTimestamp();

private slots:
    void onLocaltimeChanged();
    void onNTPFinished();

private:
    // 线程检查本地时间是否有偏差了，有就要重新同步时间
    LocalTimeDaemonThread *_daemonThread;

    // 同步未完成，直接取本地时间
    bool _syncDone;
    // 与 网络时间 之间的偏差
    qint64 _offsetTS;

    // host 列表
    QStringList _ntpServers;
    QMap<NTPClient *, bool> _ntpClients;
};

#endif // NETWORKTIMESTAMP_H
