#include "mysql_demo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mysql_demo w;
    w.show();
    return a.exec();
}
