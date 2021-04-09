#include "standarddialogs.h"
#include "ui_standarddialogs.h"
#include<QInputDialog>
#include<QWizard>
#include<QtDebug>
#include<QColorDialog>
#include<QFontDialog>
#include<QFileDialog>
#include<QProgressDialog>
#include<QMessageBox>
#include<QErrorMessage>

StandardDialogs::StandardDialogs(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StandardDialogs)
{
    ui->setupUi(this);
}

StandardDialogs::~StandardDialogs()
{
    delete ui;
}

void StandardDialogs::on_btn_getint_clicked()
{
    bool ok;
    int i = QInputDialog::getInt(this,tr("情况"),tr("几岁毕业"),25,16,100,1,&ok);
    if(ok)
        ui->label_1->setText(tr("%1").arg(i));
}

void StandardDialogs::on_btn_getdouble_clicked()
{
    bool ok;
    double d = QInputDialog::getDouble(this,tr("工作"),tr("一天挣多少钱"),1000,100,10000,1,&ok);
    if(ok)
        ui->label_2->setText(QString("%1").arg(d));
}

void StandardDialogs::on_btn_getitem_clicked()
{
    QStringList items;
    items<<tr("王者荣耀")<<tr("Dota")<<tr("Dota2")<<tr("LOL");

    bool ok;
    QString item = QInputDialog::getItem(this,tr("游戏"),tr("你玩哪一个"),items,0,false,&ok);
    if(ok&&!item.isEmpty())
        ui->label_3->setText(item);
}

void StandardDialogs::on_btn_gettext_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("发展"),tr("想跳槽吗"), QLineEdit::Normal,tr("懒"), &ok);
    if (ok && !text.isEmpty())
        ui->label_4->setText(text);
}

void StandardDialogs::on_btn_getmtext_clicked()
{
    bool ok;
    QString text = QInputDialog::getMultiLineText(this, tr("计划"),tr("下一步怎么做"), "走着瞧", &ok);
    if (ok && !text.isEmpty())
        ui->label_5->setText(text);
}

void StandardDialogs::on_btn_getcolor_clicked()
{
   QColorDialog::ColorDialogOptions option;
   if (ui->check_alpha->isChecked())
   {
       option = QColorDialog::ShowAlphaChannel;
   }
   const QColor color = QColorDialog::getColor(Qt::green, this, "选择颜色", option);
   ui->widget->setAutoFillBackground(true);
   if (color.isValid())
   {
       ui->btn_getcolor->setText(color.name());
       ui->btn_getcolor->setPalette(QPalette(color));
       ui->btn_getcolor->setAutoFillBackground(true);
   }
   ui->widget->setPalette(color);
}

void StandardDialogs::on_btn_font_clicked()
{
   bool ok;
   QFont font = QFontDialog::getFont(&ok, ui->label_font->font(), this, tr("选择字体"));
   if (ok)
   {
       ui->label_font->setFont(font);
   }
}

void StandardDialogs::on_btn_dir_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this,tr("获取文件夹"),"./");
    if (!directory.isEmpty())
        ui->line_path->setText(directory);
}

void StandardDialogs::on_btn_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("打开一个文件"),"./",tr("All Files (*);;Text Files (*.txt)"));
    if (!fileName.isEmpty())
        ui->line_path->setText(fileName);
}

void StandardDialogs::on_btn_files_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("打开多个文件"),"./",tr("All Files (*);;Text Files (*.txt)"));
    if (files.count())
        ui->line_path->setText(QString("[%1]").arg(files.join(", ")));
}

void StandardDialogs::on_btn_savefile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("保存文件"),"./",tr("All Files (*);;Text Files (*.txt)"));
    if (!fileName.isEmpty())
        ui->line_path->setText(fileName);
}

void StandardDialogs::on_btn_critical_clicked()
{
      QMessageBox::critical(this, tr("危险"), tr("路危险"), tr("返回"), tr("步行"), tr("无视"));
}

void StandardDialogs::on_btn_info_clicked()
{
      QMessageBox::information(this, tr("通知"), tr("会有个女朋友吗"), tr("不可能"), tr("真不可能"));
}

void StandardDialogs::on_btn_question_clicked()
{
       QMessageBox::question(this, tr("问题"),
                                      "喜欢身材好的还是颜值高的",
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
}

void StandardDialogs::on_btn_warning_clicked()
{
      QMessageBox msgBox(QMessageBox::Warning, tr("警告"),
                         "不要调戏女朋友", 0, this);
      msgBox.setDetailedText(tr("真的别"));
      msgBox.addButton(tr("Save &Again"), QMessageBox::AcceptRole);
      msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
      if (msgBox.exec() == QMessageBox::AcceptRole)
          qDebug() << "accept";
}

void StandardDialogs::on_btn_message_clicked()
{
   QErrorMessage message;
   message.showMessage(tr("恭喜你中了5个亿，不好意思，系统出错"));
}

void StandardDialogs::on_btn_progress_clicked()
{
    int numFiles = 50000;
    QProgressDialog progress("复制文件中...", "中断", 0, numFiles, this);
    progress.setWindowModality(Qt::WindowModal);
    progress.show();

    for (int i = 0; i < numFiles; i++)
    {
        progress.setValue(i);
        QCoreApplication::processEvents();
        if (progress.wasCanceled())
            break;
    }
    progress.setValue(numFiles);
}

void StandardDialogs::on_btn_wizard_clicked()
{
    QWizard w(this);
    w.setWindowTitle("向导");

    QWizardPage* page1 = new QWizardPage();
    QWizardPage* page2 = new QWizardPage();
    QWizardPage* page3 = new QWizardPage();

    page1->setTitle("第1步");
    page2->setTitle("第2步");
    page3->setTitle("第3步");

    w.addPage(page1);
    w.addPage(page2);
    w.addPage(page3);
    w.exec();
}
