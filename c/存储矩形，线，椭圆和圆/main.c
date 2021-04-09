#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct xian
{
    int x1;//线点1
    int y1;
    int x2;//线点2
    int y2;
} line[100];
struct rectange
{
    int x1;//左上角坐标
    int y1;
    int x2;
    int y2;//右下角坐标
} rec[100];
struct yuan
{
    int x1;//圆心
    int y1;
    int r;//半径
} cir[100];
struct ellispe
{
    int x;//椭圆圆心
    int y;
    int a;//长半轴
    int b;//短半轴
} ell[100];
void add(char b,int s[]);
void list(int s[]);
int i=0;//确定不同存储值
int main()
{
    int pan[100];
    int m;
    while(1)
    {
        system("cls");
        printf("Add/List/Delete/Quit\n");
        printf("输入首字母选择功能:");
        char a,b;
        do
        {
            a=getch();
            system("cls");
            printf("Add/List/Delete/Quit\n");
            printf("输入首字母选择功能:");
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
                printf("输入首字母选择功能:");
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
            printf("输入ID号:");
            scanf("%d",&m);
            if(m>=i)
            {
                printf("未输入过此ID");
                system("pause");
            }
            else
            {
                pan[m]=4;
                //使数组不输出
                printf("删除成功");
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
        printf("请输入直线的两个端点坐标：x1,y1,x2,y2并按回车(中间为逗号)\n");
        scanf("%d,%d,%d,%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
        s[i]=0;
        i++;
        printf("一条直线已被添加！按任意键继续。。。");
        system("pause");
    }
    else if(b=='r'||b=='R')
    {
        system("cls");
        printf("请输入矩形的左上角和右下角坐标：x1,y1,x2,y2并按回车(中间为逗号)\n");
        scanf("%d,%d,%d,%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);
        s[i]=1;
        i++;
        printf("一个矩形已被添加！按任意键继续。。。");
        system("pause");
    }
    else if(b=='c'||b=='C')
    {
        system("cls");
        printf("请输入圆心坐标和半径：x1,y1,r并按回车(中间为逗号)\n");
        scanf("%d,%d,%d",&cir[i].x1,&cir[i].y1,&cir[i].r);
        s[i]=2;
        i++;
        printf("一个圆形已被添加！按任意键继续。。。");
        system("pause");
    }
    else
    {
        system("cls");
        printf("请输入椭圆中心坐标，半长轴和半短轴：x,y,a,b并按回车(中间为逗号)\n");
        scanf("%d,%d,%d,%d",&ell[i].x,&ell[i].y,&ell[i].a,&ell[i].b);
        s[i]=3;
        i++;
        printf("一个椭圆已被添加！按任意键继续。。。");
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
            printf("ID=%d:直线: 端点坐标为:x1=%d,y1=%d,x2=%d,y2=%d\n",j,line[j].x1,line[j].y1,line[j].x2,line[j].y2);
            break;
        case 1:
            printf("ID=%d:矩形: 左上角坐标为: x1=%d,y1=%d,右下角坐标为x2=%d,y2=%d\n",j,rec[j].x1,rec[j].y1,rec[j].x2,rec[j].y2);
            break;
        case 2:
            printf("ID=%d:圆形: 圆心坐标为: x=%d,y=%d;半径为r=%d\n",j,cir[j].x1,cir[j].y1,cir[j].r);
            break;
        case 3:
            printf("ID=%d:椭圆: 中心坐标为x=%d,y=%d;半轴长为:a=%d,b=%d\n",j,ell[j].x,ell[j].y,ell[j].a,ell[j].b);
        }
    }
    printf("按任意键继续");
    system("pause");
}
