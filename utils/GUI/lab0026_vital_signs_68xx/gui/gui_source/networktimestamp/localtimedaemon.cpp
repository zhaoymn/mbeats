#include "localtimedaemon.h"
#include <QDebug>
#include <QtCore>


#define daemon_sleep        60000
#define daemon_interval     1000
#define daemon_precision    1000


LocalTimeDaemonThread::LocalTimeDaemonThread(QObject *parent)
    : QThread (parent)
    , _predictTimestamp(0)
{

}

void LocalTimeDaemonThread::run() {
    _predictTimestamp = 0;

    bool isSleep = false;

    while (!isInterruptionRequested()) {
        qint64 currentTS = QDateTime::currentMSecsSinceEpoch();
        qint64 offset = currentTS - _predictTimestamp;
        if (offset < -daemon_precision || offset > daemon_precision) {
            _predictTimestamp = currentTS;
            isSleep = true;
            // 不符合预期，说明时间戳不准了，重新同步
            emit localtimeChanged();
        }

        if (isSleep) {
            // 如果进行 ntp 同步，则 休眠 60s 再进行下次检测
            msleep(daemon_sleep);
            _predictTimestamp += daemon_sleep;
        } else {
            msleep(daemon_interval);
            _predictTimestamp += daemon_interval;
        }
        isSleep = false;
    }
}










