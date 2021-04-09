#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct data
{
    char no[7];
    char name[9];
    int grade;
} Student;

int partition(Student stu[],int low,int high,int flag)//flag用于表示对哪一个指标排序
{
    switch (flag)
    {
        char pivotkey1[7];
        char pivotkey2[9];
        int pivotkey3;
    case 1 ://对学号排序
        strcpy(pivotkey1,stu[low].no);
        strcpy(pivotkey2,stu[low].name);
        pivotkey3=stu[low].grade;
        while(low<high)
        {
            while(low<high&&strcmp(stu[high].no,pivotkey1)>=0)
                --high;
            strcpy(stu[low].no,stu[high].no);
            strcpy(stu[low].name,stu[high].name);
            stu[low].grade=stu[high].grade;
            while(low<high&&strcmp(stu[low].no,pivotkey1)<=0)
                ++low;
            strcpy(stu[high].no,stu[low].no);
            strcpy(stu[high].name,stu[low].name);
            stu[high].grade=stu[low].grade;
        }
        strcpy(stu[low].no,pivotkey1);
        strcpy(stu[low].name,pivotkey2);
        stu[low].grade=pivotkey3;
        break;
    case 2://姓名排序
        strcpy(pivotkey1,stu[low].no);
        strcpy(pivotkey2,stu[low].name);
        pivotkey3=stu[low].grade;
        while(low<high)
        {
            while(low<high&&strcmp(stu[high].name,pivotkey2)>=0)
                --high;
            strcpy(stu[low].no,stu[high].no);
            strcpy(stu[low].name,stu[high].name);
            stu[low].grade=stu[high].grade;
            while(low<high&&strcmp(stu[low].name,pivotkey2)<=0)
                ++low;
            strcpy(stu[high].no,stu[low].no);
            strcpy(stu[high].name,stu[low].name);
            stu[high].grade=stu[low].grade;
        }
        strcpy(stu[low].no,pivotkey1);
        strcpy(stu[low].name,pivotkey2);
        stu[low].grade=pivotkey3;
        break;
    case 3://成绩排序
        strcpy(pivotkey1,stu[low].no);
        strcpy(pivotkey2,stu[low].name);
        pivotkey3=stu[low].grade;
        while(low<high)
        {
            while(low<high&&stu[high].grade>=pivotkey3)
                --high;
            strcpy(stu[low].no,stu[high].no);
            strcpy(stu[low].name,stu[high].name);
            stu[low].grade=stu[high].grade;
            while(low<high&&stu[low].grade<=pivotkey3)
                ++low;
            strcpy(stu[high].no,stu[low].no);
            strcpy(stu[high].name,stu[low].name);
            stu[high].grade=stu[low].grade;
        }
        strcpy(stu[low].no,pivotkey1);
        strcpy(stu[low].name,pivotkey2);
        stu[low].grade=pivotkey3;
        break;
    default:
        printf("You scan a wrong flag\n");
    }
    return low;
}

void QSort(Student stu[],int low,int high,int flag)
{
    int pivotloc;
    if(low<high)
    {
        pivotloc = partition(stu,low,high,flag);
        QSort(stu,low,pivotloc-1,flag);
        QSort(stu,pivotloc+1,high,flag);
    }
}
int main()
{
    Student* stu;
    int N,C;//记录记录条数和指定排列序号
    scanf("%d %d",&N,&C);
    stu = (Student*)malloc(N*sizeof(struct data));
    for(int i=0; i<N; i++)
    {
        scanf("%s%s %d",stu[i].no,stu[i].name,&stu[i].grade);
    }
    QSort(stu,0,N-1,C);
    for(int i=0; i<N; i++)
    {
        printf("%s\t%s\t%d\n",stu[i].no,stu[i].name,stu[i].grade);
    }
    return 0;
}
