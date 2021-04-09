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
#include <QtWidgets/QLineEdit>
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
    QPushButton *btn_getitem;
    QPushButton *btn_gettext;
    QPushButton *btn_getmtext;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *tab_2;
    QWidget *widget;
    QPushButton *btn_getcolor;
    QLabel *label_color;
    QToolButton *check_alpha;
    QWidget *tab_3;
    QPushButton *btn_font;
    QLabel *label_font;
    QWidget *tab_4;
    QLineEdit *line_path;
    QPushButton *btn_dir;
    QPushButton *btn_file;
    QPushButton *btn_files;
    QPushButton *btn_savefile;
    QWidget *tab_5;
    QPushButton *btn_critical;
    QPushButton *btn_info;
    QPushButton *btn_question;
    QPushButton *btn_warning;
    QPushButton *btn_message;
    QWidget *tab_6;
    QPushButton *btn_progress;
    QWidget *tab_7;
    QPushButton *btn_wizard;

    void setupUi(QWidget *StandardDialogs)
    {
        if (StandardDialogs->objectName().isEmpty())
            StandardDialogs->setObjectName(QString::fromUtf8("StandardDialogs"));
        StandardDialogs->resize(800, 600);
        tabWidget = new QTabWidget(StandardDialogs);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 40, 741, 451));
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
        btn_getitem = new QPushButton(frame);
        btn_getitem->setObjectName(QString::fromUtf8("btn_getitem"));
        btn_getitem->setGeometry(QRect(50, 120, 100, 25));
        btn_gettext = new QPushButton(frame);
        btn_gettext->setObjectName(QString::fromUtf8("btn_gettext"));
        btn_gettext->setGeometry(QRect(50, 160, 100, 25));
        btn_getmtext = new QPushButton(frame);
        btn_getmtext->setObjectName(QString::fromUtf8("btn_getmtext"));
        btn_getmtext->setGeometry(QRect(50, 200, 100, 25));
        label_1 = new QLabel(frame);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(200, 40, 100, 25));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 80, 100, 25));
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
        widget = new QWidget(tab_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 40, 621, 341));
        btn_getcolor = new QPushButton(widget);
        btn_getcolor->setObjectName(QString::fromUtf8("btn_getcolor"));
        btn_getcolor->setGeometry(QRect(30, 20, 150, 100));
        label_color = new QLabel(widget);
        label_color->setObjectName(QString::fromUtf8("label_color"));
        label_color->setGeometry(QRect(80, 140, 100, 20));
        check_alpha = new QToolButton(widget);
        check_alpha->setObjectName(QString::fromUtf8("check_alpha"));
        check_alpha->setGeometry(QRect(40, 140, 20, 20));
        check_alpha->setCheckable(true);
        check_alpha->setChecked(false);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        btn_font = new QPushButton(tab_3);
        btn_font->setObjectName(QString::fromUtf8("btn_font"));
        btn_font->setGeometry(QRect(90, 80, 100, 25));
        label_font = new QLabel(tab_3);
        label_font->setObjectName(QString::fromUtf8("label_font"));
        label_font->setGeometry(QRect(270, 120, 60, 20));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        line_path = new QLineEdit(tab_4);
        line_path->setObjectName(QString::fromUtf8("line_path"));
        line_path->setGeometry(QRect(140, 60, 150, 25));
        btn_dir = new QPushButton(tab_4);
        btn_dir->setObjectName(QString::fromUtf8("btn_dir"));
        btn_dir->setGeometry(QRect(400, 60, 200, 25));
        btn_file = new QPushButton(tab_4);
        btn_file->setObjectName(QString::fromUtf8("btn_file"));
        btn_file->setGeometry(QRect(400, 100, 200, 25));
        btn_files = new QPushButton(tab_4);
        btn_files->setObjectName(QString::fromUtf8("btn_files"));
        btn_files->setGeometry(QRect(400, 140, 200, 25));
        btn_savefile = new QPushButton(tab_4);
        btn_savefile->setObjectName(QString::fromUtf8("btn_savefile"));
        btn_savefile->setGeometry(QRect(400, 180, 200, 25));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        btn_critical = new QPushButton(tab_5);
        btn_critical->setObjectName(QString::fromUtf8("btn_critical"));
        btn_critical->setGeometry(QRect(80, 60, 100, 30));
        btn_info = new QPushButton(tab_5);
        btn_info->setObjectName(QString::fromUtf8("btn_info"));
        btn_info->setGeometry(QRect(80, 120, 100, 30));
        btn_question = new QPushButton(tab_5);
        btn_question->setObjectName(QString::fromUtf8("btn_question"));
        btn_question->setGeometry(QRect(80, 180, 100, 30));
        btn_warning = new QPushButton(tab_5);
        btn_warning->setObjectName(QString::fromUtf8("btn_warning"));
        btn_warning->setGeometry(QRect(300, 60, 100, 30));
        btn_message = new QPushButton(tab_5);
        btn_message->setObjectName(QString::fromUtf8("btn_message"));
        btn_message->setGeometry(QRect(300, 120, 100, 30));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        btn_progress = new QPushButton(tab_6);
        btn_progress->setObjectName(QString::fromUtf8("btn_progress"));
        btn_progress->setGeometry(QRect(140, 110, 75, 30));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        btn_wizard = new QPushButton(tab_7);
        btn_wizard->setObjectName(QString::fromUtf8("btn_wizard"));
        btn_wizard->setGeometry(QRect(200, 150, 75, 30));
        tabWidget->addTab(tab_7, QString());

        retranslateUi(StandardDialogs);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(StandardDialogs);
    } // setupUi

    void retranslateUi(QWidget *StandardDialogs)
    {
        StandardDialogs->setWindowTitle(QCoreApplication::translate("StandardDialogs", "StandardDialogs", nullptr));
        btn_getint->setText(QCoreApplication::translate("StandardDialogs", " getInt()", nullptr));
        btn_getdouble->setText(QCoreApplication::translate("StandardDialogs", "getDouble()", nullptr));
        btn_getitem->setText(QCoreApplication::translate("StandardDialogs", "getItem", nullptr));
        btn_gettext->setText(QCoreApplication::translate("StandardDialogs", "getText()", nullptr));
        btn_getmtext->setText(QCoreApplication::translate("StandardDialogs", "getMultiText()", nullptr));
        label_1->setText(QCoreApplication::translate("StandardDialogs", "int", nullptr));
        label_2->setText(QCoreApplication::translate("StandardDialogs", "double", nullptr));
        label_3->setText(QCoreApplication::translate("StandardDialogs", "item", nullptr));
        label_4->setText(QCoreApplication::translate("StandardDialogs", "text", nullptr));
        label_5->setText(QCoreApplication::translate("StandardDialogs", "multitext", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("StandardDialogs", "\350\276\223\345\205\245\345\257\271\350\257\235\346\241\206 ", nullptr));
        btn_getcolor->setText(QCoreApplication::translate("StandardDialogs", "getColor", nullptr));
        label_color->setText(QCoreApplication::translate("StandardDialogs", "\346\230\257\345\220\246\346\230\276\347\244\272\351\200\217\346\230\216\345\272\246", nullptr));
        check_alpha->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("StandardDialogs", "\351\242\234\350\211\262\345\257\271\350\257\235\346\241\206 ", nullptr));
        btn_font->setText(QCoreApplication::translate("StandardDialogs", "getFont()", nullptr));
        label_font->setText(QCoreApplication::translate("StandardDialogs", " \344\275\240\345\245\275,Qt", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("StandardDialogs", "\345\255\227\344\275\223\345\257\271\350\257\235\346\241\206 ", nullptr));
        btn_dir->setText(QCoreApplication::translate("StandardDialogs", "getExistingDirectory()", nullptr));
        btn_file->setText(QCoreApplication::translate("StandardDialogs", "getOpenFileName()", nullptr));
        btn_files->setText(QCoreApplication::translate("StandardDialogs", "getOpenFileNames()", nullptr));
        btn_savefile->setText(QCoreApplication::translate("StandardDialogs", "getSaveFilenames()", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("StandardDialogs", "\346\226\207\344\273\266\345\257\271\350\257\235\346\241\206 ", nullptr));
        btn_critical->setText(QCoreApplication::translate("StandardDialogs", "critical()", nullptr));
        btn_info->setText(QCoreApplication::translate("StandardDialogs", "information()", nullptr));
        btn_question->setText(QCoreApplication::translate("StandardDialogs", "question()", nullptr));
        btn_warning->setText(QCoreApplication::translate("StandardDialogs", "warning()", nullptr));
        btn_message->setText(QCoreApplication::translate("StandardDialogs", "showMessage()", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("StandardDialogs", "\346\266\210\346\201\257\345\257\271\350\257\235\346\241\206 ", nullptr));
        btn_progress->setText(QCoreApplication::translate("StandardDialogs", "  \350\277\233\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("StandardDialogs", "\350\277\233\345\272\246\345\257\271\350\257\235\346\241\206 ", nullptr));
        btn_wizard->setText(QCoreApplication::translate("StandardDialogs", " \345\274\271\345\207\272\345\220\221\345\257\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("StandardDialogs", "\345\220\221\345\257\274\345\257\271\350\257\235\346\241\206 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StandardDialogs: public Ui_StandardDialogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STANDARDDIALOGS_H
