#include <stdio.h>
#include <stdlib.h>
typedef int Position;
typedef int ElementType;
struct QNode
{
    ElementType *Data;
    /* 存储元素的数组 */
    Position Front, Rear;
    /* 队列的头、尾指针 */
    int MaxSize;
    /* 队列最大容量 */
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
        printf("队列满");
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
        printf("队列空");
        return 0;
    }
    else
    {
        Q->Front =(Q->Front+1)%Q->MaxSize;
        return  Q->Data[Q->Front];
    }
}
