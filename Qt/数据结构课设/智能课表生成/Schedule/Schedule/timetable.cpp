#include "timetable.h"
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QVariant>
#include <random>
#include <time.h>

#define Pc 0.5
#define	Pt 0.06

using namespace std;

extern QSqlDatabase myDB;

timeTable::timeTable(QObject *parent)
	: QObject(parent)
{
	srand((unsigned int)time(0));
	countnum = 0;
	time1 << "1" << "2" << "3" << "4";
	day << "1" << "2" << "3" << "4" << "5";
	QSqlQuery *query = new QSqlQuery(myDB);
	bool bRet = query->exec("select * from classroom");
	if (bRet)
	{
		while (query->next())
		{
			QString str = query->value(0).toString();
			int vec = query->value(1).toInt();
			classRoom << str;
			roomVector.insert(str, vec);
		}
	}
	else
	{
		QMessageBox::critical(0, tr("error!"), QStringLiteral("��ȡ������Ϣ����"));
	}
	query->clear();
	bRet = query->exec("select * from CourseReqView");
	if (bRet)
	{
		int i = 0;
		while (query->next())
		{
			QStringList a;
			for (int j = 1; j < 10; j++)
			{
				QString str = query->value(j).toString();
				a << str;
			}
			QString str = query->value(10).toString();
			req.insert(str, a);
			i++;
		}
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	query->clear();
	bRet = query->exec("select * from CoursePlanView");
	if (bRet)
	{
		while (query->next())
		{
			int times = query->value(9).toInt();
			for (int i = 0; i < times;i++)
			{
				QStringList a;
				QString str0 = query->value(0).toString();
				QString str1 = query->value(1).toString();
				QString str2 = query->value(3).toString();
				QString str3 = query->value(4).toString();
				QString str4 = query->value(5).toString();
				a << str0 << str1 << str2 << str3 << str4;
				course.push_back(a);
			}
		}
	}
	else
	{
		QString str = query->lastError().type();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
	for (auto i:day)
	{
		for (auto j:time1)
		{
			for (auto k:classRoom)
			{
				QStringList list;
				list << i << j << k;
				timeRoom.push_back(list);
			}
		}
	}
}
void timeTable::start(){
	while (population.size() < Pmax)
	{
		QVector<QStringList> vec;
		QVector<QStringList> ntimeRoom = timeRoom;
		for (auto list :course)
		{
			do{
				if (getAdaptnum(vec) == 0)
				{
					vec.removeLast();
				}
				auto newlist = list;
				if (ntimeRoom.size() == 0)
				{
					ntimeRoom = timeRoom;
				}
				int rand = getRand(0, ntimeRoom.size() - 1);
				auto timeroomlist = ntimeRoom.takeAt(rand);
				newlist << timeroomlist.at(0);
				newlist << timeroomlist.at(1);
				newlist << timeroomlist.at(2);
				vec.push_back(newlist);
			} while (getAdaptnum(vec) == 0);
		}
		if (vec.size() == course.size())
		{
			population.push_back(vec);
		}
	}
	while (countnum<Gmax)
	{
		genetic();
		countnum++;
	}
	finnished();
}
void timeTable::setnum(int g, int p){
	Gmax = g;
	Pmax = p;
}
double timeTable::getAdaptnum(QVector<QStringList> vec){
	int tolnum1 = 1;//����ͳ�Ƹ���������а༶ͬʱ�����ſΣ���ʦͬʱ�����ſΣ�����ͬʱ�����ſΣ������������㡣�κ�һ��������ֱ����ӦֵΪ0;
	double tolnum2 = 0;//����ͳ��ͬһ�γ�Ӧ�ü��1�죬���һ������0�֣���������8�֣�ͬһ��10��
	double tolnum3 = 0;//����ͳ�ƿγ��Ƿ��������ʦ��Ҫ�󣬷�ͬһ�죬��ͬһ��ʱ�Σ���ͬһ�����ң����������ֱ����6��3��1�ķ�ֵ
	QString front = NULL;//��¼ǰһ���γ̵Ĵ��α��
	int id = 0;//����ȷ����Ӧ����Ҫ����±�λ��
	
	int aid = 0;
	for (auto &a:vec)
	{
		bool flag2[2] = { false, false };//��־Լ������2�ĺ����������������
		bool flag3[3] = { false, false, false };//��־Լ������3�����������������
		int bid = 0;
		for(auto &b:vec)
		{
			if (aid != bid)
			{
				if (a.at(5).compare(b.at(5)) == 0 && a.at(6).compare(b.at(6)) == 0)
				{
					//���Ҹ��ſγ��еİ༶�Ƿ�ͬʱ���������γ�
					for (int i = 2; i < 5; i++)
					{
						if (a.at(i).length() == 1)
						{
							break;
						}
						for (int j = 2; j < 5;j++)
						{
							if (b.at(j).length() == 1)
							{
								break;
							}
							if (a.at(i).compare(b.at(j)) == 0)
							{
								tolnum1 = 0;
							}
						}
					}
					//������ʦ�Ƿ�ͬʱ�����������γ�
					if (a.at(1).compare(b.at(1)) == 0)
					{
						tolnum1 = 0;
					}
					//���ý����Ƿ�ͬʱ�����������γ�
					if (a.at(7).compare(b.at(7)) == 0)
					{
						tolnum1 = 0;
					}
				}


				//������ͬ�γ̼��
				if (a.at(0).compare(b.at(0)) == 0)
				{
					int aday = a.at(5).toInt();
					int bday = b.at(5).toInt();
					if (aday - bday == 0)
					{
						flag2[0] = true;
					}
					else if (aday - bday ==1 ||aday - bday == -1)
					{
						flag2[1] = true;
					}
				}
			}

			bid++;
		}

		//�����������Ƿ�����
		int studentNum = 50;
		if (a.at(3).length() !=1)
		{
			studentNum += 50;
		}
		if (a.at(4).length() != 1)
		{
			studentNum += 50;
		}
		int classvec = roomVector.value(a.at(7));//ȡ��������
		if (classvec < studentNum)
		{
			tolnum1 = 0;
		}
		QString courseNum = a.at(0);
		//���γ��Ƿ������ʦҪ��,�����Ϸ�ֵ��
		if (courseNum.compare(front) != 0)
		{
			id = 0;
		}
		front = courseNum;
		QStringList newlist = req.value(courseNum);
		if (newlist.length() != 0)
		{
			if (a.at(5).compare(newlist.at(id)) != 0)
			{
				flag3[0] = true;
			}
			id++;
			if (a.at(6).compare(newlist.at(id)) != 0)
			{
				flag3[1] = true;
			}
			id++;
			if (a.at(7).compare(newlist.at(id)) != 0)
			{
				flag3[2] = true;
			}
			id++;
		}


		//���γ�Լ������2���Լ����ֵ����
		if (flag2[0])
		{
			tolnum2 += 10;
		}
		else if (flag2[1])
		{
			tolnum2 += 8;
		}
		//���γ�Լ������3��ʦҪ���ֵ����
		if (flag3[0]){
			tolnum3 += 6;
		}
		if (flag3[1])
		{
			tolnum3 += 3;
		}
		if (flag3[2])
		{
			tolnum3 += 1;
		}
		aid++;

	}

	double adapt = (10 - (tolnum2 * 4 + tolnum3 * 6) / (10 * vec.size()))* tolnum1;
	return adapt;
}
int timeTable::getRand(int i, int j){
	if (i == j)
	{
		return i;
	}
	int k = rand() % (j-i) + i;
	return k;
}
double timeTable::getRand(double i, double j){
	if (i == j)
	{
		return i;
	}
	double K = rand() / double(RAND_MAX / (j - i))+i;//��ȡi - j��Χ�������
	return K;
}
int timeTable::roulette(QVector<double> vec){
	double sum = 0;
	for (auto a:vec)
	{
		sum += a;
	}
	double a = getRand(0.0, sum);
	double b = 0;
	int m = 0;
	while (b<a)
	{
		m = getRand(0, vec.size());
		b += vec.at(m);
	}
	return m;
}
void timeTable::genetic(){
	QVector<double> vec;
	QVector <QStringList> little = population.at(0);
	double littlenum = getAdaptnum(little);

	adaptNum.clear();
	for (auto a:population)
	{
		double num = getAdaptnum(a);
		if (num>littlenum)
		{
			littlenum = num;
			little = a;
		}
		adaptNum.push_back(num);
	}
	QVector<QVector <QStringList>> newpopulation;
	newpopulation.push_back(little);
	while (newpopulation.size()<Pmax)
	{
		int m = roulette(adaptNum);
		int n = roulette(adaptNum);

		QVector<QStringList> munit = population.at(m);
		QVector<QStringList> nunit = population.at(n);

		bool flag1 = exchange(munit, nunit);
		bool flag2 = variation(munit);
		bool flag3 = variation(nunit);
		if (flag1||flag2)
		{
			if (getAdaptnum(munit) >= getAdaptnum(population.at(m))){
				if (newpopulation.size() < Pmax)
				{
					newpopulation.push_back(munit);
				}
			}
			else
			{
				if (newpopulation.size() < Pmax)
				{
					newpopulation.push_back(population.at(m));
				}
			}
		}
		if (flag1||flag3)
		{
			if (getAdaptnum(nunit) >= getAdaptnum(population.at(n))){
				if (newpopulation.size() < Pmax)
				{
					newpopulation.push_back(nunit);
				}
			}
			else
			{
				if (newpopulation.size() < Pmax)
				{
					newpopulation.push_back(population.at(n));
				}
			}
		}		
	}
	population = newpopulation;
}
bool timeTable::exchange(QVector<QStringList> &m, QVector<QStringList> &n){
	int randnum = getRand(0, 100);
	if (randnum >= (Pc * 100))//�Ƿ�������
	{
		return false;
	}
	int i = getRand(0, m.size() - 1);
	QStringList mlist = m.at(i);//ȡ������Ⱦɫ��
	QStringList nlist = n.at(i);
	int j = getRand(5, 7);
	for (j; j < 8; j++)
	{
		QString mstr = mlist.at(j);
		QString nstr = nlist.at(j);
		mlist.replace(j, nstr);
		nlist.replace(j, mstr);
		m.replace(i, mlist);
		n.replace(i, nlist);
	}
	i++;
	//�����������ȫ���滻
	for (i; i < m.size();i++)
	{
		mlist = m.at(i);
		nlist = n.at(i);
		n.replace(i, mlist);
		m.replace(i, nlist);
	}
	return true;
}
bool timeTable::variation(QVector<QStringList> &vec){
		int randnum = getRand(0, 1000);
		if (randnum > (Pt * 1000))//�Ƿ�������
		{
			return false;
		}
		int i = getRand(0, vec.size() - 1);
		int j = getRand(5, 7);
		QStringList list = vec.at(i);
		QString str = NULL;
		QString datstr = list.at(j);
		if (j == 5)
		{
			while (str.compare(datstr) == 0 || str.size() == 0)
			{
				int k = getRand(0, day.size() - 1);
				str = day.at(k);
			}
		}
		if (j == 6)
		{
			while (str.compare(datstr) == 0 || str.size() == 0)
			{
				int k = getRand(0, time1.size() - 1);
				str = time1.at(k);
			}
		}
		if (j == 7)
		{
			while (str.compare(datstr) == 0 || str.size() == 0)
			{
				int k = getRand(0, classRoom.size() - 1);
				str = classRoom.at(k);
			}
		}
		list.replace(j, str);
		vec.replace(i, list);
	return true;
}
void timeTable::finnished(){
	QVector<QStringList> vec = population.at(0);
	QSqlQuery *query = new QSqlQuery(myDB);
	bool flag = true;
	for (auto list:vec)
	{
		QString Coursenum = list.at(0);
		QString daynum = list.at(5);
		QString timenum = list.at(6);
		QString roomnum = list.at(7);

		bool bRet = query->exec(QString("insert into timetable values(%1,%2,%3,%4)").arg(daynum).arg(timenum).arg(roomnum).arg(Coursenum));
		if (!bRet)
		{
			if (flag)
			{
				QString str = query->lastError().type();
				QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
				flag = false;
			}
		}
	}
	/*if (!flag)
	{
		bool bRet = query->exec(QString("delete from timetable"));
		if (!bRet)
		{
			QString str = query->lastError().type();
			QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
		}
	}*/
}
timeTable::~timeTable()
{

}
