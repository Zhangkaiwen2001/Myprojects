#include "teacher.h"
#include <QStringList>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include "timetabwidget.h"
extern QSqlDatabase myDB;
extern QString id;

teacher::teacher(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.apply, SIGNAL(clicked()), this, SLOT(addReq()));
	connect(ui.DelReqBtn, SIGNAL(clicked()), this, SLOT(delReq()));
	connect(ui.clearReqBtn, SIGNAL(clicked()), this, SLOT(clearReq()));
	connect(ui.courseBox, SIGNAL(currentTextChanged(QString)), this, SLOT(updataUI(QString)));
	connect(ui.comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(updataTTimetable(QString)));
}
teacher::~teacher()
{

}
void teacher::initUI(){
	QStringList list;
	list << "1" << "2" << "3" << "4";
	ui.timeBox1->addItems(list);
	list << "5";
	ui.dayBox1->addItems(list);


	QSqlQuery * query = new QSqlQuery(myDB);
	bool bRet = query->exec(QStringLiteral("select 课程名 from TeacherCourseView where 教师号 = %1").arg(id));
	if (bRet)
	{
		list.clear();
		while (query->next())
		{
			list << query->value(0).toString();
		}
		ui.courseBox->addItems(list);
		if (list.size()>0)
		{
			updataUI(list.at(0));
		}		
	} 
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	updataReq();
	for (int i = 0; i < 5; i++)
	{
		ui.timetable->setColumnWidth(i, 112);
	}
	for (int i = 0; i < 4; i++)
	{
		ui.timetable->setRowHeight(i, 62);
	}
	updataTTimetable("");
}
void teacher::updataUI(QString course){
	QSqlQuery * query = new QSqlQuery(myDB);
	bool bRet = query->exec(QStringLiteral("select * from TeacherCourseView where 教师号 = %1 and 课程名 = '%2'").arg(id).arg(course));
	int times = 1;
	int classnum = 1;
	if (bRet)
	{
		query->next();
		classnum = query->value(2).toInt();
		times = query->value(3).toInt();
		if (times >= 2)
		{
			QStringList list;
			list << "1" << "2" << "3" << "4";
			ui.timeBox2->addItems(list);
			list << "5";
			ui.dayBox2->addItems(list);
		}
		if (times == 3)
		{
			QStringList list;
			list << "1" << "2" << "3" << "4";
			ui.timeBox3->addItems(list);
			list << "5";
			ui.dayBox3->addItems(list);
		}
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
		return;
	}
	query->clear();
	bRet = query->exec(QStringLiteral("select 教室号 from classroom where 容量 >= %1").arg(classnum * 50));
	if (bRet)
	{
		QStringList list;
		while (query->next())
		{
			list << query->value(0).toString();
		}
		ui.classBox1->addItems(list);
		if (times>=2)
		{
			ui.classBox2->addItems(list);
		}
		if (times>=3)
		{
			ui.classBox3->addItems(list);
		}	
	} 
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
}
void teacher::updataReq(){
	ui.tableWidget->clearContents();
	QSqlQuery *query = new QSqlQuery(myDB);
	QString sql = QStringLiteral("select * from CourseReqView where 教师号 = %1").arg(id);
	bool bRet = query->exec(sql);
	if (bRet)
	{
		int i = 0;
		while (query->next())
		{
			for (int j = 0; j < 10;j++)
			{
				QString str = query->value(j).toString();
				ui.tableWidget->setItem(i, j, new QTableWidgetItem(str));
			}
			i++;
		}
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
}
void teacher::addReq(){
	QString day1 = ui.dayBox1->currentText();
	QString day2 = ui.dayBox2->currentText();
	QString day3 = ui.dayBox3->currentText();

	QString time1 = ui.timeBox1->currentText();
	QString time2 = ui.timeBox2->currentText();
	QString time3 = ui.timeBox3->currentText();

	QString class1 = ui.classBox1->currentText();
	QString class2 = ui.classBox2->currentText();
	QString class3 = ui.classBox3->currentText();

	QString course = ui.courseBox->currentText();

	QSqlQuery *query = new QSqlQuery(myDB);
	query->prepare("exec CCoursePlanReq ?,?,?,?,?,?,?,?,?,?,?,?");
	query->bindValue(0,id);
	query->bindValue(1,course);
	query->bindValue(2,0);
	query->bindValue(3,day1);
	query->bindValue(4,time1);
	query->bindValue(5,class1);
	query->bindValue(6,day2);
	query->bindValue(7,time2);
	query->bindValue(8,class2);
	query->bindValue(9,day3);
	query->bindValue(10,time3);
	query->bindValue(11,class3);
	int bRet = query->exec();
	if (!bRet)
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	updataReq();
}
void teacher::delReq(){
	if (ui.tableWidget->selectedItems().length() == 0)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("请先选中一行数据！"));
		return;
	}
	int row = ui.tableWidget->currentRow();
	auto item0 = ui.tableWidget->item(row, 0);
	QString course = item0->text();

	QSqlQuery *query = new QSqlQuery(myDB);
	query->prepare("exec CCoursePlanReq ?,?,?,?,?,?,?,?,?,?,?,?");
	query->bindValue(0, id);
	query->bindValue(1, course);
	query->bindValue(2, 1);
	bool bRet = query->exec();
	if (!bRet)
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	updataReq();
}
void teacher::clearReq(){
	QSqlQuery *query = new QSqlQuery(myDB);
	query->prepare("exec CCoursePlanReq ?,?,?,?,?,?,?,?,?,?,?,?");
	query->bindValue(2, 2);
	bool bRet = query->exec();
	if (!bRet)
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	updataReq();
}
void teacher::updataTTimetable(QString str){
	ui.timetable->clearContents();
	QSqlQuery *query = new QSqlQuery(myDB);
	QString sql = QStringLiteral("select * from timeTableView where 教师号 = %1").arg(id);
	if (ui.comboBox->currentIndex() != 0)
	{
		sql += QStringLiteral("and 开始周次 <= %1 and 结束周次 >= %2").arg(ui.comboBox->currentIndex()).arg(ui.comboBox->currentIndex());
	}
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
			ui.timetable->setCellWidget(time1 - 1, day - 1, widget);
		}
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
}