#ifndef MYSQL_DEMO_H
#define MYSQL_DEMO_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class mysql_demo; }
QT_END_NAMESPACE

class mysql_demo : public QWidget
{
    Q_OBJECT

public:
    mysql_demo(QWidget *parent = nullptr);
    ~mysql_demo();

public slots:
    void on_btn_insert_clicked();
    void on_btn_delete_clicked();
private:
    Ui::mysql_demo *ui;
};
#endif // MYSQL_DEMO_H
