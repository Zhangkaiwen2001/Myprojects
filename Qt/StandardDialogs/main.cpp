#include "standarddialogs.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StandardDialogs w;
    w.show();
    return a.exec();
}
