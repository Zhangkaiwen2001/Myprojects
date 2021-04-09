#include <stdio.h>
#include <stdlib.h>

struct PolyNode
{
    int coef;//系数
    int expon;//指数
    struct PolyNode* link;//指向下一个节点的指针
};

typedef struct PolyNode* Polynomial;

void Attach(int c,int e,Polynomial *pRear)
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    if(!P)
    {
        printf("error");
        exit(0);//地址分配错误报错
    }
    P->coef=c;
    P->expon=e;
    P->link=NULL;
    (*pRear)->link = P;
    *pRear = P;
}

Polynomial ReadPoly()
{
    int N;//判断输入多项式个数
    int c,e;//多项式系数与指数
    Polynomial P,Rear,t;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    if(!P)
    {
        printf("error");
        exit(0);//地址分配错误报错
    }
    P->link = NULL;
    Rear = P;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    t = P;
    P = P->link;
    free(t);//删除临时生成的头节点
    return P;//返回多项式的第一个节点
}

Polynomial Derivation(Polynomial P1)
{
    Polynomial P,Rear,t;
    int c,e;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    if(!P)
    {
        printf("error");
        exit(0);//地址分配错误报错
    }
    P->link = NULL;
    Rear = P;
    while(P1)//求导过程
    {
        c = P1->coef*P1->expon;
        e = P1->expon-1;
        if(e>=0)
            Attach(c,e,&Rear);
        P1 = P1->link;
    }
    t = P;
    P = P->link;
    free(t);//删除临时生成的头节点
    return P;//返回多项式的第一个节点
}

void PrintPoly(Polynomial P)
{
    int flag = 0;
    if(!P)
    {
        printf("0 0");
        exit(0);
    }
    while(P)
    {
        if(!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d",P->coef,P->expon);
        P=P->link;
    }
    printf("\n");
}

int main()
{
    Polynomial P1,P2;
    P1 = ReadPoly();
    P2 = Derivation(P1);
    PrintPoly(P2);
    return 0;
}
