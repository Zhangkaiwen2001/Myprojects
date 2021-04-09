#include <stdio.h>
#include <stdlib.h>
#include"GraphList.h"
int Visited[MaxVertexNum] = {0};
/* �ڽӱ�洢��ͼ - DFS */
void Visit( Vertex V )
{
    printf("���ڷ��ʶ���%d\n", V);
}
/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */

void DFS( LGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    /* ��VΪ��������ڽӱ�洢��ͼGraph����DFS���� */
    PtrToAdjVNode W;
    Visit( V ); /* ���ʵ�V������ */
    Visited[V] = 1; /* ���V�ѷ��� */
    for( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* ��V��ÿ���ڽӵ�W->AdjV */
        if ( !Visited[W->AdjV] )
            /* ��W->AdjVδ������ */
            DFS( Graph, W->AdjV, Visit );    /* ��ݹ����֮ */
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
