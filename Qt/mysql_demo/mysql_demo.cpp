#include "mysql_demo.h"
#include "ui_mysql_demo.h"
#include<QMessageBox>
#include<QDebug>
#include<QtSql>

mysql_demo::mysql_demo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mysql_demo)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("mydata");
        db.setUserName("root");
        db.setPassword("root");
        bool ok = db.open();
        if (ok){
            QMessageBox::information(this, "infor", "success");
        }
        else {
            QMessageBox::information(this, "infor", "open failed");
            qDebug()<<"error open database because"<<db.lastError().text();
        }
        //查询数据库中所有表的名称
            QStringList tables = db.tables();
            foreach(QString table, tables)
                qDebug()<<table;
/*
        //ODBC查询数据
            QSqlQuery result = db.exec(" select * from users");
            while(result.next()){
                qDebug()<<"user_id:"<<result.value("user_id").toInt();
                qDebug()<<"name:"<<result.value("name").toString();
                qDebug()<<"password:"<<result.value("password").toString();
                qDebug()<<"score:"<<result.value("score").toInt()<<endl;
            }
            */
       db.close();
}

mysql_demo::~mysql_demo()
{
    delete ui;
}

void mysql_demo::on_btn_insert_clicked()
{
    //ODBC插入数据
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    if(db.open()){
        QSqlQuery query;
        query.prepare("INSERT INTO person (id, forename, surname) "
                      "VALUES (:id, :forename, :surname)");
        query.bindValue(0, 1002);
        query.bindValue(1, "Lei");
        query.bindValue(2, "Li");
        query.exec();
    }
        db.close();
}

void mysql_demo::on_btn_delete_clicked()
{
    QString id = ui->lineEdit->text();
    QString sql = QString("delete from person where id = '%0'").arg(id);
    qDebug() << sql;
    //开启一个事务
    QSqlDatabase::database().transaction();
    // 执行sql语句
    QSqlQuery query;
    query.exec(sql);
    QSqlDatabase::database().commit();
}
