/********************************************************************************
** Form generated from reading UI file 'teacher.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_H
#define UI_TEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teacher
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QTableWidget *timetable;
    QLabel *label_2;
    QComboBox *comboBox;
    QWidget *tab_2;
    QTableWidget *tableWidget;
    QComboBox *courseBox;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *dayBox1;
    QComboBox *timeBox1;
    QComboBox *dayBox2;
    QComboBox *dayBox3;
    QComboBox *timeBox3;
    QComboBox *timeBox2;
    QLabel *label_7;
    QComboBox *classBox1;
    QComboBox *classBox2;
    QComboBox *classBox3;
    QPushButton *apply;
    QPushButton *DelReqBtn;
    QPushButton *clearReqBtn;

    void setupUi(QMainWindow *teacher)
    {
        if (teacher->objectName().isEmpty())
            teacher->setObjectName(QStringLiteral("teacher"));
        teacher->resize(600, 450);
        teacher->setMinimumSize(QSize(600, 450));
        teacher->setMaximumSize(QSize(600, 450));
        centralWidget = new QWidget(teacher);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(600, 450));
        centralWidget->setMaximumSize(QSize(600, 450));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(6, 9, 591, 441));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        timetable = new QTableWidget(tab_3);
        if (timetable->columnCount() < 5)
            timetable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        timetable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        timetable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        timetable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        timetable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        timetable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (timetable->rowCount() < 4)
            timetable->setRowCount(4);
        timetable->setObjectName(QStringLiteral("timetable"));
        timetable->setGeometry(QRect(10, 10, 561, 251));
        timetable->setContextMenuPolicy(Qt::CustomContextMenu);
        timetable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        timetable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        timetable->setAutoScroll(true);
        timetable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        timetable->setSelectionMode(QAbstractItemView::NoSelection);
        timetable->setGridStyle(Qt::DashDotDotLine);
        timetable->setWordWrap(false);
        timetable->setRowCount(4);
        timetable->setColumnCount(5);
        timetable->horizontalHeader()->setVisible(false);
        timetable->horizontalHeader()->setMinimumSectionSize(25);
        timetable->verticalHeader()->setVisible(false);
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 290, 54, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        comboBox = new QComboBox(tab_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(240, 290, 69, 22));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem14);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(5, 11, 571, 171));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setRowCount(10);
        tableWidget->setColumnCount(10);
        tableWidget->verticalHeader()->setVisible(false);
        courseBox = new QComboBox(tab_2);
        courseBox->setObjectName(QStringLiteral("courseBox"));
        courseBox->setGeometry(QRect(100, 200, 191, 22));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 202, 54, 20));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 260, 54, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 310, 54, 20));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        dayBox1 = new QComboBox(tab_2);
        dayBox1->setObjectName(QStringLiteral("dayBox1"));
        dayBox1->setGeometry(QRect(100, 260, 69, 22));
        timeBox1 = new QComboBox(tab_2);
        timeBox1->setObjectName(QStringLiteral("timeBox1"));
        timeBox1->setGeometry(QRect(100, 310, 69, 22));
        dayBox2 = new QComboBox(tab_2);
        dayBox2->setObjectName(QStringLiteral("dayBox2"));
        dayBox2->setGeometry(QRect(220, 260, 69, 22));
        dayBox3 = new QComboBox(tab_2);
        dayBox3->setObjectName(QStringLiteral("dayBox3"));
        dayBox3->setGeometry(QRect(330, 260, 69, 22));
        timeBox3 = new QComboBox(tab_2);
        timeBox3->setObjectName(QStringLiteral("timeBox3"));
        timeBox3->setGeometry(QRect(330, 310, 69, 22));
        timeBox2 = new QComboBox(tab_2);
        timeBox2->setObjectName(QStringLiteral("timeBox2"));
        timeBox2->setGeometry(QRect(220, 310, 69, 22));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 360, 54, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        classBox1 = new QComboBox(tab_2);
        classBox1->setObjectName(QStringLiteral("classBox1"));
        classBox1->setGeometry(QRect(100, 360, 69, 22));
        classBox2 = new QComboBox(tab_2);
        classBox2->setObjectName(QStringLiteral("classBox2"));
        classBox2->setGeometry(QRect(220, 360, 69, 22));
        classBox3 = new QComboBox(tab_2);
        classBox3->setObjectName(QStringLiteral("classBox3"));
        classBox3->setGeometry(QRect(330, 360, 69, 22));
        apply = new QPushButton(tab_2);
        apply->setObjectName(QStringLiteral("apply"));
        apply->setGeometry(QRect(450, 352, 75, 31));
        apply->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        DelReqBtn = new QPushButton(tab_2);
        DelReqBtn->setObjectName(QStringLiteral("DelReqBtn"));
        DelReqBtn->setGeometry(QRect(450, 292, 75, 31));
        DelReqBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        clearReqBtn = new QPushButton(tab_2);
        clearReqBtn->setObjectName(QStringLiteral("clearReqBtn"));
        clearReqBtn->setGeometry(QRect(450, 232, 75, 31));
        clearReqBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        tabWidget->addTab(tab_2, QString());
        teacher->setCentralWidget(centralWidget);

        retranslateUi(teacher);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(teacher);
    } // setupUi

    void retranslateUi(QMainWindow *teacher)
    {
        teacher->setWindowTitle(QApplication::translate("teacher", "teacher", 0));
        QTableWidgetItem *___qtablewidgetitem = timetable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("teacher", "\346\230\237\346\234\237\344\270\200", 0));
        QTableWidgetItem *___qtablewidgetitem1 = timetable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("teacher", "\346\230\237\346\234\237\344\272\214", 0));
        QTableWidgetItem *___qtablewidgetitem2 = timetable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("teacher", "\346\230\237\346\234\237\344\270\211", 0));
        QTableWidgetItem *___qtablewidgetitem3 = timetable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("teacher", "\346\230\237\346\234\237\345\233\233", 0));
        QTableWidgetItem *___qtablewidgetitem4 = timetable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("teacher", "\346\230\237\346\234\237\344\272\224", 0));
        label_2->setText(QApplication::translate("teacher", "\345\221\250\346\225\260\357\274\232", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("teacher", "\346\227\240", 0)
         << QApplication::translate("teacher", "1", 0)
         << QApplication::translate("teacher", "2", 0)
         << QApplication::translate("teacher", "3", 0)
         << QApplication::translate("teacher", "4", 0)
         << QApplication::translate("teacher", "5", 0)
         << QApplication::translate("teacher", "6", 0)
         << QApplication::translate("teacher", "7", 0)
         << QApplication::translate("teacher", "8", 0)
         << QApplication::translate("teacher", "9", 0)
         << QApplication::translate("teacher", "10", 0)
         << QApplication::translate("teacher", "11", 0)
         << QApplication::translate("teacher", "12", 0)
         << QApplication::translate("teacher", "13", 0)
         << QApplication::translate("teacher", "14", 0)
         << QApplication::translate("teacher", "15", 0)
         << QApplication::translate("teacher", "16", 0)
         << QApplication::translate("teacher", "17", 0)
         << QApplication::translate("teacher", "18", 0)
         << QApplication::translate("teacher", "19", 0)
         << QApplication::translate("teacher", "20", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("teacher", "\350\257\276\350\241\250\346\237\245\350\257\242", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("teacher", "\350\257\276\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("teacher", "1.\346\230\237\346\234\237\345\207\240", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("teacher", "1.\345\244\247\350\212\202", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("teacher", "1.\346\225\231\345\256\244", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("teacher", "2.\346\230\237\346\234\237\345\207\240", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("teacher", "2.\345\244\247\350\212\202", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("teacher", "2.\346\225\231\345\256\244", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem12->setText(QApplication::translate("teacher", "3.\346\230\237\346\234\237\345\207\240", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem13->setText(QApplication::translate("teacher", "3.\345\244\247\350\212\202", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem14->setText(QApplication::translate("teacher", "3.\346\225\231\345\256\244", 0));
        label->setText(QApplication::translate("teacher", "\350\257\276\347\250\213\357\274\232", 0));
        label_5->setText(QApplication::translate("teacher", "\346\230\237\346\234\237\357\274\232", 0));
        label_6->setText(QApplication::translate("teacher", "\345\244\247\350\212\202\357\274\232", 0));
        label_7->setText(QApplication::translate("teacher", "\346\225\231\345\256\244\357\274\232", 0));
        apply->setText(QApplication::translate("teacher", "\347\224\263\350\257\267", 0));
        DelReqBtn->setText(QApplication::translate("teacher", "\345\210\240\351\231\244", 0));
        clearReqBtn->setText(QApplication::translate("teacher", "\346\270\205\347\251\272", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("teacher", "\344\273\243\350\257\276\350\246\201\346\261\202", 0));
    } // retranslateUi

};

namespace Ui {
    class teacher: public Ui_teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_H
