/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_BreathingRate;
    QLCDNumber *lcdNumber_Breathingrate;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_HeartRate;
    QLCDNumber *lcdNumber_HeartRate;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QCustomPlot *BreathingWfmPlot;
    QCustomPlot *heartWfmPlot;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QCustomPlot *phaseWfmPlot;
    QCustomPlot *plot_RangeProfile;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Count;
    QLCDNumber *lcdNumber_FrameCount;
    QLabel *label_BR_pk;
    QLCDNumber *lcdNumber_Breath_pk;
    QLabel *label_5;
    QLCDNumber *lcdNumber_Breath_FT;
    QLCDNumber *lcdNumber_Breath_xCorr;
    QLCDNumber *lcdNumber_breathRate_HarmEnergy;
    QLabel *label_7;
    QLCDNumber *lcdNumber_CM_Breath;
    QLCDNumber *lcdNumber_CM_Breath_xCorr;
    QLCDNumber *lcdNumber_reserved2;
    QLabel *label;
    QLCDNumber *lcdNumber_BreathEnergy;
    QLabel *label_9;
    QDoubleSpinBox *SpinBox_TH_Breath;
    QLabel *label_4;
    QLCDNumber *lcdNumber_RCS;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Index;
    QLCDNumber *lcdNumber_Index;
    QLabel *label_HR_pk;
    QLCDNumber *lcdNumber_Heart_pk;
    QLabel *label_6;
    QLCDNumber *lcdNumber_Heart_FT;
    QLCDNumber *lcdNumber_Heart_xCorr;
    QLCDNumber *lcdNumber_Heart_FT_4Hz;
    QLabel *label_8;
    QLCDNumber *lcdNumber_CM_Heart;
    QLCDNumber *lcdNumber_CM_Heart_xCorr;
    QLCDNumber *lcdNumber_Display4;
    QLabel *label_3;
    QLCDNumber *lcdNumber_HeartEnergy;
    QLabel *label_10;
    QDoubleSpinBox *SpinBox_TH_Heart;
    QLabel *label_11;
    QDoubleSpinBox *SpinBox_RCS;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *checkBox_xCorr;
    QCheckBox *checkBox_FFT;
    QCheckBox *checkBox_SaveData;
    QCheckBox *checkBox_LoadConfig;
    QCheckBox *checkBox_displayPlots;
    QCheckBox *checkBox_AutoDetectPorts;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_start;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_settings;
    QPushButton *pushButton_Refresh;
    QLabel *label_user_uart_port;
    QLineEdit *lineEdit_UART_port;
    QLabel *label_2;
    QLineEdit *lineEdit_data_port;
    QGroupBox *groupBox;
    QRadioButton *radioButton_BackMeasurements;
    QRadioButton *radioButton_FrontMeasurements;
    QLineEdit *lineEdit_ProfileBack;
    QLineEdit *lineEdit_ProfileFront;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_Icon;
    QLCDNumber *lcdNumber_Display3;
    QLCDNumber *lcdNumber_ReliabilityMetric;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1485, 999);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_BreathingRate = new QLabel(layoutWidget);
        label_BreathingRate->setObjectName(QString::fromUtf8("label_BreathingRate"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_BreathingRate->setFont(font);
        label_BreathingRate->setAutoFillBackground(false);
        label_BreathingRate->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_4->addWidget(label_BreathingRate);

        lcdNumber_Breathingrate = new QLCDNumber(layoutWidget);
        lcdNumber_Breathingrate->setObjectName(QString::fromUtf8("lcdNumber_Breathingrate"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdNumber_Breathingrate->sizePolicy().hasHeightForWidth());
        lcdNumber_Breathingrate->setSizePolicy(sizePolicy1);
        lcdNumber_Breathingrate->setMinimumSize(QSize(0, 70));
        lcdNumber_Breathingrate->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_Breathingrate->setFrameShape(QFrame::Box);
        lcdNumber_Breathingrate->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout_4->addWidget(lcdNumber_Breathingrate);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_HeartRate = new QLabel(layoutWidget);
        label_HeartRate->setObjectName(QString::fromUtf8("label_HeartRate"));
        label_HeartRate->setFont(font);
        label_HeartRate->setAutoFillBackground(false);
        label_HeartRate->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_3->addWidget(label_HeartRate);

        lcdNumber_HeartRate = new QLCDNumber(layoutWidget);
        lcdNumber_HeartRate->setObjectName(QString::fromUtf8("lcdNumber_HeartRate"));
        sizePolicy1.setHeightForWidth(lcdNumber_HeartRate->sizePolicy().hasHeightForWidth());
        lcdNumber_HeartRate->setSizePolicy(sizePolicy1);
        lcdNumber_HeartRate->setMinimumSize(QSize(0, 70));

        verticalLayout_3->addWidget(lcdNumber_HeartRate);


        horizontalLayout_5->addLayout(verticalLayout_3);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        BreathingWfmPlot = new QCustomPlot(layoutWidget1);
        BreathingWfmPlot->setObjectName(QString::fromUtf8("BreathingWfmPlot"));
        sizePolicy1.setHeightForWidth(BreathingWfmPlot->sizePolicy().hasHeightForWidth());
        BreathingWfmPlot->setSizePolicy(sizePolicy1);
        BreathingWfmPlot->setMinimumSize(QSize(471, 250));

        horizontalLayout_3->addWidget(BreathingWfmPlot);

        heartWfmPlot = new QCustomPlot(layoutWidget1);
        heartWfmPlot->setObjectName(QString::fromUtf8("heartWfmPlot"));
        sizePolicy1.setHeightForWidth(heartWfmPlot->sizePolicy().hasHeightForWidth());
        heartWfmPlot->setSizePolicy(sizePolicy1);
        heartWfmPlot->setMinimumSize(QSize(471, 250));

        horizontalLayout_3->addWidget(heartWfmPlot);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        phaseWfmPlot = new QCustomPlot(layoutWidget2);
        phaseWfmPlot->setObjectName(QString::fromUtf8("phaseWfmPlot"));
        sizePolicy1.setHeightForWidth(phaseWfmPlot->sizePolicy().hasHeightForWidth());
        phaseWfmPlot->setSizePolicy(sizePolicy1);
        phaseWfmPlot->setMinimumSize(QSize(611, 231));

        horizontalLayout_4->addWidget(phaseWfmPlot);

        plot_RangeProfile = new QCustomPlot(layoutWidget2);
        plot_RangeProfile->setObjectName(QString::fromUtf8("plot_RangeProfile"));
        sizePolicy1.setHeightForWidth(plot_RangeProfile->sizePolicy().hasHeightForWidth());
        plot_RangeProfile->setSizePolicy(sizePolicy1);
        plot_RangeProfile->setMinimumSize(QSize(391, 231));

        horizontalLayout_4->addWidget(plot_RangeProfile);

        splitter->addWidget(layoutWidget2);
        layoutWidget3 = new QWidget(splitter);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_Count = new QLabel(layoutWidget3);
        label_Count->setObjectName(QString::fromUtf8("label_Count"));
        label_Count->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_Count);

        lcdNumber_FrameCount = new QLCDNumber(layoutWidget3);
        lcdNumber_FrameCount->setObjectName(QString::fromUtf8("lcdNumber_FrameCount"));
        lcdNumber_FrameCount->setDigitCount(8);
        lcdNumber_FrameCount->setProperty("intValue", QVariant(0));

        horizontalLayout->addWidget(lcdNumber_FrameCount);

        label_BR_pk = new QLabel(layoutWidget3);
        label_BR_pk->setObjectName(QString::fromUtf8("label_BR_pk"));
        label_BR_pk->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_BR_pk);

        lcdNumber_Breath_pk = new QLCDNumber(layoutWidget3);
        lcdNumber_Breath_pk->setObjectName(QString::fromUtf8("lcdNumber_Breath_pk"));

        horizontalLayout->addWidget(lcdNumber_Breath_pk);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_5);

        lcdNumber_Breath_FT = new QLCDNumber(layoutWidget3);
        lcdNumber_Breath_FT->setObjectName(QString::fromUtf8("lcdNumber_Breath_FT"));

        horizontalLayout->addWidget(lcdNumber_Breath_FT);

        lcdNumber_Breath_xCorr = new QLCDNumber(layoutWidget3);
        lcdNumber_Breath_xCorr->setObjectName(QString::fromUtf8("lcdNumber_Breath_xCorr"));

        horizontalLayout->addWidget(lcdNumber_Breath_xCorr);

        lcdNumber_breathRate_HarmEnergy = new QLCDNumber(layoutWidget3);
        lcdNumber_breathRate_HarmEnergy->setObjectName(QString::fromUtf8("lcdNumber_breathRate_HarmEnergy"));

        horizontalLayout->addWidget(lcdNumber_breathRate_HarmEnergy);

        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_7);

        lcdNumber_CM_Breath = new QLCDNumber(layoutWidget3);
        lcdNumber_CM_Breath->setObjectName(QString::fromUtf8("lcdNumber_CM_Breath"));

        horizontalLayout->addWidget(lcdNumber_CM_Breath);

        lcdNumber_CM_Breath_xCorr = new QLCDNumber(layoutWidget3);
        lcdNumber_CM_Breath_xCorr->setObjectName(QString::fromUtf8("lcdNumber_CM_Breath_xCorr"));

        horizontalLayout->addWidget(lcdNumber_CM_Breath_xCorr);

        lcdNumber_reserved2 = new QLCDNumber(layoutWidget3);
        lcdNumber_reserved2->setObjectName(QString::fromUtf8("lcdNumber_reserved2"));

        horizontalLayout->addWidget(lcdNumber_reserved2);

        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        lcdNumber_BreathEnergy = new QLCDNumber(layoutWidget3);
        lcdNumber_BreathEnergy->setObjectName(QString::fromUtf8("lcdNumber_BreathEnergy"));

        horizontalLayout->addWidget(lcdNumber_BreathEnergy);

        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_9);

        SpinBox_TH_Breath = new QDoubleSpinBox(layoutWidget3);
        SpinBox_TH_Breath->setObjectName(QString::fromUtf8("SpinBox_TH_Breath"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(SpinBox_TH_Breath->sizePolicy().hasHeightForWidth());
        SpinBox_TH_Breath->setSizePolicy(sizePolicy2);
        SpinBox_TH_Breath->setDecimals(3);
        SpinBox_TH_Breath->setMaximum(1000.000000000000000);
        SpinBox_TH_Breath->setSingleStep(0.010000000000000);
        SpinBox_TH_Breath->setValue(0.005000000000000);

        horizontalLayout->addWidget(SpinBox_TH_Breath);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        lcdNumber_RCS = new QLCDNumber(layoutWidget3);
        lcdNumber_RCS->setObjectName(QString::fromUtf8("lcdNumber_RCS"));

        horizontalLayout->addWidget(lcdNumber_RCS);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_Index = new QLabel(layoutWidget3);
        label_Index->setObjectName(QString::fromUtf8("label_Index"));
        label_Index->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_Index);

        lcdNumber_Index = new QLCDNumber(layoutWidget3);
        lcdNumber_Index->setObjectName(QString::fromUtf8("lcdNumber_Index"));

        horizontalLayout_2->addWidget(lcdNumber_Index);

        label_HR_pk = new QLabel(layoutWidget3);
        label_HR_pk->setObjectName(QString::fromUtf8("label_HR_pk"));
        label_HR_pk->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_HR_pk);

        lcdNumber_Heart_pk = new QLCDNumber(layoutWidget3);
        lcdNumber_Heart_pk->setObjectName(QString::fromUtf8("lcdNumber_Heart_pk"));

        horizontalLayout_2->addWidget(lcdNumber_Heart_pk);

        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_6);

        lcdNumber_Heart_FT = new QLCDNumber(layoutWidget3);
        lcdNumber_Heart_FT->setObjectName(QString::fromUtf8("lcdNumber_Heart_FT"));

        horizontalLayout_2->addWidget(lcdNumber_Heart_FT);

        lcdNumber_Heart_xCorr = new QLCDNumber(layoutWidget3);
        lcdNumber_Heart_xCorr->setObjectName(QString::fromUtf8("lcdNumber_Heart_xCorr"));

        horizontalLayout_2->addWidget(lcdNumber_Heart_xCorr);

        lcdNumber_Heart_FT_4Hz = new QLCDNumber(layoutWidget3);
        lcdNumber_Heart_FT_4Hz->setObjectName(QString::fromUtf8("lcdNumber_Heart_FT_4Hz"));

        horizontalLayout_2->addWidget(lcdNumber_Heart_FT_4Hz);

        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_8);

        lcdNumber_CM_Heart = new QLCDNumber(layoutWidget3);
        lcdNumber_CM_Heart->setObjectName(QString::fromUtf8("lcdNumber_CM_Heart"));

        horizontalLayout_2->addWidget(lcdNumber_CM_Heart);

        lcdNumber_CM_Heart_xCorr = new QLCDNumber(layoutWidget3);
        lcdNumber_CM_Heart_xCorr->setObjectName(QString::fromUtf8("lcdNumber_CM_Heart_xCorr"));

        horizontalLayout_2->addWidget(lcdNumber_CM_Heart_xCorr);

        lcdNumber_Display4 = new QLCDNumber(layoutWidget3);
        lcdNumber_Display4->setObjectName(QString::fromUtf8("lcdNumber_Display4"));

        horizontalLayout_2->addWidget(lcdNumber_Display4);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_3);

        lcdNumber_HeartEnergy = new QLCDNumber(layoutWidget3);
        lcdNumber_HeartEnergy->setObjectName(QString::fromUtf8("lcdNumber_HeartEnergy"));

        horizontalLayout_2->addWidget(lcdNumber_HeartEnergy);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_10);

        SpinBox_TH_Heart = new QDoubleSpinBox(layoutWidget3);
        SpinBox_TH_Heart->setObjectName(QString::fromUtf8("SpinBox_TH_Heart"));
        sizePolicy2.setHeightForWidth(SpinBox_TH_Heart->sizePolicy().hasHeightForWidth());
        SpinBox_TH_Heart->setSizePolicy(sizePolicy2);
        SpinBox_TH_Heart->setDecimals(3);
        SpinBox_TH_Heart->setSingleStep(0.010000000000000);
        SpinBox_TH_Heart->setValue(0.000000000000000);

        horizontalLayout_2->addWidget(SpinBox_TH_Heart);

        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_11);

        SpinBox_RCS = new QDoubleSpinBox(layoutWidget3);
        SpinBox_RCS->setObjectName(QString::fromUtf8("SpinBox_RCS"));
        sizePolicy2.setHeightForWidth(SpinBox_RCS->sizePolicy().hasHeightForWidth());
        SpinBox_RCS->setSizePolicy(sizePolicy2);
        SpinBox_RCS->setDecimals(0);
        SpinBox_RCS->setMaximum(10000.000000000000000);
        SpinBox_RCS->setValue(500.000000000000000);

        horizontalLayout_2->addWidget(SpinBox_RCS);


        verticalLayout_5->addLayout(horizontalLayout_2);

        splitter->addWidget(layoutWidget3);
        splitter_2->addWidget(splitter);
        layoutWidget4 = new QWidget(splitter_2);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        verticalLayout_7 = new QVBoxLayout(layoutWidget4);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        checkBox_xCorr = new QCheckBox(layoutWidget4);
        checkBox_xCorr->setObjectName(QString::fromUtf8("checkBox_xCorr"));
        QFont font1;
        font1.setPointSize(12);
        checkBox_xCorr->setFont(font1);
        checkBox_xCorr->setChecked(false);

        verticalLayout_2->addWidget(checkBox_xCorr);

        checkBox_FFT = new QCheckBox(layoutWidget4);
        checkBox_FFT->setObjectName(QString::fromUtf8("checkBox_FFT"));
        checkBox_FFT->setFont(font1);

        verticalLayout_2->addWidget(checkBox_FFT);

        checkBox_SaveData = new QCheckBox(layoutWidget4);
        checkBox_SaveData->setObjectName(QString::fromUtf8("checkBox_SaveData"));
        checkBox_SaveData->setFont(font1);

        verticalLayout_2->addWidget(checkBox_SaveData);

        checkBox_LoadConfig = new QCheckBox(layoutWidget4);
        checkBox_LoadConfig->setObjectName(QString::fromUtf8("checkBox_LoadConfig"));
        checkBox_LoadConfig->setFont(font1);

        verticalLayout_2->addWidget(checkBox_LoadConfig);

        checkBox_displayPlots = new QCheckBox(layoutWidget4);
        checkBox_displayPlots->setObjectName(QString::fromUtf8("checkBox_displayPlots"));
        checkBox_displayPlots->setFont(font1);
        checkBox_displayPlots->setChecked(true);

        verticalLayout_2->addWidget(checkBox_displayPlots);

        checkBox_AutoDetectPorts = new QCheckBox(layoutWidget4);
        checkBox_AutoDetectPorts->setObjectName(QString::fromUtf8("checkBox_AutoDetectPorts"));
        checkBox_AutoDetectPorts->setFont(font1);
        checkBox_AutoDetectPorts->setChecked(true);

        verticalLayout_2->addWidget(checkBox_AutoDetectPorts);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_start = new QPushButton(layoutWidget4);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_start->sizePolicy().hasHeightForWidth());
        pushButton_start->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_start->setFont(font2);

        verticalLayout->addWidget(pushButton_start);

        pushButton_pause = new QPushButton(layoutWidget4);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        pushButton_pause->setFont(font2);

        verticalLayout->addWidget(pushButton_pause);

        pushButton_stop = new QPushButton(layoutWidget4);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        sizePolicy3.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy3);
        pushButton_stop->setFont(font2);

        verticalLayout->addWidget(pushButton_stop);

        pushButton_settings = new QPushButton(layoutWidget4);
        pushButton_settings->setObjectName(QString::fromUtf8("pushButton_settings"));
        sizePolicy3.setHeightForWidth(pushButton_settings->sizePolicy().hasHeightForWidth());
        pushButton_settings->setSizePolicy(sizePolicy3);
        pushButton_settings->setFont(font2);

        verticalLayout->addWidget(pushButton_settings);

        pushButton_Refresh = new QPushButton(layoutWidget4);
        pushButton_Refresh->setObjectName(QString::fromUtf8("pushButton_Refresh"));
        sizePolicy3.setHeightForWidth(pushButton_Refresh->sizePolicy().hasHeightForWidth());
        pushButton_Refresh->setSizePolicy(sizePolicy3);
        pushButton_Refresh->setFont(font2);

        verticalLayout->addWidget(pushButton_Refresh);

        label_user_uart_port = new QLabel(layoutWidget4);
        label_user_uart_port->setObjectName(QString::fromUtf8("label_user_uart_port"));

        verticalLayout->addWidget(label_user_uart_port);

        lineEdit_UART_port = new QLineEdit(layoutWidget4);
        lineEdit_UART_port->setObjectName(QString::fromUtf8("lineEdit_UART_port"));

        verticalLayout->addWidget(lineEdit_UART_port);

        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_data_port = new QLineEdit(layoutWidget4);
        lineEdit_data_port->setObjectName(QString::fromUtf8("lineEdit_data_port"));

        verticalLayout->addWidget(lineEdit_data_port);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_7->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(layoutWidget4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 80));
        radioButton_BackMeasurements = new QRadioButton(groupBox);
        radioButton_BackMeasurements->setObjectName(QString::fromUtf8("radioButton_BackMeasurements"));
        radioButton_BackMeasurements->setGeometry(QRect(10, 10, 291, 31));
        radioButton_BackMeasurements->setFont(font1);
        radioButton_BackMeasurements->setChecked(false);
        radioButton_FrontMeasurements = new QRadioButton(groupBox);
        radioButton_FrontMeasurements->setObjectName(QString::fromUtf8("radioButton_FrontMeasurements"));
        radioButton_FrontMeasurements->setGeometry(QRect(10, 40, 291, 50));
        radioButton_FrontMeasurements->setMinimumSize(QSize(0, 50));
        radioButton_FrontMeasurements->setFont(font1);
        radioButton_FrontMeasurements->setChecked(true);
        lineEdit_ProfileBack = new QLineEdit(groupBox);
        lineEdit_ProfileBack->setObjectName(QString::fromUtf8("lineEdit_ProfileBack"));
        lineEdit_ProfileBack->setGeometry(QRect(92, 20, 231, 20));
        lineEdit_ProfileFront = new QLineEdit(groupBox);
        lineEdit_ProfileFront->setObjectName(QString::fromUtf8("lineEdit_ProfileFront"));
        lineEdit_ProfileFront->setGeometry(QRect(90, 50, 231, 22));

        verticalLayout_7->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        pushButton_Icon = new QPushButton(layoutWidget4);
        pushButton_Icon->setObjectName(QString::fromUtf8("pushButton_Icon"));
        sizePolicy2.setHeightForWidth(pushButton_Icon->sizePolicy().hasHeightForWidth());
        pushButton_Icon->setSizePolicy(sizePolicy2);
        pushButton_Icon->setAutoFillBackground(false);
        pushButton_Icon->setText(QString::fromUtf8(""));
        pushButton_Icon->setIconSize(QSize(300, 135));
        pushButton_Icon->setFlat(true);

        verticalLayout_7->addWidget(pushButton_Icon);

        lcdNumber_Display3 = new QLCDNumber(layoutWidget4);
        lcdNumber_Display3->setObjectName(QString::fromUtf8("lcdNumber_Display3"));

        verticalLayout_7->addWidget(lcdNumber_Display3);

        lcdNumber_ReliabilityMetric = new QLCDNumber(layoutWidget4);
        lcdNumber_ReliabilityMetric->setObjectName(QString::fromUtf8("lcdNumber_ReliabilityMetric"));

        verticalLayout_7->addWidget(lcdNumber_ReliabilityMetric);

        splitter_2->addWidget(layoutWidget4);

        verticalLayout_6->addWidget(splitter_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1485, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Texas Instruments - Human Vital Signs Measurement Demo", nullptr));
        label_BreathingRate->setText(QCoreApplication::translate("MainWindow", "Breathing Rate", nullptr));
        label_HeartRate->setText(QCoreApplication::translate("MainWindow", "Heart Rate", nullptr));
        label_Count->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        label_BR_pk->setText(QCoreApplication::translate("MainWindow", "BR-pk", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "BR-FT", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "CM-Breath", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Breath-Wfm", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TH-Breath", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "RCS", nullptr));
        label_Index->setText(QCoreApplication::translate("MainWindow", "Index ", nullptr));
        label_HR_pk->setText(QCoreApplication::translate("MainWindow", "HR-pk", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "HR-FT", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "CM-Heart", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Heart-Wfm", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "TH-Heart", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "TH-RCS", nullptr));
        checkBox_xCorr->setText(QCoreApplication::translate("MainWindow", "Use Time-Domain", nullptr));
        checkBox_FFT->setText(QCoreApplication::translate("MainWindow", "Use Freq-Domain", nullptr));
        checkBox_SaveData->setText(QCoreApplication::translate("MainWindow", "Save Data", nullptr));
        checkBox_LoadConfig->setText(QCoreApplication::translate("MainWindow", "Load Config", nullptr));
        checkBox_displayPlots->setText(QCoreApplication::translate("MainWindow", "Display Plots", nullptr));
        checkBox_AutoDetectPorts->setText(QCoreApplication::translate("MainWindow", "Auto-Detect COM Ports", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        pushButton_Refresh->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        label_user_uart_port->setText(QCoreApplication::translate("MainWindow", "User UART COM Port", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Data COM Port", nullptr));
        groupBox->setTitle(QString());
        radioButton_BackMeasurements->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        radioButton_FrontMeasurements->setText(QCoreApplication::translate("MainWindow", "Front", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
