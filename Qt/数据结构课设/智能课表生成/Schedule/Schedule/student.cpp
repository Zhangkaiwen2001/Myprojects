#include "student.h"
#include "timetabwidget.h"
#include <QPalette>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSql>
#include <QStringList>
#include <QInputDialog>
extern QSqlDatabase myDB;
extern QString id;
student::student(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.weekBox, SIGNAL(currentTextChanged(QString)), this, SLOT(updataSTimetable(QString)));
	connect(ui.roomBox, SIGNAL(currentTextChanged(QString)), this, SLOT(updataSTimetable(QString)));
}
void student::initUI(){
	QSqlQuery * query = new QSqlQuery(myDB);
	bool bRet = query->exec(QStringLiteral("select 教室号 from classroom"));
	if (bRet)
	{
		QStringList list;
		while (query->next())
		{
			QString str = query->value(0).toString();
			list << str;
		}
		ui.roomBox->addItems(list);
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	for (int i = 0; i < 5; i++)
	{
		ui.tableWidget->setColumnWidth(i, 112);
	}
	for (int i = 0; i < 4; i++)
	{
		ui.tableWidget->setRowHeight(i, 62);
	}
	updataSTimetable("");
}
void student::updataSTimetable(QString str){ 
	ui.tableWidget->clearContents();
	QString sql;
	if (ui.roomBox->currentIndex() != 0 )
	{
		QString room = ui.roomBox->currentText();
		sql = QStringLiteral("select * from timeTableView where 教室号 = '%1'").arg(room);
		if (ui.weekBox->currentIndex() != 0)
		{
			sql += QStringLiteral("and 开始周次 <= %1 and 结束周次 >= %2").arg(ui.weekBox->currentIndex()).arg(ui.weekBox->currentIndex());
		}
	}
	else
	{
		str = id.mid(0, 8);
		sql = QStringLiteral("select * from timeTableView where 班级号1 = '%1' or 班级号2 = '%2'or 班级号3 = '%3'").arg(str).arg(str).arg(str);
	}
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec(sql);
	if (bRet)
	{
		while (query->next())
		{
			int day = query->value(0).toInt();
			int time1 = query->value(1).toInt();
			QString room = query->value(2).toString();
			QString teacher = query->value(3).toString();
			QString startweek = query->value(4).toString();
			QString endweek = query->value(5).toString();
			QString course = query->value(6).toString();
			QStringList clist = course.split(' ');
			course = clist.at(0);
			timeTabWidget * widget = new timeTabWidget(NULL);
			QString week = QStringLiteral("周");
			week = startweek + "-" + endweek + week;
			widget->init(course, week, teacher, room);
			ui.tableWidget->setCellWidget(time1 - 1, day - 1, widget);
		}
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}

}
student::~student()
{

}
