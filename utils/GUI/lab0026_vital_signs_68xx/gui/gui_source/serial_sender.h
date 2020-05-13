#ifndef SERIAL_SENDER_H
#define SERIAL_SENDER_H
#include <string>
#include <iostream>
#include <Windows.h>
#include <QSerialPort>
#include <QByteArray>
using namespace std;


class serial_sender
{
private:
    QString portname;
    QSerialPort serial;
    QByteArray intToByte(int i);
public:
    serial_sender();
    int serial_connect();
    void send_command(int angle);
};

#endif // SERIAL_SENDER_H
