/********************************************************************************
** Form generated from reading UI file 'levelmonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELMONITOR_H
#define UI_LEVELMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelMonitor
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_19;
    QGridLayout *gridLayout_21;
    QLabel *label_332;
    QLineEdit *Current1;
    QHBoxLayout *horizontalLayout_122;
    QLabel *label_246;
    QLabel *lbl_Symbol3;
    QLabel *label_335;
    QHBoxLayout *horizontalLayout_118;
    QLabel *label_242;
    QLabel *lbl_Symbol2;
    QLabel *label_156;
    QLineEdit *sensor3;
    QLabel *label_333;
    QLabel *label_326;
    QLineEdit *sensor2;
    QLabel *label_336;
    QLabel *label_158;
    QLineEdit *Current0;
    QLabel *label_334;
    QHBoxLayout *horizontalLayout_120;
    QLabel *label_244;
    QLabel *lbl_Symbol1;
    QLineEdit *sensor1;
    QLabel *label_159;
    QLabel *label_157;
    QLabel *label_338;
    QLineEdit *Current2;
    QLineEdit *sensor0;
    QLineEdit *Current3;
    QHBoxLayout *horizontalLayout_116;
    QLabel *label_240;
    QLabel *lbl_Symbol0;
    QLabel *label_337;
    QGroupBox *groupBox_20;
    QVBoxLayout *verticalLayout_25;
    QGridLayout *gridLayout_23;
    QLabel *label_341;
    QHBoxLayout *horizontalLayout_125;
    QLabel *lbl_SymbolAll;
    QLabel *label_342;
    QLineEdit *AngleX;
    QLabel *label_331;
    QLineEdit *AngleY;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_63;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *lblFsLimit2;
    QLabel *label_84;
    QLabel *lblFsLimit3;
    QLabel *lblAxisSpeed2;
    QLabel *label_26;
    QLabel *lblBsLimit0;
    QLabel *lblAxisSpeed1;
    QLabel *label_21;
    QSpacerItem *verticalSpacer;
    QLabel *lblAxisUnits0;
    QLabel *lblAxisType0;
    QLabel *lblAxisType1;
    QLabel *lblPosi3;
    QLabel *lblAxisStatus1;
    QLabel *lblAxisInit2;
    QLabel *label_77;
    QLabel *label_30;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_24;
    QLabel *lblAxisAccel0;
    QLabel *lblAxisSpeed3;
    QLabel *label_171;
    QLabel *lblAxisDecel0;
    QLabel *label_78;
    QLabel *lblAxisAccel3;
    QLabel *lblAxisAccel2;
    QLabel *lblAxisDecel1;
    QLabel *lblAxisUnits2;
    QLabel *lblAxisInit0;
    QLabel *lblAxisStatus2;
    QLabel *label_27;
    QLabel *lblPosi2;
    QLabel *label_18;
    QLabel *lblAxisAccel1;
    QLabel *lblAxisStatus3;
    QLabel *lblAxisSpeed0;
    QLabel *lblBsLimit1;
    QLabel *label_28;
    QLabel *label_194;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *lblAxisDecel2;
    QLabel *lblAxisInit3;
    QLabel *lblAxisStatus0;
    QLabel *lblBsLimit2;
    QLabel *lblAxisInit1;
    QLabel *label_25;
    QLabel *lblBsLimit3;
    QLabel *lblPosi1;
    QLabel *lblAxisUnits3;
    QLabel *lblPosi0;
    QLabel *label_20;
    QLabel *lblFsLimit1;
    QLabel *lblFsLimit0;
    QLabel *lblAxisDecel3;
    QLabel *lblAxisUnits1;
    QLabel *label_29;
    QLabel *lblAxisType2;
    QLabel *lblAxisType3;

    void setupUi(QMainWindow *LevelMonitor)
    {
        if (LevelMonitor->objectName().isEmpty())
            LevelMonitor->setObjectName(QString::fromUtf8("LevelMonitor"));
        LevelMonitor->resize(921, 435);
        LevelMonitor->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(LevelMonitor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_19 = new QGroupBox(centralwidget);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_19->sizePolicy().hasHeightForWidth());
        groupBox_19->setSizePolicy(sizePolicy);
        groupBox_19->setMinimumSize(QSize(500, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        groupBox_19->setFont(font);
        groupBox_19->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        gridLayout_21 = new QGridLayout(groupBox_19);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        label_332 = new QLabel(groupBox_19);
        label_332->setObjectName(QString::fromUtf8("label_332"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_332->sizePolicy().hasHeightForWidth());
        label_332->setSizePolicy(sizePolicy1);
        label_332->setMinimumSize(QSize(80, 0));
        label_332->setMaximumSize(QSize(80, 16777215));

        gridLayout_21->addWidget(label_332, 3, 4, 1, 1);

        Current1 = new QLineEdit(groupBox_19);
        Current1->setObjectName(QString::fromUtf8("Current1"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Current1->sizePolicy().hasHeightForWidth());
        Current1->setSizePolicy(sizePolicy2);
        Current1->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(Current1, 1, 5, 1, 1);

        horizontalLayout_122 = new QHBoxLayout();
        horizontalLayout_122->setObjectName(QString::fromUtf8("horizontalLayout_122"));
        label_246 = new QLabel(groupBox_19);
        label_246->setObjectName(QString::fromUtf8("label_246"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_246->sizePolicy().hasHeightForWidth());
        label_246->setSizePolicy(sizePolicy3);
        label_246->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_122->addWidget(label_246);

        lbl_Symbol3 = new QLabel(groupBox_19);
        lbl_Symbol3->setObjectName(QString::fromUtf8("lbl_Symbol3"));
        sizePolicy3.setHeightForWidth(lbl_Symbol3->sizePolicy().hasHeightForWidth());
        lbl_Symbol3->setSizePolicy(sizePolicy3);
        lbl_Symbol3->setMaximumSize(QSize(15, 15));
        lbl_Symbol3->setStyleSheet(QString::fromUtf8("border-radius: 7px; border: 2px solid black;background-color: white;"));

        horizontalLayout_122->addWidget(lbl_Symbol3);


        gridLayout_21->addLayout(horizontalLayout_122, 4, 1, 1, 1);

        label_335 = new QLabel(groupBox_19);
        label_335->setObjectName(QString::fromUtf8("label_335"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_335->sizePolicy().hasHeightForWidth());
        label_335->setSizePolicy(sizePolicy4);
        label_335->setMinimumSize(QSize(80, 0));
        label_335->setMaximumSize(QSize(80, 16777215));

        gridLayout_21->addWidget(label_335, 4, 4, 1, 1);

        horizontalLayout_118 = new QHBoxLayout();
        horizontalLayout_118->setObjectName(QString::fromUtf8("horizontalLayout_118"));
        label_242 = new QLabel(groupBox_19);
        label_242->setObjectName(QString::fromUtf8("label_242"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_242->sizePolicy().hasHeightForWidth());
        label_242->setSizePolicy(sizePolicy5);
        label_242->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_118->addWidget(label_242);

        lbl_Symbol2 = new QLabel(groupBox_19);
        lbl_Symbol2->setObjectName(QString::fromUtf8("lbl_Symbol2"));
        sizePolicy3.setHeightForWidth(lbl_Symbol2->sizePolicy().hasHeightForWidth());
        lbl_Symbol2->setSizePolicy(sizePolicy3);
        lbl_Symbol2->setMaximumSize(QSize(15, 15));
        lbl_Symbol2->setStyleSheet(QString::fromUtf8("border-radius: 7px; border: 2px solid black;background-color: white;"));

        horizontalLayout_118->addWidget(lbl_Symbol2);


        gridLayout_21->addLayout(horizontalLayout_118, 3, 1, 1, 1);

        label_156 = new QLabel(groupBox_19);
        label_156->setObjectName(QString::fromUtf8("label_156"));
        sizePolicy5.setHeightForWidth(label_156->sizePolicy().hasHeightForWidth());
        label_156->setSizePolicy(sizePolicy5);
        label_156->setMaximumSize(QSize(120, 16777215));
        label_156->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(label_156, 1, 0, 1, 1);

        sensor3 = new QLineEdit(groupBox_19);
        sensor3->setObjectName(QString::fromUtf8("sensor3"));
        sizePolicy2.setHeightForWidth(sensor3->sizePolicy().hasHeightForWidth());
        sensor3->setSizePolicy(sizePolicy2);
        sensor3->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(sensor3, 4, 3, 1, 1);

        label_333 = new QLabel(groupBox_19);
        label_333->setObjectName(QString::fromUtf8("label_333"));
        sizePolicy4.setHeightForWidth(label_333->sizePolicy().hasHeightForWidth());
        label_333->setSizePolicy(sizePolicy4);
        label_333->setMinimumSize(QSize(80, 0));
        label_333->setMaximumSize(QSize(80, 16777215));

        gridLayout_21->addWidget(label_333, 0, 2, 1, 1);

        label_326 = new QLabel(groupBox_19);
        label_326->setObjectName(QString::fromUtf8("label_326"));
        sizePolicy4.setHeightForWidth(label_326->sizePolicy().hasHeightForWidth());
        label_326->setSizePolicy(sizePolicy4);
        label_326->setMinimumSize(QSize(80, 0));
        label_326->setMaximumSize(QSize(80, 16777215));

        gridLayout_21->addWidget(label_326, 1, 4, 1, 1);

        sensor2 = new QLineEdit(groupBox_19);
        sensor2->setObjectName(QString::fromUtf8("sensor2"));
        sizePolicy2.setHeightForWidth(sensor2->sizePolicy().hasHeightForWidth());
        sensor2->setSizePolicy(sizePolicy2);
        sensor2->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(sensor2, 3, 3, 1, 1);

        label_336 = new QLabel(groupBox_19);
        label_336->setObjectName(QString::fromUtf8("label_336"));
        sizePolicy4.setHeightForWidth(label_336->sizePolicy().hasHeightForWidth());
        label_336->setSizePolicy(sizePolicy4);
        label_336->setMinimumSize(QSize(80, 0));
        label_336->setMaximumSize(QSize(80, 16777215));

        gridLayout_21->addWidget(label_336, 1, 2, 1, 1);

        label_158 = new QLabel(groupBox_19);
        label_158->setObjectName(QString::fromUtf8("label_158"));
        sizePolicy5.setHeightForWidth(label_158->sizePolicy().hasHeightForWidth());
        label_158->setSizePolicy(sizePolicy5);
        label_158->setMaximumSize(QSize(120, 16777215));
        label_158->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(label_158, 3, 0, 1, 1);

        Current0 = new QLineEdit(groupBox_19);
        Current0->setObjectName(QString::fromUtf8("Current0"));
        sizePolicy2.setHeightForWidth(Current0->sizePolicy().hasHeightForWidth());
        Current0->setSizePolicy(sizePolicy2);
        Current0->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(Current0, 0, 5, 1, 1);

        label_334 = new QLabel(groupBox_19);
        label_334->setObjectName(QString::fromUtf8("label_334"));
        sizePolicy1.setHeightForWidth(label_334->sizePolicy().hasHeightForWidth());
        label_334->setSizePolicy(sizePolicy1);
        label_334->setMinimumSize(QSize(80, 0));
        label_334->setMaximumSize(QSize(80, 16777215));

        gridLayout_21->addWidget(label_334, 3, 2, 1, 1);

        horizontalLayout_120 = new QHBoxLayout();
        horizontalLayout_120->setObjectName(QString::fromUtf8("horizontalLayout_120"));
        label_244 = new QLabel(groupBox_19);
        label_244->setObjectName(QString::fromUtf8("label_244"));
        sizePolicy5.setHeightForWidth(label_244->sizePolicy().hasHeightForWidth());
        label_244->setSizePolicy(sizePolicy5);
        label_244->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_120->addWidget(label_244);

        lbl_Symbol1 = new QLabel(groupBox_19);
        lbl_Symbol1->setObjectName(QString::fromUtf8("lbl_Symbol1"));
        sizePolicy3.setHeightForWidth(lbl_Symbol1->sizePolicy().hasHeightForWidth());
        lbl_Symbol1->setSizePolicy(sizePolicy3);
        lbl_Symbol1->setMaximumSize(QSize(15, 15));
        lbl_Symbol1->setStyleSheet(QString::fromUtf8("border-radius: 7px; border: 2px solid black;background-color: white;"));

        horizontalLayout_120->addWidget(lbl_Symbol1);


        gridLayout_21->addLayout(horizontalLayout_120, 1, 1, 1, 1);

        sensor1 = new QLineEdit(groupBox_19);
        sensor1->setObjectName(QString::fromUtf8("sensor1"));
        sizePolicy2.setHeightForWidth(sensor1->sizePolicy().hasHeightForWidth());
        sensor1->setSizePolicy(sizePolicy2);
        sensor1->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(sensor1, 1, 3, 1, 1);

        label_159 = new QLabel(groupBox_19);
        label_159->setObjectName(QString::fromUtf8("label_159"));
        sizePolicy3.setHeightForWidth(label_159->sizePolicy().hasHeightForWidth());
        label_159->setSizePolicy(sizePolicy3);
        label_159->setMaximumSize(QSize(120, 16777215));
        label_159->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(label_159, 4, 0, 1, 1);

        label_157 = new QLabel(groupBox_19);
        label_157->setObjectName(QString::fromUtf8("label_157"));
        sizePolicy5.setHeightForWidth(label_157->sizePolicy().hasHeightForWidth());
        label_157->setSizePolicy(sizePolicy5);
        label_157->setMaximumSize(QSize(120, 16777215));
        label_157->setAlignment(Qt::AlignCenter);

        gridLayout_21->addWidget(label_157, 0, 0, 1, 1);

        label_338 = new QLabel(groupBox_19);
        label_338->setObjectName(QString::fromUtf8("label_338"));
        sizePolicy4.setHeightForWidth(label_338->sizePolicy().hasHeightForWidth());
        label_338->setSizePolicy(sizePolicy4);
        label_338->setMinimumSize(QSize(80, 0));
        label_338->setMaximumSize(QSize(80, 16777215));

        gridLayout_21->addWidget(label_338, 4, 2, 1, 1);

        Current2 = new QLineEdit(groupBox_19);
        Current2->setObjectName(QString::fromUtf8("Current2"));
        sizePolicy2.setHeightForWidth(Current2->sizePolicy().hasHeightForWidth());
        Current2->setSizePolicy(sizePolicy2);
        Current2->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(Current2, 3, 5, 1, 1);

        sensor0 = new QLineEdit(groupBox_19);
        sensor0->setObjectName(QString::fromUtf8("sensor0"));
        sizePolicy2.setHeightForWidth(sensor0->sizePolicy().hasHeightForWidth());
        sensor0->setSizePolicy(sizePolicy2);
        sensor0->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(sensor0, 0, 3, 1, 1);

        Current3 = new QLineEdit(groupBox_19);
        Current3->setObjectName(QString::fromUtf8("Current3"));
        sizePolicy2.setHeightForWidth(Current3->sizePolicy().hasHeightForWidth());
        Current3->setSizePolicy(sizePolicy2);
        Current3->setMaximumSize(QSize(100, 16777215));

        gridLayout_21->addWidget(Current3, 4, 5, 1, 1);

        horizontalLayout_116 = new QHBoxLayout();
        horizontalLayout_116->setObjectName(QString::fromUtf8("horizontalLayout_116"));
        label_240 = new QLabel(groupBox_19);
        label_240->setObjectName(QString::fromUtf8("label_240"));
        sizePolicy3.setHeightForWidth(label_240->sizePolicy().hasHeightForWidth());
        label_240->setSizePolicy(sizePolicy3);
        label_240->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_116->addWidget(label_240);

        lbl_Symbol0 = new QLabel(groupBox_19);
        lbl_Symbol0->setObjectName(QString::fromUtf8("lbl_Symbol0"));
        sizePolicy3.setHeightForWidth(lbl_Symbol0->sizePolicy().hasHeightForWidth());
        lbl_Symbol0->setSizePolicy(sizePolicy3);
        lbl_Symbol0->setMaximumSize(QSize(15, 15));
        lbl_Symbol0->setStyleSheet(QString::fromUtf8("border-radius: 7px; border: 2px solid black;background-color: white;"));

        horizontalLayout_116->addWidget(lbl_Symbol0);


        gridLayout_21->addLayout(horizontalLayout_116, 0, 1, 1, 1);

        label_337 = new QLabel(groupBox_19);
        label_337->setObjectName(QString::fromUtf8("label_337"));
        sizePolicy4.setHeightForWidth(label_337->sizePolicy().hasHeightForWidth());
        label_337->setSizePolicy(sizePolicy4);
        label_337->setMinimumSize(QSize(80, 0));
        label_337->setMaximumSize(QSize(80, 16777215));

        gridLayout_21->addWidget(label_337, 0, 4, 1, 1);


        gridLayout->addWidget(groupBox_19, 0, 0, 1, 1);

        groupBox_20 = new QGroupBox(centralwidget);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        sizePolicy3.setHeightForWidth(groupBox_20->sizePolicy().hasHeightForWidth());
        groupBox_20->setSizePolicy(sizePolicy3);
        groupBox_20->setMinimumSize(QSize(300, 161));
        groupBox_20->setMaximumSize(QSize(300, 16777215));
        groupBox_20->setFont(font);
        groupBox_20->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        verticalLayout_25 = new QVBoxLayout(groupBox_20);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        gridLayout_23 = new QGridLayout();
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        label_341 = new QLabel(groupBox_20);
        label_341->setObjectName(QString::fromUtf8("label_341"));
        sizePolicy4.setHeightForWidth(label_341->sizePolicy().hasHeightForWidth());
        label_341->setSizePolicy(sizePolicy4);
        label_341->setMinimumSize(QSize(80, 0));
        label_341->setMaximumSize(QSize(80, 16777215));

        gridLayout_23->addWidget(label_341, 1, 0, 1, 1, Qt::AlignLeft);

        horizontalLayout_125 = new QHBoxLayout();
        horizontalLayout_125->setObjectName(QString::fromUtf8("horizontalLayout_125"));
        lbl_SymbolAll = new QLabel(groupBox_20);
        lbl_SymbolAll->setObjectName(QString::fromUtf8("lbl_SymbolAll"));
        sizePolicy3.setHeightForWidth(lbl_SymbolAll->sizePolicy().hasHeightForWidth());
        lbl_SymbolAll->setSizePolicy(sizePolicy3);
        lbl_SymbolAll->setMaximumSize(QSize(15, 15));
        lbl_SymbolAll->setStyleSheet(QString::fromUtf8("border-radius: 7px; border: 2px solid black;background-color: white;"));

        horizontalLayout_125->addWidget(lbl_SymbolAll);


        gridLayout_23->addLayout(horizontalLayout_125, 2, 1, 1, 1);

        label_342 = new QLabel(groupBox_20);
        label_342->setObjectName(QString::fromUtf8("label_342"));
        sizePolicy4.setHeightForWidth(label_342->sizePolicy().hasHeightForWidth());
        label_342->setSizePolicy(sizePolicy4);
        label_342->setMinimumSize(QSize(80, 0));
        label_342->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_342, 0, 0, 1, 1, Qt::AlignLeft);

        AngleX = new QLineEdit(groupBox_20);
        AngleX->setObjectName(QString::fromUtf8("AngleX"));
        sizePolicy2.setHeightForWidth(AngleX->sizePolicy().hasHeightForWidth());
        AngleX->setSizePolicy(sizePolicy2);
        AngleX->setMaximumSize(QSize(150, 16777215));

        gridLayout_23->addWidget(AngleX, 0, 1, 1, 1);

        label_331 = new QLabel(groupBox_20);
        label_331->setObjectName(QString::fromUtf8("label_331"));
        sizePolicy1.setHeightForWidth(label_331->sizePolicy().hasHeightForWidth());
        label_331->setSizePolicy(sizePolicy1);
        label_331->setMaximumSize(QSize(90, 16777215));

        gridLayout_23->addWidget(label_331, 2, 0, 1, 1);

        AngleY = new QLineEdit(groupBox_20);
        AngleY->setObjectName(QString::fromUtf8("AngleY"));
        sizePolicy2.setHeightForWidth(AngleY->sizePolicy().hasHeightForWidth());
        AngleY->setSizePolicy(sizePolicy2);
        AngleY->setMaximumSize(QSize(150, 16777215));

        gridLayout_23->addWidget(AngleY, 1, 1, 1, 1);


        verticalLayout_25->addLayout(gridLayout_23);


        gridLayout->addWidget(groupBox_20, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(3);
        sizePolicy6.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy6);
        groupBox_3->setMinimumSize(QSize(900, 0));
        groupBox_3->setMaximumSize(QSize(16777215, 250));
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
        lblFsLimit2 = new QLabel(groupBox_3);
        lblFsLimit2->setObjectName(QString::fromUtf8("lblFsLimit2"));
        lblFsLimit2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit2, 6, 6, 1, 1);

        label_84 = new QLabel(groupBox_3);
        label_84->setObjectName(QString::fromUtf8("label_84"));
        label_84->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_84, 0, 10, 1, 1);

        lblFsLimit3 = new QLabel(groupBox_3);
        lblFsLimit3->setObjectName(QString::fromUtf8("lblFsLimit3"));
        lblFsLimit3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit3, 8, 6, 1, 1);

        lblAxisSpeed2 = new QLabel(groupBox_3);
        lblAxisSpeed2->setObjectName(QString::fromUtf8("lblAxisSpeed2"));
        lblAxisSpeed2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed2, 6, 8, 1, 1);

        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy7);
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_26, 0, 0, 1, 1);

        lblBsLimit0 = new QLabel(groupBox_3);
        lblBsLimit0->setObjectName(QString::fromUtf8("lblBsLimit0"));
        lblBsLimit0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit0, 2, 7, 1, 1);

        lblAxisSpeed1 = new QLabel(groupBox_3);
        lblAxisSpeed1->setObjectName(QString::fromUtf8("lblAxisSpeed1"));
        lblAxisSpeed1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed1, 4, 8, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_21, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer, 1, 4, 1, 1);

        lblAxisUnits0 = new QLabel(groupBox_3);
        lblAxisUnits0->setObjectName(QString::fromUtf8("lblAxisUnits0"));
        lblAxisUnits0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits0, 2, 4, 1, 1);

        lblAxisType0 = new QLabel(groupBox_3);
        lblAxisType0->setObjectName(QString::fromUtf8("lblAxisType0"));
        lblAxisType0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType0, 2, 3, 1, 1);

        lblAxisType1 = new QLabel(groupBox_3);
        lblAxisType1->setObjectName(QString::fromUtf8("lblAxisType1"));
        lblAxisType1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType1, 4, 3, 1, 1);

        lblPosi3 = new QLabel(groupBox_3);
        lblPosi3->setObjectName(QString::fromUtf8("lblPosi3"));
        lblPosi3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi3, 8, 1, 1, 1);

        lblAxisStatus1 = new QLabel(groupBox_3);
        lblAxisStatus1->setObjectName(QString::fromUtf8("lblAxisStatus1"));
        lblAxisStatus1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus1, 4, 2, 1, 1);

        lblAxisInit2 = new QLabel(groupBox_3);
        lblAxisInit2->setObjectName(QString::fromUtf8("lblAxisInit2"));
        lblAxisInit2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit2, 6, 5, 1, 1);

        label_77 = new QLabel(groupBox_3);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        label_77->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_77, 0, 8, 1, 1);

        label_30 = new QLabel(groupBox_3);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        sizePolicy1.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy1);
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_30, 8, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer_4, 7, 4, 1, 1);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_24, 0, 2, 1, 1);

        lblAxisAccel0 = new QLabel(groupBox_3);
        lblAxisAccel0->setObjectName(QString::fromUtf8("lblAxisAccel0"));
        lblAxisAccel0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel0, 2, 9, 1, 1);

        lblAxisSpeed3 = new QLabel(groupBox_3);
        lblAxisSpeed3->setObjectName(QString::fromUtf8("lblAxisSpeed3"));
        lblAxisSpeed3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed3, 8, 8, 1, 1);

        label_171 = new QLabel(groupBox_3);
        label_171->setObjectName(QString::fromUtf8("label_171"));
        label_171->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_171, 0, 5, 1, 1);

        lblAxisDecel0 = new QLabel(groupBox_3);
        lblAxisDecel0->setObjectName(QString::fromUtf8("lblAxisDecel0"));
        lblAxisDecel0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel0, 2, 10, 1, 1);

        label_78 = new QLabel(groupBox_3);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_78, 0, 9, 1, 1);

        lblAxisAccel3 = new QLabel(groupBox_3);
        lblAxisAccel3->setObjectName(QString::fromUtf8("lblAxisAccel3"));
        lblAxisAccel3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel3, 8, 9, 1, 1);

        lblAxisAccel2 = new QLabel(groupBox_3);
        lblAxisAccel2->setObjectName(QString::fromUtf8("lblAxisAccel2"));
        lblAxisAccel2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel2, 6, 9, 1, 1);

        lblAxisDecel1 = new QLabel(groupBox_3);
        lblAxisDecel1->setObjectName(QString::fromUtf8("lblAxisDecel1"));
        lblAxisDecel1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel1, 4, 10, 1, 1);

        lblAxisUnits2 = new QLabel(groupBox_3);
        lblAxisUnits2->setObjectName(QString::fromUtf8("lblAxisUnits2"));
        lblAxisUnits2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits2, 6, 4, 1, 1);

        lblAxisInit0 = new QLabel(groupBox_3);
        lblAxisInit0->setObjectName(QString::fromUtf8("lblAxisInit0"));
        lblAxisInit0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit0, 2, 5, 1, 1);

        lblAxisStatus2 = new QLabel(groupBox_3);
        lblAxisStatus2->setObjectName(QString::fromUtf8("lblAxisStatus2"));
        lblAxisStatus2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus2, 6, 2, 1, 1);

        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_27, 0, 6, 1, 1);

        lblPosi2 = new QLabel(groupBox_3);
        lblPosi2->setObjectName(QString::fromUtf8("lblPosi2"));
        lblPosi2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi2, 6, 1, 1, 1);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 0, 7, 1, 1);

        lblAxisAccel1 = new QLabel(groupBox_3);
        lblAxisAccel1->setObjectName(QString::fromUtf8("lblAxisAccel1"));
        lblAxisAccel1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel1, 4, 9, 1, 1);

        lblAxisStatus3 = new QLabel(groupBox_3);
        lblAxisStatus3->setObjectName(QString::fromUtf8("lblAxisStatus3"));
        lblAxisStatus3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus3, 8, 2, 1, 1);

        lblAxisSpeed0 = new QLabel(groupBox_3);
        lblAxisSpeed0->setObjectName(QString::fromUtf8("lblAxisSpeed0"));
        lblAxisSpeed0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed0, 2, 8, 1, 1);

        lblBsLimit1 = new QLabel(groupBox_3);
        lblBsLimit1->setObjectName(QString::fromUtf8("lblBsLimit1"));
        lblBsLimit1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit1, 4, 7, 1, 1);

        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_28, 0, 3, 1, 1);

        label_194 = new QLabel(groupBox_3);
        label_194->setObjectName(QString::fromUtf8("label_194"));
        label_194->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_194, 0, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer_3, 5, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer_2, 3, 4, 1, 1);

        lblAxisDecel2 = new QLabel(groupBox_3);
        lblAxisDecel2->setObjectName(QString::fromUtf8("lblAxisDecel2"));
        lblAxisDecel2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel2, 6, 10, 1, 1);

        lblAxisInit3 = new QLabel(groupBox_3);
        lblAxisInit3->setObjectName(QString::fromUtf8("lblAxisInit3"));
        lblAxisInit3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit3, 8, 5, 1, 1);

        lblAxisStatus0 = new QLabel(groupBox_3);
        lblAxisStatus0->setObjectName(QString::fromUtf8("lblAxisStatus0"));
        lblAxisStatus0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus0, 2, 2, 1, 1);

        lblBsLimit2 = new QLabel(groupBox_3);
        lblBsLimit2->setObjectName(QString::fromUtf8("lblBsLimit2"));
        lblBsLimit2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit2, 6, 7, 1, 1);

        lblAxisInit1 = new QLabel(groupBox_3);
        lblAxisInit1->setObjectName(QString::fromUtf8("lblAxisInit1"));
        lblAxisInit1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit1, 4, 5, 1, 1);

        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_25, 0, 1, 1, 1);

        lblBsLimit3 = new QLabel(groupBox_3);
        lblBsLimit3->setObjectName(QString::fromUtf8("lblBsLimit3"));
        lblBsLimit3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit3, 8, 7, 1, 1);

        lblPosi1 = new QLabel(groupBox_3);
        lblPosi1->setObjectName(QString::fromUtf8("lblPosi1"));
        sizePolicy1.setHeightForWidth(lblPosi1->sizePolicy().hasHeightForWidth());
        lblPosi1->setSizePolicy(sizePolicy1);
        lblPosi1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi1, 4, 1, 1, 1);

        lblAxisUnits3 = new QLabel(groupBox_3);
        lblAxisUnits3->setObjectName(QString::fromUtf8("lblAxisUnits3"));
        lblAxisUnits3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits3, 8, 4, 1, 1);

        lblPosi0 = new QLabel(groupBox_3);
        lblPosi0->setObjectName(QString::fromUtf8("lblPosi0"));
        lblPosi0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi0, 2, 1, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy1);
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_20, 2, 0, 1, 1);

        lblFsLimit1 = new QLabel(groupBox_3);
        lblFsLimit1->setObjectName(QString::fromUtf8("lblFsLimit1"));
        lblFsLimit1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit1, 4, 6, 1, 1);

        lblFsLimit0 = new QLabel(groupBox_3);
        lblFsLimit0->setObjectName(QString::fromUtf8("lblFsLimit0"));
        lblFsLimit0->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit0, 2, 6, 1, 1);

        lblAxisDecel3 = new QLabel(groupBox_3);
        lblAxisDecel3->setObjectName(QString::fromUtf8("lblAxisDecel3"));
        lblAxisDecel3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel3, 8, 10, 1, 1);

        lblAxisUnits1 = new QLabel(groupBox_3);
        lblAxisUnits1->setObjectName(QString::fromUtf8("lblAxisUnits1"));
        lblAxisUnits1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits1, 4, 4, 1, 1);

        label_29 = new QLabel(groupBox_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        sizePolicy1.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy1);
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_29, 6, 0, 1, 1);

        lblAxisType2 = new QLabel(groupBox_3);
        lblAxisType2->setObjectName(QString::fromUtf8("lblAxisType2"));
        lblAxisType2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType2, 6, 3, 1, 1);

        lblAxisType3 = new QLabel(groupBox_3);
        lblAxisType3->setObjectName(QString::fromUtf8("lblAxisType3"));
        lblAxisType3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType3, 8, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);


        verticalLayout_63->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 2);

        LevelMonitor->setCentralWidget(centralwidget);

        retranslateUi(LevelMonitor);

        QMetaObject::connectSlotsByName(LevelMonitor);
    } // setupUi

    void retranslateUi(QMainWindow *LevelMonitor)
    {
        LevelMonitor->setWindowTitle(QCoreApplication::translate("LevelMonitor", "\350\260\203\345\271\263\347\263\273\347\273\237\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        groupBox_19->setTitle(QCoreApplication::translate("LevelMonitor", "\351\230\262\350\231\232\350\204\232\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_332->setText(QCoreApplication::translate("LevelMonitor", "\347\224\265\346\234\2722\347\224\265\346\265\201\357\274\232", nullptr));
        label_246->setText(QCoreApplication::translate("LevelMonitor", "\346\217\220\347\244\272\357\274\232", nullptr));
        lbl_Symbol3->setText(QString());
        label_335->setText(QCoreApplication::translate("LevelMonitor", "\347\224\265\346\234\2723\347\224\265\346\265\201\357\274\232", nullptr));
        label_242->setText(QCoreApplication::translate("LevelMonitor", "\346\217\220\347\244\272\357\274\232", nullptr));
        lbl_Symbol2->setText(QString());
        label_156->setText(QCoreApplication::translate("LevelMonitor", "\350\204\232\345\272\2471\350\247\246\345\234\260", nullptr));
        label_333->setText(QCoreApplication::translate("LevelMonitor", "\350\204\232\345\272\2470\345\216\213\345\212\233\357\274\232", nullptr));
        label_326->setText(QCoreApplication::translate("LevelMonitor", "\347\224\265\346\234\2721\347\224\265\346\265\201\357\274\232", nullptr));
        label_336->setText(QCoreApplication::translate("LevelMonitor", "\350\204\232\345\272\2471\345\216\213\345\212\233\357\274\232", nullptr));
        label_158->setText(QCoreApplication::translate("LevelMonitor", "\350\204\232\345\272\2472\350\247\246\345\234\260", nullptr));
        label_334->setText(QCoreApplication::translate("LevelMonitor", "\350\204\232\345\272\2472\345\216\213\345\212\233\357\274\232", nullptr));
        label_244->setText(QCoreApplication::translate("LevelMonitor", "\346\217\220\347\244\272\357\274\232", nullptr));
        lbl_Symbol1->setText(QString());
        label_159->setText(QCoreApplication::translate("LevelMonitor", "\350\204\232\345\272\2473\350\247\246\345\234\260", nullptr));
        label_157->setText(QCoreApplication::translate("LevelMonitor", "\350\204\232\345\272\2470\350\247\246\345\234\260", nullptr));
        label_338->setText(QCoreApplication::translate("LevelMonitor", "\350\204\232\345\272\2473\345\216\213\345\212\233\357\274\232", nullptr));
        label_240->setText(QCoreApplication::translate("LevelMonitor", "\346\217\220\347\244\272\357\274\232", nullptr));
        lbl_Symbol0->setText(QString());
        label_337->setText(QCoreApplication::translate("LevelMonitor", "\347\224\265\346\234\2720\347\224\265\346\265\201\357\274\232", nullptr));
        groupBox_20->setTitle(QCoreApplication::translate("LevelMonitor", "\345\200\276\350\247\222\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_341->setText(QCoreApplication::translate("LevelMonitor", "Y\346\226\271\345\220\221\345\200\276\350\247\222\357\274\232", nullptr));
        lbl_SymbolAll->setText(QString());
        label_342->setText(QCoreApplication::translate("LevelMonitor", "X\346\226\271\345\220\221\345\200\276\350\247\222\357\274\232", nullptr));
        label_331->setText(QCoreApplication::translate("LevelMonitor", "\350\260\203\345\271\263\346\240\207\345\277\227\357\274\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("LevelMonitor", "\350\260\203\345\271\263\347\224\265\346\234\272\347\212\266\346\200\201\345\217\215\351\246\210", nullptr));
        lblFsLimit2->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_84->setText(QCoreApplication::translate("LevelMonitor", "\345\207\217\351\200\237\345\272\246", nullptr));
        lblFsLimit3->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisSpeed2->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_26->setText(QCoreApplication::translate("LevelMonitor", "\347\224\265\346\234\272", nullptr));
        lblBsLimit0->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisSpeed1->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_21->setText(QCoreApplication::translate("LevelMonitor", "\345\211\215\345\217\263\347\224\265\346\234\272", nullptr));
        lblAxisUnits0->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisType0->setText(QCoreApplication::translate("LevelMonitor", "\345\276\205\346\234\272", nullptr));
        lblAxisType1->setText(QCoreApplication::translate("LevelMonitor", "\345\276\205\346\234\272", nullptr));
        lblPosi3->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisStatus1->setText(QCoreApplication::translate("LevelMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        lblAxisInit2->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_77->setText(QCoreApplication::translate("LevelMonitor", "\351\200\237\345\272\246", nullptr));
        label_30->setText(QCoreApplication::translate("LevelMonitor", "\345\220\216\345\217\263\347\224\265\346\234\272", nullptr));
        label_24->setText(QCoreApplication::translate("LevelMonitor", "\350\275\264\347\212\266\346\200\201", nullptr));
        lblAxisAccel0->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisSpeed3->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_171->setText(QCoreApplication::translate("LevelMonitor", "\345\210\235\345\247\213", nullptr));
        lblAxisDecel0->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_78->setText(QCoreApplication::translate("LevelMonitor", "\345\212\240\351\200\237\345\272\246", nullptr));
        lblAxisAccel3->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisAccel2->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisDecel1->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisUnits2->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisInit0->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisStatus2->setText(QCoreApplication::translate("LevelMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        label_27->setText(QCoreApplication::translate("LevelMonitor", "\346\255\243\351\231\220\344\275\215", nullptr));
        lblPosi2->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_18->setText(QCoreApplication::translate("LevelMonitor", "\350\264\237\351\231\220\344\275\215", nullptr));
        lblAxisAccel1->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisStatus3->setText(QCoreApplication::translate("LevelMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        lblAxisSpeed0->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblBsLimit1->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_28->setText(QCoreApplication::translate("LevelMonitor", "\350\275\264\347\261\273\345\236\213", nullptr));
        label_194->setText(QCoreApplication::translate("LevelMonitor", "\350\204\211\345\206\262\345\275\223\351\207\217", nullptr));
        lblAxisDecel2->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisInit3->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisStatus0->setText(QCoreApplication::translate("LevelMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        lblBsLimit2->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisInit1->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_25->setText(QCoreApplication::translate("LevelMonitor", "\350\275\264\345\235\220\346\240\207", nullptr));
        lblBsLimit3->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblPosi1->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisUnits3->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblPosi0->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_20->setText(QCoreApplication::translate("LevelMonitor", "\345\211\215\345\267\246\347\224\265\346\234\272", nullptr));
        lblFsLimit1->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblFsLimit0->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisDecel3->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        lblAxisUnits1->setText(QCoreApplication::translate("LevelMonitor", "0", nullptr));
        label_29->setText(QCoreApplication::translate("LevelMonitor", "\345\220\216\345\267\246\347\224\265\346\234\272", nullptr));
        lblAxisType2->setText(QCoreApplication::translate("LevelMonitor", "\345\276\205\346\234\272", nullptr));
        lblAxisType3->setText(QCoreApplication::translate("LevelMonitor", "\345\276\205\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelMonitor: public Ui_LevelMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELMONITOR_H
