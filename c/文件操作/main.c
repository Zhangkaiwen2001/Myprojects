#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct DATA
{
    int ID;
    char name[11];
    char type;
    int length;
};

void Find(int n,struct DATA *p)

{
    int t,i;
    system("cls");
    for(i=0;i<n;i++)
    {
        (p+i)->ID=i+1;
        printf("������ID=%d���ֶ����ƣ�",i+1);
        scanf("%s",(p+i)->name);
        fflush(stdin);
        printf("��ѡ���ֶ�����(int n/string s)��");
        scanf("%c",&(p+i)->type);
        fflush(stdin);
        if((p+i)->type=='s')
        {
            printf("�������ַ������ȣ�");
            scanf("%d",&t);
            (p+i)->length=t+1;
        }
        else if((p+i)->type=='n')
        {
            (p+i)->length=4;
        }
        printf("һ���ֶ�����������ϣ������������\n");
        getch();
    }

}

int Search(int n,struct DATA *p)
{
    int sum=0,i;
    system("cls");
    printf("�ѽ�����¼���ֶ�������Ϣ��\n");
    for(i=0;i<n;i++)
    {
        sum+=(p+i)->length;
        printf("�ֶ�ID��%d,�ֶ�����%s,�ֶγ��ȣ�%d,�ֶ����ͣ�%c\n",(p+i)->ID,(p+i)->name,(p+i)->length,(p+i)->type);
    }
    printf("�����ֶ���ռ�ռ�Ϊ%d�ֽ�\n",sum);
    printf("�������¼����Ϣ");
    getch();
    return sum;
}

int Input(int n,int m,struct DATA *p,char *pc)

{
    system("cls");
    int i,j,t=0,count=0,a;
    for(j=0;j<m;j++)
    {
        count++;
        for(i=0;i<n;i++)
        {
            printf("%s=",(p+i)->name);
            if((p+i)->type=='s')
                scanf("%s",pc+t);
            else
                scanf("%d",(int*)pc+t);
            t+=(p+i)->length;
        }
        if(j==m-1) printf("��¼ȫ��¼����ϣ�����������¼�����Ϣ");
        else printf("һ����¼¼����ϣ����������������ESC��ֹͣ¼����Ϣ\n");
        a=getch();
        if(a==27) break;
    }
    return count;
}

void Print(int n,int count,struct DATA *p,char *pc)
{
    system("cls");
    printf("�Ѿ�¼�����Ϣ��\n");
    int i,j,t=0;
    for(j=0;j<count;j++)
    {
        for(i=0;i<n;i++)
        {
            if((p+i)->type=='s')
                printf("%s:%s, ",(p+i)->name,pc+t);
            else
                printf("%s:%d",(p+i)->name,*(pc+t));
            t+=(p+i)->length;
        }
        printf("\n");
    }
}

FILE *pf;
void Write(int m,int n,int sum,struct DATA *p,char *pc,int count)
{
    char filename[10];
    int i,j;
    printf("������Ҫ�������ļ�����");
    scanf("%s",filename);
    pf=fopen(filename,"wb+");
    if(pf==NULL)
    {
        printf("����ʧ�ܣ�");
        exit(0);
    }
    char a=19;
    fwrite(&a,1,1,pf);
    fwrite(&m,4,1,pf);
    fwrite(&n,4,1,pf);
    fwrite(&sum,4,1,pf);
    fwrite(&count,4,1,pf);
    for(i=0;i<n;i++)
    {
        fwrite(&(p+i)->ID,4,1,pf);
        fwrite(&(p+i)->name,11,1,pf);
        fwrite(&(p+i)->type,1,1,pf);
        fwrite(&(p+i)->length,4,1,pf);
    }
    int t=0;
    for(j=0;j<count;j++)
    {
        for(i=0;i<n;i++)
        {
            fwrite(&(p+i)->name,11,1,pf);
            fwrite(&(p+i)->length,4,1,pf);
            fwrite(&(p+i)->type,1,1,pf);
            fwrite(pc+t,(p+i)->length,1,pf);
            t+=(p+i)->length;
        }
    }
    fclose(pf);
}

void Open()
{
    system("cls");
    int i,j;
    char filename[10];
    printf("������Ҫ��ѯ���ļ�����");
    scanf("%s",filename);
    pf=fopen(filename,"rb");
    if(pf==NULL)
    {
        printf("����ʧ�ܣ�");
        exit(0);
    }
    else printf("�����Ǵ��ļ��ж�ȡ����Ϣ��\n");
    char out1,out3[11];
    int out2;
    fread(&out1,1,1,pf);
    printf("�汾�ţ�%d\n",out1);
    int m;
    fread(&m,4,1,pf);
    printf("��¼����%d\n",m);
    int n;
    fread(&n,4,1,pf);
    printf("�ֶ�����%d\n",n);
    fread(&out2,4,1,pf);
    printf("ÿ����¼�ĳ��ȣ�%d\n",out2);
    int count;
    fread(&count,4,1,pf);
    printf("��¼ͷ���ȣ�%d\n",n*24+13);
    printf("\n�ֶ����ԣ�\n");
    for(i=0;i<n;i++)
    {
        fread(&out2,4,1,pf);
        printf("�ֶ�ID��%-2d",out2);
        fread(&out3,11,1,pf);
        printf("�ֶ����ƣ�%-11s",out3);
        fread(&out1,1,1,pf);
        printf("�ֶ����ͣ�%-2c",out1);
        fread(&out2,4,1,pf);
        printf("�ֶγ��ȣ�%-3d\n",out2);
    }
    printf("\n��¼���ݣ�\n");
    int length;
    char type;
    for(j=0;j<count;j++)
    {
        for(i=0;i<n;i++)
        {
            fread(&out3,11,1,pf);
            printf("%s��",out3);
            fread(&length,4,1,pf);
            fread(&type,1,1,pf);
            if(type=='s')
            {
                fread(&out3,length,1,pf);
                printf("%s  ",out3);
            }
            else
            {
                fread(&out2,length,1,pf);
                printf("%d  ",out2);
            }
        }
        printf("\n");
    }
    fclose(pf);
    printf("��ȡ��ϣ�����������ز˵�");
    getch();
}

int main()
{
    int n,m,sum,count,a;
     while(1)
    {
        system("cls");
        printf("���¶�Ӧ����ѡ���ܣ�\n");
        printf("[C]:������¼ [L]:�г���¼ [Q]:�˳�");
        a=getch();
        if(a=='c'||a=='C')
        {
            system("cls");
            printf("�������¼���ֶ�����");
            scanf("%d",&n);
            printf("�������¼������");
            scanf("%d",&m);
            struct DATA *p=calloc(n,sizeof(struct DATA));
            if(p==NULL)
            {
                printf("error��");
                return 0;
            }
            Find(n,p);
            sum=Search(n,p);
            char *pc=calloc(m,sum);
            if(pc==NULL)
            {
                printf("error��");
                return 0;
            }
            count=Input(n,m,p,pc);
            Print(n,count,p,pc);
            Write(m,n,sum,p,pc,count);
            free(p);
            free(pc);
        }
        else if(a=='l'||a=='L') Open();
        else if(a=='q'||a=='Q') break;

    }
 return 0;
}
