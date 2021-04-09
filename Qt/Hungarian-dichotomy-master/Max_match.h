//
// Created by Wentw on 2018/12/27.
//

#ifndef UNTITLED_CLASS_MAX_MATCH_H
#define UNTITLED_CLASS_MAX_MATCH_H

#include "header.h"
#include "Tea_Cou_Data.h"

class Max_match {
private:
    int linker_T[20];    //linker_T[教师编号]=课程编号
    int linker_C[20];    //记录匹配信息
    bool used[20];       //判断课程是否有人教授
public:
    bool find_path(int teacher, Tea_Cou_Data &TC);//寻找匹配
    int hungary_algorithnm(Tea_Cou_Data &TC);//匈牙利二分法
    void show_result(Tea_Cou_Data &TC);//展示老师与对应的课程
};


#endif //UNTITLED_CLASS_MAX_MATCH_H
