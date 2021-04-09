#ifndef WIDGETPROPERTY_H
#define WIDGETPROPERTY_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetProperty; }
QT_END_NAMESPACE

class WidgetProperty : public QWidget
{
    Q_OBJECT

public:
    WidgetProperty(QWidget *parent = nullptr);
    ~WidgetProperty();

private:
    Ui::WidgetProperty *ui;
};
#endif // WIDGETPROPERTY_H
