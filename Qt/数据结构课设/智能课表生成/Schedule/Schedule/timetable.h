#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QObject>
#include <QVector>
#include <QMap>
#include <QStringList>

class timeTable : public QObject
{
	Q_OBJECT

public:
	timeTable(QObject *parent);
	~timeTable();
	void start();
	int getRand(int ,int);
	double getRand(double, double);
	int roulette(QVector<double> vec);
	void genetic();
	bool exchange(QVector <QStringList> &, QVector <QStringList> &);
	bool variation(QVector <QStringList> &);
	void finnished();
	void setnum(int, int);
private:
	double getAdaptnum(QVector <QStringList>);
	QVector <QStringList> timeRoom;
	QVector<QVector <QStringList> > population;
	QStringList time1;
	QStringList classRoom;
	QStringList day;
	QMap<QString,int> roomVector;
	QVector<double> adaptNum;
	QMap<QString, QStringList> req;
	QVector<QStringList> course;
	int countnum;
	int Pmax;
	int Gmax;
};

#endif // TIMETABLE_H
