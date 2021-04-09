#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXS 10
#define MINS 3
#define MAXB 5
#define MAXTable 500009

typedef char ElementType[MAXS + 1];

typedef struct FileEntry
{
    int words;//第一个表示词汇总数，之后表示词汇在文件位置
    struct FileEntry *Next;
} WList;

typedef struct WordEntry
{
    int FileNo;//文件编号
    struct WordEntry *Next;//指向下一个文件编号
} FList;

struct HashEntry
{
    ElementType Element;//存储信息
    int FileNo;
    FList *InvIndex;
};

typedef struct HashTbl
{
    int TableSize;//文件总数
    struct HashEntry *TheCells;//散列表静态数组
} HashTable;

HashTable* Table_Init(int TableSize)//初始化散列表静态数组
{
    HashTable *H = malloc(sizeof(HashTable));
    H->TableSize = TableSize;
    H->TheCells = malloc(sizeof(struct HashEntry) * H->TableSize);
    while (TableSize)
    {
        H->TheCells[--TableSize].FileNo = 0;
        H->TheCells[TableSize].InvIndex = NULL;
    }
    return H;
}

WList* FileIndex_Init(int Size)//初始化文件位置表
{
    WList *F = malloc(sizeof(FList) * Size);
    while (Size)
    {
        F[--Size].words = 0;
        F[Size].Next = NULL;
    }
    return F;
}

int GetWord(ElementType Word)
//从当前字符开始到字符尾第一个非字母符号
//读到文件结束返回0
{
    char c;
    int p = 0;
    scanf("%c", &c);
    while (!isalpha(c) && (c != '#'))
        scanf("%c", &c);
    if (c == '#')
        return 0;
    while (isalpha(c) && (p < MAXS))
    {
        Word[p++] = tolower(c);//利用tolower函数将大写转为小写，避免大小写判断问题
        scanf("%c", &c);
    }
    while (isalpha(c))//跳过超长的字符
        scanf("%c", &c);
    if (p < MINS)//去除过短的单词
        return GetWord(Word);
    else
    {
        Word[p] = '\0';
        return 1;
    }
}

int Hash(char *key,int p)
{
    unsigned int h = 0;
    while (*key != '\0')
        h = (h << MAXB) + (*key++ - 'a');
    return h % p;
}

int Find(ElementType key, HashTable *H)
{
//返回key的位置，或者返回适合插入Key的位置
    int pos = Hash(key, H->TableSize);
//先找到散列后映射的位置
    while (H->TheCells[pos].FileNo && strcmp(H->TheCells[pos].Element, key))
    {
//该位置被其他关键字占用
        pos++;
        if (pos == H->TableSize)
            pos -= H->TableSize;
    }
    return pos;
}

int InsertAndIndex(int FileNo, ElementType key, HashTable *H)
{
    FList *F;
    int pos = Find(key, H);
    if (H->TheCells[pos].FileNo != FileNo)
    {
        if (!H->TheCells[pos].FileNo)
            strcpy(H->TheCells[pos].Element, key);
        H->TheCells[pos].FileNo = FileNo;//更新最近文件
        F = malloc(sizeof(FList));
        F->FileNo = FileNo;
        F->Next = H->TheCells[pos].InvIndex;
        H->TheCells[pos].InvIndex = F;
        return pos;
    }
    else
        return -1;
}

void FileIndex(WList *File, int FileNo, int pos)
{
    WList *W;
    if (pos < 0)
        return;
//插入索引表
    W = malloc(sizeof(WList));
    W->words = pos;
    W->Next = File[FileNo-1].Next;
    File[FileNo-1].Next = W;
    File[FileNo-1].words++;
}

double work(WList *File, int F1, int F2, HashTable *H)
{
    int temp;
    WList *W;
    FList *F;
    if (File[F1-1].words > File[F2-1].words)
    {
        temp = F1;
        F1 = F2;
        F2 = temp;
    }
    temp = 0;
    W = File[F1-1].Next;
    while (W)
    {
        F = H->TheCells[W->words].InvIndex;
        while (F)
        {
            if (F->FileNo == F2)
                break;
            F = F->Next;
        }
        if (F)
            temp++;
        W = W->Next;
    }
    return ((double)(temp * 100)/ (double)(File[F1 - 1].words + File[F2 - 1].words - temp));
}

int main()
{
    int n, m, f1, f2;
    ElementType word;
    HashTable *H;
    WList *File;
    scanf("%d", &n);
    File = FileIndex_Init(n);
    H = Table_Init(MAXTable);
    for (int i = 0; i < n; i++)
        while(GetWord(word))
            FileIndex(File, i + 1, InsertAndIndex(i+1, word, H));
    scanf("%d", &m);
    for (int i = 0 ; i < m; i++)
    {
        scanf("%d %d", &f1, &f2);
        printf("%.1f%c\n", work(File, f1, f2, H), '%');
    }
    return 0;
}
