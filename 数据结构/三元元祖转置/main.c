#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 12500
typedef struct
{
    int i,j;//该非零元的行下表和列下表
    int element;
} Triple;
typedef struct
{
    Triple data[MAXSIZE+1];//非零三元组，data[0]未用
    int mu,nu,tu;//矩阵的行数，列数和非零元个数
} TSMatrix;
TSMatrix TransposeSMatrix(TSMatrix M)
{
    TSMatrix T;
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    int num[M.nu+1];
    int cpot[M.tu+1];//cpto[col]指示M中第col列的第一个非零元在转换的data中的恰当位置
    int col;
    if(T.tu)
    {
        for(col=1; col<=M.nu; ++col)
            num[col]=0;//num[col]表示矩阵M中第col列中非零元的个数
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
