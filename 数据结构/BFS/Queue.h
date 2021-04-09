#include <stdio.h>
#include <stdlib.h>
typedef int Position;
typedef int ElementType;
struct QNode
{
    ElementType *Data;
    /* �洢Ԫ�ص����� */
    Position Front, Rear;
    /* ���е�ͷ��βָ�� */
    int MaxSize;
    /* ����������� */
};
typedef struct QNode *Queue;
Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
int IsFull( Queue Q )
{
    return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}
int AddQ( Queue Q, ElementType X )
{
    if ( IsFull(Q) )
    {
        printf("������");
        return 0;
    }
    else
    {
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return 1;
    }
}
int IsEmpty( Queue Q )
{
    return (Q->Front == Q->Rear);
}
ElementType DeleteQ( Queue Q )
{
    if ( IsEmpty(Q) )
    {
        printf("���п�");
        return 0;
    }
    else
    {
        Q->Front =(Q->Front+1)%Q->MaxSize;
        return  Q->Data[Q->Front];
    }
}
