#include <stdio.h>
#include <stdlib.h>
int main()
{
    double grade [5][4]={{1,2,3,4}};
    double *Chinese=grade[1],*Math=grade[2],*English=grade[3],*Total=grade[4];
    int numstud,count,scan;

    for(count=1;count<5;count++)
    {system("cls");
    printf("开始录入学生成绩\n");
    printf("\n请输入您要录入成绩的学生编号  已录入学生(%d/4)\n",count);
    do
       {
       fflush(stdin);
       scan=scanf("%d",&numstud);
       if(scan!=1||numstud>4||numstud<0)printf("您输入了范围外的编号，请重新输入（示例编号：1 2 3 4）\n");
       }while(scan!=1||numstud>4||numstud<0);
    numstud=numstud-1;
    printf("请输入语文成绩：\n");
    scanf("%lf",&*Chinese+numstud);
    printf("请输入数学成绩：\n");
    scanf("%lf",&*Math+numstud);
    printf("请输入英语成绩：\n");
    scanf("%lf",&*English+numstud);
    *(Total+numstud)=*(Chinese+numstud)+*(English+numstud)+*(Math+numstud);
    }
    printf("\n\n录入完成，开始输出成绩单\n");
    for(count=0;count<4;count++)
    {
            printf("学号: %d\n",(int)grade[0][count]);
            printf("语文成绩: %f\n",(float)grade[1][count]);
            printf("数学成绩: %f\n",(float)grade[2][count]);
            printf("英语成绩: %f\n",(float)grade[3][count]);
            printf("总分: %lf\n\n",(double)grade[4][count]);
    }
    return 0;
}
