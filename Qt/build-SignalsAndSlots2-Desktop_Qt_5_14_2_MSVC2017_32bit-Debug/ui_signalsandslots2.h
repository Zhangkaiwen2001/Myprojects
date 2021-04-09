/********************************************************************************
** Form generated from reading UI file 'signalsandslots2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALSANDSLOTS2_H
#define UI_SIGNALSANDSLOTS2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignalsAndSlots2
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SignalsAndSlots2)
    {
        if (SignalsAndSlots2->objectName().isEmpty())
            SignalsAndSlots2->setObjectName(QString::fromUtf8("SignalsAndSlots2"));
        SignalsAndSlots2->resize(800, 600);
        centralwidget = new QWidget(SignalsAndSlots2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(220, 180, 118, 23));
        progressBar->setValue(24);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 180, 75, 23));
        pushButton->setCheckable(true);
        pushButton->setChecked(true);
        SignalsAndSlots2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SignalsAndSlots2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        SignalsAndSlots2->setMenuBar(menubar);
        statusbar = new QStatusBar(SignalsAndSlots2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SignalsAndSlots2->setStatusBar(statusbar);

        retranslateUi(SignalsAndSlots2);
        QObject::connect(pushButton, SIGNAL(toggled(bool)), progressBar, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(SignalsAndSlots2);
    } // setupUi

    void retranslateUi(QMainWindow *SignalsAndSlots2)
    {
        SignalsAndSlots2->setWindowTitle(QCoreApplication::translate("SignalsAndSlots2", "SignalsAndSlots2", nullptr));
        pushButton->setText(QCoreApplication::translate("SignalsAndSlots2", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignalsAndSlots2: public Ui_SignalsAndSlots2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALSANDSLOTS2_H
