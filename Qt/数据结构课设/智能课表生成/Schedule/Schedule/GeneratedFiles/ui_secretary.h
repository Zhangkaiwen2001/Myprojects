/********************************************************************************
** Form generated from reading UI file 'secretary.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECRETARY_H
#define UI_SECRETARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_secretary
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *TtableWidget;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QComboBox *TClassBox;
    QComboBox *TCourseBox;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *TAddBtn;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *TDelBtn;
    QPushButton *TClearBtn;
    QWidget *tab_2;
    QPushButton *CAddBtn;
    QLabel *label_13;
    QPushButton *CDelBtn;
    QLabel *label_14;
    QTableWidget *CtableWidget;
    QComboBox *CTeacherBox;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QComboBox *CCourseBox;
    QPushButton *CClearBtn;
    QComboBox *class1;
    QComboBox *class2;
    QComboBox *class3;
    QLabel *label_8;
    QFrame *line_2;
    QFrame *line_3;
    QComboBox *startWeekBox;
    QComboBox *weekTimesBox;
    QLabel *label_7;
    QLabel *label_9;
    QWidget *tab_3;
    QTableWidget *tableWidget;
    QPushButton *startBtn;
    QComboBox *RoomTimeTab;
    QComboBox *ClassTimeTab;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QComboBox *TeacherTimeTab;
    QComboBox *GmaxBox;
    QComboBox *PmaxBox;
    QLabel *label_19;
    QLabel *label_20;

    void setupUi(QMainWindow *secretary)
    {
        if (secretary->objectName().isEmpty())
            secretary->setObjectName(QStringLiteral("secretary"));
        secretary->resize(600, 450);
        secretary->setMinimumSize(QSize(600, 450));
        secretary->setMaximumSize(QSize(600, 450));
        centralWidget = new QWidget(secretary);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(600, 450));
        centralWidget->setMaximumSize(QSize(600, 450));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 600, 450));
        tabWidget->setMinimumSize(QSize(600, 450));
        tabWidget->setMaximumSize(QSize(600, 450));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        TtableWidget = new QTableWidget(tab);
        if (TtableWidget->columnCount() < 3)
            TtableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TtableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TtableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TtableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (TtableWidget->rowCount() < 100)
            TtableWidget->setRowCount(100);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TtableWidget->setItem(0, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TtableWidget->setItem(0, 1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TtableWidget->setItem(0, 2, __qtablewidgetitem5);
        TtableWidget->setObjectName(QStringLiteral("TtableWidget"));
        TtableWidget->setGeometry(QRect(10, 10, 321, 401));
        TtableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        TtableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        TtableWidget->setWordWrap(true);
        TtableWidget->setRowCount(100);
        TtableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        TtableWidget->horizontalHeader()->setHighlightSections(true);
        TtableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        TtableWidget->horizontalHeader()->setStretchLastSection(false);
        TtableWidget->verticalHeader()->setVisible(false);
        TtableWidget->verticalHeader()->setCascadingSectionResizes(false);
        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(330, 200, 341, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 10, 121, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(390, 220, 121, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        TClassBox = new QComboBox(tab);
        TClassBox->setObjectName(QStringLiteral("TClassBox"));
        TClassBox->setGeometry(QRect(410, 50, 161, 22));
        TClassBox->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        TCourseBox = new QComboBox(tab);
        TCourseBox->setObjectName(QStringLiteral("TCourseBox"));
        TCourseBox->setGeometry(QRect(410, 100, 161, 22));
        TCourseBox->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 50, 54, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 100, 54, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        TAddBtn = new QPushButton(tab);
        TAddBtn->setObjectName(QStringLiteral("TAddBtn"));
        TAddBtn->setGeometry(QRect(430, 140, 75, 31));
        TAddBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 250, 291, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(340, 300, 301, 21));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        TDelBtn = new QPushButton(tab);
        TDelBtn->setObjectName(QStringLiteral("TDelBtn"));
        TDelBtn->setGeometry(QRect(350, 350, 75, 31));
        TDelBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        TClearBtn = new QPushButton(tab);
        TClearBtn->setObjectName(QStringLiteral("TClearBtn"));
        TClearBtn->setGeometry(QRect(464, 350, 71, 31));
        TClearBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        CAddBtn = new QPushButton(tab_2);
        CAddBtn->setObjectName(QStringLiteral("CAddBtn"));
        CAddBtn->setGeometry(QRect(500, 370, 75, 31));
        CAddBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(300, 210, 291, 31));
        label_13->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        CDelBtn = new QPushButton(tab_2);
        CDelBtn->setObjectName(QStringLiteral("CDelBtn"));
        CDelBtn->setGeometry(QRect(360, 280, 75, 31));
        CDelBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(70, 190, 121, 31));
        label_14->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        CtableWidget = new QTableWidget(tab_2);
        if (CtableWidget->columnCount() < 10)
            CtableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        CtableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        CtableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        CtableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        CtableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        CtableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        CtableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        if (CtableWidget->rowCount() < 50)
            CtableWidget->setRowCount(50);
        CtableWidget->setObjectName(QStringLiteral("CtableWidget"));
        CtableWidget->setGeometry(QRect(0, 10, 591, 171));
        CtableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        CtableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        CtableWidget->setGridStyle(Qt::SolidLine);
        CtableWidget->setWordWrap(true);
        CtableWidget->setRowCount(50);
        CtableWidget->setColumnCount(10);
        CtableWidget->horizontalHeader()->setVisible(false);
        CtableWidget->horizontalHeader()->setHighlightSections(true);
        CtableWidget->verticalHeader()->setVisible(false);
        CTeacherBox = new QComboBox(tab_2);
        CTeacherBox->setObjectName(QStringLiteral("CTeacherBox"));
        CTeacherBox->setGeometry(QRect(100, 230, 161, 22));
        CTeacherBox->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 270, 54, 20));
        label_15->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 230, 54, 21));
        label_16->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(400, 180, 121, 31));
        label_17->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(310, 250, 301, 21));
        label_18->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        CCourseBox = new QComboBox(tab_2);
        CCourseBox->setObjectName(QStringLiteral("CCourseBox"));
        CCourseBox->setGeometry(QRect(100, 270, 161, 22));
        CCourseBox->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        CClearBtn = new QPushButton(tab_2);
        CClearBtn->setObjectName(QStringLiteral("CClearBtn"));
        CClearBtn->setGeometry(QRect(500, 280, 75, 31));
        CClearBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        class1 = new QComboBox(tab_2);
        class1->setObjectName(QStringLiteral("class1"));
        class1->setGeometry(QRect(100, 310, 161, 22));
        class1->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        class2 = new QComboBox(tab_2);
        class2->setObjectName(QStringLiteral("class2"));
        class2->setGeometry(QRect(100, 350, 161, 22));
        class2->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        class3 = new QComboBox(tab_2);
        class3->setObjectName(QStringLiteral("class3"));
        class3->setGeometry(QRect(100, 390, 161, 22));
        class3->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 310, 54, 20));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        line_2 = new QFrame(tab_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(300, 180, 20, 141));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(tab_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(310, 310, 291, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        startWeekBox = new QComboBox(tab_2);
        startWeekBox->setObjectName(QStringLiteral("startWeekBox"));
        startWeekBox->setGeometry(QRect(400, 330, 69, 22));
        startWeekBox->setLayoutDirection(Qt::LeftToRight);
        startWeekBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        startWeekBox->setMaxVisibleItems(5);
        weekTimesBox = new QComboBox(tab_2);
        weekTimesBox->setObjectName(QStringLiteral("weekTimesBox"));
        weekTimesBox->setGeometry(QRect(400, 380, 69, 22));
        weekTimesBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(310, 330, 91, 21));
        label_7->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(310, 380, 91, 20));
        label_9->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableWidget = new QTableWidget(tab_3);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(15, 11, 561, 251));
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
        startBtn = new QPushButton(tab_3);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(484, 290, 91, 31));
        startBtn->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        RoomTimeTab = new QComboBox(tab_3);
        RoomTimeTab->setObjectName(QStringLiteral("RoomTimeTab"));
        RoomTimeTab->setGeometry(QRect(180, 290, 121, 22));
        ClassTimeTab = new QComboBox(tab_3);
        ClassTimeTab->setObjectName(QStringLiteral("ClassTimeTab"));
        ClassTimeTab->setGeometry(QRect(180, 340, 121, 22));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 290, 131, 21));
        label_10->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 340, 131, 21));
        label_11->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 390, 131, 20));
        label_12->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        TeacherTimeTab = new QComboBox(tab_3);
        TeacherTimeTab->setObjectName(QStringLiteral("TeacherTimeTab"));
        TeacherTimeTab->setGeometry(QRect(180, 390, 121, 22));
        GmaxBox = new QComboBox(tab_3);
        GmaxBox->setObjectName(QStringLiteral("GmaxBox"));
        GmaxBox->setGeometry(QRect(490, 330, 69, 22));
        PmaxBox = new QComboBox(tab_3);
        PmaxBox->setObjectName(QStringLiteral("PmaxBox"));
        PmaxBox->setGeometry(QRect(490, 360, 69, 22));
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(390, 330, 91, 21));
        label_19->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(390, 360, 91, 21));
        label_20->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tabWidget->addTab(tab_3, QString());
        secretary->setCentralWidget(centralWidget);

        retranslateUi(secretary);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(secretary);
    } // setupUi

    void retranslateUi(QMainWindow *secretary)
    {
        secretary->setWindowTitle(QApplication::translate("secretary", "secretary", 0));
        QTableWidgetItem *___qtablewidgetitem = TtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("secretary", "\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem1 = TtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("secretary", "\350\257\276\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem2 = TtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("secretary", "\345\255\246\346\227\266", 0));

        const bool __sortingEnabled = TtableWidget->isSortingEnabled();
        TtableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = TtableWidget->item(0, 1);
        ___qtablewidgetitem3->setText(QApplication::translate("secretary", "\343\200\201", 0));
        TtableWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("secretary", "\346\267\273\345\212\240\346\225\231\345\255\246\350\256\241\345\210\222", 0));
        label_2->setText(QApplication::translate("secretary", "\345\210\240\351\231\244\346\225\231\345\255\246\350\256\241\345\210\222", 0));
        label_3->setText(QApplication::translate("secretary", "\347\217\255\347\272\247\357\274\232", 0));
        label_4->setText(QApplication::translate("secretary", "\350\257\276\347\250\213\357\274\232", 0));
        TAddBtn->setText(QApplication::translate("secretary", "\346\267\273\345\212\240", 0));
        label_5->setText(QApplication::translate("secretary", "    \347\202\271\345\207\273\345\267\246\344\276\247\350\241\250\346\240\274\351\200\211\346\213\251\344\270\200\350\241\214\357\274\214\347\204\266\345\220\216\347\202\271\345\207\273", 0));
        label_6->setText(QApplication::translate("secretary", "\344\270\213\346\226\271\347\232\204\345\210\240\351\231\244\346\214\211\351\222\256\343\200\202\350\257\267\346\205\216\347\224\250\346\270\205\347\251\272\346\223\215\344\275\234\357\274\201", 0));
        TDelBtn->setText(QApplication::translate("secretary", "\345\210\240\351\231\244", 0));
        TClearBtn->setText(QApplication::translate("secretary", "\346\270\205\347\251\272", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("secretary", "\346\225\231\345\255\246\350\256\241\345\210\222\347\256\241\347\220\206", 0));
        CAddBtn->setText(QApplication::translate("secretary", "\346\267\273\345\212\240", 0));
        label_13->setText(QApplication::translate("secretary", "    \347\202\271\345\207\273\345\267\246\344\276\247\350\241\250\346\240\274\351\200\211\346\213\251\344\270\200\350\241\214\357\274\214\347\204\266\345\220\216\347\202\271\345\207\273\344\270\213\346\226\271", 0));
        CDelBtn->setText(QApplication::translate("secretary", "\345\210\240\351\231\244", 0));
        label_14->setText(QApplication::translate("secretary", "\346\267\273\345\212\240\344\273\243\350\257\276\350\256\241\345\210\222", 0));
        QTableWidgetItem *___qtablewidgetitem4 = CtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("secretary", "\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem5 = CtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("secretary", "\346\225\231\345\270\210", 0));
        QTableWidgetItem *___qtablewidgetitem6 = CtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("secretary", "\350\257\276\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem7 = CtableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("secretary", "\347\217\255\347\272\2471", 0));
        QTableWidgetItem *___qtablewidgetitem8 = CtableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("secretary", "\347\217\255\347\272\2472", 0));
        QTableWidgetItem *___qtablewidgetitem9 = CtableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("secretary", "\347\217\255\347\272\2473", 0));
        label_15->setText(QApplication::translate("secretary", "\350\257\276\347\250\213\357\274\232", 0));
        label_16->setText(QApplication::translate("secretary", "\346\225\231\345\270\210\357\274\232", 0));
        label_17->setText(QApplication::translate("secretary", "\345\210\240\351\231\244\344\273\243\350\257\276\350\256\241\345\210\222", 0));
        label_18->setText(QApplication::translate("secretary", "\347\232\204\345\210\240\351\231\244\346\214\211\351\222\256\343\200\202\350\257\267\346\205\216\347\224\250\346\270\205\347\251\272\346\223\215\344\275\234\357\274\201", 0));
        CClearBtn->setText(QApplication::translate("secretary", "\346\270\205\347\251\272", 0));
        class2->clear();
        class2->insertItems(0, QStringList()
         << QApplication::translate("secretary", "\346\227\240", 0)
        );
        class3->clear();
        class3->insertItems(0, QStringList()
         << QApplication::translate("secretary", "\346\227\240", 0)
        );
        label_8->setText(QApplication::translate("secretary", "\347\217\255\347\272\247\357\274\232", 0));
        startWeekBox->clear();
        startWeekBox->insertItems(0, QStringList()
         << QApplication::translate("secretary", "1", 0)
         << QApplication::translate("secretary", "2", 0)
         << QApplication::translate("secretary", "3", 0)
         << QApplication::translate("secretary", "4", 0)
         << QApplication::translate("secretary", "5", 0)
         << QApplication::translate("secretary", "6", 0)
         << QApplication::translate("secretary", "7", 0)
         << QApplication::translate("secretary", "8", 0)
         << QApplication::translate("secretary", "9", 0)
         << QApplication::translate("secretary", "10", 0)
         << QApplication::translate("secretary", "11", 0)
         << QApplication::translate("secretary", "12", 0)
         << QApplication::translate("secretary", "13", 0)
         << QApplication::translate("secretary", "14", 0)
         << QApplication::translate("secretary", "15", 0)
         << QApplication::translate("secretary", "16", 0)
         << QApplication::translate("secretary", "17", 0)
         << QApplication::translate("secretary", "18", 0)
         << QApplication::translate("secretary", "19", 0)
         << QApplication::translate("secretary", "20", 0)
        );
        weekTimesBox->clear();
        weekTimesBox->insertItems(0, QStringList()
         << QApplication::translate("secretary", "1", 0)
         << QApplication::translate("secretary", "2", 0)
         << QApplication::translate("secretary", "3", 0)
        );
        label_7->setText(QApplication::translate("secretary", "\345\274\200\350\257\276\345\221\250\346\225\260\357\274\232", 0));
        label_9->setText(QApplication::translate("secretary", "\345\215\225\345\221\250\350\257\276\346\254\241\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("secretary", "\344\273\243\350\257\276\350\256\241\345\210\222\347\256\241\347\220\206", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("secretary", "\346\230\237\346\234\237\344\270\200", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("secretary", "\346\230\237\346\234\237\344\272\214", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("secretary", "\346\230\237\346\234\237\344\270\211", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("secretary", "\346\230\237\346\234\237\345\233\233", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QApplication::translate("secretary", "\346\230\237\346\234\237\344\272\224", 0));
        startBtn->setText(QApplication::translate("secretary", "\347\224\237\346\210\220\350\257\276\350\241\250", 0));
        RoomTimeTab->clear();
        RoomTimeTab->insertItems(0, QStringList()
         << QApplication::translate("secretary", "\346\227\240", 0)
        );
        ClassTimeTab->clear();
        ClassTimeTab->insertItems(0, QStringList()
         << QApplication::translate("secretary", "\346\227\240", 0)
        );
        label_10->setText(QApplication::translate("secretary", "\346\237\245\350\257\242\346\225\231\345\256\244\350\257\276\350\241\250\357\274\232", 0));
        label_11->setText(QApplication::translate("secretary", "\346\237\245\350\257\242\345\255\246\347\224\237\350\257\276\350\241\250\357\274\232", 0));
        label_12->setText(QApplication::translate("secretary", "\346\237\245\350\257\242\346\225\231\345\270\210\350\257\276\350\241\250\357\274\232", 0));
        TeacherTimeTab->clear();
        TeacherTimeTab->insertItems(0, QStringList()
         << QApplication::translate("secretary", "\346\227\240", 0)
        );
        GmaxBox->clear();
        GmaxBox->insertItems(0, QStringList()
         << QApplication::translate("secretary", "100", 0)
         << QApplication::translate("secretary", "200", 0)
         << QApplication::translate("secretary", "500", 0)
         << QApplication::translate("secretary", "1000", 0)
        );
        PmaxBox->clear();
        PmaxBox->insertItems(0, QStringList()
         << QApplication::translate("secretary", "50", 0)
         << QApplication::translate("secretary", "100", 0)
         << QApplication::translate("secretary", "150", 0)
         << QApplication::translate("secretary", "200", 0)
        );
        label_19->setText(QApplication::translate("secretary", "\351\201\227\344\274\240\344\273\243\346\225\260\357\274\232", 0));
        label_20->setText(QApplication::translate("secretary", "\347\247\215\347\276\244\345\244\247\345\260\217\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("secretary", "  \350\257\276\350\241\250\347\256\241\347\220\206  ", 0));
    } // retranslateUi

};

namespace Ui {
    class secretary: public Ui_secretary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECRETARY_H
