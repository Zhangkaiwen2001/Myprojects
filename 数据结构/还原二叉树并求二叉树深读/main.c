#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef char Elem;
typedef struct BiTNode
{
    Elem data;
    struct  BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

int TreeDepth(BiTree T)
{
    int depthval,depthLeft,depthRight;
    if(!T)
        depthval = 0;
    else
    {
        depthLeft = TreeDepth(T->lchild);
        depthRight = TreeDepth(T->rchild);
        depthval=1+(depthLeft>depthRight?depthLeft:depthRight);
    }
    return depthval;
}

int Search(char ino[],char t)
{
    unsigned int i;
    for(i=0; i<strlen(ino); i++)
    {
        if(t==ino[i])
            break;
    }
    if(i>strlen(ino))
        return -1;
    else
        return i;
}

BiTree CrtBT(char pre[],char ino[],int ps,int is,int n)//��֪pre[ps..ps+n-1]Ϊ���������������У�ino[is..is+n-1]Ϊ����������������
{
    BiTree T;
    int k;
    if(n==0)
        return NULL;
    else
    {
        k = Search(ino,pre[ps]);//���Ҹ��ڵ������������λ��
        if(k==-1)
            return NULL;
        else
        {
            T=(BiTNode*)malloc(sizeof(BiTNode));
            T->data = pre[ps];
            if(k==is)
                T->lchild = NULL;
            else
                T->lchild = CrtBT(pre,ino,ps+1,is,k-is);
            if(k==is+n-1)
                T->rchild = NULL;
            else
                T->rchild = CrtBT(pre,ino,ps+1+(k-is),k+1,n-(k-is)-1);
        }
    }
    return T;
}

int main()
{
    int n;
    scanf("%d",&n);
    int depth = 0;
    char pre[50],ino[50];
    getchar();
    scanf("%s",pre);
    getchar();
    scanf("%s",ino);
    BiTree T;
    T = CrtBT(pre,ino,0,0,n);
    depth = TreeDepth(T);
    printf("%d",depth);
    return 0;
}
