/********************************************************************************
** Form generated from reading UI file 'signalsandslotswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALSANDSLOTSWIDGET_H
#define UI_SIGNALSANDSLOTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignalsAndSlotsWidget
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QSlider *horizontalSlider;

    void setupUi(QWidget *SignalsAndSlotsWidget)
    {
        if (SignalsAndSlotsWidget->objectName().isEmpty())
            SignalsAndSlotsWidget->setObjectName(QString::fromUtf8("SignalsAndSlotsWidget"));
        SignalsAndSlotsWidget->resize(800, 600);
        label = new QLabel(SignalsAndSlotsWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(420, 240, 81, 20));
        lineEdit = new QLineEdit(SignalsAndSlotsWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 290, 331, 20));
        horizontalSlider = new QSlider(SignalsAndSlotsWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(140, 240, 231, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(SignalsAndSlotsWidget);

        QMetaObject::connectSlotsByName(SignalsAndSlotsWidget);
    } // setupUi

    void retranslateUi(QWidget *SignalsAndSlotsWidget)
    {
        SignalsAndSlotsWidget->setWindowTitle(QCoreApplication::translate("SignalsAndSlotsWidget", "SignalsAndSlotsWidget", nullptr));
        label->setText(QCoreApplication::translate("SignalsAndSlotsWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignalsAndSlotsWidget: public Ui_SignalsAndSlotsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALSANDSLOTSWIDGET_H
