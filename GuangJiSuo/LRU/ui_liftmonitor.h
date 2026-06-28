/********************************************************************************
** Form generated from reading UI file 'liftmonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIFTMONITOR_H
#define UI_LIFTMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LiftMonitor
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_27;
    QGroupBox *groupBox_27;
    QVBoxLayout *verticalLayout_10;
    QGridLayout *gridLayout_20;
    QLabel *label_115;
    QLabel *lbl_MY;
    QLabel *lbl_FX;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_116;
    QLabel *lbl_FY;
    QLabel *lbl_MZ;
    QLabel *label_108;
    QLabel *label_13;
    QLabel *lbl_FZ;
    QLabel *lbl_MX;
    QGroupBox *groupBox_32;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_CrashInfo;
    QLabel *lbl_isCrash;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_4;
    QLabel *label_56;
    QLabel *lbl_PlatformStatus;
    QLabel *label_95;
    QLabel *lbl_PlatformWarning;
    QLabel *lbl_PlatformInfoRz;
    QLabel *lbl_PlatformInfoX;
    QLabel *label_96;
    QLabel *lbl_PlatformInfoRy;
    QLabel *label_54;
    QLabel *label_55;
    QLabel *label_44;
    QLabel *lbl_PlatformInfoRx;
    QLabel *lbl_PlatformInfoZ;
    QLabel *label_94;
    QLabel *label_10;
    QLabel *lbl_PlatformInfoY;
    QLabel *label_57;
    QLabel *lbl_PlatformEnable;
    QLabel *label_100;
    QLabel *lbl_PlatformIsTarget;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_63;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label_77;
    QLabel *label_28;
    QLabel *label_20;
    QLabel *lblFsLimit12;
    QLabel *lblAxisInit4;
    QLabel *lblAxisSpeed12;
    QLabel *lblAxisDecel4;
    QLabel *label_21;
    QLabel *lblPosi4;
    QLabel *lblPosi12;
    QLabel *label_171;
    QLabel *label_194;
    QLabel *label_27;
    QLabel *label_26;
    QLabel *lblAxisSpeed4;
    QLabel *label_78;
    QLabel *label_25;
    QLabel *lblAxisStatus12;
    QLabel *lblAxisAccel12;
    QLabel *label_24;
    QLabel *lblFsLimit4;
    QLabel *label_18;
    QLabel *lblAxisStatus4;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_84;
    QLabel *lblAxisUnits4;
    QLabel *lblAxisAccel4;
    QLabel *lblAxisUnits12;
    QSpacerItem *verticalSpacer;
    QLabel *lblAxisDecel12;
    QLabel *lblAxisInit12;
    QLabel *lblBsLimit4;
    QLabel *lblBsLimit12;
    QLabel *lblAxisType4;
    QLabel *lblAxisType12;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *label_129;
    QLabel *lbl_GapAngle;
    QLabel *label_132;
    QLabel *lbl_GapWidth;
    QLabel *label_133;
    QLabel *lbl_GapWidth1;

    void setupUi(QMainWindow *LiftMonitor)
    {
        if (LiftMonitor->objectName().isEmpty())
            LiftMonitor->setObjectName(QString::fromUtf8("LiftMonitor"));
        LiftMonitor->resize(996, 769);
        LiftMonitor->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(LiftMonitor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_6 = new QGridLayout(centralwidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox_13 = new QGroupBox(centralwidget);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_13->sizePolicy().hasHeightForWidth());
        groupBox_13->setSizePolicy(sizePolicy);
        groupBox_13->setMinimumSize(QSize(0, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        groupBox_13->setFont(font);
        groupBox_13->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_27 = new QGridLayout(groupBox_13);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        groupBox_27 = new QGroupBox(groupBox_13);
        groupBox_27->setObjectName(QString::fromUtf8("groupBox_27"));
        verticalLayout_10 = new QVBoxLayout(groupBox_27);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        gridLayout_20 = new QGridLayout();
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        label_115 = new QLabel(groupBox_27);
        label_115->setObjectName(QString::fromUtf8("label_115"));

        gridLayout_20->addWidget(label_115, 1, 2, 1, 1);

        lbl_MY = new QLabel(groupBox_27);
        lbl_MY->setObjectName(QString::fromUtf8("lbl_MY"));

        gridLayout_20->addWidget(lbl_MY, 1, 3, 1, 1);

        lbl_FX = new QLabel(groupBox_27);
        lbl_FX->setObjectName(QString::fromUtf8("lbl_FX"));

        gridLayout_20->addWidget(lbl_FX, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox_27);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_20->addWidget(label_16, 1, 0, 1, 1);

        label_17 = new QLabel(groupBox_27);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_20->addWidget(label_17, 2, 0, 1, 1);

        label_116 = new QLabel(groupBox_27);
        label_116->setObjectName(QString::fromUtf8("label_116"));

        gridLayout_20->addWidget(label_116, 2, 2, 1, 1);

        lbl_FY = new QLabel(groupBox_27);
        lbl_FY->setObjectName(QString::fromUtf8("lbl_FY"));

        gridLayout_20->addWidget(lbl_FY, 1, 1, 1, 1);

        lbl_MZ = new QLabel(groupBox_27);
        lbl_MZ->setObjectName(QString::fromUtf8("lbl_MZ"));

        gridLayout_20->addWidget(lbl_MZ, 2, 3, 1, 1);

        label_108 = new QLabel(groupBox_27);
        label_108->setObjectName(QString::fromUtf8("label_108"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_108->sizePolicy().hasHeightForWidth());
        label_108->setSizePolicy(sizePolicy1);

        gridLayout_20->addWidget(label_108, 0, 2, 1, 1);

        label_13 = new QLabel(groupBox_27);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        gridLayout_20->addWidget(label_13, 0, 0, 1, 1);

        lbl_FZ = new QLabel(groupBox_27);
        lbl_FZ->setObjectName(QString::fromUtf8("lbl_FZ"));

        gridLayout_20->addWidget(lbl_FZ, 2, 1, 1, 1);

        lbl_MX = new QLabel(groupBox_27);
        lbl_MX->setObjectName(QString::fromUtf8("lbl_MX"));

        gridLayout_20->addWidget(lbl_MX, 0, 3, 1, 1);


        verticalLayout_10->addLayout(gridLayout_20);


        gridLayout_27->addWidget(groupBox_27, 0, 0, 1, 2);

        groupBox_32 = new QGroupBox(groupBox_13);
        groupBox_32->setObjectName(QString::fromUtf8("groupBox_32"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_32);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lbl_CrashInfo = new QLabel(groupBox_32);
        lbl_CrashInfo->setObjectName(QString::fromUtf8("lbl_CrashInfo"));

        horizontalLayout_4->addWidget(lbl_CrashInfo);

        lbl_isCrash = new QLabel(groupBox_32);
        lbl_isCrash->setObjectName(QString::fromUtf8("lbl_isCrash"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbl_isCrash->sizePolicy().hasHeightForWidth());
        lbl_isCrash->setSizePolicy(sizePolicy2);
        lbl_isCrash->setMaximumSize(QSize(50, 50));
        lbl_isCrash->setStyleSheet(QString::fromUtf8("border-radius: 25px; border: 2px solid black;background-color: white;"));

        horizontalLayout_4->addWidget(lbl_isCrash);


        gridLayout_27->addWidget(groupBox_32, 1, 0, 1, 2);


        gridLayout_6->addWidget(groupBox_13, 2, 0, 1, 1);

        groupBox_15 = new QGroupBox(centralwidget);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setFont(font);
        groupBox_15->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_2 = new QGridLayout(groupBox_15);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(30);
        label_56 = new QLabel(groupBox_15);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        gridLayout_4->addWidget(label_56, 1, 3, 1, 1);

        lbl_PlatformStatus = new QLabel(groupBox_15);
        lbl_PlatformStatus->setObjectName(QString::fromUtf8("lbl_PlatformStatus"));

        gridLayout_4->addWidget(lbl_PlatformStatus, 1, 10, 1, 1);

        label_95 = new QLabel(groupBox_15);
        label_95->setObjectName(QString::fromUtf8("label_95"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_95->sizePolicy().hasHeightForWidth());
        label_95->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(label_95, 1, 9, 1, 1);

        lbl_PlatformWarning = new QLabel(groupBox_15);
        lbl_PlatformWarning->setObjectName(QString::fromUtf8("lbl_PlatformWarning"));
        sizePolicy1.setHeightForWidth(lbl_PlatformWarning->sizePolicy().hasHeightForWidth());
        lbl_PlatformWarning->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(lbl_PlatformWarning, 0, 10, 1, 1);

        lbl_PlatformInfoRz = new QLabel(groupBox_15);
        lbl_PlatformInfoRz->setObjectName(QString::fromUtf8("lbl_PlatformInfoRz"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lbl_PlatformInfoRz->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoRz->setSizePolicy(sizePolicy4);
        lbl_PlatformInfoRz->setMinimumSize(QSize(40, 0));

        gridLayout_4->addWidget(lbl_PlatformInfoRz, 1, 7, 1, 2);

        lbl_PlatformInfoX = new QLabel(groupBox_15);
        lbl_PlatformInfoX->setObjectName(QString::fromUtf8("lbl_PlatformInfoX"));
        sizePolicy4.setHeightForWidth(lbl_PlatformInfoX->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoX->setSizePolicy(sizePolicy4);
        lbl_PlatformInfoX->setMinimumSize(QSize(40, 0));

        gridLayout_4->addWidget(lbl_PlatformInfoX, 0, 1, 1, 2);

        label_96 = new QLabel(groupBox_15);
        label_96->setObjectName(QString::fromUtf8("label_96"));
        sizePolicy1.setHeightForWidth(label_96->sizePolicy().hasHeightForWidth());
        label_96->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_96, 0, 11, 1, 1);

        lbl_PlatformInfoRy = new QLabel(groupBox_15);
        lbl_PlatformInfoRy->setObjectName(QString::fromUtf8("lbl_PlatformInfoRy"));
        sizePolicy4.setHeightForWidth(lbl_PlatformInfoRy->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoRy->setSizePolicy(sizePolicy4);
        lbl_PlatformInfoRy->setMinimumSize(QSize(40, 0));

        gridLayout_4->addWidget(lbl_PlatformInfoRy, 1, 4, 1, 2);

        label_54 = new QLabel(groupBox_15);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        sizePolicy1.setHeightForWidth(label_54->sizePolicy().hasHeightForWidth());
        label_54->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_54, 0, 6, 1, 1);

        label_55 = new QLabel(groupBox_15);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        gridLayout_4->addWidget(label_55, 1, 6, 1, 1);

        label_44 = new QLabel(groupBox_15);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        sizePolicy1.setHeightForWidth(label_44->sizePolicy().hasHeightForWidth());
        label_44->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_44, 0, 3, 1, 1);

        lbl_PlatformInfoRx = new QLabel(groupBox_15);
        lbl_PlatformInfoRx->setObjectName(QString::fromUtf8("lbl_PlatformInfoRx"));
        sizePolicy4.setHeightForWidth(lbl_PlatformInfoRx->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoRx->setSizePolicy(sizePolicy4);
        lbl_PlatformInfoRx->setMinimumSize(QSize(40, 0));

        gridLayout_4->addWidget(lbl_PlatformInfoRx, 1, 1, 1, 2);

        lbl_PlatformInfoZ = new QLabel(groupBox_15);
        lbl_PlatformInfoZ->setObjectName(QString::fromUtf8("lbl_PlatformInfoZ"));
        sizePolicy4.setHeightForWidth(lbl_PlatformInfoZ->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoZ->setSizePolicy(sizePolicy4);
        lbl_PlatformInfoZ->setMinimumSize(QSize(40, 0));

        gridLayout_4->addWidget(lbl_PlatformInfoZ, 0, 7, 1, 2);

        label_94 = new QLabel(groupBox_15);
        label_94->setObjectName(QString::fromUtf8("label_94"));
        sizePolicy2.setHeightForWidth(label_94->sizePolicy().hasHeightForWidth());
        label_94->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(label_94, 0, 9, 1, 1);

        label_10 = new QLabel(groupBox_15);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(50, 0));
        label_10->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);

        lbl_PlatformInfoY = new QLabel(groupBox_15);
        lbl_PlatformInfoY->setObjectName(QString::fromUtf8("lbl_PlatformInfoY"));
        sizePolicy4.setHeightForWidth(lbl_PlatformInfoY->sizePolicy().hasHeightForWidth());
        lbl_PlatformInfoY->setSizePolicy(sizePolicy4);
        lbl_PlatformInfoY->setMinimumSize(QSize(40, 0));

        gridLayout_4->addWidget(lbl_PlatformInfoY, 0, 4, 1, 2);

        label_57 = new QLabel(groupBox_15);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        sizePolicy1.setHeightForWidth(label_57->sizePolicy().hasHeightForWidth());
        label_57->setSizePolicy(sizePolicy1);
        label_57->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(label_57, 1, 0, 1, 1);

        lbl_PlatformEnable = new QLabel(groupBox_15);
        lbl_PlatformEnable->setObjectName(QString::fromUtf8("lbl_PlatformEnable"));
        sizePolicy1.setHeightForWidth(lbl_PlatformEnable->sizePolicy().hasHeightForWidth());
        lbl_PlatformEnable->setSizePolicy(sizePolicy1);
        lbl_PlatformEnable->setMinimumSize(QSize(50, 0));

        gridLayout_4->addWidget(lbl_PlatformEnable, 0, 12, 1, 1);

        label_100 = new QLabel(groupBox_15);
        label_100->setObjectName(QString::fromUtf8("label_100"));

        gridLayout_4->addWidget(label_100, 1, 11, 1, 1);

        lbl_PlatformIsTarget = new QLabel(groupBox_15);
        lbl_PlatformIsTarget->setObjectName(QString::fromUtf8("lbl_PlatformIsTarget"));
        sizePolicy4.setHeightForWidth(lbl_PlatformIsTarget->sizePolicy().hasHeightForWidth());
        lbl_PlatformIsTarget->setSizePolicy(sizePolicy4);
        lbl_PlatformIsTarget->setMinimumSize(QSize(50, 0));

        gridLayout_4->addWidget(lbl_PlatformIsTarget, 1, 12, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_15, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(3);
        sizePolicy5.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy5);
        groupBox_3->setMinimumSize(QSize(900, 0));
        groupBox_3->setMaximumSize(QSize(16777215, 200));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        verticalLayout_63 = new QVBoxLayout(groupBox_3);
        verticalLayout_63->setObjectName(QString::fromUtf8("verticalLayout_63"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_77 = new QLabel(groupBox_3);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        label_77->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_77, 0, 8, 1, 1);

        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_28, 0, 3, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy6);
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_20, 2, 0, 1, 1);

        lblFsLimit12 = new QLabel(groupBox_3);
        lblFsLimit12->setObjectName(QString::fromUtf8("lblFsLimit12"));
        lblFsLimit12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit12, 4, 6, 1, 1);

        lblAxisInit4 = new QLabel(groupBox_3);
        lblAxisInit4->setObjectName(QString::fromUtf8("lblAxisInit4"));
        lblAxisInit4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit4, 2, 5, 1, 1);

        lblAxisSpeed12 = new QLabel(groupBox_3);
        lblAxisSpeed12->setObjectName(QString::fromUtf8("lblAxisSpeed12"));
        lblAxisSpeed12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed12, 4, 8, 1, 1);

        lblAxisDecel4 = new QLabel(groupBox_3);
        lblAxisDecel4->setObjectName(QString::fromUtf8("lblAxisDecel4"));
        lblAxisDecel4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel4, 2, 10, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy6.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy6);
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_21, 4, 0, 1, 1);

        lblPosi4 = new QLabel(groupBox_3);
        lblPosi4->setObjectName(QString::fromUtf8("lblPosi4"));
        lblPosi4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi4, 2, 1, 1, 1);

        lblPosi12 = new QLabel(groupBox_3);
        lblPosi12->setObjectName(QString::fromUtf8("lblPosi12"));
        sizePolicy6.setHeightForWidth(lblPosi12->sizePolicy().hasHeightForWidth());
        lblPosi12->setSizePolicy(sizePolicy6);
        lblPosi12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi12, 4, 1, 1, 1);

        label_171 = new QLabel(groupBox_3);
        label_171->setObjectName(QString::fromUtf8("label_171"));
        label_171->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_171, 0, 5, 1, 1);

        label_194 = new QLabel(groupBox_3);
        label_194->setObjectName(QString::fromUtf8("label_194"));
        label_194->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_194, 0, 4, 1, 1);

        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_27, 0, 6, 1, 1);

        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        sizePolicy6.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy6);
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_26, 0, 0, 1, 1);

        lblAxisSpeed4 = new QLabel(groupBox_3);
        lblAxisSpeed4->setObjectName(QString::fromUtf8("lblAxisSpeed4"));
        lblAxisSpeed4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed4, 2, 8, 1, 1);

        label_78 = new QLabel(groupBox_3);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_78, 0, 9, 1, 1);

        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        sizePolicy6.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy6);
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_25, 0, 1, 1, 1);

        lblAxisStatus12 = new QLabel(groupBox_3);
        lblAxisStatus12->setObjectName(QString::fromUtf8("lblAxisStatus12"));
        lblAxisStatus12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus12, 4, 2, 1, 1);

        lblAxisAccel12 = new QLabel(groupBox_3);
        lblAxisAccel12->setObjectName(QString::fromUtf8("lblAxisAccel12"));
        lblAxisAccel12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel12, 4, 9, 1, 1);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_24, 0, 2, 1, 1);

        lblFsLimit4 = new QLabel(groupBox_3);
        lblFsLimit4->setObjectName(QString::fromUtf8("lblFsLimit4"));
        lblFsLimit4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit4, 2, 6, 1, 1);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 0, 7, 1, 1);

        lblAxisStatus4 = new QLabel(groupBox_3);
        lblAxisStatus4->setObjectName(QString::fromUtf8("lblAxisStatus4"));
        lblAxisStatus4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus4, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer_2, 3, 4, 1, 1);

        label_84 = new QLabel(groupBox_3);
        label_84->setObjectName(QString::fromUtf8("label_84"));
        label_84->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_84, 0, 10, 1, 1);

        lblAxisUnits4 = new QLabel(groupBox_3);
        lblAxisUnits4->setObjectName(QString::fromUtf8("lblAxisUnits4"));
        lblAxisUnits4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits4, 2, 4, 1, 1);

        lblAxisAccel4 = new QLabel(groupBox_3);
        lblAxisAccel4->setObjectName(QString::fromUtf8("lblAxisAccel4"));
        lblAxisAccel4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel4, 2, 9, 1, 1);

        lblAxisUnits12 = new QLabel(groupBox_3);
        lblAxisUnits12->setObjectName(QString::fromUtf8("lblAxisUnits12"));
        lblAxisUnits12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits12, 4, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer, 1, 4, 1, 1);

        lblAxisDecel12 = new QLabel(groupBox_3);
        lblAxisDecel12->setObjectName(QString::fromUtf8("lblAxisDecel12"));
        lblAxisDecel12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel12, 4, 10, 1, 1);

        lblAxisInit12 = new QLabel(groupBox_3);
        lblAxisInit12->setObjectName(QString::fromUtf8("lblAxisInit12"));
        lblAxisInit12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit12, 4, 5, 1, 1);

        lblBsLimit4 = new QLabel(groupBox_3);
        lblBsLimit4->setObjectName(QString::fromUtf8("lblBsLimit4"));
        lblBsLimit4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit4, 2, 7, 1, 1);

        lblBsLimit12 = new QLabel(groupBox_3);
        lblBsLimit12->setObjectName(QString::fromUtf8("lblBsLimit12"));
        lblBsLimit12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit12, 4, 7, 1, 1);

        lblAxisType4 = new QLabel(groupBox_3);
        lblAxisType4->setObjectName(QString::fromUtf8("lblAxisType4"));
        lblAxisType4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType4, 2, 3, 1, 1);

        lblAxisType12 = new QLabel(groupBox_3);
        lblAxisType12->setObjectName(QString::fromUtf8("lblAxisType12"));
        lblAxisType12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType12, 4, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);


        verticalLayout_63->addLayout(horizontalLayout_2);


        gridLayout_6->addWidget(groupBox_3, 4, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        label_129 = new QLabel(groupBox);
        label_129->setObjectName(QString::fromUtf8("label_129"));

        gridLayout->addWidget(label_129, 0, 0, 1, 1);

        lbl_GapAngle = new QLabel(groupBox);
        lbl_GapAngle->setObjectName(QString::fromUtf8("lbl_GapAngle"));
        sizePolicy4.setHeightForWidth(lbl_GapAngle->sizePolicy().hasHeightForWidth());
        lbl_GapAngle->setSizePolicy(sizePolicy4);
        lbl_GapAngle->setMinimumSize(QSize(30, 0));

        gridLayout->addWidget(lbl_GapAngle, 0, 1, 1, 1, Qt::AlignHCenter);

        label_132 = new QLabel(groupBox);
        label_132->setObjectName(QString::fromUtf8("label_132"));

        gridLayout->addWidget(label_132, 0, 2, 1, 1);

        lbl_GapWidth = new QLabel(groupBox);
        lbl_GapWidth->setObjectName(QString::fromUtf8("lbl_GapWidth"));
        sizePolicy4.setHeightForWidth(lbl_GapWidth->sizePolicy().hasHeightForWidth());
        lbl_GapWidth->setSizePolicy(sizePolicy4);
        lbl_GapWidth->setMinimumSize(QSize(30, 0));

        gridLayout->addWidget(lbl_GapWidth, 0, 3, 1, 1, Qt::AlignHCenter);

        label_133 = new QLabel(groupBox);
        label_133->setObjectName(QString::fromUtf8("label_133"));

        gridLayout->addWidget(label_133, 0, 4, 1, 1);

        lbl_GapWidth1 = new QLabel(groupBox);
        lbl_GapWidth1->setObjectName(QString::fromUtf8("lbl_GapWidth1"));
        sizePolicy4.setHeightForWidth(lbl_GapWidth1->sizePolicy().hasHeightForWidth());
        lbl_GapWidth1->setSizePolicy(sizePolicy4);
        lbl_GapWidth1->setMinimumSize(QSize(30, 0));

        gridLayout->addWidget(lbl_GapWidth1, 0, 5, 1, 1, Qt::AlignHCenter);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox, 3, 0, 1, 1);

        LiftMonitor->setCentralWidget(centralwidget);

        retranslateUi(LiftMonitor);

        QMetaObject::connectSlotsByName(LiftMonitor);
    } // setupUi

    void retranslateUi(QMainWindow *LiftMonitor)
    {
        LiftMonitor->setWindowTitle(QCoreApplication::translate("LiftMonitor", "\345\215\207\351\231\215\347\263\273\347\273\237\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("LiftMonitor", "\345\205\255\347\273\264\345\212\233\344\274\240\346\204\237\345\231\250\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        groupBox_27->setTitle(QCoreApplication::translate("LiftMonitor", "\345\212\233\344\277\241\346\201\257", nullptr));
        label_115->setText(QCoreApplication::translate("LiftMonitor", "My: ", nullptr));
        lbl_MY->setText(QString());
        lbl_FX->setText(QString());
        label_16->setText(QCoreApplication::translate("LiftMonitor", "Fy:", nullptr));
        label_17->setText(QCoreApplication::translate("LiftMonitor", "Fz:", nullptr));
        label_116->setText(QCoreApplication::translate("LiftMonitor", "Mz:", nullptr));
        lbl_FY->setText(QString());
        lbl_MZ->setText(QString());
        label_108->setText(QCoreApplication::translate("LiftMonitor", "Mx:", nullptr));
        label_13->setText(QCoreApplication::translate("LiftMonitor", "FX:", nullptr));
        lbl_FZ->setText(QString());
        lbl_MX->setText(QString());
        groupBox_32->setTitle(QCoreApplication::translate("LiftMonitor", "\347\242\260\346\222\236\344\277\241\346\201\257", nullptr));
        lbl_CrashInfo->setText(QString());
        lbl_isCrash->setText(QString());
        groupBox_15->setTitle(QCoreApplication::translate("LiftMonitor", "\345\205\255\350\207\252\347\224\261\345\272\246\345\271\263\345\217\260\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_56->setText(QCoreApplication::translate("LiftMonitor", "RY\357\274\232", nullptr));
        lbl_PlatformStatus->setText(QCoreApplication::translate("LiftMonitor", "\345\201\234\346\255\242\350\277\220\345\212\250", nullptr));
        label_95->setText(QCoreApplication::translate("LiftMonitor", "\350\277\220\345\212\250\347\212\266\346\200\201: ", nullptr));
        lbl_PlatformWarning->setText(QCoreApplication::translate("LiftMonitor", "NoError", nullptr));
        lbl_PlatformInfoRz->setText(QString());
        lbl_PlatformInfoX->setText(QString());
        label_96->setText(QCoreApplication::translate("LiftMonitor", "\345\271\263\345\217\260\344\275\277\350\203\275\357\274\232", nullptr));
        lbl_PlatformInfoRy->setText(QString());
        label_54->setText(QCoreApplication::translate("LiftMonitor", "Z\357\274\232", nullptr));
        label_55->setText(QCoreApplication::translate("LiftMonitor", "RZ\357\274\232", nullptr));
        label_44->setText(QCoreApplication::translate("LiftMonitor", "Y\357\274\232", nullptr));
        lbl_PlatformInfoRx->setText(QString());
        lbl_PlatformInfoZ->setText(QString());
        label_94->setText(QCoreApplication::translate("LiftMonitor", "\350\255\246\345\221\212\344\277\241\346\201\257\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("LiftMonitor", "X\357\274\232", nullptr));
        lbl_PlatformInfoY->setText(QString());
        label_57->setText(QCoreApplication::translate("LiftMonitor", "RX\357\274\232", nullptr));
        lbl_PlatformEnable->setText(QCoreApplication::translate("LiftMonitor", "False", nullptr));
        label_100->setText(QCoreApplication::translate("LiftMonitor", "\345\247\277\346\200\201\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_PlatformIsTarget->setText(QCoreApplication::translate("LiftMonitor", "False", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("LiftMonitor", "\345\215\207\351\231\215\347\224\265\346\234\272\347\212\266\346\200\201\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_77->setText(QCoreApplication::translate("LiftMonitor", "\351\200\237\345\272\246", nullptr));
        label_28->setText(QCoreApplication::translate("LiftMonitor", "\350\275\264\347\212\266\346\200\201", nullptr));
        label_20->setText(QCoreApplication::translate("LiftMonitor", "\344\270\200\347\272\247\345\215\207\351\231\215", nullptr));
        lblFsLimit12->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblAxisInit4->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblAxisSpeed12->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblAxisDecel4->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        label_21->setText(QCoreApplication::translate("LiftMonitor", "\344\272\214\347\272\247\345\215\207\351\231\215", nullptr));
        lblPosi4->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblPosi12->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        label_171->setText(QCoreApplication::translate("LiftMonitor", "\345\210\235\345\247\213", nullptr));
        label_194->setText(QCoreApplication::translate("LiftMonitor", "\350\204\211\345\206\262\345\275\223\351\207\217", nullptr));
        label_27->setText(QCoreApplication::translate("LiftMonitor", "\346\255\243\351\231\220\344\275\215", nullptr));
        label_26->setText(QCoreApplication::translate("LiftMonitor", "\347\224\265\346\234\272", nullptr));
        lblAxisSpeed4->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        label_78->setText(QCoreApplication::translate("LiftMonitor", "\345\212\240\351\200\237\345\272\246", nullptr));
        label_25->setText(QCoreApplication::translate("LiftMonitor", "\350\275\264\345\235\220\346\240\207", nullptr));
        lblAxisStatus12->setText(QCoreApplication::translate("LiftMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        lblAxisAccel12->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        label_24->setText(QCoreApplication::translate("LiftMonitor", "\350\275\264\347\212\266\346\200\201", nullptr));
        lblFsLimit4->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        label_18->setText(QCoreApplication::translate("LiftMonitor", "\350\264\237\351\231\220\344\275\215", nullptr));
        lblAxisStatus4->setText(QCoreApplication::translate("LiftMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        label_84->setText(QCoreApplication::translate("LiftMonitor", "\345\207\217\351\200\237\345\272\246", nullptr));
        lblAxisUnits4->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblAxisAccel4->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblAxisUnits12->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblAxisDecel12->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblAxisInit12->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblBsLimit4->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblBsLimit12->setText(QCoreApplication::translate("LiftMonitor", "0", nullptr));
        lblAxisType4->setText(QCoreApplication::translate("LiftMonitor", "\345\276\205\346\234\272", nullptr));
        lblAxisType12->setText(QCoreApplication::translate("LiftMonitor", "\345\276\205\346\234\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LiftMonitor", "\350\247\206\350\247\211\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_129->setText(QCoreApplication::translate("LiftMonitor", "\347\274\235\351\232\231\350\247\222\345\272\246(deg)\357\274\232", nullptr));
        lbl_GapAngle->setText(QCoreApplication::translate("LiftMonitor", "0.0", nullptr));
        label_132->setText(QCoreApplication::translate("LiftMonitor", "\347\274\235\351\232\231\345\256\275\345\272\2461(mm)\357\274\232", nullptr));
        lbl_GapWidth->setText(QCoreApplication::translate("LiftMonitor", "2.0", nullptr));
        label_133->setText(QCoreApplication::translate("LiftMonitor", "\347\274\235\351\232\231\345\256\275\345\272\2462(mm)\357\274\232", nullptr));
        lbl_GapWidth1->setText(QCoreApplication::translate("LiftMonitor", "2.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LiftMonitor: public Ui_LiftMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIFTMONITOR_H
