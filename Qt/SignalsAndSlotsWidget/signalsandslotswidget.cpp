#include "signalsandslotswidget.h"
#include "ui_signalsandslotswidget.h"
#include"QIntValidator"

SignalsAndSlotsWidget::SignalsAndSlotsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignalsAndSlotsWidget)
{
    ui->setupUi(this);
    int max = 100;
    int min = 0;
    ui->horizontalSlider->setMaximum(max);
    ui->horizontalSlider->setMinimum(min);

    //设置QLineEdit只能输入数字，且为0-100
    QIntValidator* validator = new QIntValidator(min,max,this);
    ui->lineEdit->setValidator(validator);
    connect(ui->lineEdit,&QLineEdit::textChanged,this,&SignalsAndSlotsWidget::sltLineEditChanged);

    connect(this,SIGNAL(sigShowVal(QString)),ui->label,SLOT(setText(QString)));
}

SignalsAndSlotsWidget::~SignalsAndSlotsWidget()
{
    delete ui;
}

void SignalsAndSlotsWidget::sltLineEditChanged(const QString &text)
{
    int val = text.toInt();
    ui->horizontalSlider->setValue(val);//设置slider当前值
    emit sigShowVal(text);//通知label显示文字
}
