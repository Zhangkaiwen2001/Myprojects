# pragma execution_character_set("utf-8")
#include "modelwidget.h"
#include "ui_modelwidget.h"
#include"customdialog.h"
#include<QDebug>
#include<QDialog>

ModelWidget::ModelWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModelWidget)
{
    ui->setupUi(this);
}

ModelWidget::~ModelWidget()
{
    delete ui;
}

//弹出窗口模态对话框
void ModelWidget::on_btnWindow_clicked()
{
    QDialog* dlg = new QDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后自动销毁
    dlg->setWindowModality(Qt::WindowModal);
    dlg->show();
    qDebug()<<"显示模态对话框后，不需要用户操作就会马上执行我";

}

//弹出应用模态对话框
void ModelWidget::on_btnApp_clicked()
{
    QDialog* dlg = new QDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后自动销毁
    dlg->setWindowModality(Qt::WindowModal);
    dlg->show();
    qDebug()<<"显示模态对话框后，不需要用户操作就会马上执行我";

}

//自定义模态对话框
void ModelWidget::on_btnCustom_clicked()
{
    CustomDialog* dlg = new CustomDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后自动销毁
    int ret = dlg->exec();
    if(ret == QDialog::Accepted)
    {
        ui->lineEdit->setText("你点击了OK按钮");
    }
    else if(ret == QDialog::Rejected)
    {
        ui->lineEdit->setText("你点击了Cancle按钮");
    }

}
