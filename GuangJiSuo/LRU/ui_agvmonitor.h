/********************************************************************************
** Form generated from reading UI file 'agvmonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGVMONITOR_H
#define UI_AGVMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AGVMonitor
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_35;
    QGridLayout *gridLayout_3;
    QLabel *label_141;
    QLabel *label_138;
    QLineEdit *lineEdit_current_station;
    QLineEdit *remainingmAh;
    QLineEdit *lineEdit_brake;
    QLabel *label_165;
    QLineEdit *lineEdit_block_reason;
    QLabel *label_145;
    QLabel *label_143;
    QLabel *label_166;
    QLabel *label_147;
    QLineEdit *lineEdit_reloc_status;
    QLabel *label_151;
    QLineEdit *lineEdit_emergency;
    QLabel *label_149;
    QLabel *label_150;
    QLineEdit *lineEdit_loadmap_status;
    QLabel *label_148;
    QLabel *label_137;
    QLabel *label_139;
    QLabel *label_144;
    QLineEdit *lineEdit_task_type;
    QLabel *label_142;
    QLineEdit *lineEdit_taskStatus;
    QLineEdit *lineEdit_batt_level;
    QLineEdit *lineEdit_target_dist;
    QLabel *label_140;
    QLineEdit *lineEdit_driver_emc;
    QLabel *label_136;
    QLineEdit *lineEdit_electric;
    QLineEdit *lineEdit_agv_blocked;
    QLineEdit *lineEdit_soft_emc;
    QLabel *lbl_handle;
    QLineEdit *packTotalCurrent;
    QLineEdit *packTotalVoltage;
    QLabel *label_146;
    QGroupBox *groupBox_31;
    QGridLayout *gridLayout_26;
    QGridLayout *gridLayout_23;
    QLabel *label_342;
    QLineEdit *Distance1;
    QLineEdit *Distance2;
    QLabel *label_343;
    QLineEdit *Distance0;
    QLineEdit *Distance3;
    QLabel *label_341;
    QLabel *label_344;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_Info;

    void setupUi(QMainWindow *AGVMonitor)
    {
        if (AGVMonitor->objectName().isEmpty())
            AGVMonitor->setObjectName(QString::fromUtf8("AGVMonitor"));
        AGVMonitor->resize(922, 615);
        AGVMonitor->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(AGVMonitor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_35 = new QGroupBox(centralwidget);
        groupBox_35->setObjectName(QString::fromUtf8("groupBox_35"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_35->sizePolicy().hasHeightForWidth());
        groupBox_35->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        groupBox_35->setFont(font);
        groupBox_35->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        gridLayout_3 = new QGridLayout(groupBox_35);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_141 = new QLabel(groupBox_35);
        label_141->setObjectName(QString::fromUtf8("label_141"));

        gridLayout_3->addWidget(label_141, 2, 2, 1, 1);

        label_138 = new QLabel(groupBox_35);
        label_138->setObjectName(QString::fromUtf8("label_138"));

        gridLayout_3->addWidget(label_138, 0, 2, 1, 1);

        lineEdit_current_station = new QLineEdit(groupBox_35);
        lineEdit_current_station->setObjectName(QString::fromUtf8("lineEdit_current_station"));

        gridLayout_3->addWidget(lineEdit_current_station, 3, 1, 1, 1);

        remainingmAh = new QLineEdit(groupBox_35);
        remainingmAh->setObjectName(QString::fromUtf8("remainingmAh"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(remainingmAh->sizePolicy().hasHeightForWidth());
        remainingmAh->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(remainingmAh, 1, 1, 1, 1);

        lineEdit_brake = new QLineEdit(groupBox_35);
        lineEdit_brake->setObjectName(QString::fromUtf8("lineEdit_brake"));

        gridLayout_3->addWidget(lineEdit_brake, 3, 3, 1, 1);

        label_165 = new QLabel(groupBox_35);
        label_165->setObjectName(QString::fromUtf8("label_165"));

        gridLayout_3->addWidget(label_165, 5, 0, 1, 1);

        lineEdit_block_reason = new QLineEdit(groupBox_35);
        lineEdit_block_reason->setObjectName(QString::fromUtf8("lineEdit_block_reason"));

        gridLayout_3->addWidget(lineEdit_block_reason, 0, 5, 1, 1);

        label_145 = new QLabel(groupBox_35);
        label_145->setObjectName(QString::fromUtf8("label_145"));

        gridLayout_3->addWidget(label_145, 3, 2, 1, 1);

        label_143 = new QLabel(groupBox_35);
        label_143->setObjectName(QString::fromUtf8("label_143"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_143->sizePolicy().hasHeightForWidth());
        label_143->setSizePolicy(sizePolicy2);
        label_143->setMinimumSize(QSize(80, 0));
        label_143->setScaledContents(false);

        gridLayout_3->addWidget(label_143, 1, 2, 1, 1);

        label_166 = new QLabel(groupBox_35);
        label_166->setObjectName(QString::fromUtf8("label_166"));

        gridLayout_3->addWidget(label_166, 5, 2, 1, 1);

        label_147 = new QLabel(groupBox_35);
        label_147->setObjectName(QString::fromUtf8("label_147"));

        gridLayout_3->addWidget(label_147, 3, 4, 1, 1);

        lineEdit_reloc_status = new QLineEdit(groupBox_35);
        lineEdit_reloc_status->setObjectName(QString::fromUtf8("lineEdit_reloc_status"));

        gridLayout_3->addWidget(lineEdit_reloc_status, 5, 3, 1, 1);

        label_151 = new QLabel(groupBox_35);
        label_151->setObjectName(QString::fromUtf8("label_151"));

        gridLayout_3->addWidget(label_151, 4, 2, 1, 1);

        lineEdit_emergency = new QLineEdit(groupBox_35);
        lineEdit_emergency->setObjectName(QString::fromUtf8("lineEdit_emergency"));

        gridLayout_3->addWidget(lineEdit_emergency, 2, 3, 1, 1);

        label_149 = new QLabel(groupBox_35);
        label_149->setObjectName(QString::fromUtf8("label_149"));

        gridLayout_3->addWidget(label_149, 4, 0, 1, 1);

        label_150 = new QLabel(groupBox_35);
        label_150->setObjectName(QString::fromUtf8("label_150"));

        gridLayout_3->addWidget(label_150, 5, 4, 1, 1);

        lineEdit_loadmap_status = new QLineEdit(groupBox_35);
        lineEdit_loadmap_status->setObjectName(QString::fromUtf8("lineEdit_loadmap_status"));

        gridLayout_3->addWidget(lineEdit_loadmap_status, 5, 1, 1, 1);

        label_148 = new QLabel(groupBox_35);
        label_148->setObjectName(QString::fromUtf8("label_148"));

        gridLayout_3->addWidget(label_148, 4, 4, 1, 1);

        label_137 = new QLabel(groupBox_35);
        label_137->setObjectName(QString::fromUtf8("label_137"));
        sizePolicy2.setHeightForWidth(label_137->sizePolicy().hasHeightForWidth());
        label_137->setSizePolicy(sizePolicy2);
        label_137->setMinimumSize(QSize(80, 0));
        label_137->setScaledContents(false);

        gridLayout_3->addWidget(label_137, 1, 0, 1, 1);

        label_139 = new QLabel(groupBox_35);
        label_139->setObjectName(QString::fromUtf8("label_139"));

        gridLayout_3->addWidget(label_139, 0, 4, 1, 1);

        label_144 = new QLabel(groupBox_35);
        label_144->setObjectName(QString::fromUtf8("label_144"));

        gridLayout_3->addWidget(label_144, 3, 0, 1, 1);

        lineEdit_task_type = new QLineEdit(groupBox_35);
        lineEdit_task_type->setObjectName(QString::fromUtf8("lineEdit_task_type"));

        gridLayout_3->addWidget(lineEdit_task_type, 3, 5, 1, 1);

        label_142 = new QLabel(groupBox_35);
        label_142->setObjectName(QString::fromUtf8("label_142"));

        gridLayout_3->addWidget(label_142, 2, 4, 1, 1);

        lineEdit_taskStatus = new QLineEdit(groupBox_35);
        lineEdit_taskStatus->setObjectName(QString::fromUtf8("lineEdit_taskStatus"));

        gridLayout_3->addWidget(lineEdit_taskStatus, 2, 1, 1, 1);

        lineEdit_batt_level = new QLineEdit(groupBox_35);
        lineEdit_batt_level->setObjectName(QString::fromUtf8("lineEdit_batt_level"));
        sizePolicy1.setHeightForWidth(lineEdit_batt_level->sizePolicy().hasHeightForWidth());
        lineEdit_batt_level->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lineEdit_batt_level, 0, 1, 1, 1);

        lineEdit_target_dist = new QLineEdit(groupBox_35);
        lineEdit_target_dist->setObjectName(QString::fromUtf8("lineEdit_target_dist"));

        gridLayout_3->addWidget(lineEdit_target_dist, 4, 5, 1, 1);

        label_140 = new QLabel(groupBox_35);
        label_140->setObjectName(QString::fromUtf8("label_140"));

        gridLayout_3->addWidget(label_140, 2, 0, 1, 1);

        lineEdit_driver_emc = new QLineEdit(groupBox_35);
        lineEdit_driver_emc->setObjectName(QString::fromUtf8("lineEdit_driver_emc"));

        gridLayout_3->addWidget(lineEdit_driver_emc, 4, 1, 1, 1);

        label_136 = new QLabel(groupBox_35);
        label_136->setObjectName(QString::fromUtf8("label_136"));
        sizePolicy2.setHeightForWidth(label_136->sizePolicy().hasHeightForWidth());
        label_136->setSizePolicy(sizePolicy2);
        label_136->setMinimumSize(QSize(80, 0));
        label_136->setScaledContents(false);

        gridLayout_3->addWidget(label_136, 0, 0, 1, 1);

        lineEdit_electric = new QLineEdit(groupBox_35);
        lineEdit_electric->setObjectName(QString::fromUtf8("lineEdit_electric"));

        gridLayout_3->addWidget(lineEdit_electric, 4, 3, 1, 1);

        lineEdit_agv_blocked = new QLineEdit(groupBox_35);
        lineEdit_agv_blocked->setObjectName(QString::fromUtf8("lineEdit_agv_blocked"));

        gridLayout_3->addWidget(lineEdit_agv_blocked, 0, 3, 1, 1);

        lineEdit_soft_emc = new QLineEdit(groupBox_35);
        lineEdit_soft_emc->setObjectName(QString::fromUtf8("lineEdit_soft_emc"));

        gridLayout_3->addWidget(lineEdit_soft_emc, 2, 5, 1, 1);

        lbl_handle = new QLabel(groupBox_35);
        lbl_handle->setObjectName(QString::fromUtf8("lbl_handle"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lbl_handle->sizePolicy().hasHeightForWidth());
        lbl_handle->setSizePolicy(sizePolicy3);
        lbl_handle->setMinimumSize(QSize(15, 15));
        lbl_handle->setMaximumSize(QSize(15, 15));
        lbl_handle->setStyleSheet(QString::fromUtf8("border-radius: 7px; \n"
"border: 2px solid black; "));

        gridLayout_3->addWidget(lbl_handle, 5, 5, 1, 1, Qt::AlignHCenter);

        packTotalCurrent = new QLineEdit(groupBox_35);
        packTotalCurrent->setObjectName(QString::fromUtf8("packTotalCurrent"));
        sizePolicy1.setHeightForWidth(packTotalCurrent->sizePolicy().hasHeightForWidth());
        packTotalCurrent->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(packTotalCurrent, 1, 3, 1, 1);

        packTotalVoltage = new QLineEdit(groupBox_35);
        packTotalVoltage->setObjectName(QString::fromUtf8("packTotalVoltage"));
        sizePolicy1.setHeightForWidth(packTotalVoltage->sizePolicy().hasHeightForWidth());
        packTotalVoltage->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(packTotalVoltage, 1, 5, 1, 1);

        label_146 = new QLabel(groupBox_35);
        label_146->setObjectName(QString::fromUtf8("label_146"));
        sizePolicy2.setHeightForWidth(label_146->sizePolicy().hasHeightForWidth());
        label_146->setSizePolicy(sizePolicy2);
        label_146->setMinimumSize(QSize(80, 0));
        label_146->setScaledContents(false);

        gridLayout_3->addWidget(label_146, 1, 4, 1, 1);


        gridLayout_2->addWidget(groupBox_35, 0, 0, 1, 1);

        groupBox_31 = new QGroupBox(centralwidget);
        groupBox_31->setObjectName(QString::fromUtf8("groupBox_31"));
        sizePolicy2.setHeightForWidth(groupBox_31->sizePolicy().hasHeightForWidth());
        groupBox_31->setSizePolicy(sizePolicy2);
        groupBox_31->setMinimumSize(QSize(900, 0));
        groupBox_31->setMaximumSize(QSize(500, 16777215));
        groupBox_31->setFont(font);
        groupBox_31->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        gridLayout_26 = new QGridLayout(groupBox_31);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_23 = new QGridLayout();
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        label_342 = new QLabel(groupBox_31);
        label_342->setObjectName(QString::fromUtf8("label_342"));
        sizePolicy2.setHeightForWidth(label_342->sizePolicy().hasHeightForWidth());
        label_342->setSizePolicy(sizePolicy2);
        label_342->setMinimumSize(QSize(80, 0));
        label_342->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_342, 1, 0, 1, 1);

        Distance1 = new QLineEdit(groupBox_31);
        Distance1->setObjectName(QString::fromUtf8("Distance1"));

        gridLayout_23->addWidget(Distance1, 0, 3, 1, 1);

        Distance2 = new QLineEdit(groupBox_31);
        Distance2->setObjectName(QString::fromUtf8("Distance2"));

        gridLayout_23->addWidget(Distance2, 1, 1, 1, 1);

        label_343 = new QLabel(groupBox_31);
        label_343->setObjectName(QString::fromUtf8("label_343"));
        sizePolicy2.setHeightForWidth(label_343->sizePolicy().hasHeightForWidth());
        label_343->setSizePolicy(sizePolicy2);
        label_343->setMinimumSize(QSize(80, 0));
        label_343->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_343, 0, 2, 1, 1);

        Distance0 = new QLineEdit(groupBox_31);
        Distance0->setObjectName(QString::fromUtf8("Distance0"));

        gridLayout_23->addWidget(Distance0, 0, 1, 1, 1);

        Distance3 = new QLineEdit(groupBox_31);
        Distance3->setObjectName(QString::fromUtf8("Distance3"));

        gridLayout_23->addWidget(Distance3, 1, 3, 1, 1);

        label_341 = new QLabel(groupBox_31);
        label_341->setObjectName(QString::fromUtf8("label_341"));
        sizePolicy2.setHeightForWidth(label_341->sizePolicy().hasHeightForWidth());
        label_341->setSizePolicy(sizePolicy2);
        label_341->setMinimumSize(QSize(80, 0));
        label_341->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_341, 0, 0, 1, 1);

        label_344 = new QLabel(groupBox_31);
        label_344->setObjectName(QString::fromUtf8("label_344"));
        sizePolicy2.setHeightForWidth(label_344->sizePolicy().hasHeightForWidth());
        label_344->setSizePolicy(sizePolicy2);
        label_344->setMinimumSize(QSize(80, 0));
        label_344->setMaximumSize(QSize(50, 16777215));

        gridLayout_23->addWidget(label_344, 1, 2, 1, 1);


        gridLayout_26->addLayout(gridLayout_23, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_31, 1, 0, 1, 1);

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
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit_Info = new QTextEdit(groupBox);
        textEdit_Info->setObjectName(QString::fromUtf8("textEdit_Info"));

        gridLayout->addWidget(textEdit_Info, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 1);

        AGVMonitor->setCentralWidget(centralwidget);

        retranslateUi(AGVMonitor);

        QMetaObject::connectSlotsByName(AGVMonitor);
    } // setupUi

    void retranslateUi(QMainWindow *AGVMonitor)
    {
        AGVMonitor->setWindowTitle(QCoreApplication::translate("AGVMonitor", "AGV\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        groupBox_35->setTitle(QCoreApplication::translate("AGVMonitor", "AGV\345\260\217\350\275\246\347\212\266\346\200\201", nullptr));
        label_141->setText(QCoreApplication::translate("AGVMonitor", "\346\200\245\345\201\234\357\274\232", nullptr));
        label_138->setText(QCoreApplication::translate("AGVMonitor", "\346\277\200\345\205\211\351\201\256\346\214\241\357\274\232", nullptr));
        label_165->setText(QCoreApplication::translate("AGVMonitor", "\345\234\260\345\233\276\350\275\275\345\205\245\347\212\266\346\200\201\357\274\232", nullptr));
        label_145->setText(QCoreApplication::translate("AGVMonitor", "\346\212\261\351\227\270\357\274\232", nullptr));
        label_143->setText(QCoreApplication::translate("AGVMonitor", "\347\224\265\346\261\2402\347\224\265\346\265\201\357\274\232", nullptr));
        label_166->setText(QCoreApplication::translate("AGVMonitor", "\351\207\215\345\256\232\344\275\215\347\212\266\346\200\201\357\274\232", nullptr));
        label_147->setText(QCoreApplication::translate("AGVMonitor", "\345\257\274\350\210\252\347\261\273\345\236\213\357\274\232", nullptr));
        label_151->setText(QCoreApplication::translate("AGVMonitor", "\347\273\247\347\224\265\345\231\250\357\274\232", nullptr));
        label_149->setText(QCoreApplication::translate("AGVMonitor", "\347\224\265\346\234\272\351\251\261\345\212\250\346\200\245\345\201\234\357\274\232", nullptr));
        label_150->setText(QCoreApplication::translate("AGVMonitor", "\346\211\213\346\237\204\346\230\257\345\220\246\346\277\200\346\264\273", nullptr));
        label_148->setText(QCoreApplication::translate("AGVMonitor", "\345\211\251\344\275\231\350\267\257\345\276\204\351\225\277\345\272\246\357\274\232", nullptr));
        label_137->setText(QCoreApplication::translate("AGVMonitor", "\347\224\265\346\261\2402\347\224\265\351\207\217\357\274\232", nullptr));
        label_139->setText(QCoreApplication::translate("AGVMonitor", "\351\201\256\346\214\241\345\216\237\345\233\240\357\274\232", nullptr));
        label_144->setText(QCoreApplication::translate("AGVMonitor", "\345\275\223\345\211\215\346\234\200\350\277\221\347\253\231\347\202\271\357\274\232", nullptr));
        label_142->setText(QCoreApplication::translate("AGVMonitor", "\350\275\257\346\200\245\345\201\234\357\274\232", nullptr));
        label_140->setText(QCoreApplication::translate("AGVMonitor", "\344\273\273\345\212\241\347\212\266\346\200\201\357\274\232", nullptr));
        label_136->setText(QCoreApplication::translate("AGVMonitor", "\347\224\265\346\261\240\347\224\265\351\207\217\357\274\232", nullptr));
        lbl_handle->setText(QString());
        label_146->setText(QCoreApplication::translate("AGVMonitor", "\347\224\265\346\261\2402\347\224\265\345\216\213", nullptr));
        groupBox_31->setTitle(QCoreApplication::translate("AGVMonitor", "AGV \350\276\271\347\274\230\350\267\235\347\246\273\345\217\215\351\246\210", nullptr));
        label_342->setText(QCoreApplication::translate("AGVMonitor", "\345\267\246\345\220\216\350\267\235\347\246\273\357\274\232", nullptr));
        label_343->setText(QCoreApplication::translate("AGVMonitor", "\345\217\263\345\211\215\350\267\235\347\246\273\357\274\232", nullptr));
        label_341->setText(QCoreApplication::translate("AGVMonitor", "\345\267\246\345\211\215\350\267\235\347\246\273\357\274\232", nullptr));
        label_344->setText(QCoreApplication::translate("AGVMonitor", "\345\217\263\345\220\216\350\267\235\347\246\273\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AGVMonitor", "\346\217\220\347\244\272\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AGVMonitor: public Ui_AGVMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGVMONITOR_H
