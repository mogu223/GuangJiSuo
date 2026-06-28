/********************************************************************************
** Form generated from reading UI file 'coverplatemonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COVERPLATEMONITOR_H
#define UI_COVERPLATEMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoverPlateMonitor
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *lblAxisStatus7;
    QLabel *lblAxisAccel9;
    QLabel *lblFsLimit6;
    QLabel *lblAxisSpeed7;
    QLabel *lblPosi6;
    QLabel *label_40;
    QLabel *lblAxisStatus5;
    QLabel *lblFsLimit7;
    QLabel *lblBsLimit9;
    QLabel *label_84;
    QLabel *label_27;
    QLabel *lblAxisAccel6;
    QLabel *lblAxisDecel6;
    QLabel *lblAxisDecel7;
    QLabel *label_77;
    QLabel *label_106;
    QLabel *lblAxisUnits11;
    QLabel *label_78;
    QLabel *label_39;
    QLabel *lblFsLimit8;
    QLabel *lblAxisUnits8;
    QLabel *lblPosi5;
    QLabel *label_38;
    QLabel *lblAxisUnits6;
    QLabel *lblBsLimit11;
    QLabel *lblBsLimit6;
    QLabel *lblAxisType9;
    QLabel *lblAxisAccel8;
    QLabel *label_171;
    QLabel *lblPosi10;
    QLabel *lblAxisUnits9;
    QLabel *lblAxisAccel5;
    QLabel *lblAxisInit9;
    QLabel *lblAxisStatus9;
    QLabel *lblAxisInit8;
    QLabel *lblAxisSpeed10;
    QLabel *label_18;
    QLabel *lblPosi9;
    QLabel *lblBsLimit5;
    QLabel *lblAxisInit11;
    QLabel *lblAxisStatus8;
    QLabel *lblAxisSpeed6;
    QLabel *lblAxisDecel8;
    QLabel *lblAxisDecel10;
    QLabel *lblAxisInit7;
    QLabel *label_25;
    QLabel *lblAxisUnits7;
    QLabel *lblAxisDecel11;
    QLabel *label_31;
    QLabel *lblAxisSpeed8;
    QLabel *lblAxisAccel11;
    QLabel *lblAxisSpeed5;
    QLabel *lblFsLimit10;
    QLabel *lblPosi7;
    QLabel *lblAxisInit5;
    QLabel *lblAxisType5;
    QLabel *lblAxisUnits10;
    QLabel *lblAxisType6;
    QLabel *label_26;
    QLabel *lblAxisInit6;
    QLabel *lblAxisStatus10;
    QLabel *lblAxisUnits5;
    QLabel *lblPosi8;
    QLabel *lblAxisDecel5;
    QLabel *lblAxisInit10;
    QLabel *lblFsLimit11;
    QLabel *lblAxisStatus6;
    QLabel *label_24;
    QLabel *lblAxisAccel10;
    QLabel *lblAxisSpeed11;
    QLabel *lblAxisDecel9;
    QLabel *lblAxisStatus11;
    QLabel *label_109;
    QLabel *lblBsLimit10;
    QLabel *lblAxisType11;
    QLabel *lblAxisAccel7;
    QLabel *lblPosi11;
    QLabel *lblBsLimit7;
    QLabel *lblFsLimit9;
    QLabel *lblAxisSpeed9;
    QLabel *lblAxisType7;
    QLabel *label_194;
    QLabel *lblFsLimit5;
    QLabel *lblAxisType8;
    QLabel *lblBsLimit8;
    QLabel *label_110;
    QLabel *lblAxisType10;
    QLabel *label_137;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_250;
    QLabel *lbl_TakePlate;
    QHBoxLayout *horizontalLayout;
    QLabel *label_253;
    QLabel *lbl_TakeDoor;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_251;
    QLabel *lbl_FixPlate;
    QHBoxLayout *horizontalLayout_44;
    QLabel *label_322;
    QLabel *lbl_FixDoor;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CoverPlateMonitor)
    {
        if (CoverPlateMonitor->objectName().isEmpty())
            CoverPlateMonitor->setObjectName(QString::fromUtf8("CoverPlateMonitor"));
        CoverPlateMonitor->resize(1111, 810);
        CoverPlateMonitor->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(CoverPlateMonitor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
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
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(20);
        lblAxisStatus7 = new QLabel(groupBox);
        lblAxisStatus7->setObjectName(QString::fromUtf8("lblAxisStatus7"));
        lblAxisStatus7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus7, 4, 2, 1, 1);

        lblAxisAccel9 = new QLabel(groupBox);
        lblAxisAccel9->setObjectName(QString::fromUtf8("lblAxisAccel9"));
        lblAxisAccel9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel9, 6, 9, 1, 1);

        lblFsLimit6 = new QLabel(groupBox);
        lblFsLimit6->setObjectName(QString::fromUtf8("lblFsLimit6"));
        lblFsLimit6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit6, 3, 6, 1, 1);

        lblAxisSpeed7 = new QLabel(groupBox);
        lblAxisSpeed7->setObjectName(QString::fromUtf8("lblAxisSpeed7"));
        lblAxisSpeed7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed7, 4, 8, 1, 1);

        lblPosi6 = new QLabel(groupBox);
        lblPosi6->setObjectName(QString::fromUtf8("lblPosi6"));
        lblPosi6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi6, 3, 1, 1, 1);

        label_40 = new QLabel(groupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_40, 4, 0, 1, 1);

        lblAxisStatus5 = new QLabel(groupBox);
        lblAxisStatus5->setObjectName(QString::fromUtf8("lblAxisStatus5"));
        lblAxisStatus5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus5, 2, 2, 1, 1);

        lblFsLimit7 = new QLabel(groupBox);
        lblFsLimit7->setObjectName(QString::fromUtf8("lblFsLimit7"));
        lblFsLimit7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit7, 4, 6, 1, 1);

        lblBsLimit9 = new QLabel(groupBox);
        lblBsLimit9->setObjectName(QString::fromUtf8("lblBsLimit9"));
        lblBsLimit9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit9, 6, 7, 1, 1);

        label_84 = new QLabel(groupBox);
        label_84->setObjectName(QString::fromUtf8("label_84"));
        label_84->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_84, 0, 10, 1, 1);

        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_27, 0, 6, 1, 1);

        lblAxisAccel6 = new QLabel(groupBox);
        lblAxisAccel6->setObjectName(QString::fromUtf8("lblAxisAccel6"));
        lblAxisAccel6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel6, 3, 9, 1, 1);

        lblAxisDecel6 = new QLabel(groupBox);
        lblAxisDecel6->setObjectName(QString::fromUtf8("lblAxisDecel6"));
        lblAxisDecel6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel6, 3, 10, 1, 1);

        lblAxisDecel7 = new QLabel(groupBox);
        lblAxisDecel7->setObjectName(QString::fromUtf8("lblAxisDecel7"));
        lblAxisDecel7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel7, 4, 10, 1, 1);

        label_77 = new QLabel(groupBox);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        label_77->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_77, 0, 8, 1, 1);

        label_106 = new QLabel(groupBox);
        label_106->setObjectName(QString::fromUtf8("label_106"));
        label_106->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_106, 5, 0, 1, 1);

        lblAxisUnits11 = new QLabel(groupBox);
        lblAxisUnits11->setObjectName(QString::fromUtf8("lblAxisUnits11"));
        lblAxisUnits11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits11, 8, 4, 1, 1);

        label_78 = new QLabel(groupBox);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_78, 0, 9, 1, 1);

        label_39 = new QLabel(groupBox);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_39, 3, 0, 1, 1);

        lblFsLimit8 = new QLabel(groupBox);
        lblFsLimit8->setObjectName(QString::fromUtf8("lblFsLimit8"));
        lblFsLimit8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit8, 5, 6, 1, 1);

        lblAxisUnits8 = new QLabel(groupBox);
        lblAxisUnits8->setObjectName(QString::fromUtf8("lblAxisUnits8"));
        lblAxisUnits8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits8, 5, 4, 1, 1);

        lblPosi5 = new QLabel(groupBox);
        lblPosi5->setObjectName(QString::fromUtf8("lblPosi5"));
        lblPosi5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi5, 2, 1, 1, 1);

        label_38 = new QLabel(groupBox);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_38, 2, 0, 1, 1);

        lblAxisUnits6 = new QLabel(groupBox);
        lblAxisUnits6->setObjectName(QString::fromUtf8("lblAxisUnits6"));
        lblAxisUnits6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits6, 3, 4, 1, 1);

        lblBsLimit11 = new QLabel(groupBox);
        lblBsLimit11->setObjectName(QString::fromUtf8("lblBsLimit11"));
        lblBsLimit11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit11, 8, 7, 1, 1);

        lblBsLimit6 = new QLabel(groupBox);
        lblBsLimit6->setObjectName(QString::fromUtf8("lblBsLimit6"));
        lblBsLimit6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit6, 3, 7, 1, 1);

        lblAxisType9 = new QLabel(groupBox);
        lblAxisType9->setObjectName(QString::fromUtf8("lblAxisType9"));
        lblAxisType9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType9, 6, 3, 1, 1);

        lblAxisAccel8 = new QLabel(groupBox);
        lblAxisAccel8->setObjectName(QString::fromUtf8("lblAxisAccel8"));
        lblAxisAccel8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel8, 5, 9, 1, 1);

        label_171 = new QLabel(groupBox);
        label_171->setObjectName(QString::fromUtf8("label_171"));
        label_171->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_171, 0, 5, 1, 1);

        lblPosi10 = new QLabel(groupBox);
        lblPosi10->setObjectName(QString::fromUtf8("lblPosi10"));
        lblPosi10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi10, 7, 1, 1, 1);

        lblAxisUnits9 = new QLabel(groupBox);
        lblAxisUnits9->setObjectName(QString::fromUtf8("lblAxisUnits9"));
        lblAxisUnits9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits9, 6, 4, 1, 1);

        lblAxisAccel5 = new QLabel(groupBox);
        lblAxisAccel5->setObjectName(QString::fromUtf8("lblAxisAccel5"));
        lblAxisAccel5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel5, 2, 9, 1, 1);

        lblAxisInit9 = new QLabel(groupBox);
        lblAxisInit9->setObjectName(QString::fromUtf8("lblAxisInit9"));
        lblAxisInit9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit9, 6, 5, 1, 1);

        lblAxisStatus9 = new QLabel(groupBox);
        lblAxisStatus9->setObjectName(QString::fromUtf8("lblAxisStatus9"));
        lblAxisStatus9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus9, 6, 2, 1, 1);

        lblAxisInit8 = new QLabel(groupBox);
        lblAxisInit8->setObjectName(QString::fromUtf8("lblAxisInit8"));
        lblAxisInit8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit8, 5, 5, 1, 1);

        lblAxisSpeed10 = new QLabel(groupBox);
        lblAxisSpeed10->setObjectName(QString::fromUtf8("lblAxisSpeed10"));
        lblAxisSpeed10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed10, 7, 8, 1, 1);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 0, 7, 1, 1);

        lblPosi9 = new QLabel(groupBox);
        lblPosi9->setObjectName(QString::fromUtf8("lblPosi9"));
        lblPosi9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi9, 6, 1, 1, 1);

        lblBsLimit5 = new QLabel(groupBox);
        lblBsLimit5->setObjectName(QString::fromUtf8("lblBsLimit5"));
        lblBsLimit5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit5, 2, 7, 1, 1);

        lblAxisInit11 = new QLabel(groupBox);
        lblAxisInit11->setObjectName(QString::fromUtf8("lblAxisInit11"));
        lblAxisInit11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit11, 8, 5, 1, 1);

        lblAxisStatus8 = new QLabel(groupBox);
        lblAxisStatus8->setObjectName(QString::fromUtf8("lblAxisStatus8"));
        lblAxisStatus8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus8, 5, 2, 1, 1);

        lblAxisSpeed6 = new QLabel(groupBox);
        lblAxisSpeed6->setObjectName(QString::fromUtf8("lblAxisSpeed6"));
        lblAxisSpeed6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed6, 3, 8, 1, 1);

        lblAxisDecel8 = new QLabel(groupBox);
        lblAxisDecel8->setObjectName(QString::fromUtf8("lblAxisDecel8"));
        lblAxisDecel8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel8, 5, 10, 1, 1);

        lblAxisDecel10 = new QLabel(groupBox);
        lblAxisDecel10->setObjectName(QString::fromUtf8("lblAxisDecel10"));
        lblAxisDecel10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel10, 7, 10, 1, 1);

        lblAxisInit7 = new QLabel(groupBox);
        lblAxisInit7->setObjectName(QString::fromUtf8("lblAxisInit7"));
        lblAxisInit7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit7, 4, 5, 1, 1);

        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_25, 0, 1, 1, 1);

        lblAxisUnits7 = new QLabel(groupBox);
        lblAxisUnits7->setObjectName(QString::fromUtf8("lblAxisUnits7"));
        lblAxisUnits7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits7, 4, 4, 1, 1);

        lblAxisDecel11 = new QLabel(groupBox);
        lblAxisDecel11->setObjectName(QString::fromUtf8("lblAxisDecel11"));
        lblAxisDecel11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel11, 8, 10, 1, 1);

        label_31 = new QLabel(groupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_31, 0, 3, 1, 1);

        lblAxisSpeed8 = new QLabel(groupBox);
        lblAxisSpeed8->setObjectName(QString::fromUtf8("lblAxisSpeed8"));
        lblAxisSpeed8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed8, 5, 8, 1, 1);

        lblAxisAccel11 = new QLabel(groupBox);
        lblAxisAccel11->setObjectName(QString::fromUtf8("lblAxisAccel11"));
        lblAxisAccel11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel11, 8, 9, 1, 1);

        lblAxisSpeed5 = new QLabel(groupBox);
        lblAxisSpeed5->setObjectName(QString::fromUtf8("lblAxisSpeed5"));
        lblAxisSpeed5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed5, 2, 8, 1, 1);

        lblFsLimit10 = new QLabel(groupBox);
        lblFsLimit10->setObjectName(QString::fromUtf8("lblFsLimit10"));
        lblFsLimit10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit10, 7, 6, 1, 1);

        lblPosi7 = new QLabel(groupBox);
        lblPosi7->setObjectName(QString::fromUtf8("lblPosi7"));
        lblPosi7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi7, 4, 1, 1, 1);

        lblAxisInit5 = new QLabel(groupBox);
        lblAxisInit5->setObjectName(QString::fromUtf8("lblAxisInit5"));
        lblAxisInit5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit5, 2, 5, 1, 1);

        lblAxisType5 = new QLabel(groupBox);
        lblAxisType5->setObjectName(QString::fromUtf8("lblAxisType5"));
        lblAxisType5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType5, 2, 3, 1, 1);

        lblAxisUnits10 = new QLabel(groupBox);
        lblAxisUnits10->setObjectName(QString::fromUtf8("lblAxisUnits10"));
        lblAxisUnits10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits10, 7, 4, 1, 1);

        lblAxisType6 = new QLabel(groupBox);
        lblAxisType6->setObjectName(QString::fromUtf8("lblAxisType6"));
        lblAxisType6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType6, 3, 3, 1, 1);

        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_26, 0, 0, 1, 1);

        lblAxisInit6 = new QLabel(groupBox);
        lblAxisInit6->setObjectName(QString::fromUtf8("lblAxisInit6"));
        lblAxisInit6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit6, 3, 5, 1, 1);

        lblAxisStatus10 = new QLabel(groupBox);
        lblAxisStatus10->setObjectName(QString::fromUtf8("lblAxisStatus10"));
        lblAxisStatus10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus10, 7, 2, 1, 1);

        lblAxisUnits5 = new QLabel(groupBox);
        lblAxisUnits5->setObjectName(QString::fromUtf8("lblAxisUnits5"));
        lblAxisUnits5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisUnits5, 2, 4, 1, 1);

        lblPosi8 = new QLabel(groupBox);
        lblPosi8->setObjectName(QString::fromUtf8("lblPosi8"));
        lblPosi8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi8, 5, 1, 1, 1);

        lblAxisDecel5 = new QLabel(groupBox);
        lblAxisDecel5->setObjectName(QString::fromUtf8("lblAxisDecel5"));
        lblAxisDecel5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel5, 2, 10, 1, 1);

        lblAxisInit10 = new QLabel(groupBox);
        lblAxisInit10->setObjectName(QString::fromUtf8("lblAxisInit10"));
        lblAxisInit10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisInit10, 7, 5, 1, 1);

        lblFsLimit11 = new QLabel(groupBox);
        lblFsLimit11->setObjectName(QString::fromUtf8("lblFsLimit11"));
        lblFsLimit11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit11, 8, 6, 1, 1);

        lblAxisStatus6 = new QLabel(groupBox);
        lblAxisStatus6->setObjectName(QString::fromUtf8("lblAxisStatus6"));
        lblAxisStatus6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus6, 3, 2, 1, 1);

        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_24, 0, 2, 1, 1);

        lblAxisAccel10 = new QLabel(groupBox);
        lblAxisAccel10->setObjectName(QString::fromUtf8("lblAxisAccel10"));
        lblAxisAccel10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel10, 7, 9, 1, 1);

        lblAxisSpeed11 = new QLabel(groupBox);
        lblAxisSpeed11->setObjectName(QString::fromUtf8("lblAxisSpeed11"));
        lblAxisSpeed11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed11, 8, 8, 1, 1);

        lblAxisDecel9 = new QLabel(groupBox);
        lblAxisDecel9->setObjectName(QString::fromUtf8("lblAxisDecel9"));
        lblAxisDecel9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisDecel9, 6, 10, 1, 1);

        lblAxisStatus11 = new QLabel(groupBox);
        lblAxisStatus11->setObjectName(QString::fromUtf8("lblAxisStatus11"));
        lblAxisStatus11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisStatus11, 8, 2, 1, 1);

        label_109 = new QLabel(groupBox);
        label_109->setObjectName(QString::fromUtf8("label_109"));
        label_109->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_109, 6, 0, 1, 1);

        lblBsLimit10 = new QLabel(groupBox);
        lblBsLimit10->setObjectName(QString::fromUtf8("lblBsLimit10"));
        lblBsLimit10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit10, 7, 7, 1, 1);

        lblAxisType11 = new QLabel(groupBox);
        lblAxisType11->setObjectName(QString::fromUtf8("lblAxisType11"));
        lblAxisType11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType11, 8, 3, 1, 1);

        lblAxisAccel7 = new QLabel(groupBox);
        lblAxisAccel7->setObjectName(QString::fromUtf8("lblAxisAccel7"));
        lblAxisAccel7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisAccel7, 4, 9, 1, 1);

        lblPosi11 = new QLabel(groupBox);
        lblPosi11->setObjectName(QString::fromUtf8("lblPosi11"));
        lblPosi11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblPosi11, 8, 1, 1, 1);

        lblBsLimit7 = new QLabel(groupBox);
        lblBsLimit7->setObjectName(QString::fromUtf8("lblBsLimit7"));
        lblBsLimit7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit7, 4, 7, 1, 1);

        lblFsLimit9 = new QLabel(groupBox);
        lblFsLimit9->setObjectName(QString::fromUtf8("lblFsLimit9"));
        lblFsLimit9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit9, 6, 6, 1, 1);

        lblAxisSpeed9 = new QLabel(groupBox);
        lblAxisSpeed9->setObjectName(QString::fromUtf8("lblAxisSpeed9"));
        lblAxisSpeed9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisSpeed9, 6, 8, 1, 1);

        lblAxisType7 = new QLabel(groupBox);
        lblAxisType7->setObjectName(QString::fromUtf8("lblAxisType7"));
        lblAxisType7->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType7, 4, 3, 1, 1);

        label_194 = new QLabel(groupBox);
        label_194->setObjectName(QString::fromUtf8("label_194"));
        label_194->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_194, 0, 4, 1, 1);

        lblFsLimit5 = new QLabel(groupBox);
        lblFsLimit5->setObjectName(QString::fromUtf8("lblFsLimit5"));
        lblFsLimit5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblFsLimit5, 2, 6, 1, 1);

        lblAxisType8 = new QLabel(groupBox);
        lblAxisType8->setObjectName(QString::fromUtf8("lblAxisType8"));
        lblAxisType8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType8, 5, 3, 1, 1);

        lblBsLimit8 = new QLabel(groupBox);
        lblBsLimit8->setObjectName(QString::fromUtf8("lblBsLimit8"));
        lblBsLimit8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblBsLimit8, 5, 7, 1, 1);

        label_110 = new QLabel(groupBox);
        label_110->setObjectName(QString::fromUtf8("label_110"));
        label_110->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_110, 7, 0, 1, 1);

        lblAxisType10 = new QLabel(groupBox);
        lblAxisType10->setObjectName(QString::fromUtf8("lblAxisType10"));
        lblAxisType10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lblAxisType10, 7, 3, 1, 1);

        label_137 = new QLabel(groupBox);
        label_137->setObjectName(QString::fromUtf8("label_137"));
        label_137->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_137, 8, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #000000; /* 2px\345\256\275\347\232\204\351\273\221\350\211\262\350\276\271\346\241\206\357\274\214\345\217\257\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\347\262\227\347\273\206\345\222\214\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \345\217\257\351\200\211\357\274\232\346\267\273\345\212\240\350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"    margin-top: 10px; /* \344\270\272\346\240\207\351\242\230\347\225\231\345\207\272\347\251\272\351\227\264 */\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* \346\240\207\351\242\230\344\275\215\347\275\256 */\n"
"    left: 10px; /* \346\240\207\351\242\230\345\267\246\344\276\247\351\227\264\350\267\235 */\n"
"    padding: 0 3px 0 3px; /* \346\240\207\351\242\230\346\226\207\345\255\227\345\221\250\345\233\264\347\225\231\347\231\275 */\n"
"}\n"
""));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_250 = new QLabel(groupBox_2);
        label_250->setObjectName(QString::fromUtf8("label_250"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_250->sizePolicy().hasHeightForWidth());
        label_250->setSizePolicy(sizePolicy);
        label_250->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(label_250, 0, Qt::AlignHCenter);

        lbl_TakePlate = new QLabel(groupBox_2);
        lbl_TakePlate->setObjectName(QString::fromUtf8("lbl_TakePlate"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_TakePlate->sizePolicy().hasHeightForWidth());
        lbl_TakePlate->setSizePolicy(sizePolicy1);
        lbl_TakePlate->setMinimumSize(QSize(15, 15));
        lbl_TakePlate->setMaximumSize(QSize(15, 15));
        lbl_TakePlate->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout_3->addWidget(lbl_TakePlate);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_253 = new QLabel(groupBox_2);
        label_253->setObjectName(QString::fromUtf8("label_253"));
        sizePolicy.setHeightForWidth(label_253->sizePolicy().hasHeightForWidth());
        label_253->setSizePolicy(sizePolicy);
        label_253->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(label_253);

        lbl_TakeDoor = new QLabel(groupBox_2);
        lbl_TakeDoor->setObjectName(QString::fromUtf8("lbl_TakeDoor"));
        sizePolicy1.setHeightForWidth(lbl_TakeDoor->sizePolicy().hasHeightForWidth());
        lbl_TakeDoor->setSizePolicy(sizePolicy1);
        lbl_TakeDoor->setMinimumSize(QSize(15, 15));
        lbl_TakeDoor->setMaximumSize(QSize(15, 15));
        lbl_TakeDoor->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout->addWidget(lbl_TakeDoor);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_251 = new QLabel(groupBox_2);
        label_251->setObjectName(QString::fromUtf8("label_251"));
        sizePolicy.setHeightForWidth(label_251->sizePolicy().hasHeightForWidth());
        label_251->setSizePolicy(sizePolicy);
        label_251->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_6->addWidget(label_251);

        lbl_FixPlate = new QLabel(groupBox_2);
        lbl_FixPlate->setObjectName(QString::fromUtf8("lbl_FixPlate"));
        sizePolicy1.setHeightForWidth(lbl_FixPlate->sizePolicy().hasHeightForWidth());
        lbl_FixPlate->setSizePolicy(sizePolicy1);
        lbl_FixPlate->setMinimumSize(QSize(15, 15));
        lbl_FixPlate->setMaximumSize(QSize(15, 15));
        lbl_FixPlate->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout_6->addWidget(lbl_FixPlate);


        gridLayout_2->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        label_322 = new QLabel(groupBox_2);
        label_322->setObjectName(QString::fromUtf8("label_322"));
        sizePolicy.setHeightForWidth(label_322->sizePolicy().hasHeightForWidth());
        label_322->setSizePolicy(sizePolicy);
        label_322->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_44->addWidget(label_322, 0, Qt::AlignHCenter);

        lbl_FixDoor = new QLabel(groupBox_2);
        lbl_FixDoor->setObjectName(QString::fromUtf8("lbl_FixDoor"));
        sizePolicy1.setHeightForWidth(lbl_FixDoor->sizePolicy().hasHeightForWidth());
        lbl_FixDoor->setSizePolicy(sizePolicy1);
        lbl_FixDoor->setMinimumSize(QSize(15, 15));
        lbl_FixDoor->setMaximumSize(QSize(15, 15));
        lbl_FixDoor->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        horizontalLayout_44->addWidget(lbl_FixDoor);


        gridLayout_2->addLayout(horizontalLayout_44, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        CoverPlateMonitor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CoverPlateMonitor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1111, 25));
        CoverPlateMonitor->setMenuBar(menubar);
        statusbar = new QStatusBar(CoverPlateMonitor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CoverPlateMonitor->setStatusBar(statusbar);

        retranslateUi(CoverPlateMonitor);

        QMetaObject::connectSlotsByName(CoverPlateMonitor);
    } // setupUi

    void retranslateUi(QMainWindow *CoverPlateMonitor)
    {
        CoverPlateMonitor->setWindowTitle(QCoreApplication::translate("CoverPlateMonitor", "\347\233\226\346\235\277\347\263\273\347\273\237\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CoverPlateMonitor", "\347\233\226\346\235\277\347\224\265\346\234\272\347\212\266\346\200\201\345\217\215\351\246\210", nullptr));
        lblAxisStatus7->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        lblAxisAccel9->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblFsLimit6->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisSpeed7->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblPosi6->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_40->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\250\252\347\247\273\347\224\265\346\234\2721", nullptr));
        lblAxisStatus5->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        lblFsLimit7->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblBsLimit9->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_84->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\207\217\351\200\237\345\272\246", nullptr));
        label_27->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\255\243\351\231\220\344\275\215", nullptr));
        lblAxisAccel6->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisDecel6->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisDecel7->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_77->setText(QCoreApplication::translate("CoverPlateMonitor", "\351\200\237\345\272\246", nullptr));
        label_106->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\250\252\347\247\273\347\224\265\346\234\2722", nullptr));
        lblAxisUnits11->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_78->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\212\240\351\200\237\345\272\246", nullptr));
        label_39->setText(QCoreApplication::translate("CoverPlateMonitor", "\347\272\265\347\247\273\347\224\265\346\234\2722", nullptr));
        lblFsLimit8->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisUnits8->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblPosi5->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_38->setText(QCoreApplication::translate("CoverPlateMonitor", "\347\272\265\347\247\273\347\224\265\346\234\2721", nullptr));
        lblAxisUnits6->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblBsLimit11->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblBsLimit6->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisType9->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\276\205\346\234\272", nullptr));
        lblAxisAccel8->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_171->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\210\235\345\247\213", nullptr));
        lblPosi10->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisUnits9->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisAccel5->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisInit9->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisStatus9->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        lblAxisInit8->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisSpeed10->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_18->setText(QCoreApplication::translate("CoverPlateMonitor", "\350\264\237\351\231\220\344\275\215", nullptr));
        lblPosi9->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblBsLimit5->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisInit11->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisStatus8->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        lblAxisSpeed6->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisDecel8->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisDecel10->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisInit7->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_25->setText(QCoreApplication::translate("CoverPlateMonitor", "\350\275\264\345\235\220\346\240\207", nullptr));
        lblAxisUnits7->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisDecel11->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_31->setText(QCoreApplication::translate("CoverPlateMonitor", "\350\275\264\347\261\273\345\236\213", nullptr));
        lblAxisSpeed8->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisAccel11->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisSpeed5->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblFsLimit10->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblPosi7->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisInit5->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisType5->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\276\205\346\234\272", nullptr));
        lblAxisUnits10->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisType6->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\276\205\346\234\272", nullptr));
        label_26->setText(QCoreApplication::translate("CoverPlateMonitor", "\347\224\265\346\234\272", nullptr));
        lblAxisInit6->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisStatus10->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        lblAxisUnits5->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblPosi8->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisDecel5->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisInit10->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblFsLimit11->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisStatus6->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        label_24->setText(QCoreApplication::translate("CoverPlateMonitor", "\350\275\264\347\212\266\346\200\201", nullptr));
        lblAxisAccel10->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisSpeed11->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisDecel9->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisStatus11->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\255\243\345\270\270\347\212\266\346\200\201", nullptr));
        label_109->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\211\213\346\214\207\347\224\265\346\234\2721", nullptr));
        lblBsLimit10->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisType11->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\276\205\346\234\272", nullptr));
        lblAxisAccel7->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblPosi11->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblBsLimit7->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblFsLimit9->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisSpeed9->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisType7->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\276\205\346\234\272", nullptr));
        label_194->setText(QCoreApplication::translate("CoverPlateMonitor", "\350\204\211\345\206\262\345\275\223\351\207\217", nullptr));
        lblFsLimit5->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        lblAxisType8->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\276\205\346\234\272", nullptr));
        lblBsLimit8->setText(QCoreApplication::translate("CoverPlateMonitor", "0", nullptr));
        label_110->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\211\213\346\214\207\347\224\265\346\234\2722", nullptr));
        lblAxisType10->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\276\205\346\234\272", nullptr));
        label_137->setText(QCoreApplication::translate("CoverPlateMonitor", "\346\211\230\344\270\276\347\224\265\346\234\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CoverPlateMonitor", "\346\265\201\347\250\213\344\277\241\346\201\257\345\217\215\351\246\210", nullptr));
        label_250->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\217\226\347\233\226\346\235\277\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_TakePlate->setText(QString());
        label_253->setText(QCoreApplication::translate("CoverPlateMonitor", "\345\217\226\345\260\201\351\227\250\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_TakeDoor->setText(QString());
        label_251->setText(QCoreApplication::translate("CoverPlateMonitor", "\347\233\226\347\233\226\346\235\277\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_FixPlate->setText(QString());
        label_322->setText(QCoreApplication::translate("CoverPlateMonitor", "\347\233\226\345\260\201\351\227\250\345\256\214\346\210\220\357\274\232", nullptr));
        lbl_FixDoor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CoverPlateMonitor: public Ui_CoverPlateMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COVERPLATEMONITOR_H
