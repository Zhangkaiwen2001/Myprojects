/********************************************************************************
** Form generated from reading UI file 'modelwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELWIDGET_H
#define UI_MODELWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelWidget
{
public:
    QPushButton *btnWindow;
    QPushButton *btnApp;
    QLineEdit *lineEdit;
    QPushButton *btnCustom;

    void setupUi(QWidget *ModelWidget)
    {
        if (ModelWidget->objectName().isEmpty())
            ModelWidget->setObjectName(QString::fromUtf8("ModelWidget"));
        ModelWidget->resize(800, 600);
        btnWindow = new QPushButton(ModelWidget);
        btnWindow->setObjectName(QString::fromUtf8("btnWindow"));
        btnWindow->setGeometry(QRect(320, 190, 171, 23));
        btnWindow->setCheckable(true);
        btnApp = new QPushButton(ModelWidget);
        btnApp->setObjectName(QString::fromUtf8("btnApp"));
        btnApp->setGeometry(QRect(320, 230, 171, 23));
        btnApp->setCheckable(true);
        lineEdit = new QLineEdit(ModelWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(320, 270, 171, 21));
        btnCustom = new QPushButton(ModelWidget);
        btnCustom->setObjectName(QString::fromUtf8("btnCustom"));
        btnCustom->setGeometry(QRect(320, 310, 171, 23));
        btnCustom->setCheckable(true);
        btnCustom->setChecked(false);

        retranslateUi(ModelWidget);

        QMetaObject::connectSlotsByName(ModelWidget);
    } // setupUi

    void retranslateUi(QWidget *ModelWidget)
    {
        ModelWidget->setWindowTitle(QCoreApplication::translate("ModelWidget", "ModelWidget", nullptr));
        btnWindow->setText(QCoreApplication::translate("ModelWidget", "\345\274\271\345\207\272\347\252\227\345\217\243\346\250\241\346\200\201\345\257\271\350\257\235\346\241\206", nullptr));
        btnApp->setText(QCoreApplication::translate("ModelWidget", "\345\274\271\345\207\272\345\272\224\347\224\250\346\250\241\346\200\201\345\257\271\350\257\235\346\241\206", nullptr));
        btnCustom->setText(QCoreApplication::translate("ModelWidget", "\345\274\271\345\207\272\350\207\252\345\256\232\344\271\211\345\257\271\350\257\235\346\241\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelWidget: public Ui_ModelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELWIDGET_H
