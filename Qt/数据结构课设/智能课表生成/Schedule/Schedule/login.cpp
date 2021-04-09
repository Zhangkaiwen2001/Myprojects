#include "login.h"
#include <QPalette>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QHostAddress>
#include <QBitArray>
#include <QSql>

QSqlDatabase myDB;
QString id;
QTcpSocket * tsocket;

Schedule::Schedule(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QPalette palette;
	palette.setBrush(QPalette::Background, QBrush(QPixmap(":/Schedule/Resources/bg.png")));
	ui.centralWidget->setPalette(palette);
	ui.loginBtn->setFlat(true);
	tsocket = new QTcpSocket(this);
	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(userLogin()));
	connect(tsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(showError(QAbstractSocket::SocketError)));
}
void Schedule::userLogin(){
	Connection();
	QString username = ui.username->text();
	id = username;
	QString password = ui.password->text();
	int power = ui.powerBox->currentIndex();
	power++;
	if (username == NULL || password == NULL)
	{
		QMessageBox::critical(0, QStringLiteral("警告!"), QStringLiteral("账号或密码不能为空!"));
		return;
	}
	QSqlQuery *query = new QSqlQuery(myDB);
	query->prepare("exec userLogin ?,?,?,?");
	query->bindValue(0, username);
	query->bindValue(1, password);
	query->bindValue(2, power);
	query->bindValue(3, 2, QSql::Out);
	bool bRet = query->exec();
	if (bRet)
	{
		int result = query->boundValue(3).toInt();
		if (result == 0)
		{
			QMessageBox::critical(0, tr("error!"), QStringLiteral("账号或密码错误！"));
			return;
		}
		if (power == 3)
		{
			this->close();
			s.show();
			s.initUI();
			s.setName(QStringLiteral("教学秘书"));
			s.updataC();
			s.updataT();
		}
		if (power == 2)
		{
			this->close();
			t.show();
			t.initUI();
		}
		if (power == 1)
		{
			this->close();
			st.show();
			st.initUI();
		}
	}
	else
	{
		QString str = query->lastError().text();
		QMessageBox::critical(0, tr("error!"), tr("%1").arg(str));
	}
}
bool Schedule::Connection()
{
	QString serverName = "(local)";
	QString dbName = "tableview";
	myDB = QSqlDatabase::addDatabase("QODBC");//连接到ODBC驱动
	QString dsn = QString("Driver={SQL Server};Server=%1;Database=%2;Trusted_Connection=yes").arg(serverName).arg(dbName);
	myDB.setDatabaseName(dsn);
	myDB.open();
	return true;
}
Schedule::~Schedule()
{

}
void Schedule::showError(QAbstractSocket::SocketError socketError){
	switch (socketError){
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::information(this, QStringLiteral("课表服务客户端"), QStringLiteral("服务器不可达"));
		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::information(this, QStringLiteral("课表服务客户端"), QStringLiteral("连接被拒绝"));
		break;
	default:
		QMessageBox::information(this, QStringLiteral("课表服务客户端"), QStringLiteral("主机产生如下错误：%1").arg(tsocket->errorString()));
	}
}