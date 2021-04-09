//
// Created by Wentw on 2018/12/27.
//

#include "Max_match.h"

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

void Max_match::show_result(Tea_Cou_Data &TC) {
    for(int teacher_No=0;teacher_No<TC.the_sizeofTeacher();teacher_No++)
    {
        if(linker_T[teacher_No]!=-1)
        {
            cout<<"Teacher:"<<TC.the_nameofTeacher(teacher_No)<<"  can teach "<< TC.the_nameofCourse(linker_T[teacher_No]);
            cout<<endl;
        }
    }
}

