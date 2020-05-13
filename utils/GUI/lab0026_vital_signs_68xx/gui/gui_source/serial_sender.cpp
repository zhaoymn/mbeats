#include "serial_sender.h"
#include <QDebug>

QByteArray serial_sender::intToByte(int i)
{
    QByteArray abyte0;
    abyte0.resize(4);
    abyte0[0] = (uchar)  (0x000000ff & i);
    abyte0[1] = (uchar) ((0x0000ff00 & i) >> 8);
    abyte0[2] = (uchar) ((0x00ff0000 & i) >> 16);
    abyte0[3] = (uchar) ((0xff000000 & i) >> 24);
    return abyte0;
}

serial_sender::serial_sender()
{
    portname = "COM20";

}

int serial_sender::serial_connect()
{
    serial.setPortName(portname);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    int r = serial.open(QIODevice::ReadWrite);
    if(!serial.isOpen()){
        qDebug()<<"connect failed";
        return -1;
    }
    return 0;
}

void serial_sender::send_command(int angle)
{
    //QByteArray output = intToByte(angle);
    qDebug()<<angle;
    serial.write(QString::number(angle).toStdString().c_str(),QString::number(angle).size());
    serial.flush();
    qDebug()<<"message sent";
}

