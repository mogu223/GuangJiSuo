/********************************************************************************
** Form generated from reading UI file 'robotcontrolform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTCONTROLFORM_H
#define UI_ROBOTCONTROLFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotControlForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_control;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBoxGrid_real;
    QCheckBox *checkBoxWorldCoordinate_real;
    QCheckBox *checkBoxDesk_real;
    QFrame *line;
    QGroupBox *groupBoxRobot;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *groupBoxControl;
    QGridLayout *gridLayout_2;
    QSlider *sliderQ6;
    QLabel *label_7;
    QLabel *label_10;
    QSlider *sliderQ1;
    QCheckBox *checkBoxJ5;
    QSlider *sliderQ2;
    QCheckBox *checkBoxJ2;
    QCheckBox *checkBoxJ4;
    QCheckBox *checkBoxJ6;
    QCheckBox *checkBoxJ1;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_3;
    QSlider *sliderQ3;
    QCheckBox *checkBoxJ3;
    QSlider *sliderQ5;
    QSlider *sliderQ4;
    QFrame *line_2;

    void setupUi(QWidget *RobotControlForm)
    {
        if (RobotControlForm->objectName().isEmpty())
            RobotControlForm->setObjectName(QString::fromUtf8("RobotControlForm"));
        RobotControlForm->resize(924, 512);
        RobotControlForm->setStyleSheet(QString::fromUtf8("/*\346\273\221\345\235\227\347\232\204\346\240\267\345\274\217*/\n"
"QSlider::groove:horizontal {\n"
"	border: 1px solid rgb(21, 156, 119);\n"
"	background: rgb(21, 156, 119);\n"
"	height: 2px;\n"
"	border-radius: 50px;\n"
"	padding-left:0px;\n"
"	padding-right:0px;\n"
"}\n"
" \n"
"/*\346\273\221\345\235\227\347\273\217\350\277\207\347\232\204\351\242\234\350\211\262:\345\211\215\351\235\242\347\232\204\351\242\234\350\211\262*/\n"
"QSlider::sub-page:horizontal {\n"
"	background: rgb(21, 156, 119);\n"
"	border: 1px solid rgb(21, 156, 119);\n"
"	height: 2px;\n"
"	border-radius: 2px;\n"
"}\n"
" \n"
"QSlider::add-page:horizontal {\n"
"	background: rgb(160, 215, 218);\n"
"	border: 0px solid rgb(160, 215, 218);\n"
"	height: 2px;\n"
"	border-radius: 2px;\n"
"}\n"
"QSlider::handle:horizontal \n"
"{\n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,stop:0.6 rgb(21, 156, 119),stop:0.98409 rgba(255, 255, 255, 255));\n"
"    width: 15px;\n"
"    margin-top: -6px;\n"
"    margin-bo"
                        "ttom: -6px;\n"
"    border-radius: 6px;\n"
"}\n"
" \n"
"QSlider::handle:horizontal:hover {\n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5,stop:0.6 rgb(21, 156, 119),stop:0.98409 rgba(255, 255, 255, 255));\n"
"    width: 15px;\n"
"    margin-top: -6px;\n"
"    margin-bottom: -6px;\n"
"    border-radius: 6px;\n"
"}\n"
" "));
        verticalLayout_3 = new QVBoxLayout(RobotControlForm);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_control = new QGroupBox(RobotControlForm);
        groupBox_control->setObjectName(QString::fromUtf8("groupBox_control"));
        verticalLayout = new QVBoxLayout(groupBox_control);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, -1);
        checkBoxGrid_real = new QCheckBox(groupBox_control);
        checkBoxGrid_real->setObjectName(QString::fromUtf8("checkBoxGrid_real"));

        horizontalLayout_9->addWidget(checkBoxGrid_real);

        checkBoxWorldCoordinate_real = new QCheckBox(groupBox_control);
        checkBoxWorldCoordinate_real->setObjectName(QString::fromUtf8("checkBoxWorldCoordinate_real"));

        horizontalLayout_9->addWidget(checkBoxWorldCoordinate_real);

        checkBoxDesk_real = new QCheckBox(groupBox_control);
        checkBoxDesk_real->setObjectName(QString::fromUtf8("checkBoxDesk_real"));

        horizontalLayout_9->addWidget(checkBoxDesk_real);


        verticalLayout->addLayout(horizontalLayout_9);

        line = new QFrame(groupBox_control);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(10,10,10);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        groupBoxRobot = new QGroupBox(groupBox_control);
        groupBoxRobot->setObjectName(QString::fromUtf8("groupBoxRobot"));
        horizontalLayout_10 = new QHBoxLayout(groupBoxRobot);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 0, -1, -1);
        groupBoxControl = new QGroupBox(groupBoxRobot);
        groupBoxControl->setObjectName(QString::fromUtf8("groupBoxControl"));
        gridLayout_2 = new QGridLayout(groupBoxControl);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 20, -1, 0);
        sliderQ6 = new QSlider(groupBoxControl);
        sliderQ6->setObjectName(QString::fromUtf8("sliderQ6"));
        sliderQ6->setMinimum(-180);
        sliderQ6->setMaximum(180);
        sliderQ6->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderQ6, 5, 2, 1, 1);

        label_7 = new QLabel(groupBoxControl);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 3, 1, 1, 1);

        label_10 = new QLabel(groupBoxControl);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 5, 1, 1, 1);

        sliderQ1 = new QSlider(groupBoxControl);
        sliderQ1->setObjectName(QString::fromUtf8("sliderQ1"));
        sliderQ1->setMinimum(-180);
        sliderQ1->setMaximum(180);
        sliderQ1->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderQ1, 0, 2, 1, 1);

        checkBoxJ5 = new QCheckBox(groupBoxControl);
        checkBoxJ5->setObjectName(QString::fromUtf8("checkBoxJ5"));

        gridLayout_2->addWidget(checkBoxJ5, 4, 0, 1, 1);

        sliderQ2 = new QSlider(groupBoxControl);
        sliderQ2->setObjectName(QString::fromUtf8("sliderQ2"));
        sliderQ2->setMinimum(-180);
        sliderQ2->setMaximum(180);
        sliderQ2->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderQ2, 1, 2, 1, 1);

        checkBoxJ2 = new QCheckBox(groupBoxControl);
        checkBoxJ2->setObjectName(QString::fromUtf8("checkBoxJ2"));

        gridLayout_2->addWidget(checkBoxJ2, 1, 0, 1, 1);

        checkBoxJ4 = new QCheckBox(groupBoxControl);
        checkBoxJ4->setObjectName(QString::fromUtf8("checkBoxJ4"));

        gridLayout_2->addWidget(checkBoxJ4, 3, 0, 1, 1);

        checkBoxJ6 = new QCheckBox(groupBoxControl);
        checkBoxJ6->setObjectName(QString::fromUtf8("checkBoxJ6"));

        gridLayout_2->addWidget(checkBoxJ6, 5, 0, 1, 1);

        checkBoxJ1 = new QCheckBox(groupBoxControl);
        checkBoxJ1->setObjectName(QString::fromUtf8("checkBoxJ1"));

        gridLayout_2->addWidget(checkBoxJ1, 0, 0, 1, 1);

        label_9 = new QLabel(groupBoxControl);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 4, 1, 1, 1);

        label_5 = new QLabel(groupBoxControl);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 1, 1, 1);

        label = new QLabel(groupBoxControl);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        label_3 = new QLabel(groupBoxControl);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 1, 1, 1);

        sliderQ3 = new QSlider(groupBoxControl);
        sliderQ3->setObjectName(QString::fromUtf8("sliderQ3"));
        sliderQ3->setMinimum(-180);
        sliderQ3->setMaximum(180);
        sliderQ3->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderQ3, 2, 2, 1, 1);

        checkBoxJ3 = new QCheckBox(groupBoxControl);
        checkBoxJ3->setObjectName(QString::fromUtf8("checkBoxJ3"));

        gridLayout_2->addWidget(checkBoxJ3, 2, 0, 1, 1);

        sliderQ5 = new QSlider(groupBoxControl);
        sliderQ5->setObjectName(QString::fromUtf8("sliderQ5"));
        sliderQ5->setMinimum(-180);
        sliderQ5->setMaximum(180);
        sliderQ5->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderQ5, 4, 2, 1, 1);

        sliderQ4 = new QSlider(groupBoxControl);
        sliderQ4->setObjectName(QString::fromUtf8("sliderQ4"));
        sliderQ4->setMinimum(-180);
        sliderQ4->setMaximum(180);
        sliderQ4->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderQ4, 3, 2, 1, 1);

        gridLayout_2->setRowStretch(0, 1);

        horizontalLayout_10->addWidget(groupBoxControl);

        line_2 = new QFrame(groupBoxRobot);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb(10,10,10);"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_10->addWidget(line_2);

        horizontalLayout_10->setStretch(0, 1);

        verticalLayout->addWidget(groupBoxRobot);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 6);

        verticalLayout_3->addWidget(groupBox_control);


        retranslateUi(RobotControlForm);

        QMetaObject::connectSlotsByName(RobotControlForm);
    } // setupUi

    void retranslateUi(QWidget *RobotControlForm)
    {
        RobotControlForm->setWindowTitle(QCoreApplication::translate("RobotControlForm", "Form", nullptr));
        checkBoxGrid_real->setText(QCoreApplication::translate("RobotControlForm", "\347\275\221\346\240\274", nullptr));
        checkBoxWorldCoordinate_real->setText(QCoreApplication::translate("RobotControlForm", "\344\270\226\347\225\214\345\235\220\346\240\207\347\263\273", nullptr));
        checkBoxDesk_real->setText(QCoreApplication::translate("RobotControlForm", "\350\257\225\351\252\214\345\217\260", nullptr));
        groupBoxControl->setTitle(QCoreApplication::translate("RobotControlForm", "\346\250\241\345\236\213\346\216\247\345\210\266", nullptr));
        label_7->setText(QCoreApplication::translate("RobotControlForm", "J4:", nullptr));
        label_10->setText(QCoreApplication::translate("RobotControlForm", "J6:", nullptr));
        checkBoxJ5->setText(QString());
        checkBoxJ2->setText(QString());
        checkBoxJ4->setText(QString());
        checkBoxJ6->setText(QString());
        checkBoxJ1->setText(QString());
        label_9->setText(QCoreApplication::translate("RobotControlForm", "J5:", nullptr));
        label_5->setText(QCoreApplication::translate("RobotControlForm", "J3:", nullptr));
        label->setText(QCoreApplication::translate("RobotControlForm", "J1:", nullptr));
        label_3->setText(QCoreApplication::translate("RobotControlForm", "J2:", nullptr));
        checkBoxJ3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RobotControlForm: public Ui_RobotControlForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTCONTROLFORM_H
