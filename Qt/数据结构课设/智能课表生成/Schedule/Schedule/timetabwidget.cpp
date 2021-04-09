#include "timetabwidget.h"

timeTabWidget::timeTabWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
void timeTabWidget::init(QString course, QString week, QString teacher, QString room){
	ui.Courselab->setText(course);
	ui.Weeklab->setText(week);
	ui.Teacherlab->setText(teacher);
	ui.Roomlab->setText(room);
}
QString timeTabWidget::getClass(){
	QString str = ui.Roomlab->text();
	return str;
}
timeTabWidget::~timeTabWidget()
{

}
