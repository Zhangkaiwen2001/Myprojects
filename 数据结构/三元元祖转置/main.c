#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 12500
typedef struct
{
    int i,j;//�÷���Ԫ�����±�����±�
    int element;
} Triple;
typedef struct
{
    Triple data[MAXSIZE+1];//������Ԫ�飬data[0]δ��
    int mu,nu,tu;//����������������ͷ���Ԫ����
} TSMatrix;
TSMatrix TransposeSMatrix(TSMatrix M)
{
    TSMatrix T;
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    int num[M.nu+1];
    int cpot[M.tu+1];//cpto[col]ָʾM�е�col�еĵ�һ������Ԫ��ת����data�е�ǡ��λ��
    int col;
    if(T.tu)
    {
        for(col=1; col<=M.nu; ++col)
            num[col]=0;//num[col]��ʾ����M�е�col���з���Ԫ�ĸ���
        for(int t=1; t<=M.tu;++t)
            ++num[M.data[t].j];
        cpot[1]=1;
        for(col=2;col<=M.nu;++col)
            cpot[col]=cpot[col-1]+num[col-1];
        for(int p=1;p<=M.tu;++p)
        {
            col=M.data[p].j;
            int q = cpot[col];
            T.data[q].i=M.data[p].j;
            T.data[q].j=M.data[p].i;
            T.data[q].element=M.data[p].element;
            ++cpot[col];
        }
        }
        return T;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
