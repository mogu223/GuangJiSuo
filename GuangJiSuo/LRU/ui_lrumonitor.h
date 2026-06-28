/********************************************************************************
** Form generated from reading UI file 'lrumonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LRUMONITOR_H
#define UI_LRUMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lrumonitor
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_28;
    QComboBox *comboBox_STLFiles;
    QPushButton *btn_LoadLRU;
    QWidget *robot3D_virtual;
    QPushButton *btn_MonitorStart;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_6;
    QLabel *label_15;
    QLineEdit *lineEdit_LRUMoveX;
    QLabel *label_58;
    QLineEdit *lineEdit_LRUMoveY;
    QLabel *label_35;
    QLineEdit *lineEdit_LRUMoveZ;
    QLabel *label_59;
    QLineEdit *lineEdit_LRURotY;

    void setupUi(QMainWindow *lrumonitor)
    {
        if (lrumonitor->objectName().isEmpty())
            lrumonitor->setObjectName(QString::fromUtf8("lrumonitor"));
        lrumonitor->resize(800, 980);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lrumonitor->sizePolicy().hasHeightForWidth());
        lrumonitor->setSizePolicy(sizePolicy);
        lrumonitor->setMaximumSize(QSize(800, 16777215));
        lrumonitor->setStyleSheet(QString::fromUtf8("Background:white;\n"
""));
        centralwidget = new QWidget(lrumonitor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy1);
        groupBox_6->setMinimumSize(QSize(150, 0));
        groupBox_6->setMaximumSize(QSize(800, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(12);
        groupBox_6->setFont(font);
        groupBox_6->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        gridLayout_28 = new QGridLayout(groupBox_6);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        comboBox_STLFiles = new QComboBox(groupBox_6);
        comboBox_STLFiles->setObjectName(QString::fromUtf8("comboBox_STLFiles"));

        gridLayout_28->addWidget(comboBox_STLFiles, 2, 2, 1, 1);

        btn_LoadLRU = new QPushButton(groupBox_6);
        btn_LoadLRU->setObjectName(QString::fromUtf8("btn_LoadLRU"));

        gridLayout_28->addWidget(btn_LoadLRU, 2, 0, 1, 1);

        robot3D_virtual = new QWidget(groupBox_6);
        robot3D_virtual->setObjectName(QString::fromUtf8("robot3D_virtual"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(4);
        sizePolicy2.setVerticalStretch(3);
        sizePolicy2.setHeightForWidth(robot3D_virtual->sizePolicy().hasHeightForWidth());
        robot3D_virtual->setSizePolicy(sizePolicy2);
        robot3D_virtual->setMaximumSize(QSize(16777215, 700));

        gridLayout_28->addWidget(robot3D_virtual, 0, 0, 1, 3);

        btn_MonitorStart = new QPushButton(groupBox_6);
        btn_MonitorStart->setObjectName(QString::fromUtf8("btn_MonitorStart"));

        gridLayout_28->addWidget(btn_MonitorStart, 2, 1, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(4);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy3);
        groupBox_7->setMinimumSize(QSize(0, 120));
        groupBox_7->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
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
        gridLayout_6 = new QGridLayout(groupBox_7);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 0, 0, 1, 1);

        lineEdit_LRUMoveX = new QLineEdit(groupBox_7);
        lineEdit_LRUMoveX->setObjectName(QString::fromUtf8("lineEdit_LRUMoveX"));

        gridLayout_6->addWidget(lineEdit_LRUMoveX, 0, 1, 1, 1);

        label_58 = new QLabel(groupBox_7);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        gridLayout_6->addWidget(label_58, 0, 2, 1, 1);

        lineEdit_LRUMoveY = new QLineEdit(groupBox_7);
        lineEdit_LRUMoveY->setObjectName(QString::fromUtf8("lineEdit_LRUMoveY"));

        gridLayout_6->addWidget(lineEdit_LRUMoveY, 0, 3, 1, 1);

        label_35 = new QLabel(groupBox_7);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_6->addWidget(label_35, 1, 0, 1, 1);

        lineEdit_LRUMoveZ = new QLineEdit(groupBox_7);
        lineEdit_LRUMoveZ->setObjectName(QString::fromUtf8("lineEdit_LRUMoveZ"));

        gridLayout_6->addWidget(lineEdit_LRUMoveZ, 1, 1, 1, 1);

        label_59 = new QLabel(groupBox_7);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        gridLayout_6->addWidget(label_59, 1, 2, 1, 1);

        lineEdit_LRURotY = new QLineEdit(groupBox_7);
        lineEdit_LRURotY->setObjectName(QString::fromUtf8("lineEdit_LRURotY"));

        gridLayout_6->addWidget(lineEdit_LRURotY, 1, 3, 1, 1);


        gridLayout_28->addWidget(groupBox_7, 1, 0, 1, 3);


        gridLayout->addWidget(groupBox_6, 0, 0, 1, 1);

        lrumonitor->setCentralWidget(centralwidget);

        retranslateUi(lrumonitor);

        QMetaObject::connectSlotsByName(lrumonitor);
    } // setupUi

    void retranslateUi(QMainWindow *lrumonitor)
    {
        lrumonitor->setWindowTitle(QCoreApplication::translate("lrumonitor", "LRU\345\247\277\346\200\201\347\233\221\346\265\213", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("lrumonitor", "LRU \347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
        btn_LoadLRU->setText(QCoreApplication::translate("lrumonitor", "\345\212\240\350\275\275LRU\346\250\241\345\236\213", nullptr));
        btn_MonitorStart->setText(QCoreApplication::translate("lrumonitor", "\347\233\221\346\265\213LRU\345\247\277\346\200\201", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("lrumonitor", "\344\275\215\345\247\277\344\277\241\346\201\257", nullptr));
        label_15->setText(QCoreApplication::translate("lrumonitor", "X\346\226\271\345\220\221\345\201\217\347\247\273", nullptr));
        label_58->setText(QCoreApplication::translate("lrumonitor", "Y\346\226\271\345\220\221\347\247\273\345\212\250", nullptr));
        label_35->setText(QCoreApplication::translate("lrumonitor", "Z\346\226\271\345\220\221\345\201\217\347\247\273", nullptr));
        label_59->setText(QCoreApplication::translate("lrumonitor", "\347\273\225Y\345\201\217\350\275\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lrumonitor: public Ui_lrumonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LRUMONITOR_H
