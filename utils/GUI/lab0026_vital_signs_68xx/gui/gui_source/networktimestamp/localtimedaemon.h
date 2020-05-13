#ifndef LOCALTIMEDAEMON_H
#define LOCALTIMEDAEMON_H

#include <QThread>


class LocalTimeDaemonThread : public QThread
{
    Q_OBJECT
public:
    explicit LocalTimeDaemonThread(QObject *parent = Q_NULLPTR);

signals:
    void localtimeChanged();

protected:
    void run() Q_DECL_OVERRIDE;

private:
    qint64 _predictTimestamp;
};


#endif // LOCALTIMEDAEMON_H
