#include "widgetproperty.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetProperty w;
    w.show();
    return a.exec();
}
