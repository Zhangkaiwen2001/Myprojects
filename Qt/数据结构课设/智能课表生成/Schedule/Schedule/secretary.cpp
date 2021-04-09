#include "secretary.h"
#include "timetable.h"
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

secretary::secretary(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	popMenu = new QMenu(ui.tableWidget);
	timeAction = new QAction(QStringLiteral("修改时间"), this);
	roomAction = new QAction(QStringLiteral("修改教室"), this);
	popMenu->addAction(timeAction);
	popMenu->addAction(roomAction);
	ui.TtableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.CtableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	connect(ui.CAddBtn, SIGNAL(clicked()), this, SLOT(CAddBtnEvent()));
	connect(ui.TAddBtn, SIGNAL(clicked()), this, SLOT(TAddBtnEvent()));
	connect(ui.CDelBtn, SIGNAL(clicked()), this, SLOT(CDelBtnEvent()));
	connect(ui.TDelBtn, SIGNAL(clicked()), this, SLOT(TDelBtnEvent()));
	connect(ui.CClearBtn, SIGNAL(clicked()), this, SLOT(CClearEvent()));
	connect(ui.TClearBtn, SIGNAL(clicked()), this, SLOT(TClearEvent()));
	connect(ui.startBtn, SIGNAL(clicked()), this, SLOT(startEvent()));
	connect(ui.CCourseBox, SIGNAL(currentTextChanged(QString)), this, SLOT(updataClassBox(QString)));
	connect(ui.TeacherTimeTab, SIGNAL(currentTextChanged(QString)), this, SLOT(updataTTimetable(QString)));
	connect(ui.ClassTimeTab, SIGNAL(currentTextChanged(QString)), this, SLOT(updataSTimetable(QString)));
	connect(ui.RoomTimeTab, SIGNAL(currentTextChanged(QString)), this, SLOT(updataRTimetable(QString)));
	connect(ui.tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slot_menu(QPoint)));
	connect(timeAction, SIGNAL(triggered()), this, SLOT(slot_changetime()));
	connect(roomAction, SIGNAL(triggered()), this, SLOT(slot_changeroom()));
}
void secretary::initUI(){
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec("select * from course");
	if (bRet)
	{
		QStringList list;
		while (query->next())
		{
			QString str = query->value(1).toString();
			list << str;
		}
		QString str = list.at(0);
		updataClassBox(str);
		ui.CCourseBox->addItems(list);
		ui.TCourseBox->addItems(list);
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	query->clear();
	bRet = query->exec("select * from teacher");
	if (bRet)
	{
		QStringList list;
		while (query->next())
		{
			QString str = query->value(1).toString();
			list << str;
		}
		ui.CTeacherBox->addItems(list);
		ui.TeacherTimeTab->addItems(list);
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	query->clear();
	bRet = query->exec("select * from class");
	if (bRet)
	{
		QStringList list;
		while (query->next())
		{
			QString str = query->value(0).toString();
			list << str;
		}
		ui.TClassBox->addItems(list);
		ui.ClassTimeTab->addItems(list);
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	query->clear();
	bRet = query->exec(QStringLiteral("select 教室号 from classroom"));
	if (bRet)
	{
		QStringList list;
		while (query->next())
		{
			QString str = query->value(0).toString();
			list << str;
		}
		ui.RoomTimeTab->addItems(list);
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	for (int i = 0; i < 5;i++)
	{
		ui.tableWidget->setColumnWidth(i, 112);
	}
	for (int i = 0; i < 4; i++)
	{
		ui.tableWidget->setRowHeight(i, 62);
	}
}
void secretary::updataTTimetable(QString str){
	if (str.compare(QStringLiteral("无")) == 0)
	{
		return;
	}
	else
	{
		ui.RoomTimeTab->setCurrentIndex(0);
		ui.ClassTimeTab->setCurrentIndex(0);
	}
	ui.tableWidget->clearContents();
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec(QStringLiteral("select * from timeTableView where 姓名 = '%1'").arg(str));
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
			ui.tableWidget->setCellWidget(time1 - 1, day - 1,widget);
		}
	} 
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
}
void secretary::updataSTimetable(QString str){
	if (str.compare(QStringLiteral("无")) == 0)
	{
		return;
	}
	else
	{
		ui.RoomTimeTab->setCurrentIndex(0);
		ui.TeacherTimeTab->setCurrentIndex(0);
	}
	ui.tableWidget->clearContents();
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec(QStringLiteral("select * from timeTableView where 班级号1 = '%1' or 班级号2 = '%2'or 班级号3 = '%3'").arg(str).arg(str).arg(str));
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
void secretary::updataRTimetable(QString str){
	if (str.compare(QStringLiteral("无")) == 0)
	{
		return;
	}
	else
	{
		ui.TeacherTimeTab->setCurrentIndex(0);
		ui.ClassTimeTab->setCurrentIndex(0);
	}
	ui.tableWidget->clearContents();
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec(QStringLiteral("select * from timeTableView where 教室号 = '%1'").arg(str));
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
void secretary::updataT(){
	ui.TtableWidget->clearContents();
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec("select * from TeachingPlanView");
	if (bRet)
	{
		int i = 0;
		while(query->next())
		{
			QString str0 = query->value(0).toString();
			QString str1 = query->value(1).toString();
			QString str2 = query->value(2).toString();
			ui.TtableWidget->setItem(i, 0, new QTableWidgetItem(str0));
			ui.TtableWidget->setItem(i, 1, new QTableWidgetItem(str1));
			ui.TtableWidget->setItem(i, 2, new QTableWidgetItem(str2));
			i++;
		}
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
}
void secretary::updataC(){
	ui.CtableWidget->clearContents();
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec("select * from CoursePlanView");
	if (bRet)
	{
		int i = 0;
		while (query->next())
		{
			for (int j = 0; j < 10;j++)
			{
				QString str = query->value(j).toString();
				ui.CtableWidget->setItem(i, j, new QTableWidgetItem(str));
			}		
			i++;
		}
	}
	else
	{
		QString str = query->lastError().type();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
}
void secretary::updataClassBox(QString course){
	QString a = QStringLiteral("select 班号 from TeachingPlanView where 课程名 = '%1' ").arg(course);
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec(a);
	if (bRet)
	{
		QStringList list;
		while (query->next())
		{
			QString str = query->value(0).toString();
			list << str;
		}
		ui.class1->clear();
		ui.class2->clear();
		ui.class3->clear();
		ui.class1->addItems(list);
		ui.class2->addItem(QStringLiteral("无"));
		ui.class2->addItems(list);
		ui.class3->addItem(QStringLiteral("无"));
		ui.class3->addItems(list);
	}
}
void secretary::CAddBtnEvent(){
	QString course = ui.CCourseBox->currentText();
	QString teacher = ui.CTeacherBox->currentText();
	QString class1 = ui.class1->currentText();
	QString class2 = ui.class2->currentText();
	QString class3 = ui.class3->currentText();

	int startweek = ui.startWeekBox->currentText().toInt();
	int endweek = 0;
	int weektimes = ui.weekTimesBox->currentText().toInt();
	QSqlQuery *query = new QSqlQuery(myDB);
	QString a = QStringLiteral("select 课时 from TeachingPlanView where 班号=%1 and 课程名 = '%2' ").arg(class1).arg(course);
	bool bRet = query->exec(a);
	if (bRet)
	{
		query->next();
		int studytime = query->value(0).toInt();
		endweek = startweek + (studytime / 2) / weektimes;
		if ((studytime / 2) % weektimes == 0)
		{
			endweek--;
		}
		QString str = QStringLiteral("课程将从第%1周上到第%2周，每周%3次课").arg(startweek).arg(endweek).arg(weektimes);
		switch (QMessageBox::question(0, QStringLiteral("提示!"), str, QMessageBox::Ok, QMessageBox::Cancel))
		{
		case  QMessageBox::Ok:
			break;
		default:
			return;

		}
	} 
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	query->clear(); 
	query = new QSqlQuery(myDB);
	query->prepare("exec CCoursePlan ?,?,?,?,?,?,?,?,?,?,?");
	query->bindValue(1, teacher);
	query->bindValue(2, course);
	
	int classnum = 1;
	if (class2.compare(QStringLiteral("无")))
	{
		query->bindValue(5, class2);
		classnum = 2;
	}
	if (class3.compare(QStringLiteral("无")))
	{
		query->bindValue(6, class3);
		classnum = 3;
	}
	query->bindValue(3, classnum);
	query->bindValue(4, class1);
	query->bindValue(7, startweek);
	query->bindValue(8, endweek);
	query->bindValue(9, weektimes);
	query->bindValue(10,0);
	bRet = query->exec();
	if(!bRet)
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
		//QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("已存在该代课计划!请不要重复添加"));
	}
	updataC();
}
void secretary::TAddBtnEvent(){
	QSqlQuery *query = new QSqlQuery(myDB);
	query->prepare("exec PTeachingPlan ?,?,?");
	int class1 = ui.TClassBox->currentText().toInt();
	QString course = ui.TCourseBox->currentText();

	query->bindValue(0, class1);
	query->bindValue(1, course);
	query->bindValue(2, 0);
	bool bRet = query->exec();
	if (!bRet)
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
		//QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("已存在该教学计划!请不要重复添加"));
	}
	updataT();
}
void secretary::TDelBtnEvent(){
	if (ui.TtableWidget->selectedItems().length() == 0)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("请先选中一行数据！"));
		return;
	}
	int row = ui.TtableWidget->currentRow();
	auto item0 = ui.TtableWidget->item(row, 0);
	auto item1 = ui.TtableWidget->item(row, 1);
	int class1 = item0->text().toInt();
	QString course = item1->text();

	QSqlQuery *query = new QSqlQuery(myDB);
	query->prepare("exec PTeachingPlan ?,?,?");
	query->bindValue(0, class1);
	query->bindValue(1, course);
	query->bindValue(2, 1);
	bool bRet = query->exec();
	if (!bRet)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("不存在该教学计划!请不要重复删除!"));
	}
	updataT();
}
void secretary::CDelBtnEvent(){
	if (ui.CtableWidget->selectedItems().length()==0)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("请先选中一行数据！"));
		return;
	}
	int row = ui.CtableWidget->currentRow();
	auto item0 = ui.CtableWidget->item(row, 0);
	QString str0 = item0->text();

	QSqlQuery * query = new QSqlQuery(myDB);
	query->prepare("exec CCoursePlan ?,?,?,?,?,?,?,?,?,?,?");
	query->bindValue(0, str0);
	query->bindValue(10, 1);
	bool bRet = query->exec();
	if (!bRet)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("不存在该代课计划!请不要重复删除!"));
	}
	updataC();
}
void secretary::CClearEvent(){
	switch (QMessageBox::question(0, QStringLiteral("警告!"), QStringLiteral("确定全部删除？"), QMessageBox::Ok, QMessageBox::Cancel))
	{
		case  QMessageBox::Ok:
			break;
		default:
		return;

	}
	QSqlQuery *query = new QSqlQuery(myDB);
	query->prepare("exec CCoursePlan ?,?,?,?,?,?,?,?,?,?,?");
	query->bindValue(10, 2);
	bool bRet = query->exec();
	if (!bRet)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("不存在该代课计划!请不要重复删除!"));
	}
	updataC();
	
}
void secretary::TClearEvent(){
	switch (QMessageBox::question(0, QStringLiteral("警告!"), QStringLiteral("确定全部删除？"), QMessageBox::Ok, QMessageBox::Cancel))
	{
	case  QMessageBox::Ok:
		break;
	default:
		return;
	}

	QSqlQuery *query = new QSqlQuery(myDB);
	query->prepare("exec PTeachingPlan ?,?,?");
	query->bindValue(0, 100);
	query->bindValue(1, 100);
	query->bindValue(2, 2);
	bool bRet = query->exec();
	if (!bRet)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("不存在该教学计划!请不要重复删除!"));
	}
	updataT();
}
void secretary::startEvent(){
	switch (QMessageBox::question(0, QStringLiteral("警告!"), QStringLiteral("重新生成课表将会删除就有课表，是否确定？"), QMessageBox::Ok, QMessageBox::Cancel))
	{
	case  QMessageBox::Ok:
		break;
	default:
		return;

	}
	QSqlQuery * query = new QSqlQuery(myDB);
	bool bRet = query->exec("delete from timetable");
	if (!bRet)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("删除现有课表失败！"));
		return;
	}
	timeTable t = new timeTable(NULL);
	t.setnum(ui.GmaxBox->currentText().toInt(), ui.PmaxBox->currentText().toInt());
	t.start();
}
void secretary::slot_menu(QPoint pos){
	popMenu->exec(QCursor::pos());
}
void secretary::slot_changetime(){
	int row = -1, col = -1;
	row = ui.tableWidget->currentRow();
	col = ui.tableWidget->currentColumn();
	if (row == -1 || col == -1)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("请先选中一个课程数据！"));
		return;
	}
	int oldDay = col + 1;
	int oldTime = row + 1;
	timeTabWidget * wight = (timeTabWidget *)ui.tableWidget->cellWidget(row, col);
	int room = wight->getClass().toInt();
	QStringList list;
	list << "1" << "2" << "3" << "4" << "5";
	bool ok;
	int newDay, newTime;
	QString dayStr = QInputDialog::getItem(this, QStringLiteral("时间修改---星期选择"), QStringLiteral("请选择星期："), list, 0, false, &ok);
	if (ok && !dayStr.isEmpty())
	{
		newDay = dayStr.toInt();
	}
	else
	{
		return;
	}
	list.pop_back();
	QString timeStr = QInputDialog::getItem(this, QStringLiteral("时间修改---大节选择"), QStringLiteral("请选择大节："), list, 0, false, &ok);
	if (ok && !dayStr.isEmpty())
	{
		newTime = timeStr.toInt();
	}
	else
	{
		return;
	}
	bool bret1 = changeTimeEnable(oldDay, oldTime, room, newDay, newTime, room);
	if (!bret1)
	{
		QMessageBox::critical(0, tr("error!"), QStringLiteral("课程存在冲突无法进行修改！"));
		return;
	}
	QSqlQuery * query = new QSqlQuery(myDB);
	bool bRet = query->prepare("exec ChangeTimeTable ?,?,?,?,?,?");
	query->bindValue(0, oldDay);
	query->bindValue(1, oldTime);
	query->bindValue(2, room);
	query->bindValue(3, newDay);
	query->bindValue(4, newTime);
	query->bindValue(5, room);
	bRet = query->exec();
	if (!bRet)
	{
		
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}

	if (ui.TeacherTimeTab->currentIndex() != 0)
	{
		updataTTimetable(ui.TeacherTimeTab->currentText());
	}
	if (ui.RoomTimeTab->currentIndex() != 0)
	{
		updataRTimetable(ui.RoomTimeTab->currentText());
	}
	if (ui.ClassTimeTab->currentIndex() != 0)
	{
		updataSTimetable(ui.ClassTimeTab->currentText());
	}
}
bool secretary::changeTimeEnable(int oldday,int oldtime,int oldroom,int newday,int newtime,int newroom){
	bool flag = true;
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec(QStringLiteral("select * from timeTableView where 星期 = '%1' and 大节 = '%2' and  教室号 = '%3'").arg(oldday).arg(oldtime).arg(oldroom));
	if (bRet)
	{
		query->next();
		QString teacher = query->value(3).toString();
		int class1 = query->value(7).toInt();
		int class2 = query->value(8).toInt();
		int class3 = query->value(9).toInt();
		query->clear();
		bRet = query->exec(QStringLiteral("select * from timeTableView where 星期 = '%1' and 大节 = '%2'").arg(newday).arg(newtime));
		if (bRet)
		{
			while (query->next())
			{
				int nroom = query->value(2).toInt();
				QString nteacher = query->value(3).toString();
				int nclass1 = query->value(7).toInt();
				int nclass2 = query->value(8).toInt();
				int nclass3 = query->value(9).toInt();
				if (nteacher.compare(teacher) == 0)
				{
					flag = false;
				}
				if (class1 != 0 &&( class1 == nclass1 || class1 == nclass2 || class1 == nclass3))
				{
					flag = false;
				}
				if (class2 != 0 && (class1 == nclass1 || class1 == nclass2 || class1 == nclass3))
				{
					flag = false;
				}
				if (class3 != 0 && (class1 == nclass1 || class1 == nclass2 || class1 == nclass3))
				{
					flag = false;
				}
				if (newroom == nroom)
				{
					flag = false;
				}
			}
		}
		else
		{
			QString str = query->lastError().text();
			QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
		}
	} 
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	return flag;
}
bool secretary::changeRoomEnable(int oldday, int oldtime, int oldroom, int newday, int newtime, int newroom){
	bool flag = true;
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec(QStringLiteral("select * from timeTableView where 星期 = '%1' and 大节 = '%2' and  教室号 = '%3'").arg(oldday).arg(oldtime).arg(oldroom));
	if (bRet)
	{
		query->next();
		QString teacher = query->value(3).toString();
		int class1 = query->value(7).toInt();
		int class2 = query->value(8).toInt();
		int class3 = query->value(9).toInt();
		query->clear();
		bRet = query->exec(QStringLiteral("select * from timeTableView where 星期 = '%1' and 大节 = '%2'").arg(newday).arg(newtime));
		if (bRet)
		{
			while (query->next())
			{
				int nroom = query->value(2).toInt();
				if (newroom == nroom)
				{
					flag = false;
				}
			}
		}
		else
		{
			QString str = query->lastError().text();
			QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
		}
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	return flag;
}
void secretary::slot_changeroom(){
	int row = -1, col = -1;
	row = ui.tableWidget->currentRow();
	col = ui.tableWidget->currentColumn();
	if (row == -1 || col == -1)
	{
		QMessageBox::critical(0, QStringLiteral("错误!"), QStringLiteral("请先选中一个课程数据！"));
		return;
	}
	int oldDay = col + 1;
	int oldTime = row + 1;
	timeTabWidget * wight = (timeTabWidget *)ui.tableWidget->cellWidget(row, col);
	int oldroom = wight->getClass().toInt();

	QSqlQuery * query = new QSqlQuery(myDB);
	bool bRet  = query->exec(QStringLiteral("select 教室号 from classroom where 容量 >= (select 容量 from classroom where 教室号 = %1)").arg(oldroom));
	QStringList list;
	if (bRet)
	{
		while (query->next())
		{
			list << query->value(0).toString();
		}
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}

	bool ok;
	int newroom;
	QString dayStr = QInputDialog::getItem(this, QStringLiteral("地点修改---教室选择"), QStringLiteral("请选择教室："), list, 0, false, &ok);
	if (ok && !dayStr.isEmpty())
	{
		newroom = dayStr.toInt();
	}
	else
	{
		return;
	}

	bool bret1 = changeRoomEnable(oldDay, oldTime, oldroom, oldDay,oldTime, newroom);
	if (!bret1)
	{
		QMessageBox::critical(0, tr("error!"), QStringLiteral("课程存在冲突无法进行修改！"));
		return;
	}
	
	bRet = query->prepare("exec ChangeTimeTable ?,?,?,?,?,?");
	query->bindValue(0, oldDay);
	query->bindValue(1, oldTime);
	query->bindValue(2, oldroom);
	query->bindValue(3, oldDay);
	query->bindValue(4, oldTime);
	query->bindValue(5, newroom);
	bRet = query->exec();
	if (!bRet)
	{

		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}

	//更新
	if (ui.TeacherTimeTab->currentIndex()!=0)
	{
		updataTTimetable(ui.TeacherTimeTab->currentText());
	}
	if (ui.RoomTimeTab->currentIndex() != 0)
	{
		updataRTimetable(ui.RoomTimeTab->currentText());
	}
	if (ui.ClassTimeTab->currentIndex() != 0)
	{
		updataSTimetable(ui.ClassTimeTab->currentText());
	}

}
void secretary::setName(QString str){
	this->setWindowTitle(str);
}
secretary::~secretary()
{
	
}
