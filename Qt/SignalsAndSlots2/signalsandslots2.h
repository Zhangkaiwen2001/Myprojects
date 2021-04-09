#ifndef SIGNALSANDSLOTS2_H
#define SIGNALSANDSLOTS2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SignalsAndSlots2; }
QT_END_NAMESPACE

class SignalsAndSlots2 : public QMainWindow
{
    Q_OBJECT

public:
    SignalsAndSlots2(QWidget *parent = nullptr);
    ~SignalsAndSlots2();

private slots:
    void on_pushButton_toggled(bool checked);

private:
    Ui::SignalsAndSlots2 *ui;
};
#endif // SIGNALSANDSLOTS2_H
