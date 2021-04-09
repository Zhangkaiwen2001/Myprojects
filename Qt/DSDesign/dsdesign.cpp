#include "dsdesign.h"
#include "ui_dsdesign.h"
#include<QMessageBox>
#include<QDebug>
#include<QStack>
#include<QPainter>
#include<QString>
#include<QFile>
#include<QtSql>

DSDesign::DSDesign(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DSDesign)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());
    this->setWindowTitle("校园排课软件");
    this->setWindowIcon(QIcon(":///icon.ico"));
    for(int i=1;i<100;i++)
    {
        ist[i].isvalid=3;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("mydata");
        db.setUserName("root");
        db.setPassword("root");
        bool ok = db.open();
        if (ok){
            QMessageBox::information(this, "数据库连接", "success");
        }
        else {
            QMessageBox::information(this, "infor", "open failed");
            qDebug()<<"error open database because"<<db.lastError().text();
        }
}

DSDesign::~DSDesign()
{
    delete ui;
}

void DSDesign::on_btn_classnum_clicked()
{
    int classNum = ui->line_classnum->text().toInt();
    A.vexnum = classNum;
    if(A.vexnum==classNum)
    {
        QMessageBox msgBox(QMessageBox::Warning, tr("提示"),
                       "设置课数成功", 0, this);
        char cln[100]={0};
        sprintf(cln,"%d",A.vexnum);
        msgBox.setDetailedText(tr(cln));
        msgBox.exec();
    }
}

void DSDesign::on_btn_over_clicked()
{
    QString f = ui->line_over_1->text();
    if(f == NULL)
    {
        QMessageBox msgBox(QMessageBox::Warning, tr("提示"),
                   "您未输入任何信息", 0, this);
        msgBox.exec();
    }
    else
    {
        QString data1 = ui->line_over_1->text();
        QString data2 = ui->line_over_2->text();
        QString data3 = ui->line_over_3->text();
        QString data4 = ui->line_over_4->text();
        if(data1.toInt()>=100||data3>=100)
        {
            QMessageBox msg;
            msg.setWindowTitle("学期输入");
            msg.setWindowIcon(QIcon(":///icon.ico"));
            msg.setText("请输入100以内的课程序号或课程前序");
            msg.exec();
        }
        else
        {
            istlen++;
            ist[istlen].isvalid=1;
            ist[istlen].flag = data1.toInt();
            ist[istlen].classname = data2;
            ist[istlen].pre = data3.toInt();
            ist[istlen].classtime = data4.toInt();
            OutputInf();
        }
    }
}

void DSDesign::on_btn_toltimes_clicked()
{
    int classTolTimes = ui->line_CTimes->text().toInt();
    A.termperiod = classTolTimes;
    if(A.termperiod == classTolTimes)
    {
        QMessageBox msgBox(QMessageBox::Warning, tr("提示"),
                   "设置课程总时长成功", 0, this);
        char cln[100]={0};
        sprintf(cln,"%d",A.termperiod);
        msgBox.setDetailedText(tr(cln));
        msgBox.exec();
    }
}

void DSDesign::on_btn_output_clicked()
{
    ui->textBrowser_1->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_3->clear();
    ui->textBrowser_4->clear();
    QString f = A.vertices[1].classname;
    if(f == NULL)
    {
        QMessageBox msgBox(QMessageBox::Warning, tr("提示"),
                   "您未输入任何信息或输入信息格式错误", 0, this);
        msgBox.exec();
    }
    else
    {
        int i=ans[0],j=1,tmp;
        while(i>=1)
        {
            tmp = A.termperiod;
            while(tmp-A.vertices[ans[i]].classtime>=0&&i>=1)
            {
                tmp=tmp-A.vertices[ans[i]].classtime;
                A.vertices[ans[i]].term = j;
                switch (j) {
                case 1:
                    ui->textBrowser_1->append(A.vertices[ans[i]].classname);//输出到textbrowser
                    break;
                case 2:
                    ui->textBrowser_2->append(A.vertices[ans[i]].classname);//输出到textbrowser
                    break;
                case 3:
                    ui->textBrowser_3->append(A.vertices[ans[i]].classname);//输出到textbrowser
                    break;
                case 4:
                    ui->textBrowser_4->append(A.vertices[ans[i]].classname);//输出到textbrowser
                    break;
                  }
                i--;
              }
            j++;
          }
    }
}

void DSDesign::create()
{
    for(int i=1; i<=A.vexnum; i++)
    {
        for(int j=1; j<A.vertices[i].precourse[0]; j++)
        {
            ArcNode *s=(ArcNode *)malloc(sizeof(ArcNode));
            s->adjvex=i;
            s->next= A.vertices[A.vertices[i].precourse[j]].firstarc;
            A.vertices[A.vertices[i].precourse[j]].firstarc=s;
        }
    }
}

void DSDesign::FindInDegree(ALGraph G)
{
    create();
    int i;
    ArcNode *p;
    for(int j=0; j<100; j++)
    {
        indegree[j]=0;
    }
    for (i=1; i<=G.vexnum; i++)
    {
        p=G.vertices[i].firstarc;
        while (p!=NULL)
        {
            indegree[p->adjvex]++;
            p=p->next;
        }
    }
}

void DSDesign::TopologicalSort(ALGraph G)
{
    QStack<int> S;
    int Count,k,i;
    ArcNode *p;
    FindInDegree(G); // 对各顶点求入度
    for (i=1; i<=G.vexnum; ++i)
    // 建零入度顶点栈S
        if (!indegree[i])
        {
            S.push(i);
        }
    // 入度为0者进栈
      Count = 0;
    // 对输出顶点计数
    while (!S.empty())
    {
        i=S.top();
        S.pop();
        ans[0]+=1;
        ans[ans[0]]=i;
        ++Count;
        for (p=G.vertices[i].firstarc; p; p=p->next)
        {
            k = p->adjvex;
            if (!(--indegree[k]))
                S.push(k);
        }
    }
}

void DSDesign::on_btn_delete_clicked()
{
    int i = ui->line_delete->text().toInt();
    if(i!=0)
    {
        ist[i].isvalid = 0;
    }
    OutputInf();
}

void DSDesign::OutputInf()
{
    ui->textBrowser_inT->clear();
    ui->textBrowser_cN->clear();
    ui->textBrowser_Cno->clear();
    ui->textBrowser_cT->clear();
    ui->textBrowser_cP->clear();
    for(int i=1;i<=istlen;i++)
    {
        if(ist[i].isvalid==1)
        {
            //文件操作
            /*
            QFile file("D:\\MyProjects\\Qt\\DSDesign\\data.txt");
            file.open(QIODevice::Append | QIODevice::Text);
            //写入文件需要字符串为QByteArray格式
            QString isl;
            isl = QString::number(i,10,0);
            ui->textBrowser_inT->append(isl);//输出到textbrowser
            file.write(ist[i].classname.toUtf8());
            ui->textBrowser_cN->append(ist[i].classname);//输出到textbrowser
            isl = "\t";
            file.write(isl.toUtf8());
            isl = QString::number(ist[i].flag,10,0);
            file.write(isl.toUtf8());
            ui->textBrowser_Cno->append(isl);//输出到textbrowser
            isl = "\t";
            file.write(isl.toUtf8());
            isl = QString::number(ist[i].classtime,10,0);
            file.write(isl.toUtf8());
            ui->textBrowser_cT->append(isl);//输出到textbrowser
            isl = "\t";
            file.write(isl.toUtf8());
            isl = QString::number(ist[i].pre,10,0);
            file.write(isl.toUtf8());
            ui->textBrowser_cP->append(isl);//输出到textbrowser
            isl = "\t";
            file.write(isl.toUtf8());
            isl = "\n";
            file.write(isl.toUtf8());
            file.close();
            */
            //地方错误
            QString isl;
            isl = QString::number(i,10,0);
            ui->textBrowser_inT->append(isl);//输出到textbrowser
            ui->textBrowser_cN->append(ist[i].classname);//输出到textbrowser
            isl = QString::number(ist[i].flag,10,0);
            ui->textBrowser_Cno->append(isl);//输出到textbrowser
            isl = QString::number(ist[i].classtime,10,0);
            ui->textBrowser_cT->append(isl);//输出到textbrowser
            isl = QString::number(ist[i].pre,10,0);
            ui->textBrowser_cP->append(isl);//输出到textbrowser
        }
    }
}

void DSDesign::on_btn_sort_clicked()
{
    if(A.vexnum == 0||A.termperiod == 0)
    {
        QMessageBox msgBox(QMessageBox::Warning, tr("提示"),
                   "课程数量与学期时长未输入", 0, this);
        msgBox.exec();
    }
    else
    {
        int i=1;
        QSqlQuery query;
        query.exec("select * from class");
        while (true == query.next()) {  //一行一行遍历
            //取出当前行的内容，以列为单位
            qDebug() << query.value(0).toInt()  //取第一列
                     << query.value(1).toString() //取第二列
                     << query.value(2).toInt()  //按名字查找
                     << query.value(3).toInt();
            A.flag = query.value(0).toInt();
            A.vertices[A.flag].classname = query.value(1).toString();
            A.vertices[A.flag].precourse[A.vertices[A.flag].precourse[0]] = query.value(2).toInt();
            A.vertices[A.flag].precourse[0]++;
            A.vertices[A.flag].classtime = query.value("classtime").toInt();
        }
        while(ist[i].isvalid!=3)
        {
            if(ist[i].isvalid==1)
            {
                A.flag = ist[i].flag;
                A.vertices[A.flag].classname = ist[i].classname;
                A.vertices[A.flag].precourse[A.vertices[A.flag].precourse[0]] = ist[i].pre;
                A.vertices[A.flag].precourse[0]++;
                A.vertices[A.flag].classtime = ist[i].classtime;
                QSqlQuery query;
                query.prepare("INSERT INTO class (classno, classname, c_precourse, classtime) "
                              "VALUES (:classno, :classname, :c_precourse, :classtime)");
                query.bindValue(0, A.flag);
                query.bindValue(1, A.vertices[A.flag].classname);
                query.bindValue(2, ist[i].pre);
                query.bindValue(3, A.vertices[A.flag].classtime);
                query.exec();
            }
            i++;
        }
        TopologicalSort(A);
    }
}

void DSDesign::on_btn_search_clicked()
{
    int i;
    QString n;
    n = ui->line_search->text();
    if(n==NULL)
    {
        QMessageBox msg;
        msg.setWindowTitle("学期查找");
        msg.setWindowIcon(QIcon(":///icon.ico"));
        msg.setText("您未输入信息");
        msg.exec();
    }
    else
    {
        int flag = 0;
        for(i=1;i<=A.vexnum;i++)
        {
            if(n.compare(A.vertices[i].classname) == 0)
            {
                flag = 1;
                QMessageBox msg;
                QString t;
                t = QString::number(A.vertices[i].term,10,0);
                msg.setWindowTitle("学期查找");
                msg.setWindowIcon(QIcon(":///icon.ico"));
                ArcNode* pre = NULL;
                pre = A.vertices[i].firstarc;
                QString tol;
                tol = "课程所在学期为第"+t+"学期,后序课程有：";
                while (pre) {
                    tol = tol +A.vertices[pre->adjvex].classname + '\t';
                    pre = pre->next;
                }
                msg.setText(tol);
                msg.exec();
            }
        }
        if(flag == 0)
        {
            QMessageBox msg;
            msg.setWindowTitle("学期查找");
            msg.setWindowIcon(QIcon(":///icon.ico"));
            msg.setText("未找到所在课程");
            msg.exec();
        }
    }
}

void DSDesign::on_btn_change_clicked()
{
    int i;
    int flag = 0;
    QString n;
    n = ui->line_change_1->text();
    if(n == NULL)
    {
        QMessageBox msg;
        msg.setWindowTitle("课程名修改");
        msg.setWindowIcon(QIcon(":///icon.ico"));
        msg.setText("您未输入信息");
        msg.exec();
    }
    else
    {
        for(i=1;i<=A.vexnum;i++)
        {
            if(n.compare(A.vertices[i].classname) == 0)
            {
                flag = 1;
                QMessageBox msg;
                QString t;
                t = ui->line_change_2->text();
                if(t == NULL)
                {
                    QMessageBox msg;
                    msg.setWindowTitle("课程名修改");
                    msg.setWindowIcon(QIcon(":///icon.ico"));
                    msg.setText("修改名不能为空");
                    msg.exec();
                }
                else
                {
                    A.vertices[i].classname = t;
                    QMessageBox msg;
                    msg.setWindowTitle("课程名修改");
                    msg.setWindowIcon(QIcon(":///icon.ico"));
                    msg.setText("修改成功");
                    msg.exec();
                }
            }
        }
        if(flag == 0)
        {
            QMessageBox msg;
            msg.setWindowTitle("课程名修改");
            msg.setWindowIcon(QIcon(":///icon.ico"));
            msg.setText("未找到该课程");
            msg.exec();
        }
    }
}
