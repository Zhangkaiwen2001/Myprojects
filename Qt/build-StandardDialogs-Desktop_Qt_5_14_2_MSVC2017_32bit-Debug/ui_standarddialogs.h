/********************************************************************************
** Form generated from reading UI file 'standarddialogs.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STANDARDDIALOGS_H
#define UI_STANDARDDIALOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StandardDialogs
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame;
    QPushButton *btn_getint;
    QPushButton *btn_getdouble;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_input;
    QLabel *label_input_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *tab_2;
    QPushButton *pushButton_6;
    QToolButton *toolButton;
    QLabel *label_6;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_7;

    void setupUi(QWidget *StandardDialogs)
    {
        if (StandardDialogs->objectName().isEmpty())
            StandardDialogs->setObjectName(QString::fromUtf8("StandardDialogs"));
        StandardDialogs->resize(800, 600);
        tabWidget = new QTabWidget(StandardDialogs);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 741, 451));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(9, 19, 711, 391));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btn_getint = new QPushButton(frame);
        btn_getint->setObjectName(QString::fromUtf8("btn_getint"));
        btn_getint->setGeometry(QRect(50, 40, 100, 25));
        btn_getint->setCheckable(true);
        btn_getdouble = new QPushButton(frame);
        btn_getdouble->setObjectName(QString::fromUtf8("btn_getdouble"));
        btn_getdouble->setGeometry(QRect(50, 80, 100, 25));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 120, 100, 25));
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 160, 100, 25));
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(50, 200, 100, 25));
        label_input = new QLabel(frame);
        label_input->setObjectName(QString::fromUtf8("label_input"));
        label_input->setGeometry(QRect(200, 40, 100, 25));
        label_input_2 = new QLabel(frame);
        label_input_2->setObjectName(QString::fromUtf8("label_input_2"));
        label_input_2->setGeometry(QRect(200, 80, 100, 25));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 120, 100, 25));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 160, 100, 25));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 200, 100, 25));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(130, 70, 150, 100));
        toolButton = new QToolButton(tab_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(130, 180, 20, 20));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(160, 180, 100, 20));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabWidget->addTab(tab_7, QString());

        retranslateUi(StandardDialogs);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StandardDialogs);
    } // setupUi

    void retranslateUi(QWidget *StandardDialogs)
    {
        StandardDialogs->setWindowTitle(QCoreApplication::translate("StandardDialogs", "StandardDialogs", nullptr));
        btn_getint->setText(QCoreApplication::translate("StandardDialogs", " getInt()", nullptr));
        btn_getdouble->setText(QCoreApplication::translate("StandardDialogs", "getDouble()", nullptr));
        pushButton_3->setText(QCoreApplication::translate("StandardDialogs", "getItem", nullptr));
        pushButton_4->setText(QCoreApplication::translate("StandardDialogs", "getText()", nullptr));
        pushButton_5->setText(QCoreApplication::translate("StandardDialogs", "getMultiText()", nullptr));
        label_input->setText(QCoreApplication::translate("StandardDialogs", "1", nullptr));
        label_input_2->setText(QCoreApplication::translate("StandardDialogs", "2", nullptr));
        label_3->setText(QCoreApplication::translate("StandardDialogs", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("StandardDialogs", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("StandardDialogs", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("StandardDialogs", "\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206 ", nullptr));
        pushButton_6->setText(QCoreApplication::translate("StandardDialogs", "getColor", nullptr));
        toolButton->setText(QCoreApplication::translate("StandardDialogs", "...", nullptr));
        label_6->setText(QCoreApplication::translate("StandardDialogs", "\346\230\257\345\220\246\346\230\276\347\244\272\351\200\217\346\230\216\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("StandardDialogs", "\351\242\234\350\211\262\345\257\271\350\257\235\346\241\206 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("StandardDialogs", "\345\255\227\344\275\223\345\257\271\350\257\235\346\241\206 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("StandardDialogs", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("StandardDialogs", "\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("StandardDialogs", "\350\277\233\345\272\246\345\257\271\350\257\235\346\241\206 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("StandardDialogs", "\345\220\221\345\257\274\345\257\271\350\257\235\346\241\206 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StandardDialogs: public Ui_StandardDialogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STANDARDDIALOGS_H
