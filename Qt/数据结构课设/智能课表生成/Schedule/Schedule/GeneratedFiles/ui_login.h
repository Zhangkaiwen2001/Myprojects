/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScheduleClass
{
public:
    QWidget *centralWidget;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *loginBtn;
    QComboBox *powerBox;
    QLabel *label_3;

    void setupUi(QMainWindow *ScheduleClass)
    {
        if (ScheduleClass->objectName().isEmpty())
            ScheduleClass->setObjectName(QStringLiteral("ScheduleClass"));
        ScheduleClass->resize(350, 230);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Schedule/Resources/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ScheduleClass->setWindowIcon(icon);
        ScheduleClass->setAutoFillBackground(false);
        centralWidget = new QWidget(ScheduleClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(true);
        username = new QLineEdit(centralWidget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(100, 70, 181, 21));
        username->setMaxLength(12);
        username->setCursorMoveStyle(Qt::LogicalMoveStyle);
        username->setClearButtonEnabled(true);
        password = new QLineEdit(centralWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(102, 120, 181, 20));
        password->setMaxLength(16);
        password->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 54, 21));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 120, 54, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        loginBtn = new QPushButton(centralWidget);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(200, 170, 80, 31));
        loginBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        powerBox = new QComboBox(centralWidget);
        powerBox->setObjectName(QStringLiteral("powerBox"));
        powerBox->setGeometry(QRect(100, 170, 70, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 170, 54, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        ScheduleClass->setCentralWidget(centralWidget);

        retranslateUi(ScheduleClass);

        QMetaObject::connectSlotsByName(ScheduleClass);
    } // setupUi

    void retranslateUi(QMainWindow *ScheduleClass)
    {
        ScheduleClass->setWindowTitle(QApplication::translate("ScheduleClass", "\350\257\276\350\241\250\347\263\273\347\273\237\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("ScheduleClass", "\350\264\246\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("ScheduleClass", "\345\257\206\347\240\201\357\274\232", 0));
        loginBtn->setText(QApplication::translate("ScheduleClass", "\347\231\273\345\275\225", 0));
        powerBox->clear();
        powerBox->insertItems(0, QStringList()
         << QApplication::translate("ScheduleClass", "\345\255\246\347\224\237", 0)
         << QApplication::translate("ScheduleClass", "\350\200\201\345\270\210", 0)
         << QApplication::translate("ScheduleClass", "\346\225\231\345\255\246\347\247\230\344\271\246", 0)
        );
        label_3->setText(QApplication::translate("ScheduleClass", "\350\272\253\344\273\275\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ScheduleClass: public Ui_ScheduleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
