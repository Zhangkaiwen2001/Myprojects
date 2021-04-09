#ifndef TIMETAB_H
#define TIMETAB_H

#include <QWidget>
#include "ui_timetab.h"

class timetab : public QWidget
{
	Q_OBJECT

public:
	timetab(QWidget *parent = 0);
	~timetab();

private:
	Ui::timetab ui;
};

#endif // TIMETAB_H
