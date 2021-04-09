#include<stdio.h>
#include<stdlib.h>
#define ERROR NULL
#define fal 0
#define tru 1
typedef int ElementType ;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/* ���� */
Position Find( List L, ElementType X )
{
    Position p = L; /* pָ��L�ĵ�1����� */
    while( p && p->Data!=X )
        p = p->Next;     /* ������������ return p; �滻 */
    if(p)
        return p;
    else
        return ERROR;
}
/* ��ͷ���Ĳ��� */ /*ע��:�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P��������ָ�룬��P֮ǰ�����½�� */
int Insert( List L, ElementType X, Position P )
{
    /* ����Ĭ��L��ͷ��� */
    Position tmp, pre;     /* ����P��ǰһ����� */
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next );
    if( pre==NULL )   /* P��ָ�Ľ�㲻��L�� */
    {
        printf("����λ�ò�������\n");
        return fal;//���ش����־
    }
    else
    {
        /* �ҵ���P��ǰһ�����pre */
        /* ��Pǰ�����½�� */
        tmp = (Position)malloc(sizeof(struct LNode)); /* ���롢��װ��� */
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return tru;
    }
}
/* ��ͷ����ɾ�� */ /*ע��:��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P����ɾ�����ָ�� */
int Delete( List L, Position P )
{
    /* ����Ĭ��L��ͷ��� */
    Position pre;
    /* ����P��ǰһ����� */
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next )
        ;
    if ( pre==NULL || P==NULL)
    {
        /* P��ָ�Ľ�㲻��L�� */
        printf("ɾ��λ�ò�������\n");
        return fal;
    }
    else
    {
        /* �ҵ���P��ǰһ�����pre */
        /* ��Pλ�õĽ��ɾ�� */
        pre->Next = P->Next;
        free(P);
        return tru;
    }
}
int main()
{
    printf("Hello,World");
    return 0;
}
