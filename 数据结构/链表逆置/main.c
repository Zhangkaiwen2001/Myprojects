#include <stdio.h>
#include <stdlib.h>

struct List_node
{
    int date;
    struct List_node* next;
};

typedef struct List_node* List;

void Reverse(List L)
{
    List p = NULL;
    List q = NULL;
    p = L->next->next;
    L->next->next=NULL;
    while(p!=NULL)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}
List CreatList_L(List L,int n)
{
    L=(List)malloc(sizeof(struct List_node));
    L->next=NULL;
    for(int i=n; i>0; --i)
    {
        List p;
        p = (List)malloc(sizeof(struct List_node));
        scanf("%d",&p->date);
        p->next = L->next;
        L->next = p;
    }
    return L;
}
int main()
{
    List L = NULL;
    int n=3;
    L=CreatList_L(L,n);
    Reverse(L);
    L=L->next;
     while(L!=NULL)
    {
        printf("%d  ",L->date);
        L=L->next;
    }
    return 0;
}
