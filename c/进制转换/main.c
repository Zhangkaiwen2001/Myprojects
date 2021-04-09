#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<conio.h>
void erjz1(void);
void erjz2(int n);
void bajz2(void);
void bajz3(int n);
void shiliujz2(void);
void shiliujz3(unsigned n,char buf[]);
int main()
{
  int a,b,c;
    int i=0;
    printf("*******************************************************\n");
    printf("*                                                     *\n");
    printf("*              >十进制数转二进制数                    *\n");
    printf("*               十进制数转八进制数                    *\n");
    printf("*               十进制数转16进制数                    *\n");
    printf("*               退出                                  *\n");
    printf("*                                                     *\n");
    printf("*******************************************************\n");
 while(1)
    {
        c=0;
        a=getch();
        if (a==13&&i==0)
        {
            erjz1();
            for(;c!=13;)
            {
                c=getch();
            }
        }
        if (a==13&&i==1)
        {
            bajz2();
            for(;c!=13;)
            {
                c=getch();
            }
        }
        if (a==13&&i==2)
        {
            shiliujz2();
            for(;c!=13;)
            {
                c=getch();
            }
        }
        else if (a==13&&i==3)
        {
            exit(0);
        }
        else
            b=getch();
        system("cls");
        if(b==80)
            i=(i+1)%4;
        if (b==72)
            i=(i+3)%4;
        switch (i)
        {
            case 0:
            {
                printf("*******************************************************\n");
                printf("*                                                     *\n");
                printf("*              >十进制数转二进制数                    *\n");
                printf("*               十进制数转八进制数                    *\n");
                printf("*               十进制数转16进制数                    *\n");
                printf("*               退出                                  *\n");
                printf("*                                                     *\n");
                printf("*******************************************************\n");
                break;
            }
            case 1:
            {
                printf("*******************************************************\n");
                printf("*                                                     *\n");
                printf("*               十进制数转二进制数                    *\n");
                printf("*              >十进制数转八进制数                    *\n");
                printf("*               十进制数转16进制数                    *\n");
                printf("*               退出                                  *\n");
                printf("*                                                     *\n");
                printf("*******************************************************\n");
                break;
            }
            case 2:
            {
               printf("*******************************************************\n");
               printf("*                                                     *\n");
               printf("*               十进制数转二进制数                    *\n");
               printf("*               十进制数转八进制数                    *\n");
               printf("*              >十进制数转16进制数                    *\n");
               printf("*               退出                                  *\n");
               printf("*                                                     *\n");
               printf("*******************************************************\n");
               break;
            }
            case 3:
            {
                printf("*******************************************************\n");
                printf("*                                                     *\n");
                printf("*               十进制数转二进制数                    *\n");
                printf("*               十进制数转八进制数                    *\n");
                printf("*               十进制数转16进制数                    *\n");
                printf("*              >退出                                  *\n");
                printf("*                                                     *\n");
                printf("*******************************************************\n");
                break;
            }
        }
    }
    return 0;
}
void erjz1(void)
{
     int n,ret;
    system("cls");
    printf("请输入一个十进制整数：");
    ret=scanf("%d",&n);
    while(ret!=1||n<0)
    {
        if(ret==1&&n>=0)
            break;
        else
        {
            printf("请重新输入一个数：");
            scanf("%d",&n);
        }
    }
    printf("%d的二进制是",n);
    erjz2(n);
    return ;

}
void erjz2(int n)
{
    if(n==0)
    {
        printf("0");
    }
    else if(n==1)
    {
        printf("1");
    }
    else
    {
        erjz2(n/2);
        printf("%d",n%2);
    }
    return ;
}
void bajz2(void)
{
    int n,ret;
    system("cls");
    printf("请输入一个十进制整数：");
    ret=scanf("%d",&n);
    while(ret!=1||n<0)
    {
        if(ret==1&&n>=0)
            break;
        else
        {
            printf("请重新输入一个数：");
            scanf("%d",&n);
        }
    }
    printf("%d的八进制是",n);
    bajz3(n);
    return ;

}
void bajz3(int n)
{
    if(n<8)
    {
        printf("0%d",n);
    }
    else
    {
        bajz3(n/8);
        printf("%d",n%8);
    }
    return ;
}
void shiliujz2(void)
{
    char buf[17]="0123456789ABCDEF";
    int n,ret;
    system("cls");
    printf("请输入一个十进制整数：");
    ret=scanf("%d",&n);
    while(ret!=1&&n<0)
    {
        if(ret==1||n>=0)
            break;
        else
        {
            printf("请重新输入一个数：");
            scanf("%d",&n);
        }
    }
    printf("%d的16进制是",n);
    shiliujz3(n,buf);
    return ;

}
void shiliujz3(unsigned n,char buf[])
{
     if(n<16)
    {
        printf("0x");
    }
    else
    {
        shiliujz3(n/16,buf);
        printf("%c",buf[n%16]);
    }
    return ;
}

