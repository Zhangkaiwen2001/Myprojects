# pragma execution_character_set("utf-8")
#include "modelwidget.h"
#include<QDebug>
#include <QApplication>
#include<QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModelWidget w;
    w.show();

    //非模态对话框
    QDialog modelLessDlg;
    modelLessDlg.setWindowTitle("非模态对话框");
    modelLessDlg.show();
    modelLessDlg.resize(200,100);
    qDebug()<<"显示完非模态对话框后，不需要用户操作就会马上执行我";


    return a.exec();
}
