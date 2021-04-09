#include "dsdesign.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DSDesign w;
    w.show();
    return a.exec();
}
