#ifndef SIGNALSANDSLOTSWIDGET_H
#define SIGNALSANDSLOTSWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SignalsAndSlotsWidget; }
QT_END_NAMESPACE

class SignalsAndSlotsWidget : public QWidget
{
    Q_OBJECT

public:
    SignalsAndSlotsWidget(QWidget *parent = nullptr);
    ~SignalsAndSlotsWidget();

signals:
    //自定义信号，发出信号槽，使得QLabel显示文字
    void sigShowVal(const QString&);

public slots:
    //自定义信号，当LineEdit发出文字改变的信号时，执行这个槽
    void sltLineEditChanged(const QString& text);
private:
    Ui::SignalsAndSlotsWidget *ui;
};
#endif // SIGNALSANDSLOTSWIDGET_H
