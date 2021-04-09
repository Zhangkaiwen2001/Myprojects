# pragma execution_character_set("utf-8")
#include "customdialog.h"
#include "ui_customdialog.h"

CustomDialog::CustomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomDialog)
{
    ui->setupUi(this);
}

CustomDialog::~CustomDialog()
{
    delete ui;
}
