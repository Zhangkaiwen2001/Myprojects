#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets/QMainWindow>
#include "ui_login.h"
#include "secretary.h"
#include "teacher.h"
#include "student.h"
#include <QTcpSocket>
#include <QAbstractSocket>

class Schedule : public QMainWindow
{
	Q_OBJECT

public:
	Schedule(QWidget *parent = 0);
	~Schedule();
private slots: 
	void userLogin();
	bool Connection();
	void showError(QAbstractSocket::SocketError socketError);
private:
	Ui::ScheduleClass ui;
	secretary s;
	teacher t;
	student st;
};

#endif // LOGIN_H
