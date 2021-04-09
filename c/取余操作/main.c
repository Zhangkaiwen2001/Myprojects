#include <stdio.h>
#include <stdlib.h>
void panduan(int a,int b);
int main()
{
    int h;
    scanf("%d",&h);
    for(int i=0; i<=h-1; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        panduan(a,b);
    }
    return 0;
}
void panduan(int a,int b)
{
    int sum1=0,sum2=0;
    for(int i=1;i<a;i++)
    {
        if(a%i==0)
        {
            sum1=sum1+i;
        }
    }
    for(int i=1;i<b;i++)
    {
        if(b%i==0)
        {
            sum2=sum2+i;
        }
    }
    if(sum1==b&&sum2==a)
        printf("YES\n");
    else
        printf("NO\n");

}
