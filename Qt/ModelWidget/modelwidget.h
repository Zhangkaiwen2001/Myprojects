#ifndef MODELWIDGET_H
#define MODELWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ModelWidget; }
QT_END_NAMESPACE

class ModelWidget : public QWidget
{
    Q_OBJECT

public:
    ModelWidget(QWidget *parent = nullptr);
    ~ModelWidget();
private slots:
    void on_btnWindow_clicked();
    void on_btnApp_clicked();
    void on_btnCustom_clicked();
private:
    Ui::ModelWidget *ui;
};
#endif // MODELWIDGET_H
