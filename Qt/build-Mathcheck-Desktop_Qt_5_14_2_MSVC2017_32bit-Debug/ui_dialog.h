/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pbt_close;
    QLabel *label_1;
    QPushButton *pbt_start;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        pbt_close = new QPushButton(Dialog);
        pbt_close->setObjectName(QString::fromUtf8("pbt_close"));
        pbt_close->setGeometry(QRect(759, 0, 41, 41));
        pbt_close->setMinimumSize(QSize(4, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/material/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbt_close->setIcon(icon);
        pbt_close->setIconSize(QSize(40, 40));
        pbt_close->setFlat(true);
        label_1 = new QLabel(Dialog);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(290, 170, 301, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label_1->setFont(font);
        pbt_start = new QPushButton(Dialog);
        pbt_start->setObjectName(QString::fromUtf8("pbt_start"));
        pbt_start->setGeometry(QRect(340, 520, 171, 41));
        pbt_start->setStyleSheet(QString::fromUtf8("font: 28pt \"Arial\";\n"
""));
        pbt_start->setFlat(true);

        retranslateUi(Dialog);

        pbt_close->setDefault(true);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pbt_close->setText(QString());
        label_1->setText(QCoreApplication::translate("Dialog", "\345\260\217\345\255\246\346\225\260\345\255\246\346\265\213\350\257\225\350\275\257\344\273\266", nullptr));
        pbt_start->setText(QCoreApplication::translate("Dialog", "\345\274\200\345\247\213\346\265\213\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
