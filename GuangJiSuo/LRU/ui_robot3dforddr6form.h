/********************************************************************************
** Form generated from reading UI file 'robot3dforddr6form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOT3DFORDDR6FORM_H
#define UI_ROBOT3DFORDDR6FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <robotview/ddr6robotwidget.h>
#include "robotview/robotcontrolform.h"

QT_BEGIN_NAMESPACE

class Ui_Robot3DForDDR6Form
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage1;
    QVBoxLayout *verticalLayout_4;
    DDR6RobotWidget *robot3D_virtual;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    RobotControlForm *robotControl;

    void setupUi(QWidget *Robot3DForDDR6Form)
    {
        if (Robot3DForDDR6Form->objectName().isEmpty())
            Robot3DForDDR6Form->setObjectName(QString::fromUtf8("Robot3DForDDR6Form"));
        Robot3DForDDR6Form->resize(699, 694);
        Robot3DForDDR6Form->setStyleSheet(QString::fromUtf8("#QScrollArea {\n"
"	background-color: rgb(39,39,39);\n"
"	border: none;\n"
"}\n"
"\n"
"#scrollAreaContents {\n"
"	background-color: rgb(39,39,39);\n"
"	border: none;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(Robot3DForDDR6Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(Robot3DForDDR6Form);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLineWidth(4);
        splitter->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QString::fromUtf8("tabWidgetPage1"));
        verticalLayout_4 = new QVBoxLayout(tabWidgetPage1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        robot3D_virtual = new DDR6RobotWidget(tabWidgetPage1);
        robot3D_virtual->setObjectName(QString::fromUtf8("robot3D_virtual"));
        robot3D_virtual->setMinimumSize(QSize(300, 0));
        robot3D_virtual->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_4->addWidget(robot3D_virtual);

        tabWidget->addTab(tabWidgetPage1, QString());
        splitter->addWidget(tabWidget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        robotControl = new RobotControlForm(layoutWidget);
        robotControl->setObjectName(QString::fromUtf8("robotControl"));
        robotControl->setMinimumSize(QSize(0, 0));
        robotControl->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(robotControl);

        splitter->addWidget(layoutWidget);

        verticalLayout->addWidget(splitter);


        retranslateUi(Robot3DForDDR6Form);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Robot3DForDDR6Form);
    } // setupUi

    void retranslateUi(QWidget *Robot3DForDDR6Form)
    {
        Robot3DForDDR6Form->setWindowTitle(QCoreApplication::translate("Robot3DForDDR6Form", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QCoreApplication::translate("Robot3DForDDR6Form", "\346\250\241\345\236\213\346\216\247\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Robot3DForDDR6Form: public Ui_Robot3DForDDR6Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOT3DFORDDR6FORM_H
