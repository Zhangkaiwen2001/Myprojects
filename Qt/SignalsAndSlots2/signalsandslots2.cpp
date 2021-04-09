#include "signalsandslots2.h"
#include "ui_signalsandslots2.h"
#pragma execution_character_set("utf-8")

SignalsAndSlots2::SignalsAndSlots2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignalsAndSlots2)
{
    ui->setupUi(this);
}

SignalsAndSlots2::~SignalsAndSlots2()
{
    delete ui;
}


void SignalsAndSlots2::on_pushButton_toggled(bool checked)
{
    if(checked)
    {
        ui->pushButton->setText("隐藏进度条");
    }
    else
    {
        ui->pushButton->setText("显示进度条");
    }
}
