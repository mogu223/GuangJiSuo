/********************************************************************************
** Form generated from reading UI file 'pinmonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINMONITOR_H
#define UI_PINMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PinMonitor
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PinMonitor)
    {
        if (PinMonitor->objectName().isEmpty())
            PinMonitor->setObjectName(QString::fromUtf8("PinMonitor"));
        PinMonitor->resize(800, 600);
        centralwidget = new QWidget(PinMonitor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PinMonitor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PinMonitor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        PinMonitor->setMenuBar(menubar);
        statusbar = new QStatusBar(PinMonitor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PinMonitor->setStatusBar(statusbar);

        retranslateUi(PinMonitor);

        QMetaObject::connectSlotsByName(PinMonitor);
    } // setupUi

    void retranslateUi(QMainWindow *PinMonitor)
    {
        PinMonitor->setWindowTitle(QCoreApplication::translate("PinMonitor", "\346\213\224\351\224\200\347\263\273\347\273\237\347\212\266\346\200\201\347\233\221\346\265\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PinMonitor: public Ui_PinMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINMONITOR_H
