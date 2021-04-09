#pragma execution_character_set("utf-8")
#include "ui_widgetproperty.h"
#include "widgetproperty.h"

WidgetProperty::WidgetProperty(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetProperty)
{
    ui->setupUi(this);
    //设置窗口背景颜色
    setAutoFillBackground(true);
    QPalette pa = this->palette();
    pa.setBrush(QPalette::Background,QBrush(Qt::gray));
    setPalette(pa);

    //设置窗口透明度
    setWindowOpacity(0.9);

    //设置窗口标题
    setWindowTitle("窗口属性");

    //设置悬停标志
    setToolTip("悬停");

    //重设大小
    resize(600,400);

    //移动
    move(0,0);
}

WidgetProperty::~WidgetProperty()
{
    delete ui;
}
