#ifndef STANDARDDIALOGS_H
#define STANDARDDIALOGS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class StandardDialogs; }
QT_END_NAMESPACE

class StandardDialogs : public QWidget
{
    Q_OBJECT

public:
    StandardDialogs(QWidget *parent = nullptr);
    ~StandardDialogs();
public slots:
    //输入对话框
    void on_btn_getint_clicked();
    void on_btn_getdouble_clicked();
    void on_btn_getitem_clicked();
    void on_btn_gettext_clicked();
    void on_btn_getmtext_clicked();
    //颜色对话框
    void on_btn_getcolor_clicked();
    //字体对话框
    void on_btn_font_clicked();
    //文件对话框
    void on_btn_dir_clicked();
    void on_btn_file_clicked();
    void on_btn_files_clicked();
    void on_btn_savefile_clicked();
    //提示对话框
    void on_btn_critical_clicked();
    void on_btn_info_clicked();
    void on_btn_question_clicked();
    void on_btn_warning_clicked();
    void on_btn_message_clicked();
    //进度对话框
    void on_btn_progress_clicked();
    //向导对话框
    void on_btn_wizard_clicked();
private:
    Ui::StandardDialogs *ui;
};
#endif // STANDARDDIALOGS_H
