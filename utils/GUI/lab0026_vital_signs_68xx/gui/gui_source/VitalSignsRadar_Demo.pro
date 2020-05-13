#-------------------------------------------------
#
# Project created by QtCreator 2017-05-31T16:53:16
#
#-------------------------------------------------

QT       += core gui
QT       += core serialport
QT       += network



CONFIG   += console

LIBS += -lOpenGL32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  printsupport

TARGET = VitalSignsRadar_Demo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QCUSTOMPLOT_USE_OPENGL

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    controller.cpp \
        mainwindow.cpp \
    dialogsettings.cpp \
    networktimestamp/localtimedaemon.cpp \
    networktimestamp/networktimestamp.cpp \
    networktimestamp/ntpclient.cpp \
    qcustomplot.cpp \
    robot.cpp \
    serial_sender.cpp

HEADERS  += mainwindow.h \
    controller.h \
    dialogsettings.h \
    networktimestamp/localtimedaemon.h \
    networktimestamp/networktimestamp.h \
    networktimestamp/ntpclient.h \
    qcustomplot.h \
    robot.h \
    serial_sender.h

FORMS    += mainwindow.ui \
    dialogsettings.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
DISTFILES +=

RESOURCES += \
    logo.qrc \
