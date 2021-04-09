#include <stdio.h>
#include <stdlib.h>
//�þ�̬�������飩��ʾ������
#define MaxTree 10
#define ElenmentType char
#define Tree int
#define Null -1

struct TreeNode
{
    ElenmentType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[])//���ظ��ڵ�
{
    int N;//�������ڵ���Ŀ
    int i;
    char cl,cr;//�����ӽڵ�
    Tree root = Null;//���ڵ�
    scanf("%d",&N);
    int check[N];//�жϸ��ڵ��־
    if(N)
    {
        for(i=0;i<N;i++)
            check[i]=0;
        for(i=0;i<N;i++)
        {
            scanf("%c %c %c\n",&T[i].Element,&cl,&cr);//���������ӽڵ�
            if(cl!='-'){
                T[i].Left = cl-'0';
                check[T[i].Left]=1;
            }
            else
                T[i].Left = Null;//��cl�Ķ�Ӧ����
            if(cr!='-'){
                T[i].Right = cr-'0';
                check[T[i].Right]=1;
            }
            else
                T[i].Right = Null;//��cr�Ķ�Ӧ����
        }
        for(i=0;i<N;i++)
        {
            if(!check[i])
                break;
        }
        root = i;
    }
    return root;
}

int Isomorphic(Tree R1, Tree R2)//�ж����Ƿ�ͬ��
{
    if((R1==Null)&&(R2==Null))//ȫΪ����
        return 1;
    if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))//һ�����ǿյ�
        return 0;
    if(T1[R1].Element!=T2[R2].Element)//���ڵ㲻ͬ
        return 0;
    if((T1[R1].Left==Null)&&(T2[R2].Left==Null))//��û��������
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Element)==T2[T2[R2].Left].Element))//����Ҫ������������λ��
        return(Isomorphic(T1[R1].Left,T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right));
    else
        return(Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));//������������λ���ж�

}

int main()
{
    Tree R1,R2;

    R1 = BuildTree(T1);
    printf("������ڶ�����");
    R2 = BuildTree(T2);
    if(Isomorphic(R1,R2))
        printf("Yes");
    else
        printf("No");


    return 0;
}
