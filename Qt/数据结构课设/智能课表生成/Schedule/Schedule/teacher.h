#ifndef TEACHER_H
#define TEACHER_H

#include <QMainWindow>
#include "ui_teacher.h"

class teacher : public QMainWindow
{
	Q_OBJECT

public:
	teacher(QWidget *parent = 0);
	~teacher();
	void initUI();
	void setName(QString str);
private slots:
	void updataUI(QString);
	void updataReq();
	void addReq();
	void delReq();
	void clearReq();
	void updataTTimetable(QString str);
private:
	Ui::teacher ui;
};

#endif // TEACHER_H
