#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
typedef int ElementType;
struct Node
{
    /* �����еĽ�� */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;
struct QNode
{
    Position Front, Rear;  /* ���е�ͷ��βָ�� */     i
    nt MaxSize;           /* ����������� */
};
typedef struct QNode *Queue;
int IsEmpty( Queue Q )
{
    return ( Q->Front == NULL);
}
ElementType DeleteQ( Queue Q )
{
    Position FrontCell;
    ElementType FrontElem;
    if  ( IsEmpty(Q) )
    {
        printf("���п�");
        return 0;
    }
    else
    {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* ������ֻ��һ��Ԫ�� */
            Q->Front = Q->Rear = NULL; /* ɾ���������Ϊ�� */
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;
        free( FrontCell );  /* �ͷű�ɾ�����ռ�  */
        return  FrontElem;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
