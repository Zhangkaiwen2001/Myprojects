#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(523,591);
    ui->textEdit_show->setText("please press the button.");
    process="";
    result=0;
    S="";
    stat=0;
    choose=0;
    sum=0;
    dot=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_Exit_clicked()
{
    close();
}

void MainWindow::on_pushButton_clear_clicked()
{
    result=0;
    S="";
    process="";
    stat=0;
    choose=0;
    ui->textEdit_show->setText("please press the button");
    dot=0;
}

void MainWindow::on_pushButton_equal_clicked()
{
    switch (choose)
    {
        case 1:

        result+=S.toFloat()+process.toFloat();
        sum=result;

        Sresult=QString("%1").arg(result);
        ui->textEdit_show->setText(Sresult);
        break;
    case 2:
        result+=S.toFloat()-process.toFloat();
        sum=result;
        Sresult=QString("%1").arg(result);
        ui->textEdit_show->setText(Sresult);
        break;
    case 3:

        if(sum==0)
        {
            result=1;
        }
        else
        {
            result=sum;
        }
        if(S.toFloat()*process.toFloat()!=0)
        {
        result*=S.toFloat()*process.toFloat();
        qDebug()<<result<<""<<sum;
        }
        else
        {
            result*=(S.toFloat()+process.toFloat());
            qDebug()<<result<<""<<sum;
        }
        sum=result;
        Sresult=QString("%1").arg(result);
        ui->textEdit_show->setText(Sresult);
        break;
    case 4:
        if(process.toFloat()==0)
        {
            ui->textEdit_show->setText("system error!");
            QTimer::singleShot(1000,this,SLOT(on_pushButton_clear_clicked()));

            break;
        }
        if(sum==0)
        {
            result=1;
        }
        else
        {
            result=sum;
        }
        if(S.toFloat()/process.toFloat()!=0)
        {
        result=S.toFloat()/process.toFloat();
        qDebug()<<result<<""<<sum;
        }
        else
        {
            result/=(S.toFloat()+process.toFloat());
            qDebug()<<result<<""<<sum;
        }
        sum=result;
        Sresult=QString("%1").arg(result);
        ui->textEdit_show->setText(Sresult);
        break;
    }
    sum=result;
    stat=-1;//如果刚按了等号又按数字，相当于做了一次AC，如果按了等号再按加号，就继续计算。
    choose=0;//告诉程序可以重新接受运算符
    S="";
    process="";
    //因为连续计算，所以不将过程值清0
}

void MainWindow::on_pushButton_1_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }

    if(choose==0)
    {
    S+="1";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="1";
        ui->textEdit_show->setText(process);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="2";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="2";
        ui->textEdit_show->setText(process);
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="3";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="3";
        ui->textEdit_show->setText(process);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="4";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="4";
        ui->textEdit_show->setText(process);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="5";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="5";
        ui->textEdit_show->setText(process);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="6";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="6";
        ui->textEdit_show->setText(process);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="7";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="7";
        ui->textEdit_show->setText(process);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="8";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="8";
        ui->textEdit_show->setText(process);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="9";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="9";
        ui->textEdit_show->setText(process);
    }
}

void MainWindow::on_pushButton_0_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="0";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="0";
        ui->textEdit_show->setText(process);
    }
}

void MainWindow::on_pushButton_plus_clicked()
{
    if(stat==0||stat==-1)
    {
        ui->textEdit_show->append("+");
    }
    stat=1;
    choose=1;
    dot=0;
}

void MainWindow::on_pushButton_jian_clicked()
{
    if(stat==0||stat==-1)
    {
        ui->textEdit_show->append("-");
    }
    stat=1;
    choose=2;
    dot=0;
}

void MainWindow::on_pushButton_chen_clicked()
{
    if(stat==0||stat==-1)
    {
        ui->textEdit_show->append("*");

    }
    sum=result;
    stat=1;
    choose=3;
    dot=0;
}
void MainWindow::on_pushButton_divide_clicked()
{
    if(stat==0||stat==-1)
    {
        ui->textEdit_show->append("/");

    }
    sum=result;
    stat=1;
    choose=4;
    dot=0;
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(dot==0)
    {
    if(choose==0)
    {
        S+=".";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+=".";
        ui->textEdit_show->setText(process);
    }
    }
    stat=1;
    dot=1;
}

void MainWindow::on_pushButton_BackSpace_clicked()
{

    if(choose==0)
    {
    S.chop(1);//退一格
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process.chop(1);
        ui->textEdit_show->setText(process);
    }

}

void MainWindow::on_pushButton_00_clicked()
{
    if(stat==-1)
    {
        result=sum;
        on_pushButton_clear_clicked();
    }
    if(choose==0)
    {
    S+="00";
    ui->textEdit_show->setText(S);
    }
    else if(choose!=0)
    {
        process+="00";
        ui->textEdit_show->setText(process);
    }
}
