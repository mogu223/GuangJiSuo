/********************************************************************************
** Form generated from reading UI file 'CGXBitmap.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGXBITMAP_H
#define UI_CGXBITMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGXBitmap
{
public:

    void setupUi(QWidget *CGXBitmap)
    {
        if (CGXBitmap->objectName().isEmpty())
            CGXBitmap->setObjectName(QString::fromUtf8("CGXBitmap"));
        CGXBitmap->resize(600, 455);
        CGXBitmap->setMaximumSize(QSize(600, 455));

        retranslateUi(CGXBitmap);

        QMetaObject::connectSlotsByName(CGXBitmap);
    } // setupUi

    void retranslateUi(QWidget *CGXBitmap)
    {
        CGXBitmap->setWindowTitle(QCoreApplication::translate("CGXBitmap", "CGXBitmap", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGXBitmap: public Ui_CGXBitmap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGXBITMAP_H
