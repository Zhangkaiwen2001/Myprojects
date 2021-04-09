//
// Created by Wentw on 2018/12/27.
//

#ifndef UNTITLED_CLASS_TEA_COU_DATA_H
#define UNTITLED_CLASS_TEA_COU_DATA_H

#include "header.h"

class Tea_Cou_Data {
private:
    bool Matrix[N][M];  //关系矩阵
    vector<string> Teachers;    //教师信息存储
    vector<string>Courses;      //课程信息存储
public:
    Tea_Cou_Data();                     //构造函数初始化数据
    long long int the_sizeofTeacher();  //返回教师人数
    long long int the_sizeofCourse();   //返回课程人数
    bool the_conofMatrix(int i,int j);  //返回课程与教师的关系
    string the_nameofCourse(int num);   //返回第i个课程的名称
    string the_nameofTeacher(int num);  //返回第i个老师的名字
    void importdata();                  //从文件导入数据
    void Add_Course();                  //添加课程
    void Show_teacherandcourse();       //打印所有老师与课程
    void Add_Teacher();                 //添加老师
    void link_node();                   //建立老师与课程的关系
    void delete_teacher();              //删除某老师与所有有关课程的关系
    void delete_courses();              //删除某课程与所有老师的关系
    void delete_relationship();         //删除某课程与某老师的关系
};


#endif //UNTITLED_CLASS_TEA_COU_DATA_H
