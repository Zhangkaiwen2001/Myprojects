#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float num[4][100];
    float *p[4];
    unsigned int *np[4];
    float *yu[4];
    float *shu[4];
    float *yin[4];
    for(i=0;i<4;i++)
    {
        p[i]=num[i];
        printf("Please enter information of student %d\n",i+1);
        printf("input the name of student %d\n",i+1);
        np[i]=(unsigned int *)(p[i]);
        scanf("%d",np[i]);
        printf("input the chinese score of student %d\n",i+1);
        yu[i]=(float *)(np[i]+4);
        scanf("%f",yu[i]);
        printf("input the math score of student %d\n",i+1);
        shu[i]=(float *)(np[i]+8);
        scanf("%f",shu[i]);
        printf("input the english score of student %d\n",i+1);
        yin[i]=(float *)(np[i]+12);
        scanf("%f",yin[i]);
    }
    printf("name        chinese      math       english     total score\n");
    for(i=0;i<4;i++)
        printf("%10u,%10f,%10f,%10f,%10f\n",*np[i],*yu[i],*shu[i],*yin[i],(double)*yu[i]+*shu[i]+*yin[i]);
    return 0;
}
