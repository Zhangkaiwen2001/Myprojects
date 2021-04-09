/********************************************************************************
** Form generated from reading UI file 'dsdesign.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSDESIGN_H
#define UI_DSDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DSDesign
{
public:
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab_input;
    QLabel *label_6;
    QLineEdit *line_classnum;
    QLabel *label_7;
    QLineEdit *line_over_1;
    QLabel *label_8;
    QLineEdit *line_CTimes;
    QPushButton *btn_classnum;
    QPushButton *btn_over;
    QPushButton *btn_toltimes;
    QLineEdit *line_over_2;
    QLineEdit *line_over_3;
    QLineEdit *line_over_4;
    QLabel *label_9;
    QLineEdit *line_delete;
    QPushButton *btn_delete;
    QTextBrowser *textBrowser_inT;
    QLabel *label_10;
    QTextBrowser *textBrowser_cN;
    QTextBrowser *textBrowser_Cno;
    QTextBrowser *textBrowser_cP;
    QTextBrowser *textBrowser_cT;
    QPushButton *btn_sort;
    QWidget *tab_present;
    QPushButton *btn_output;
    QLabel *label_2;
    QTextBrowser *textBrowser_2;
    QLabel *label_3;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_4;
    QLabel *label_4;
    QLabel *label_1;
    QTextBrowser *textBrowser_1;
    QWidget *tab;
    QLabel *label;
    QLineEdit *line_search;
    QPushButton *btn_search;
    QLabel *label_5;
    QLineEdit *line_change_1;
    QPushButton *btn_change;
    QLineEdit *line_change_2;
    QWidget *widget;

    void setupUi(QWidget *DSDesign)
    {
        if (DSDesign->objectName().isEmpty())
            DSDesign->setObjectName(QString::fromUtf8("DSDesign"));
        DSDesign->resize(1600, 900);
        DSDesign->setAutoFillBackground(true);
        verticalLayout_7 = new QVBoxLayout(DSDesign);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tabWidget = new QTabWidget(DSDesign);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(16);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_input = new QWidget();
        tab_input->setObjectName(QString::fromUtf8("tab_input"));
        label_6 = new QLabel(tab_input);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 170, 300, 50));
        line_classnum = new QLineEdit(tab_input);
        line_classnum->setObjectName(QString::fromUtf8("line_classnum"));
        line_classnum->setGeometry(QRect(100, 230, 300, 30));
        label_7 = new QLabel(tab_input);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 300, 500, 50));
        line_over_1 = new QLineEdit(tab_input);
        line_over_1->setObjectName(QString::fromUtf8("line_over_1"));
        line_over_1->setGeometry(QRect(100, 360, 35, 30));
        label_8 = new QLabel(tab_input);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(100, 40, 500, 50));
        line_CTimes = new QLineEdit(tab_input);
        line_CTimes->setObjectName(QString::fromUtf8("line_CTimes"));
        line_CTimes->setGeometry(QRect(100, 100, 300, 30));
        btn_classnum = new QPushButton(tab_input);
        btn_classnum->setObjectName(QString::fromUtf8("btn_classnum"));
        btn_classnum->setGeometry(QRect(500, 230, 300, 30));
        btn_over = new QPushButton(tab_input);
        btn_over->setObjectName(QString::fromUtf8("btn_over"));
        btn_over->setGeometry(QRect(500, 360, 300, 30));
        btn_toltimes = new QPushButton(tab_input);
        btn_toltimes->setObjectName(QString::fromUtf8("btn_toltimes"));
        btn_toltimes->setGeometry(QRect(500, 100, 300, 30));
        line_over_2 = new QLineEdit(tab_input);
        line_over_2->setObjectName(QString::fromUtf8("line_over_2"));
        line_over_2->setGeometry(QRect(140, 360, 180, 30));
        line_over_3 = new QLineEdit(tab_input);
        line_over_3->setObjectName(QString::fromUtf8("line_over_3"));
        line_over_3->setGeometry(QRect(325, 360, 35, 30));
        line_over_4 = new QLineEdit(tab_input);
        line_over_4->setObjectName(QString::fromUtf8("line_over_4"));
        line_over_4->setGeometry(QRect(365, 360, 35, 31));
        label_9 = new QLabel(tab_input);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(100, 430, 500, 50));
        line_delete = new QLineEdit(tab_input);
        line_delete->setObjectName(QString::fromUtf8("line_delete"));
        line_delete->setGeometry(QRect(100, 490, 300, 30));
        btn_delete = new QPushButton(tab_input);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));
        btn_delete->setGeometry(QRect(500, 490, 300, 30));
        textBrowser_inT = new QTextBrowser(tab_input);
        textBrowser_inT->setObjectName(QString::fromUtf8("textBrowser_inT"));
        textBrowser_inT->setGeometry(QRect(840, 80, 50, 441));
        label_10 = new QLabel(tab_input);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(840, 20, 701, 50));
        QFont font1;
        font1.setPointSize(12);
        label_10->setFont(font1);
        textBrowser_cN = new QTextBrowser(tab_input);
        textBrowser_cN->setObjectName(QString::fromUtf8("textBrowser_cN"));
        textBrowser_cN->setGeometry(QRect(900, 80, 460, 441));
        textBrowser_Cno = new QTextBrowser(tab_input);
        textBrowser_Cno->setObjectName(QString::fromUtf8("textBrowser_Cno"));
        textBrowser_Cno->setGeometry(QRect(1370, 80, 50, 441));
        textBrowser_cP = new QTextBrowser(tab_input);
        textBrowser_cP->setObjectName(QString::fromUtf8("textBrowser_cP"));
        textBrowser_cP->setGeometry(QRect(1430, 80, 50, 441));
        textBrowser_cT = new QTextBrowser(tab_input);
        textBrowser_cT->setObjectName(QString::fromUtf8("textBrowser_cT"));
        textBrowser_cT->setGeometry(QRect(1500, 80, 50, 441));
        btn_sort = new QPushButton(tab_input);
        btn_sort->setObjectName(QString::fromUtf8("btn_sort"));
        btn_sort->setGeometry(QRect(290, 580, 320, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font2.setPointSize(20);
        btn_sort->setFont(font2);
        tabWidget->addTab(tab_input, QString());
        tab_present = new QWidget();
        tab_present->setObjectName(QString::fromUtf8("tab_present"));
        btn_output = new QPushButton(tab_present);
        btn_output->setObjectName(QString::fromUtf8("btn_output"));
        btn_output->setGeometry(QRect(490, 780, 320, 50));
        btn_output->setFont(font2);
        label_2 = new QLabel(tab_present);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 16, 122, 27));
        label_2->setFont(font2);
        textBrowser_2 = new QTextBrowser(tab_present);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(340, 70, 300, 700));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(20);
        textBrowser_2->setFont(font3);
        label_3 = new QLabel(tab_present);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(690, 16, 122, 27));
        label_3->setFont(font2);
        textBrowser_3 = new QTextBrowser(tab_present);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(660, 70, 300, 700));
        textBrowser_3->setFont(font3);
        textBrowser_4 = new QTextBrowser(tab_present);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(980, 70, 300, 700));
        textBrowser_4->setFont(font3);
        label_4 = new QLabel(tab_present);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1020, 16, 136, 27));
        label_4->setFont(font2);
        label_1 = new QLabel(tab_present);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(50, 16, 122, 27));
        label_1->setFont(font2);
        textBrowser_1 = new QTextBrowser(tab_present);
        textBrowser_1->setObjectName(QString::fromUtf8("textBrowser_1"));
        textBrowser_1->setGeometry(QRect(20, 70, 300, 700));
        textBrowser_1->setFont(font3);
        textBrowser_1->setAutoFillBackground(true);
        tabWidget->addTab(tab_present, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 80, 400, 50));
        line_search = new QLineEdit(tab);
        line_search->setObjectName(QString::fromUtf8("line_search"));
        line_search->setGeometry(QRect(180, 140, 200, 30));
        btn_search = new QPushButton(tab);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setGeometry(QRect(480, 140, 100, 30));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 230, 400, 50));
        line_change_1 = new QLineEdit(tab);
        line_change_1->setObjectName(QString::fromUtf8("line_change_1"));
        line_change_1->setGeometry(QRect(180, 290, 200, 30));
        btn_change = new QPushButton(tab);
        btn_change->setObjectName(QString::fromUtf8("btn_change"));
        btn_change->setGeometry(QRect(480, 290, 100, 30));
        line_change_2 = new QLineEdit(tab);
        line_change_2->setObjectName(QString::fromUtf8("line_change_2"));
        line_change_2->setGeometry(QRect(180, 330, 200, 30));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(630, 120, 871, 381));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-image: url(:/background1.png);"));
        tabWidget->addTab(tab, QString());

        verticalLayout_7->addWidget(tabWidget);


        retranslateUi(DSDesign);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DSDesign);
    } // setupUi

    void retranslateUi(QWidget *DSDesign)
    {
        DSDesign->setWindowTitle(QCoreApplication::translate("DSDesign", "DSDesign", nullptr));
        label_6->setText(QCoreApplication::translate("DSDesign", "\350\257\267\350\276\223\345\205\245\350\246\201\350\276\223\345\205\245\350\257\276\347\250\213\346\200\273\346\225\260\357\274\232", nullptr));
        line_classnum->setText(QString());
        label_7->setText(QCoreApplication::translate("DSDesign", "\350\257\267\350\276\223\345\205\245\350\257\276\347\250\213\345\272\217\345\217\267\343\200\201\350\257\276\347\250\213\345\220\215\343\200\201\350\257\276\347\250\213\345\211\215\345\272\217\343\200\201\350\257\276\346\227\266\357\274\232", nullptr));
        line_over_1->setText(QString());
        label_8->setText(QCoreApplication::translate("DSDesign", "\350\257\267\350\276\223\345\205\245\345\255\246\346\234\237\346\200\273\345\255\246\346\227\266\357\274\210\350\246\201\345\244\247\344\272\216\345\215\225\344\270\252\350\257\276\347\250\213\345\255\246\346\227\266\357\274\211\357\274\232", nullptr));
        line_CTimes->setText(QString());
        btn_classnum->setText(QCoreApplication::translate("DSDesign", "\350\257\276\347\250\213\350\276\223\345\205\245\346\225\260\347\273\223\346\235\237", nullptr));
        btn_over->setText(QCoreApplication::translate("DSDesign", "  \350\257\276\347\250\213\344\277\241\346\201\257\350\276\223\345\205\245\347\273\223\346\235\237", nullptr));
        btn_toltimes->setText(QCoreApplication::translate("DSDesign", "\345\255\246\346\234\237\345\255\246\346\227\266\350\276\223\345\205\245\347\273\223\346\235\237", nullptr));
        label_9->setText(QCoreApplication::translate("DSDesign", "\350\257\267\350\276\223\345\205\245\351\234\200\350\246\201\345\210\240\351\231\244\347\232\204\350\276\223\345\205\245\346\235\241\347\233\256\345\272\217\345\217\267\357\274\232", nullptr));
        line_delete->setText(QString());
        btn_delete->setText(QCoreApplication::translate("DSDesign", " \345\210\240\351\231\244\345\271\266\345\261\225\347\244\272", nullptr));
        label_10->setText(QCoreApplication::translate("DSDesign", "\350\276\223\345\205\245\345\272\217\345\217\267                        \350\257\276\347\250\213\345\220\215                         \350\257\276\347\250\213\345\272\217\345\217\267  \350\257\276\347\250\213\345\211\215\345\272\217  \350\257\276\346\227\266\357\274\232", nullptr));
        btn_sort->setText(QCoreApplication::translate("DSDesign", "\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_input), QCoreApplication::translate("DSDesign", "\350\276\223\345\205\245\347\225\214\351\235\242 ", nullptr));
        btn_output->setText(QCoreApplication::translate("DSDesign", "\350\276\223\345\207\272\350\257\276\350\241\250", nullptr));
        label_2->setText(QCoreApplication::translate("DSDesign", " \347\254\254\344\272\214\345\255\246\345\271\264", nullptr));
        label_3->setText(QCoreApplication::translate("DSDesign", " \347\254\254\344\270\211\345\255\246\345\271\264", nullptr));
        label_4->setText(QCoreApplication::translate("DSDesign", "  \347\254\254\345\233\233\345\255\246\345\271\264", nullptr));
        label_1->setText(QCoreApplication::translate("DSDesign", " \347\254\254\344\270\200\345\255\246\345\271\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_present), QCoreApplication::translate("DSDesign", "\345\261\225\347\244\272\347\225\214\351\235\242 ", nullptr));
        label->setText(QCoreApplication::translate("DSDesign", "\350\257\267\350\276\223\345\205\245\346\202\250\346\203\263\346\237\245\346\211\276\347\232\204\350\257\276\347\250\213\357\274\232", nullptr));
        btn_search->setText(QCoreApplication::translate("DSDesign", "\346\237\245\346\211\276", nullptr));
        label_5->setText(QCoreApplication::translate("DSDesign", "\350\257\267\350\276\223\345\205\245\346\202\250\346\203\263\344\277\256\346\224\271\347\232\204\350\257\276\347\250\213\357\274\232", nullptr));
        line_change_1->setText(QCoreApplication::translate("DSDesign", "\345\216\237\345\220\215\347\247\260", nullptr));
        btn_change->setText(QCoreApplication::translate("DSDesign", "\344\277\256\346\224\271", nullptr));
        line_change_2->setText(QCoreApplication::translate("DSDesign", "\344\277\256\346\224\271\345\220\215\347\247\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DSDesign", "\347\273\264\346\212\244\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DSDesign: public Ui_DSDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSDESIGN_H
