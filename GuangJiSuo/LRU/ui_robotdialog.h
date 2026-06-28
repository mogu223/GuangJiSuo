/********************************************************************************
** Form generated from reading UI file 'robotdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTDIALOG_H
#define UI_ROBOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotDialog
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3D;

    void setupUi(QWidget *RobotDialog)
    {
        if (RobotDialog->objectName().isEmpty())
            RobotDialog->setObjectName(QString::fromUtf8("RobotDialog"));
        RobotDialog->resize(1117, 872);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RobotDialog->sizePolicy().hasHeightForWidth());
        RobotDialog->setSizePolicy(sizePolicy);
        RobotDialog->setStyleSheet(QString::fromUtf8("QSplitter::handle:horizontal {\n"
"    width: 3px;\n"
"	background-color: rgb(10,10,10);\n"
"}\n"
"QSplitter::handle:horizontal:pressed {\n"
"	background-color: rgb(1,155,72);\n"
"}\n"
"\n"
"QSplitter::handle:vertical {\n"
"    height: 4px;\n"
"	background-color: rgb(10,10,10);\n"
"}\n"
"QSplitter::handle:vertical:pressed {\n"
"	background-color:  rgb(1,155,72);\n"
"}"));
        verticalLayout = new QVBoxLayout(RobotDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_3D = new QVBoxLayout();
        verticalLayout_3D->setSpacing(6);
        verticalLayout_3D->setObjectName(QString::fromUtf8("verticalLayout_3D"));

        verticalLayout_5->addLayout(verticalLayout_3D);


        verticalLayout->addLayout(verticalLayout_5);


        retranslateUi(RobotDialog);

        QMetaObject::connectSlotsByName(RobotDialog);
    } // setupUi

    void retranslateUi(QWidget *RobotDialog)
    {
        RobotDialog->setWindowTitle(QCoreApplication::translate("RobotDialog", "\346\234\272\346\242\260\350\207\202+\347\201\265\345\267\247\346\211\213\345\256\236\351\252\214\345\271\263\345\217\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RobotDialog: public Ui_RobotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTDIALOG_H
