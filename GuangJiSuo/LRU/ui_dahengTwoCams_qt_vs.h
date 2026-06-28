/********************************************************************************
** Form generated from reading UI file 'dahengTwoCams_qt_vs.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAHENGTWOCAMS_QT_VS_H
#define UI_DAHENGTWOCAMS_QT_VS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CGXBitmap.h"

QT_BEGIN_NAMESPACE

class Ui_dahengTwoCams_qt_vsClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_LCam;
    CGXBitmap *bitMap_LCam;
    QWidget *tab_RCam;
    CGXBitmap *bitMap_RCam;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *cB_DeviceList;
    QPushButton *pB_refreshDeviceList;
    QPushButton *start0;
    QPushButton *closecamera;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dahengTwoCams_qt_vsClass)
    {
        if (dahengTwoCams_qt_vsClass->objectName().isEmpty())
            dahengTwoCams_qt_vsClass->setObjectName(QString::fromUtf8("dahengTwoCams_qt_vsClass"));
        dahengTwoCams_qt_vsClass->resize(878, 827);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dahengTwoCams_qt_vsClass->sizePolicy().hasHeightForWidth());
        dahengTwoCams_qt_vsClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(dahengTwoCams_qt_vsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 110, 871, 691));
        tab_LCam = new QWidget();
        tab_LCam->setObjectName(QString::fromUtf8("tab_LCam"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tab_LCam->sizePolicy().hasHeightForWidth());
        tab_LCam->setSizePolicy(sizePolicy1);
        tab_LCam->setMinimumSize(QSize(900, 700));
        tab_LCam->setMaximumSize(QSize(900, 700));
        bitMap_LCam = new CGXBitmap(tab_LCam);
        bitMap_LCam->setObjectName(QString::fromUtf8("bitMap_LCam"));
        bitMap_LCam->setGeometry(QRect(0, 0, 864, 648));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(5);
        sizePolicy2.setHeightForWidth(bitMap_LCam->sizePolicy().hasHeightForWidth());
        bitMap_LCam->setSizePolicy(sizePolicy2);
        bitMap_LCam->setMinimumSize(QSize(864, 648));
        bitMap_LCam->setMaximumSize(QSize(864, 648));
        tabWidget->addTab(tab_LCam, QString());
        tab_RCam = new QWidget();
        tab_RCam->setObjectName(QString::fromUtf8("tab_RCam"));
        sizePolicy1.setHeightForWidth(tab_RCam->sizePolicy().hasHeightForWidth());
        tab_RCam->setSizePolicy(sizePolicy1);
        tab_RCam->setMinimumSize(QSize(900, 700));
        tab_RCam->setMaximumSize(QSize(900, 700));
        bitMap_RCam = new CGXBitmap(tab_RCam);
        bitMap_RCam->setObjectName(QString::fromUtf8("bitMap_RCam"));
        bitMap_RCam->setGeometry(QRect(0, 0, 864, 648));
        sizePolicy2.setHeightForWidth(bitMap_RCam->sizePolicy().hasHeightForWidth());
        bitMap_RCam->setSizePolicy(sizePolicy2);
        bitMap_RCam->setMinimumSize(QSize(864, 648));
        bitMap_RCam->setMaximumSize(QSize(864, 648));
        tabWidget->addTab(tab_RCam, QString());
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 30, 671, 85));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cB_DeviceList = new QComboBox(layoutWidget);
        cB_DeviceList->setObjectName(QString::fromUtf8("cB_DeviceList"));
        QFont font;
        font.setFamily(QString::fromUtf8("3ds"));
        font.setPointSize(8);
        cB_DeviceList->setFont(font);

        horizontalLayout->addWidget(cB_DeviceList);

        pB_refreshDeviceList = new QPushButton(layoutWidget);
        pB_refreshDeviceList->setObjectName(QString::fromUtf8("pB_refreshDeviceList"));
        pB_refreshDeviceList->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(pB_refreshDeviceList);


        verticalLayout->addLayout(horizontalLayout);

        start0 = new QPushButton(layoutWidget);
        start0->setObjectName(QString::fromUtf8("start0"));

        verticalLayout->addWidget(start0);

        closecamera = new QPushButton(layoutWidget);
        closecamera->setObjectName(QString::fromUtf8("closecamera"));

        verticalLayout->addWidget(closecamera);

        dahengTwoCams_qt_vsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(dahengTwoCams_qt_vsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        dahengTwoCams_qt_vsClass->setStatusBar(statusBar);

        retranslateUi(dahengTwoCams_qt_vsClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(dahengTwoCams_qt_vsClass);
    } // setupUi

    void retranslateUi(QMainWindow *dahengTwoCams_qt_vsClass)
    {
        dahengTwoCams_qt_vsClass->setWindowTitle(QCoreApplication::translate("dahengTwoCams_qt_vsClass", "dahengTwoCams_qt_vs", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_LCam), QCoreApplication::translate("dahengTwoCams_qt_vsClass", "tab_LCam", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_RCam), QCoreApplication::translate("dahengTwoCams_qt_vsClass", "tab_RCam", nullptr));
        pB_refreshDeviceList->setText(QCoreApplication::translate("dahengTwoCams_qt_vsClass", "\345\210\267\346\226\260\345\210\227\350\241\250", nullptr));
        start0->setText(QCoreApplication::translate("dahengTwoCams_qt_vsClass", "\345\220\257\345\212\250\347\233\270\346\234\272", nullptr));
        closecamera->setText(QCoreApplication::translate("dahengTwoCams_qt_vsClass", "\345\205\263\351\227\255\347\233\270\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dahengTwoCams_qt_vsClass: public Ui_dahengTwoCams_qt_vsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAHENGTWOCAMS_QT_VS_H
