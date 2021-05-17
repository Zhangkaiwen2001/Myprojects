#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define num 2
typedef struct node
{
    int procID;              // 进程ID
    int releaseTime;         // 到达时间
    int priority;            // 优先级
    int cpuTime;             // 运行时间
    int executedTime;        // 已运行时间
    int state;               // 进程状态 就绪状态：0、运行状态：1、终止状态：2
    struct node * next;      // 指向下一个进程指针
} PCB;
PCB P[num];
void initiate()
{
    int i;//i为进程编号
    for(i=0; i<num; i++)
    {
        //为每个进程给出信息
        printf("请输入PCB[%d]的进程ID:\n",i+1);
        scanf("%d",&P[i].procID);
        printf("请输入PCB[%d]的到达时间:\n",i+1);
        scanf("%d",&P[i].releaseTime);
        printf("请输入PCB[%d]的优先级:\n",i+1);
        scanf("%d",&P[i].priority);
        printf("请输入PCB[%d]的运行时间:\n",i+1);
        scanf("%d",&P[i].cpuTime);
        P[i].state = 0;
        getchar();
    }
}
int max_pri()
{
    int max=-1;//max为最大优先数
    int i;
    int m;//m为最大进程的编号
    for(i=0; i<num; i++)
    {
        if(P[i].state==1)
            return -1;//正在运行
        else if((max<P[i].priority)&&(P[i].state==0))
        {
            max=P[i].priority;
            m=i;
        }
    }
    //确保最大优先数进程还没结束运行
    if(P[m].state== 2)
        return -1;
    else
        return m;
}

void show()
{
    int i;
    printf("\nID cpuTime priority state\n");
    printf("------------------------------\n");
    for(i=0; i<num; i++)
    {
        printf("%6d%6d%6d%6d\n",P[i].procID,P[i].cpuTime,P[i].priority,P[i].state);
    }
    printf("------------------------------\n");
}

void prio()
{
    int i,j,m=0;
    int max_time=-1;
    int t=0;//t为程序总运行次数
    for(i=0; i<num; i++)
        t+=P[i].cpuTime;

    printf("\n初始时各进程信息:\n");
    show();

    for(j=0; j<t; j++)
    {
        //当程序正在运行时(1为运行态)
        while(max_pri()!=-1)
        {
            if(P[max_pri()].priority!=0)
                P[max_pri()].state=1;
            else //当优先级降为0，进程还没运行完时
            {
                for(i=0; i<num; i++)
                    if(max_time<P[i].cpuTime)
                    {
                        max_time=P[i].cpuTime;
                        m=i;
                    }
                max_time=-1;
                P[m].state=1;
            }
        }
        //判断程序状态(对优先数和运行时间操作)
        for(i=0; i<num; i++)
        {
            if(P[i].state==1)
            {
                P[i].cpuTime--;
            }
            if(P[i].cpuTime==0)
                P[i].state=2;
            else
                P[i].state=0;
        }
        show();
        getchar();
    }
}

int main()
{
    initiate();
    prio();
    return 0;
}
