#include <stdio.h>
#include <stdlib.h>
int main()
{
    double grade [5][4]={{1,2,3,4}};
    double *Chinese=grade[1],*Math=grade[2],*English=grade[3],*Total=grade[4];
    int numstud,count,scan;

    for(count=1;count<5;count++)
    {system("cls");
    printf("��ʼ¼��ѧ���ɼ�\n");
    printf("\n��������Ҫ¼��ɼ���ѧ�����  ��¼��ѧ��(%d/4)\n",count);
    do
       {
       fflush(stdin);
       scan=scanf("%d",&numstud);
       if(scan!=1||numstud>4||numstud<0)printf("�������˷�Χ��ı�ţ����������루ʾ����ţ�1 2 3 4��\n");
       }while(scan!=1||numstud>4||numstud<0);
    numstud=numstud-1;
    printf("���������ĳɼ���\n");
    scanf("%lf",&*Chinese+numstud);
    printf("��������ѧ�ɼ���\n");
    scanf("%lf",&*Math+numstud);
    printf("������Ӣ��ɼ���\n");
    scanf("%lf",&*English+numstud);
    *(Total+numstud)=*(Chinese+numstud)+*(English+numstud)+*(Math+numstud);
    }
    printf("\n\n¼����ɣ���ʼ����ɼ���\n");
    for(count=0;count<4;count++)
    {
            printf("ѧ��: %d\n",(int)grade[0][count]);
            printf("���ĳɼ�: %f\n",(float)grade[1][count]);
            printf("��ѧ�ɼ�: %f\n",(float)grade[2][count]);
            printf("Ӣ��ɼ�: %f\n",(float)grade[3][count]);
            printf("�ܷ�: %lf\n\n",(double)grade[4][count]);
    }
    return 0;
}
