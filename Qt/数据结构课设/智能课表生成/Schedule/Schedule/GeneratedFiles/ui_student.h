/********************************************************************************
** Form generated from reading UI file 'student.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_H
#define UI_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_student
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QComboBox *weekBox;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *roomBox;

    void setupUi(QMainWindow *student)
    {
        if (student->objectName().isEmpty())
            student->setObjectName(QStringLiteral("student"));
        student->resize(600, 450);
        student->setMinimumSize(QSize(600, 450));
        student->setMaximumSize(QSize(600, 450));
        centralWidget = new QWidget(student);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 561, 251));
        tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAutoScroll(true);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setGridStyle(Qt::DashDotDotLine);
        tableWidget->setWordWrap(false);
        tableWidget->setRowCount(4);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(25);
        tableWidget->verticalHeader()->setVisible(false);
        weekBox = new QComboBox(centralWidget);
        weekBox->setObjectName(QStringLiteral("weekBox"));
        weekBox->setGeometry(QRect(170, 300, 69, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 300, 54, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 370, 54, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        roomBox = new QComboBox(centralWidget);
        roomBox->setObjectName(QStringLiteral("roomBox"));
        roomBox->setGeometry(QRect(170, 370, 69, 22));
        student->setCentralWidget(centralWidget);

        retranslateUi(student);

        QMetaObject::connectSlotsByName(student);
    } // setupUi

    void retranslateUi(QMainWindow *student)
    {
        student->setWindowTitle(QApplication::translate("student", "student", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("student", "\346\230\237\346\234\237\344\270\200", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("student", "\346\230\237\346\234\237\344\272\214", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("student", "\346\230\237\346\234\237\344\270\211", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("student", "\346\230\237\346\234\237\345\233\233", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("student", "\346\230\237\346\234\237\344\272\224", 0));
        weekBox->clear();
        weekBox->insertItems(0, QStringList()
         << QApplication::translate("student", "\346\227\240", 0)
         << QApplication::translate("student", "1", 0)
         << QApplication::translate("student", "2", 0)
         << QApplication::translate("student", "3", 0)
         << QApplication::translate("student", "4", 0)
         << QApplication::translate("student", "5", 0)
         << QApplication::translate("student", "6", 0)
         << QApplication::translate("student", "7", 0)
         << QApplication::translate("student", "8", 0)
         << QApplication::translate("student", "9", 0)
         << QApplication::translate("student", "10", 0)
         << QApplication::translate("student", "11", 0)
         << QApplication::translate("student", "12", 0)
         << QApplication::translate("student", "13", 0)
         << QApplication::translate("student", "14", 0)
         << QApplication::translate("student", "15", 0)
         << QApplication::translate("student", "16", 0)
         << QApplication::translate("student", "17", 0)
         << QApplication::translate("student", "18", 0)
         << QApplication::translate("student", "19", 0)
         << QApplication::translate("student", "20", 0)
        );
        label_2->setText(QApplication::translate("student", "\345\221\250\346\225\260\357\274\232", 0));
        label_3->setText(QApplication::translate("student", "\346\225\231\345\256\244\357\274\232", 0));
        roomBox->clear();
        roomBox->insertItems(0, QStringList()
         << QApplication::translate("student", "\346\227\240", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class student: public Ui_student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_H
