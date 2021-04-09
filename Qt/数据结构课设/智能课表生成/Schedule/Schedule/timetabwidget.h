#ifndef TIMETABWIDGET_H
#define TIMETABWIDGET_H

#include <QWidget>
#include "ui_timetabwidget.h"

class timeTabWidget : public QWidget
{
	Q_OBJECT

public:
	timeTabWidget(QWidget *parent = 0);
	~timeTabWidget();
	void init(QString,QString,QString,QString);
	QString getClass();

private:
	Ui::timeTabWidget ui;
};

#endif // TIMETABWIDGET_H
