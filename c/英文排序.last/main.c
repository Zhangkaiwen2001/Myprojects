#include <stdio.h>
#include<string.h>
int countspcae(char *str)
{
    int count=0;
    int i;
    for (i=0; i<strlen(str); i++)
    {
        if (str[i]==' ')
            count++;
    }
    return count;
}

void normalize(char *str,int *startChar,int *endChar,int numColume)
{
    char straline[200]="";
    int i,j;
    while ( (str[*endChar]!=' ')&&(str[*endChar]!='.')&& (str[*endChar]!=',') && (str[*endChar]!='!'))
        (*endChar)--;
    for (i=*startChar,j=0; i<*endChar; i++,j++)
        straline[j]=str[i];
    if (str[*endChar]!=' ')
        straline[++j]=str[*endChar];
    *startChar=*endChar+1;
    *endChar=*startChar+numColume;
    standardize(straline,numColume);
}

void standardize(char *straline,int numColume)
{
    int spacenum=countspcae(straline);//原来空格数
    int span=numColume-strlen(straline); //插入总量
    int insertnum=span/spacenum; //平均每个空格后面插入数量
    int restnum=span%spacenum;//多余空格
    int i,count=0;
    char output[200]="";
    if (spacenum>0)
    {

        for (i=0; i<numColume; i++)
            output[i]=' '; //初始化每一位都是空格再填数
        for (i=0; i<strlen(straline); i++)
        {
            if (straline[i]==' ')
            {
                count+=insertnum;
                if (restnum>0)
                {
                    count++;
                    restnum--;
                }
            }
            output[count]=straline[i];
            count++;
        }
        puts(output);
    }
    else
        puts(straline);

}

int  main()
{
    int i;
    char straline[200]="";
    int numColume,startChar,endChar;
    char strText[]= {"We have an old musical instrument.It is called a clavichord.It was made in Germany in 1681.Our clavichord is kept in the living-room.It has belonged to our family for a long time.The instrument was bought by my grandfather many years ago.Recently it was damaged by a visitor.She tried to play jazz on it!She struck the keys too hard and two of the strings were broken.My father was shocked.Now we are not allowed to touch it.It is being repaired by a friend of my father's."};
    int textLen=strlen(strText);
    printf("预排版如下（30列）\n");
    printf("This is a sample in 30:\n\n");
    printf("We   have   an   old   musical\ninstrument.It   is   called  a\nclavichord.It   was   made  in\nGermany       in      1681.Our\n");
    printf("clavichord   is  kept  in  the\nliving-room.It   has  belonged\nto our family for a long time.\nThe  instrument  was bought by\n");
    printf("my grandfather many years ago.\nRecently  it  was damaged by a\nvisitor.She   tried   to  play\njazz   on  it!She  struck  the\nkeys  too  hard and two of the\n");
    printf("strings  were broken.My father\nwas  shocked.Now  we  are  not\nallowed   to  touch  it.It  is\nbeing  repaired by a friend of\n");
    printf("my father's.");
    printf("\n请重新输入列宽\n");
    scanf("%d",&numColume);
    if (numColume>=textLen)
    {
        puts(strText);
        return 0;
    }
    startChar=0;
    endChar=numColume-1;
    while (endChar<textLen)
    {
        normalize(strText,&startChar,&endChar,numColume);
    }
    for (i=startChar; i<textLen; i++)
        printf("%c",strText[i]);  //打印剩余字符
    return 0;

}
