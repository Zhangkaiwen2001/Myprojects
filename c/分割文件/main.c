#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6   // ����ָ����
int main()
{
    FILE *fsrc = fopen("D:\\myprojects\\exp8\\a.txt", "rb");  // Դ�ļ�
    FILE *div = fopen("D:\\myprojects\\exp8\\b.txt","w");  // ����ָ���Ŀ����Ϣ

    if (fsrc == NULL || div == NULL)
    {
        perror("�򿪴���");
        return 0;
    }
    fseek(fsrc, 0, SEEK_END);
    int fLen = ftell(fsrc);  // �ļ�����
    //printf("�ļ����ȣ�%d\n", fLen);
    int blockLen = fLen / N;   // ÿһ��ĳ���
    //printf("blockLen:%d\n", blockLen);
    FILE *ftmp;  // ��ʱ�ļ���
    for (int i = 0; i < N; i++)  // ����ָ�
    {
        char tName[20];
        char tdir[60] = "D:\\myprojects\\exp8\\";
        sprintf(tName, "����%d.tmp", i+1);//�����ļ���
        strcat(tdir, tName);  //������ʱĿ¼
        //printf("%s\n", tdir);
        ftmp = fopen(tdir, "wb");  // ������ʱ�ļ�
        if (ftmp == NULL)
        {
            perror("�����ļ�����");
            break;
        }
        fputs(tdir, div); // д���ļ���
        fputc('\n',div);

        int offset = i*blockLen; //����ƫ����
        fseek(fsrc, offset, SEEK_SET);
        int count = 0;  //ͳ��д��ftmp������
        if (i == N - 1) blockLen = fLen - blockLen*(N - 1);  //���һ��ĳ���
        while (count<blockLen && !feof(fsrc))
        {

            fputc(fgetc(fsrc),ftmp);
            count++;
        }
        printf("count:%d\n", count);
        fclose(ftmp);
    }

    fclose(fsrc);
    fclose(div);

    system("pause");
    return 0;
}
