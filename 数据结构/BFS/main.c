#include <stdio.h>
#include <stdlib.h>
#include"Graph.h"
#include"Queue.h"
#define MaxSize 104
/* �ڽӾ���洢��ͼ - BFS */
/* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  */
/* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������*/
/* �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
void Visit(Vertex v)
{
    printf("���ڷ��ʵĶ���%d\n",v);
}
int Visited[MaxSize] = {0};
int IsEdge( MGraph Graph, Vertex V, Vertex W )
{
    return Graph->G[V][W]<INFINITY ? 1 : 0;
}
/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void BFS ( MGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    /* ��SΪ��������ڽӾ���洢��ͼGraph����BFS���� */
    Queue Q;
    Vertex V, W;
    Q = CreateQueue( MaxSize ); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
    /* ���ʶ���S���˴��ɸ��ݾ��������Ҫ��д */
    Visit( S );
    Visited[S] = 1; /* ���S�ѷ��� */
    AddQ(Q, S); /* S����� */
    while ( !IsEmpty(Q) )
    {
        V = DeleteQ(Q);  /* ����V */
        for( W=0; W<Graph->Nv; W++ ) /* ��ͼ�е�ÿ������W */
            /* ��W��V���ڽӵ㲢��δ���ʹ� */
            if ( !Visited[W] && IsEdge(Graph, V, W) )
            {
                /* ���ʶ���W */
                Visit( W );
                Visited[W] = 1; /* ���W�ѷ��� */
                AddQ(Q, W); /* W����� */
            }
    } /* while����*/
}

int main()
{
    MGraph Graph;
    Graph = BuildGraph();
    BFS(Graph,0,Visit);
    return 0;
}
