/********************************************************************************
** Form generated from reading UI file 'widgetproperty.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPROPERTY_H
#define UI_WIDGETPROPERTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetProperty
{
public:

    void setupUi(QWidget *WidgetProperty)
    {
        if (WidgetProperty->objectName().isEmpty())
            WidgetProperty->setObjectName(QString::fromUtf8("WidgetProperty"));
        WidgetProperty->resize(800, 600);

        retranslateUi(WidgetProperty);

        QMetaObject::connectSlotsByName(WidgetProperty);
    } // setupUi

    void retranslateUi(QWidget *WidgetProperty)
    {
        WidgetProperty->setWindowTitle(QCoreApplication::translate("WidgetProperty", "WidgetProperty", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetProperty: public Ui_WidgetProperty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPROPERTY_H
