/********************************************************************************
** Form generated from reading UI file 'dialogsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETTINGS_H
#define UI_DIALOGSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogSettings
{
public:
    QComboBox *comboBox_UserUART;
    QComboBox *comboBox_DataPort;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_HeartWfm_yAxisMax;
    QDoubleSpinBox *doubleSpinBox_BreathWfm_yAxisMax;
    QPushButton *pushButton_Ok;

    void setupUi(QDialog *DialogSettings)
    {
        if (DialogSettings->objectName().isEmpty())
            DialogSettings->setObjectName(QString::fromUtf8("DialogSettings"));
        DialogSettings->resize(615, 282);
        comboBox_UserUART = new QComboBox(DialogSettings);
        comboBox_UserUART->setObjectName(QString::fromUtf8("comboBox_UserUART"));
        comboBox_UserUART->setGeometry(QRect(180, 60, 161, 31));
        comboBox_DataPort = new QComboBox(DialogSettings);
        comboBox_DataPort->setObjectName(QString::fromUtf8("comboBox_DataPort"));
        comboBox_DataPort->setGeometry(QRect(180, 110, 161, 31));
        label = new QLabel(DialogSettings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 60, 161, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(DialogSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 110, 161, 31));
        label_2->setFont(font);
        doubleSpinBox_HeartWfm_yAxisMax = new QDoubleSpinBox(DialogSettings);
        doubleSpinBox_HeartWfm_yAxisMax->setObjectName(QString::fromUtf8("doubleSpinBox_HeartWfm_yAxisMax"));
        doubleSpinBox_HeartWfm_yAxisMax->setGeometry(QRect(40, 110, 91, 31));
        doubleSpinBox_HeartWfm_yAxisMax->setValue(0.060000000000000);
        doubleSpinBox_BreathWfm_yAxisMax = new QDoubleSpinBox(DialogSettings);
        doubleSpinBox_BreathWfm_yAxisMax->setObjectName(QString::fromUtf8("doubleSpinBox_BreathWfm_yAxisMax"));
        doubleSpinBox_BreathWfm_yAxisMax->setGeometry(QRect(40, 60, 91, 31));
        doubleSpinBox_BreathWfm_yAxisMax->setValue(0.060000000000000);
        pushButton_Ok = new QPushButton(DialogSettings);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        pushButton_Ok->setGeometry(QRect(180, 190, 191, 71));

        retranslateUi(DialogSettings);

        QMetaObject::connectSlotsByName(DialogSettings);
    } // setupUi

    void retranslateUi(QDialog *DialogSettings)
    {
        DialogSettings->setWindowTitle(QCoreApplication::translate("DialogSettings", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogSettings", "User UART Port", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSettings", "Data Port", nullptr));
        pushButton_Ok->setText(QCoreApplication::translate("DialogSettings", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSettings: public Ui_DialogSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETTINGS_H
