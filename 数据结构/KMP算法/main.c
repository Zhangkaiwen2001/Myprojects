#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef char SString[255];

void get_next(SString T, int next[])
{
    int i = 0;
    next[0] = -1;
    int j = -1;//�����0��ʼ���ҳ��Ȳ���T[0]��ʾ
    while(i<strlen(T))
    {
        if(j==-1||T[i]==T[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
        {
            j = next[j];
        }
    }
}

int Index_KMP(SString S,SString T,int pos)
{
    int i = pos;
    int j = -1;
    int next[strlen(T)];
    get_next(T,next);
    for(int m=0;m<strlen(T);m++)
        printf("%d ",next[m]);
    while(i<(int)strlen(S)&&j<(int)strlen(T))
    {
        if(j==-1||S[i]==T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j=next[j];
        }
    }
    if(j==strlen(T))
        return i-j;
    else
        return -1;
}
int main()
{
    SString S,T;
    printf("����������S\n");
    scanf("%s",S);
    printf("������ģʽ��T\n");
    scanf("%s",T);
    printf("\n%d",Index_KMP(S,T,0));
    return 0;
}
