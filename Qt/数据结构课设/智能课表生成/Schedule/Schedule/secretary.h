#ifndef SECRETARY_H
#define SECRETARY_H

#include <QMainWindow>
#include "ui_secretary.h"
#include <QSqlDatabase>
#include <QMenu>

class secretary : public QMainWindow
{
	Q_OBJECT

public:
	secretary(QWidget *parent = 0);
	~secretary();
	void updataT();
	void updataC();
	void initUI();
	bool changeTimeEnable(int,int,int,int,int,int);
	bool changeRoomEnable(int, int, int, int, int, int);
	void setName(QString);
private slots:
	void updataTTimetable(QString);
	void updataSTimetable(QString);
	void updataRTimetable(QString);
	void TAddBtnEvent();
	void CAddBtnEvent();
	void TDelBtnEvent();
	void CDelBtnEvent();
	void TClearEvent();
	void CClearEvent();
	void startEvent();
	void updataClassBox(QString);
	void slot_menu(QPoint);
	void slot_changetime();
	void slot_changeroom();
private:
	QMenu * popMenu;
	QAction * timeAction;
	QAction * roomAction;
	Ui::secretary ui;
};

#endif // SECRETARY_H
