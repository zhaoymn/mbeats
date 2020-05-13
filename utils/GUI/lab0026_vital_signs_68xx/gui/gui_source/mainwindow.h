#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QSerialPort>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <serial_sender.h>
#include "networktimestamp/networktimestamp.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //for experiment
    QVector<double> measure_window;
    void new_data();
    int get_next_angle(int);



    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<double> xDistTimePlot, yDistTimePlot;
    QVector<double> breathingWfmBuffer, heartWfmBuffer;
    QPalette lcdpaletteBreathing, lcdpaletteNotBreathing;
    uint32_t localCount;
    uint32_t currIndex;
    bool FLAG_PAUSE;
    bool AUTO_DETECT_COM_PORTS;
    QByteArray dataBuffer;              // DataBuffer for storing the Serial Data
    int indexBuffer = 0;
    QString dataPortNum, userPortNum;   // Serial Port configuration
    QString platform_EVM;               // Radar Device
    QTcpSocket *socket;
    QTcpServer *server;
    int gt_hr = 0;
    int bytesToInt(QByteArray bytes);

    struct CfgParams {
        float rangeStartMeters;
        float rangeEndMeters;
        float samplingRateADC_ksps;
        int   numSamplesChirp;
        float freqSlope_MHZ_us;
        float stratFreq_GHz;
        float chirpDuration_us;
        float chirpBandwidth_kHz;
        float rangeMaximum_meters;
        int   rangeFFTsize;
        float rangeBinSize_meters;
        int rangeBinStart_index;
        int rangeBinEnd_index;
        int numRangeBinProcessed;
        int totalPayloadSize_bytes;
        int totalPayloadSize_nibbles;
        float AGC_thresh;
    } demoParams;


private slots:
    void    serialRecieved();
    int     nextPower2(int num);
    float   parseValueFloat(QByteArray data,  int valuePos, int valueSize);
    quint32 parseValueUint32(QByteArray data, int valuePos, int valueSize);
    quint16 parseValueUint16(QByteArray data, int valuePos, int valueSize);
    qint16  parseValueInt16(QByteArray data, int valuePos, int valueSize);
    bool    serialPortFind();
    bool    serialPortConfig(QSerialPort *serial, qint32 baudrate, QString dataPortNum );
    void    processData();
    void    server_New_Connect();
    void    socket_Read_Data();
    //    socket_Disconnected();

    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void on_pushButton_pause_clicked();
    void on_pushButton_Refresh_clicked();
    void on_pushButton_settings_clicked();
    void gui_statusUpdate();
    void set_value();


signals:
    void gui_statusChanged();
    void gt_changed();
};

#endif // MAINWINDOW_H
