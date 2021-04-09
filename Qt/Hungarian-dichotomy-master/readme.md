# 数据结构课设
## 教务处排课系统 （匈牙利二分法）

---
- 问题描述
  - 如果一个无向图的顶点集合可以分为两个互不相交的子集，并且图中每条边的两个顶点都属于两个不同的顶点集。则称该图为一个二分图。可以用一个二分图表示教师与课程的排课关系。假设每位教师可以胜任多门课程，但一个学期只能讲授一门课程，每学期的每门课程只需一位教师讲授。在二分图中，边数最多的匹配称为图的最大匹配。图的所有顶点都是某条匹配边的顶点，称这个匹配为完全匹配。 
- 设计要求
  - 设计基于二分图的匹配算法求解教务排课表程序。
（1）采用STL的邻接矩阵结构图等数据结构。
（2）应用基本运算，实现按照增广路径的算法求解教务排课表。
---
### 数据结构设计
本次课程设计主要使用了图，vector动态数组存储教师与课程的信息，另外用了两个类Tea_Cou_Data 用来进行数据的存储删除追加等操作， Max_match 用来队数据进行处理。

```
class Tea_Cou_Data {
private:
    bool Matrix[N][M];  //关系矩阵
    vector<string> Teachers;    //教师信息存储
    vector<string>Courses;      //课程信息存储

class Max_match {
private:
    int linker_T[20];    //linker_T[教师编号]=课程编号
    int linker_C[20];    //记录匹配信息
    bool used[20];       //判断课程是否有人教授

```
### 函数原型设计
```
class Tea_Cou_Data {
public:
    Tea_Cou_Data();//构造函数初始化数据
    long long int the_sizeofTeacher();//返回教师人数
    long long int the_sizeofCourse();//返回课程人数
    bool the_conofMatrix(int i,int j);//返回课程与教师的关系
    string the_nameofCourse(int num);//返回第i个课程的名称
    string the_nameofTeacher(int num);//返回第i个老师的名字
    void importdata(); //从文件导入数据
    void Add_Course(); //添加课程
    void Show_teacherandcourse();//打印所有老师与课程
    void Add_Teacher(); //添加老师
    void link_node();   //建立老师与课程的关系
    void delete_teacher();//删除某老师与所有有关课程的关系
    void delete_courses();//删除某课程与所有老师的关系
    void delete_relationship();//删除某课程与某老师的关系
};
class Max_match {
public:
    bool find_path(int teacher, Tea_Cou_Data &TC);//寻找匹配
    int hungary_algorithnm(Tea_Cou_Data &TC);//匈牙利二分法
    void show_result(Tea_Cou_Data &TC);//展示老师与对应的课程

```
---
### 主要算法：匈牙利算法，DFS进行二分图的匹配
```
bool Max_match::find_path(int teacher, Tea_Cou_Data &TC)
{
    for(long long int course_No=0;course_No<TC.the_sizeofCourse();course_No++)
    {
        if(TC.the_conofMatrix(teacher,course_No)&&!used[course_No])//如果老师可以教授这个课程且这个课程目前没有其他老师教授
        {
            used[course_No]=true;//标记此课有老师教授
            if(linker_C[course_No]==-1|| Max_match::find_path(linker_C[course_No], TC)) //这位老师还没有找到课或者能找到他的课
            {
                linker_C[course_No]=teacher;
                linker_T[teacher]=course_No;//标记老师与课程之间的关系
                return true;
            }
        }
    }
    return false;
}
int Max_match::hungary_algorithnm(Tea_Cou_Data &TC)
{
    int res=0;//记录匹配数
    memset(linker_C,-1,sizeof(linker_C));
    memset(linker_T,-1,sizeof(linker_T));
    for(int teacher_No=0;teacher_No<TC.the_sizeofTeacher();teacher_No++)
    {
        memset(used,false, sizeof(used));
        if(find_path(teacher_No, TC))
            res++;

    }
    return res;
}

```



