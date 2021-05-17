#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define num 2
typedef struct node
{
    int procID;              // ����ID
    int releaseTime;         // ����ʱ��
    int priority;            // ���ȼ�
    int cpuTime;             // ����ʱ��
    int executedTime;        // ������ʱ��
    int state;               // ����״̬ ����״̬��0������״̬��1����ֹ״̬��2
    struct node * next;      // ָ����һ������ָ��
} PCB;
PCB P[num];
void initiate()
{
    int i;//iΪ���̱��
    for(i=0; i<num; i++)
    {
        //Ϊÿ�����̸�����Ϣ
        printf("������PCB[%d]�Ľ���ID:\n",i+1);
        scanf("%d",&P[i].procID);
        printf("������PCB[%d]�ĵ���ʱ��:\n",i+1);
        scanf("%d",&P[i].releaseTime);
        printf("������PCB[%d]�����ȼ�:\n",i+1);
        scanf("%d",&P[i].priority);
        printf("������PCB[%d]������ʱ��:\n",i+1);
        scanf("%d",&P[i].cpuTime);
        P[i].state = 0;
        getchar();
    }
}
int max_pri()
{
    int max=-1;//maxΪ���������
    int i;
    int m;//mΪ�����̵ı��
    for(i=0; i<num; i++)
    {
        if(P[i].state==1)
            return -1;//��������
        else if((max<P[i].priority)&&(P[i].state==0))
        {
            max=P[i].priority;
            m=i;
        }
    }
    //ȷ��������������̻�û��������
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
    int t=0;//tΪ���������д���
    for(i=0; i<num; i++)
        t+=P[i].cpuTime;

    printf("\n��ʼʱ��������Ϣ:\n");
    show();

    for(j=0; j<t; j++)
    {
        //��������������ʱ(1Ϊ����̬)
        while(max_pri()!=-1)
        {
            if(P[max_pri()].priority!=0)
                P[max_pri()].state=1;
            else //�����ȼ���Ϊ0�����̻�û������ʱ
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
        //�жϳ���״̬(��������������ʱ�����)
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
