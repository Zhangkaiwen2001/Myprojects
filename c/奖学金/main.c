#include <stdio.h>
#include <stdlib.h>
typedef struct winners
{
    char name[20];
    int finalScore;
    int classScore;
    char work;
    char west;
    int paper;
    int scholarship;
} WIN;
void Addup(WIN stu[], int n);
int FindMax(WIN student[], int n);
int main()
{
    int n;
    WIN  stu[30];
    printf("Input n:");
    scanf("%d",&n);
    Addup(stu,n);
    return 0;
}
void Addup(WIN stu[], int n)
{
    int i,money,max,j;
    for(i=0; i<n; i++)
    {
        money=0;
        printf("Input name:");
        scanf("%s",stu[i].name);
        printf("Input final score:");
        scanf("%d",&stu[i].finalScore);
        printf("Input class score:");
        scanf("%d",&stu[i].classScore);
        printf("Class cadre or not?(Y/N):");
        scanf(" %c",&stu[i].work);
        printf("Students from the West or not?(Y/N):");
        scanf(" %c",&stu[i].west);
        printf("Input the number of published papers:");
        scanf("%d",&stu[i].paper);
        if(stu[i].finalScore>80&&stu[i].paper>0)
            money=money+8000;
        if(stu[i].finalScore>85&&stu[i].classScore>80)
            money=money+4000;
        if(stu[i].finalScore>90)
            money=money+2000;
        if(stu[i].finalScore>85&&stu[i].west=='Y')
            money=money+1000;
        if(stu[i].classScore>80&&stu[i].work=='Y')
            money=money+850;
        stu[i].scholarship=money;
        printf("name:%s,scholarship:%d\n",stu[i].name,stu[i].scholarship);
    }
    max=stu[0].scholarship;
    for(i=1; i<n; i++)
    {
        if(max<stu[i].scholarship)
        {
            max=stu[i].scholarship;
            j=i;
        }
    }
    printf("%s get the highest scholarship %d\n",stu[j].name,max);
    return ;
}
