#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
struct infor
{
    char id[11];
    char name[11];
    float c;
    float software;
    struct infor *next;
};
struct infor*creat(struct infor*head);
void del(struct infor*head);
int j=1;
int main()
{
    struct infor *head=NULL,*p=NULL;
    head=creat(head);
    int k=0;
    while(j!=0)
    {
        head=creat(head);
        k=1;
    }
    if(k==0)
    {
        printf("未输入任何数据！");
        printf("程序结束！");
    }
    else
    {
        printf("输入结束，刚刚输入的数据为：\n");
        printf("学号       姓名       C语言  工数  \n");
        p=head;
        while(p!=NULL)
        {
            if(p->id[0]!='\0')
            {
                printf("%-10s %-10s %-5.1f %-5.1f\n",p->id,p->name,p->c,p->software);
            }
            p=p->next;
        }
        printf("程序结束！");
    }
    del(head);
    return 0;
}
struct infor*creat(struct infor*head)
{
    struct infor*p=NULL,*pr=head;
    p=(struct infor*)malloc(sizeof(struct infor));
    if(p==NULL)
    {
        printf("No enough memory");
        exit(0);
    }
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        while(pr->next!=NULL)
            pr=pr->next;
        pr->next=p;
    }
    printf("请输入学号：");
    gets(p->id);
    if(p->id[0]!='\0')
    {
        printf("请输入姓名：");
        gets(p->name);
        printf("请输入C语言和工数的成绩，并用空格分开。输入后请按回车：");
        scanf("%f%f",&p->c,&p->software);
        getchar();
        j=1;
    }
    else
        j=0;
    p->next=NULL;
    return head;
}
void del(struct infor*head)
{
    struct infor*p=head,*pr=NULL;
    while(p!=NULL)
    {
        pr=p;
        p=p->next;
        free(pr);
    }
}
