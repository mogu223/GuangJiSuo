/********************************************************************************
** Form generated from reading UI file 'newform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFORM_H
#define UI_NEWFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <STLModel/coverplatewidget.h>

QT_BEGIN_NAMESPACE

class Ui_NewForm
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    DDR6RobotWidget *robot3DVirtual;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBoxJoint4Coord;
    QSlider *sliderJoint4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBoxJoint2Coord;
    QSlider *sliderJoint2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxJoint3Coord;
    QSlider *sliderJoint3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxJoint1Coord;
    QSlider *sliderJoint1;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBoxWorldCoord;
    QCheckBox *checkBoxGrid;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NewForm)
    {
        if (NewForm->objectName().isEmpty())
            NewForm->setObjectName(QString::fromUtf8("NewForm"));
        NewForm->resize(1018, 660);
        NewForm->setMinimumSize(QSize(1000, 0));
        NewForm->setMaximumSize(QSize(1018, 16777215));
        centralwidget = new QWidget(NewForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(1000, 500));
        groupBox->setMaximumSize(QSize(1000, 500));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        robot3DVirtual = new DDR6RobotWidget(groupBox);
        robot3DVirtual->setObjectName(QString::fromUtf8("robot3DVirtual"));
        robot3DVirtual->setMinimumSize(QSize(1000, 500));
        robot3DVirtual->setMaximumSize(QSize(1000, 500));
        robot3DVirtual->setStyleSheet(QString::fromUtf8("BackGround:white;"));

        gridLayout->addWidget(robot3DVirtual, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(1000, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBoxJoint4Coord = new QCheckBox(groupBox_2);
        checkBoxJoint4Coord->setObjectName(QString::fromUtf8("checkBoxJoint4Coord"));

        horizontalLayout_4->addWidget(checkBoxJoint4Coord);

        sliderJoint4 = new QSlider(groupBox_2);
        sliderJoint4->setObjectName(QString::fromUtf8("sliderJoint4"));
        sliderJoint4->setMinimum(100);
        sliderJoint4->setMaximum(200);
        sliderJoint4->setValue(100);
        sliderJoint4->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(sliderJoint4);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBoxJoint2Coord = new QCheckBox(groupBox_2);
        checkBoxJoint2Coord->setObjectName(QString::fromUtf8("checkBoxJoint2Coord"));

        horizontalLayout_3->addWidget(checkBoxJoint2Coord);

        sliderJoint2 = new QSlider(groupBox_2);
        sliderJoint2->setObjectName(QString::fromUtf8("sliderJoint2"));
        sliderJoint2->setMinimum(50);
        sliderJoint2->setMaximum(350);
        sliderJoint2->setValue(195);
        sliderJoint2->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(sliderJoint2);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBoxJoint3Coord = new QCheckBox(groupBox_2);
        checkBoxJoint3Coord->setObjectName(QString::fromUtf8("checkBoxJoint3Coord"));

        horizontalLayout_2->addWidget(checkBoxJoint3Coord);

        sliderJoint3 = new QSlider(groupBox_2);
        sliderJoint3->setObjectName(QString::fromUtf8("sliderJoint3"));
        sliderJoint3->setMinimum(0);
        sliderJoint3->setMaximum(40);
        sliderJoint3->setSingleStep(1);
        sliderJoint3->setValue(20);
        sliderJoint3->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderJoint3);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBoxJoint1Coord = new QCheckBox(groupBox_2);
        checkBoxJoint1Coord->setObjectName(QString::fromUtf8("checkBoxJoint1Coord"));

        horizontalLayout->addWidget(checkBoxJoint1Coord);

        sliderJoint1 = new QSlider(groupBox_2);
        sliderJoint1->setObjectName(QString::fromUtf8("sliderJoint1"));
        sliderJoint1->setMinimum(35);
        sliderJoint1->setMaximum(650);
        sliderJoint1->setValue(35);
        sliderJoint1->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderJoint1);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkBoxWorldCoord = new QCheckBox(groupBox_2);
        checkBoxWorldCoord->setObjectName(QString::fromUtf8("checkBoxWorldCoord"));

        horizontalLayout_5->addWidget(checkBoxWorldCoord);

        checkBoxGrid = new QCheckBox(groupBox_2);
        checkBoxGrid->setObjectName(QString::fromUtf8("checkBoxGrid"));

        horizontalLayout_5->addWidget(checkBoxGrid);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        NewForm->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(NewForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NewForm->setStatusBar(statusbar);

        retranslateUi(NewForm);

        QMetaObject::connectSlotsByName(NewForm);
    } // setupUi

    void retranslateUi(QMainWindow *NewForm)
    {
        NewForm->setWindowTitle(QCoreApplication::translate("NewForm", "\344\270\211\347\273\264\345\217\226\347\233\226\346\235\277\346\234\272\346\236\204", nullptr));
        groupBox->setTitle(QCoreApplication::translate("NewForm", "\346\225\260\345\255\227\345\255\252\347\224\237", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("NewForm", "\350\277\220\345\212\250\346\216\247\345\210\266", nullptr));
        checkBoxJoint4Coord->setText(QCoreApplication::translate("NewForm", "\345\244\271\347\210\252\346\234\272\346\236\204", nullptr));
        checkBoxJoint2Coord->setText(QCoreApplication::translate("NewForm", "\347\272\265\347\247\273\346\234\272\346\236\204", nullptr));
        checkBoxJoint3Coord->setText(QCoreApplication::translate("NewForm", "\346\211\230\344\270\276\346\234\272\346\236\204", nullptr));
        checkBoxJoint1Coord->setText(QCoreApplication::translate("NewForm", "\346\250\252\347\247\273\346\234\272\346\236\204", nullptr));
        checkBoxWorldCoord->setText(QCoreApplication::translate("NewForm", "\344\270\226\347\225\214\345\235\220\346\240\207\347\263\273", nullptr));
        checkBoxGrid->setText(QCoreApplication::translate("NewForm", "\346\240\205\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewForm: public Ui_NewForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFORM_H
