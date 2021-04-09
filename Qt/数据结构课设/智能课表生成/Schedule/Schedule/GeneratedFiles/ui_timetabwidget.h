/********************************************************************************
** Form generated from reading UI file 'timetabwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABWIDGET_H
#define UI_TIMETABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timeTabWidget
{
public:
    QLabel *Courselab;
    QLabel *Weeklab;
    QLabel *Teacherlab;
    QLabel *Roomlab;

    void setupUi(QWidget *timeTabWidget)
    {
        if (timeTabWidget->objectName().isEmpty())
            timeTabWidget->setObjectName(QStringLiteral("timeTabWidget"));
        timeTabWidget->resize(109, 59);
        Courselab = new QLabel(timeTabWidget);
        Courselab->setObjectName(QStringLiteral("Courselab"));
        Courselab->setGeometry(QRect(0, 1, 110, 21));
        Courselab->setMinimumSize(QSize(70, 21));
        Courselab->setMaximumSize(QSize(110, 21));
        Courselab->setStyleSheet(QString::fromUtf8("font: 7pt \"\346\245\267\344\275\223\";"));
        Courselab->setTextFormat(Qt::AutoText);
        Courselab->setScaledContents(false);
        Courselab->setAlignment(Qt::AlignCenter);
        Courselab->setWordWrap(false);
        Weeklab = new QLabel(timeTabWidget);
        Weeklab->setObjectName(QStringLiteral("Weeklab"));
        Weeklab->setGeometry(QRect(10, 19, 41, 16));
        Weeklab->setMinimumSize(QSize(41, 16));
        Weeklab->setMaximumSize(QSize(41, 16));
        Weeklab->setStyleSheet(QString::fromUtf8("font: 8pt \"\346\245\267\344\275\223\";"));
        Weeklab->setTextFormat(Qt::PlainText);
        Weeklab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Teacherlab = new QLabel(timeTabWidget);
        Teacherlab->setObjectName(QStringLiteral("Teacherlab"));
        Teacherlab->setGeometry(QRect(60, 19, 41, 16));
        Teacherlab->setMinimumSize(QSize(41, 16));
        Teacherlab->setMaximumSize(QSize(41, 16));
        Teacherlab->setStyleSheet(QString::fromUtf8("font: 8pt \"\346\245\267\344\275\223\";"));
        Teacherlab->setTextFormat(Qt::PlainText);
        Teacherlab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Roomlab = new QLabel(timeTabWidget);
        Roomlab->setObjectName(QStringLiteral("Roomlab"));
        Roomlab->setGeometry(QRect(40, 37, 35, 16));
        Roomlab->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\245\267\344\275\223\";"));
        Roomlab->setAlignment(Qt::AlignCenter);

        retranslateUi(timeTabWidget);

        QMetaObject::connectSlotsByName(timeTabWidget);
    } // setupUi

    void retranslateUi(QWidget *timeTabWidget)
    {
        timeTabWidget->setWindowTitle(QApplication::translate("timeTabWidget", "timeTabWidget", 0));
        Courselab->setText(QApplication::translate("timeTabWidget", "\345\215\225\347\211\207\346\234\272\345\216\237\347\220\206\345\217\212\345\217\243\346\212\200\346\234\257", 0));
        Weeklab->setText(QApplication::translate("timeTabWidget", "0-20\345\221\250", 0));
        Teacherlab->setText(QApplication::translate("timeTabWidget", "\345\276\220\345\277\227\346\260\270", 0));
        Roomlab->setText(QApplication::translate("timeTabWidget", "15101", 0));
    } // retranslateUi

};

namespace Ui {
    class timeTabWidget: public Ui_timeTabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABWIDGET_H
