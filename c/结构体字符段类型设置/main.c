#include <stdio.h>
#include <stdlib.h>
typedef struct FIELDATRR
{
    int fieldId;
    int fieldLen;
    char fieldType;
    char fieldCaption[11];
    char sfileldcontain[11];
    int nfileldcontain;
} file;
int main()
{
    int m,n,i,j,sum=0;
    printf("�������¼���ֶ���:");
    scanf("%d",&m);
    printf("�������¼����:");
    scanf("%d",&n);
    file fil[m*n];
    system("cls");
    for(i=0; i<m; i++)
    {
        printf("�������ֶ�����:");
        scanf("%s",fil[i].fieldCaption);
        printf("������ѡ���ֶ����ͣ�int n,string s(������n����s)");
        scanf(" %c",&fil[i].fieldType);
        if(fil[i].fieldType=='s')
        {
            printf("�����ַ������ȣ�");
            scanf("%d",&fil[i].fieldLen);
            fil[i].fieldLen++;
        }
        else
        {
            fil[i].fieldLen=4;
        }
        printf("һ���ֶ�����������ϣ������������������\n");
    }
    system("cls");
    printf("�ѽ�����¼���ֶ�������Ϣ��\n");
    for(i=0; i<m; i++)
    {
        printf("�ֶ�ID:%2d,%-8s,%-2d,%c\n",i+1,fil[i].fieldCaption,fil[i].fieldLen,fil[i].fieldType);
        sum=sum+fil[i].fieldLen;
    }
    printf("%d\n",sum);
    printf("�������������¼����Ϣ\n");
    system("pause");
    system("cls");
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            printf("%s=",fil[i].fieldCaption);
            if(fil[i].fieldType=='s')
                scanf("%s",fil[i+j*m].sfileldcontain);
            else
                scanf("%d",&fil[i+j*m].nfileldcontain);
        }
        if(j<n-1)
            printf("һ����¼¼����ϣ������������¼�룬��ESC������\n");
        else
            printf("�Ѿ�¼���������һ����¼�����������������������\n");
    }
    system("pause");
    system("cls");
    printf("�Ѿ�¼�����Ϣ��\n");
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            printf(" %s:",fil[i].fieldCaption);
            if(fil[i].fieldType=='s')
                printf("%-4s",fil[i+j*m].sfileldcontain);
            else
                printf("%-4d",fil[i+j*m].nfileldcontain);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("����ִ�����!��������˳����򡣡���");
    system("pause");
    return 0;
}
