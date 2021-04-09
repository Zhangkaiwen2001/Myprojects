#include "signalsandslotswidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignalsAndSlotsWidget w;
    w.show();
    return a.exec();
}
