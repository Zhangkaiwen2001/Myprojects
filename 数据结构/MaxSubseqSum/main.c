#include <stdio.h>
#include <stdlib.h>

int MaxSubseqSum1(int A[], int N)
{
    int ThisSum,MaxSum = 0;
    int i,j,k;
    for(i=0; i<N; i++)
    {
        for(j=i; j<N; j++)
        {
            ThisSum=0;
            for(k=i; k<=j; k++)
                ThisSum+=A[k];
            if(ThisSum>MaxSum)
            {
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}

int MaxSubseqSum2(int A[], int N)
{
    int ThisSum,MaxSum = 0;
    int i,j;
    for(i=0; i<N; i++)
    {
        ThisSum=0;
        for(j=i; j<N; j++)
        {
            ThisSum+=A[j];
            if(ThisSum>MaxSum)
            {
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}

int MaxSubseqSum4(int A[], int N)
{
    int ThisSum,MaxSum = 0;
    int i;
    ThisSum=MaxSum=0;
    for(i=0; i<N; i++)
    {
        ThisSum+=A[i];
        if(ThisSum>MaxSum)
        {
            MaxSum=ThisSum;
        }
        else if(ThisSum<0)
        {
            ThisSum=0;
        }
    }
    return MaxSum;
}
int main()
{
    int a[]= {1,-123,1256,654};
    int c,d,e;
    c=MaxSubseqSum1(a,4);
    d=MaxSubseqSum2(a,4);
    e=MaxSubseqSum4(a,4);
    printf("%d\n",c);
    printf("%d\n",d);
    printf("%d",e);
    return 0;
}
