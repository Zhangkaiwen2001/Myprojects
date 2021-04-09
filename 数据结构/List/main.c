#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTCREMENT  10
typedef struct Element ElemType;
struct Element
{
    int age;
    char name;
};
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;
SqList InitList_Sq()     //����һ���յ����Ա�
{
    SqList PtrL;
    PtrL.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!PtrL.elem)
    {
        printf("error");
        exit(0);
    }
    PtrL.length=0;
    PtrL.listsize=LIST_INIT_SIZE;
    return PtrL;
}
void ListInsert_Sq(SqList L, int i, ElemType e)//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
{
    if(i<1||i>L.length+1)
    {
        printf("error");
        exit(0);
    }
    if(L.length>=L.listsize)
    {
        ElemType* newbase;
        newbase = (ElemType*)realloc(L.elem,(L.listsize+LISTCREMENT)*sizeof(ElemType));
        if(!newbase)
        {
            printf("error");
            exit(0);
        }
        L.elem = newbase;
        L.listsize += LISTCREMENT;
    }
    ElemType* m;
    ElemType* n;
    n = &(L.elem[i-1]);
    for(m=&(L.elem[L.length-1]); m>=n; --m)
        *(m+1)=*m;
    *n = e;
    ++L.length;
    return ;
}
void ListDelete_Sq(SqList L,int i,ElemType e)//�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
{
    if((i<1)||(i>L.length))
    {
        printf("error");
        exit(0);
    }
    ElemType* p;
    ElemType* q;
    p = &(L.elem[i-1]);
    e = *p;
    q = L.elem+L.length-1;
    for(++p; p<=q; ++p)
    {
        *(p-1) = *p;
    }
    --L.length;
    return;
}
int main()
{
    SqList L;
    L=InitList_Sq();
    return 0;
}
