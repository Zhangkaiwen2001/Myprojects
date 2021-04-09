/********************************************************************************
** Form generated from reading UI file 'mysql_demo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSQL_DEMO_H
#define UI_MYSQL_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mysql_demo
{
public:
    QPushButton *btn_insert;
    QPushButton *btn_delete;
    QLineEdit *lineEdit;

    void setupUi(QWidget *mysql_demo)
    {
        if (mysql_demo->objectName().isEmpty())
            mysql_demo->setObjectName(QString::fromUtf8("mysql_demo"));
        mysql_demo->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        mysql_demo->setFont(font);
        btn_insert = new QPushButton(mysql_demo);
        btn_insert->setObjectName(QString::fromUtf8("btn_insert"));
        btn_insert->setGeometry(QRect(330, 230, 151, 71));
        btn_delete = new QPushButton(mysql_demo);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));
        btn_delete->setGeometry(QRect(330, 340, 151, 71));
        lineEdit = new QLineEdit(mysql_demo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 350, 181, 51));

        retranslateUi(mysql_demo);

        QMetaObject::connectSlotsByName(mysql_demo);
    } // setupUi

    void retranslateUi(QWidget *mysql_demo)
    {
        mysql_demo->setWindowTitle(QCoreApplication::translate("mysql_demo", "mysql_demo", nullptr));
        btn_insert->setText(QCoreApplication::translate("mysql_demo", "\346\217\222\345\205\245\346\225\260\346\215\256", nullptr));
        btn_delete->setText(QCoreApplication::translate("mysql_demo", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mysql_demo: public Ui_mysql_demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSQL_DEMO_H
