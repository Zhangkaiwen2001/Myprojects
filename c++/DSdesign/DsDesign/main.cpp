#include <iostream>
#include <stdio.h>
#include <stack>
#include <stdlib.h>
#include <string>
using namespace std;
#define N 100
int indegree[N];
int ans[N];
typedef struct ArcNode//边
{
  int adjvex; // 该弧所指向的顶点的位置
  struct ArcNode *next;
// 指向下一条弧的指针
  //InfoType *info; // 该弧相关信息的指针
} ArcNode;
typedef struct vnode//顶点
{
  string classname;// 顶点信息
  int classtime;//课程时间
  int precourse[N];
  ArcNode *firstarc;
  vnode()
  {
    this->precourse[0]=1;
  }
// 指向第一条依附该顶点的弧
} vnode,adjlist[N];
typedef struct ALGraph
{
  adjlist vertices;//顶点表
  int vexnum;//点数
  int termperiod;
  //int kind; //图的种类标志
  void NameChange(){
    int indextmp;
    string name;
    cout<<"Input the index of the class you want to change name:"<<endl;
    cin>>indextmp;
    cout<<"The original name is:"<<this->vertices[indextmp].classname<<endl;
    cout<<"Input the new name:"<<endl;
    cin>>name;
    this->vertices[indextmp].classname=name;
    cout<<"Success! New name is:"<<this->vertices[indextmp].classname<<endl;
  }
  void Init()
  {
    int indextmp,ntmp;
    cout<<"Please input the total number of class:"<<endl;
    cin>>this->vexnum;
    cout<<"Please input the number of input:"<<endl;
    cin>>ntmp;
    cout<<"Now input the information as: index / classname / prerequisite course / classtime:"<<endl;
    for(int i=1; i<=ntmp; i++)
      {
        cin>>indextmp;//有问题
        cin>>this->vertices[indextmp].classname>>this->vertices[indextmp].precourse[this->vertices[indextmp].precourse[0]++];
        cin>>this->vertices[indextmp].classtime;
      }
  }
  void create()
  {
    for(int i=1; i<=this->vexnum; i++)
      {
        for(int j=1; j<this->vertices[i].precourse[0]; j++)
          {
            ArcNode *s=(ArcNode *)malloc(sizeof(ArcNode));
            s->adjvex=i;
            s->next= this->vertices[vertices[i].precourse[j]].firstarc;
            this->vertices[vertices[i].precourse[j]].firstarc=s;
          }
      }
  }
  void TermArrangement()
  {
    cout<<"Set the class hours of a term:"<<endl;
    cin>>this->termperiod;
    int i=1,j=1,tmp;
    while(i<=ans[0])
      {
        tmp=this->termperiod;
        cout<<"The class list of the term "<<j<<":"<<endl;
        while(tmp-vertices[ans[i]].classtime>=0&&i<=ans[0])
          {
            tmp=tmp-vertices[ans[i]].classtime;
            cout<<ans[i]<<" "<<this->vertices[ans[i]].classname<<"  "<<this->vertices[ans[i]].classtime<<endl;
            i++;
          }
        j++;
      }
  }
} ALGraph;
void FindInDegree(ALGraph G)
{
  int i;
  ArcNode *p;
  for (i=1; i<=G.vexnum; i++)
    {
      p=G.vertices[i].firstarc;
      while (p)
        {
          indegree[p->adjvex]++;
          p=p->next;
        }
    }
}
bool TopologicalSort(ALGraph G)
{
  cout<<"TopologicalSort:"<<endl;
  stack<int> S;
  int Count,k,i;
  ArcNode *p;
  //int indegree[N];
  FindInDegree(G); // 对各顶点求入度
  for (i=1; i<=G.vexnum; ++i)
// 建零入度顶点栈S
{
    if (!indegree[i]) S.push(i);
}
// 入度为0者进栈
  Count = 0;
// 对输出顶点计数
  while (!S.empty())
    {
      i=S.top();
      S.pop();
      ans[++ans[0]]=i;
      ++Count;
      for (p=G.vertices[i].firstarc; p; p=p->next)
        {
          k = p->adjvex;
          if (!(--indegree[k])) S.push(k);
        }
    }
  if (Count<G.vexnum) return false;
  else return true;
} // TopologicalSort
int main()
{
  ans[0]=0;
  ALGraph G;
  G.Init();
  G.create();
  //G.NameChange();
  TopologicalSort(G);
  for(int i=1;i<=G.vexnum;i++){
    cout<<ans[i]<<endl;
  }
  G.TermArrangement();
  return 0;
}
