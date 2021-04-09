#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>
#include "ui_student.h"

class student : public QMainWindow
{
	Q_OBJECT

public:
	student(QWidget *parent = 0);
	void initUI();
	~student();
private slots:
	void updataSTimetable(QString str);
private:
	Ui::student ui;
};

#endif // STUDENT_H
