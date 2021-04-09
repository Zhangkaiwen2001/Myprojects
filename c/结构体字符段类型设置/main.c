#include <stdio.h>
#include <stdlib.h>
typedef struct FIELDATRR
{
    int fieldId;
    int fieldLen;
    char fieldType;
    char fieldCaption[11];
    char sfileldcontain[11];
    int nfileldcontain;
} file;
int main()
{
    int m,n,i,j,sum=0;
    printf("请输入记录的字段数:");
    scanf("%d",&m);
    printf("请输入记录条数:");
    scanf("%d",&n);
    file fil[m*n];
    system("cls");
    for(i=0; i<m; i++)
    {
        printf("请输入字段名称:");
        scanf("%s",fil[i].fieldCaption);
        printf("请输入选择字段类型：int n,string s(请输入n或者s)");
        scanf(" %c",&fil[i].fieldType);
        if(fil[i].fieldType=='s')
        {
            printf("输入字符串长度：");
            scanf("%d",&fil[i].fieldLen);
            fil[i].fieldLen++;
        }
        else
        {
            fil[i].fieldLen=4;
        }
        printf("一个字段属性输入完毕，按任意键继续。。。\n");
    }
    system("cls");
    printf("已建立记录的字段属性信息：\n");
    for(i=0; i<m; i++)
    {
        printf("字段ID:%2d,%-8s,%-2d,%c\n",i+1,fil[i].fieldCaption,fil[i].fieldLen,fil[i].fieldType);
        sum=sum+fil[i].fieldLen;
    }
    printf("%d\n",sum);
    printf("按任意键，可以录入信息\n");
    system("pause");
    system("cls");
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            printf("%s=",fil[i].fieldCaption);
            if(fil[i].fieldType=='s')
                scanf("%s",fil[i+j*m].sfileldcontain);
            else
                scanf("%d",&fil[i+j*m].nfileldcontain);
        }
        if(j<n-1)
            printf("一条记录录入完毕！按任意键继续录入，按ESC键返回\n");
        else
            printf("已经录入完了最后一条记录，按任意键可浏览输入的数据\n");
    }
    system("pause");
    system("cls");
    printf("已经录入的信息：\n");
    for(j=0; j<n; j++)
    {
        for(i=0; i<m; i++)
        {
            printf(" %s:",fil[i].fieldCaption);
            if(fil[i].fieldType=='s')
                printf("%-4s",fil[i+j*m].sfileldcontain);
            else
                printf("%-4d",fil[i+j*m].nfileldcontain);
        }
        printf("\n");
    }
    printf("\n\n");
    printf("程序执行完毕!按任意键退出程序。。。");
    system("pause");
    return 0;
}
