#include <stdio.h>
#include <stdlib.h>
//用静态链表（数组）表示二叉树
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

Tree BuildTree(struct TreeNode T[])//返回根节点
{
    int N;//输入树节点数目
    int i;
    char cl,cr;//左右子节点
    Tree root = Null;//根节点
    scanf("%d",&N);
    int check[N];//判断根节点标志
    if(N)
    {
        for(i=0;i<N;i++)
            check[i]=0;
        for(i=0;i<N;i++)
        {
            scanf("%c %c %c\n",&T[i].Element,&cl,&cr);//输入左右子节点
            if(cl!='-'){
                T[i].Left = cl-'0';
                check[T[i].Left]=1;
            }
            else
                T[i].Left = Null;//对cl的对应处理
            if(cr!='-'){
                T[i].Right = cr-'0';
                check[T[i].Right]=1;
            }
            else
                T[i].Right = Null;//对cr的对应处理
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

int Isomorphic(Tree R1, Tree R2)//判断树是否同构
{
    if((R1==Null)&&(R2==Null))//全为空树
        return 1;
    if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))//一个树是空的
        return 0;
    if(T1[R1].Element!=T2[R2].Element)//根节点不同
        return 0;
    if((T1[R1].Left==Null)&&(T2[R2].Left==Null))//都没有左子树
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&((T1[T1[R1].Left].Element)==T2[T2[R2].Left].Element))//不需要交换左右子树位置
        return(Isomorphic(T1[R1].Left,T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right));
    else
        return(Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));//左右子树交换位置判断

}

int main()
{
    Tree R1,R2;

    R1 = BuildTree(T1);
    printf("请输入第二棵树");
    R2 = BuildTree(T2);
    if(Isomorphic(R1,R2))
        printf("Yes");
    else
        printf("No");


    return 0;
}
