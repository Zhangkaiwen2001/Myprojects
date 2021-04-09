#ifndef DSDESIGN_H
#define DSDESIGN_H
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class DSDesign; }
QT_END_NAMESPACE

typedef struct ArcNode
{
    int adjvex; // 该弧所指向的顶点的位置
    struct ArcNode *next;// 指向下一条弧的指针
  //InfoType *info; // 该弧相关信息的指针
}ArcNode;

typedef struct vnode//顶点
{
  QString classname;// 顶点信息
  int classtime;//课程时间
  int precourse[100];
  int term;//学期所在
  ArcNode *firstarc;
  vnode()
  {
      this->precourse[0]=1;
  }// 指向第一条依附该顶点的弧
} vnode,adjlist[100];

typedef struct ALGraph
{
  adjlist vertices;//顶点表
  int vexnum;//点数
  int termperiod;
  //int kind; //图的种类标志
  int flag;//标志输入的序号
} ALGraph;
typedef struct instream
{
    int isvalid;
    int flag;
    QString classname;// 顶点信息
    int classtime;//课程时间
    int pre;
} ins;

class DSDesign : public QWidget
{
    Q_OBJECT
public:
    DSDesign(QWidget *parent = nullptr);
    ~DSDesign();
    ALGraph A;
    int ans[100] = {0};
    int indegree[100];
    void create();
    void TopologicalSort(ALGraph G);
    void FindInDegree(ALGraph G);
    void OutputInf();
    ins ist[100];
    int istlen=0;
public slots:
    void on_btn_classnum_clicked();
    void on_btn_over_clicked();
    void on_btn_toltimes_clicked();
    void on_btn_output_clicked();
    void on_btn_delete_clicked();
    void on_btn_sort_clicked();
    void on_btn_search_clicked();
    void on_btn_change_clicked();

private:
    Ui::DSDesign *ui;
};
#endif // DSDESIGN_H
