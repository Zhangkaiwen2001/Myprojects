#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct xian
{
    int x1;//�ߵ�1
    int y1;
    int x2;//�ߵ�2
    int y2;
} line[100];
struct rectange
{
    int x1;//���Ͻ�����
    int y1;
    int x2;
    int y2;//���½�����
} rec[100];
struct yuan
{
    int x1;//Բ��
    int y1;
    int r;//�뾶
} cir[100];
struct ellispe
{
    int x;//��ԲԲ��
    int y;
    int a;//������
    int b;//�̰���
} ell[100];
void add(char b,int s[]);
void list(int s[]);
int i=0;//ȷ����ͬ�洢ֵ
int main()
{
    int pan[100];
    int m;
    while(1)
    {
        system("cls");
        printf("Add/List/Delete/Quit\n");
        printf("��������ĸѡ����:");
        char a,b;
        do
        {
            a=getch();
            system("cls");
            printf("Add/List/Delete/Quit\n");
            printf("��������ĸѡ����:");
        }
        while(a!='a'&&a!='A'&&a!='L'&&a!='l'&&a!='D'&&a!='d'&&a!='q'&&a!='Q');
        if(a=='q'||a=='Q')
            return 0;
        else if(a=='a'||a=='A')
        {
            do
            {
                system("cls");
                printf("Line/Rectangle/Circle/Ellipse\n");
                printf("��������ĸѡ����:");
                fflush(stdin);
                b=getch();
            }
            while(b!='r'&&b!='R'&&b!='L'&&b!='l'&&b!='c'&&b!='C'&&b!='e'&&b!='E');
            add(b,pan);
        }
        else if(a=='l'||a=='L')
            list(pan);
        else
        {
            system("cls");
            printf("����ID��:");
            scanf("%d",&m);
            if(m>=i)
            {
                printf("δ�������ID");
                system("pause");
            }
            else
            {
                pan[m]=4;
                //ʹ���鲻���
                printf("ɾ���ɹ�");
                system("pause");
            }
        }
    }
    return 0;
}
void add(char b,int s[])
{
    if(b=='l'||b=='L')
    {
        system("cls");
        printf("������ֱ�ߵ������˵����꣺x1,y1,x2,y2�����س�(�м�Ϊ����)\n");
        scanf("%d,%d,%d,%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
        s[i]=0;
        i++;
        printf("һ��ֱ���ѱ���ӣ������������������");
        system("pause");
    }
    else if(b=='r'||b=='R')
    {
        system("cls");
        printf("��������ε����ϽǺ����½����꣺x1,y1,x2,y2�����س�(�м�Ϊ����)\n");
        scanf("%d,%d,%d,%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);
        s[i]=1;
        i++;
        printf("һ�������ѱ���ӣ������������������");
        system("pause");
    }
    else if(b=='c'||b=='C')
    {
        system("cls");
        printf("������Բ������Ͱ뾶��x1,y1,r�����س�(�м�Ϊ����)\n");
        scanf("%d,%d,%d",&cir[i].x1,&cir[i].y1,&cir[i].r);
        s[i]=2;
        i++;
        printf("һ��Բ���ѱ���ӣ������������������");
        system("pause");
    }
    else
    {
        system("cls");
        printf("��������Բ�������꣬�볤��Ͱ���᣺x,y,a,b�����س�(�м�Ϊ����)\n");
        scanf("%d,%d,%d,%d",&ell[i].x,&ell[i].y,&ell[i].a,&ell[i].b);
        s[i]=3;
        i++;
        printf("һ����Բ�ѱ���ӣ������������������");
        system("pause");
    }
    return ;
}
void list(int s[])
{
    int j;
    system("cls");
    for(j=0; j<i; j++)
    {
        switch(s[j])
        {
        case 0:
            printf("ID=%d:ֱ��: �˵�����Ϊ:x1=%d,y1=%d,x2=%d,y2=%d\n",j,line[j].x1,line[j].y1,line[j].x2,line[j].y2);
            break;
        case 1:
            printf("ID=%d:����: ���Ͻ�����Ϊ: x1=%d,y1=%d,���½�����Ϊx2=%d,y2=%d\n",j,rec[j].x1,rec[j].y1,rec[j].x2,rec[j].y2);
            break;
        case 2:
            printf("ID=%d:Բ��: Բ������Ϊ: x=%d,y=%d;�뾶Ϊr=%d\n",j,cir[j].x1,cir[j].y1,cir[j].r);
            break;
        case 3:
            printf("ID=%d:��Բ: ��������Ϊx=%d,y=%d;���᳤Ϊ:a=%d,b=%d\n",j,ell[j].x,ell[j].y,ell[j].a,ell[j].b);
        }
    }
    printf("�����������");
    system("pause");
}
