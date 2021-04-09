#include <stdio.h>
#include <stdlib.h>
#define INFINTY 65535
#define MAX_VERTEX_NUM 20//最大顶点个数
/*从1开始的邻接矩阵图计算*/
typedef struct{
    int vexs[MAX_VERTEX_NUM];
    int vexnum,arcnum;
    int adjmatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}MGraph;

void Dispath(int A[][MAX_VERTEX_NUM],int path[][MAX_VERTEX_NUM],int n);

void Floyd(MGraph G)
{
	int A[MAX_VERTEX_NUM][MAX_VERTEX_NUM],path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int i,j,k;
	for (i=1;i<=G.vexnum;i++)
	{
		for (j=1;j<=G.vexnum;j++)
		{
			A[i][j]=G.adjmatrix[i][j];
			path[i][j]=-1;
		}
	}
	for (k=1;k<=G.vexnum;k++)
	{
		for (i=1;i<=G.vexnum;i++)
		{
			for (j=1;j<=G.vexnum;j++)
			{
				if (A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	Dispath(A,path,G.vexnum);
}
/*
void Ppath(int path[][MAX_VERTEX_NUM],int i,int j)
{
	int k;
	k=path[i][j];
	if (k==-1)
	{
		return;
	}
	Ppath(path,i,k);
	//printf("%d,",k + 1);
	Ppath(path,k,j);
}
*/
void Dispath(int A[][MAX_VERTEX_NUM],int path[][MAX_VERTEX_NUM],int n)
{
	int i,j;
	int count;
	for (i=1;i<=n;i++)
	{
	    count=0;
		for (j=1;j<=n;j++)
		{
			if (A[i][j]==INFINTY)
			{
				if (i!=j)
				{
					//printf("从%d到%d没有路径\n",i+1,j+1);
				}
			}
			else
			{
				//printf(" 从%d 到 %d => 最短路径长度为 : %d , 路径站点为 :",i+1,j+1,A[i][j]);
				if(A[i][j]<=6)
                    count++;//后改
				//printf("%d,",i + 1);
				//Ppath(path,i,j);
				//printf("%d\n",j + 1);
			}
		}
		printf("%d:%.2f%%\n",i,(float)count*100/(float)n);//后改
	}
}

int main()
{
    int i,j;
    int m,n;
    MGraph Graph;
    for(i=0;i<MAX_VERTEX_NUM;i++)
    {
        for(j=0;j<MAX_VERTEX_NUM;j++)
            Graph.adjmatrix[i][j]=INFINTY;
    }
    scanf("%d %d",&Graph.vexnum,&Graph.arcnum);//输入点数和边数
    for(i=1;i<=Graph.arcnum;i++)//导入边
    {
        scanf("%d %d",&m,&n);
        Graph.adjmatrix[m][n]=1;
        Graph.adjmatrix[n][m]=1;
    }
    Floyd(Graph);
    return 0;
}
