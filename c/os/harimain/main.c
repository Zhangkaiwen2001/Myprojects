#include <stdio.h>
#include <stdlib.h>

void HariMain(void)
{
    int i; /* �������ԡ�i�Ȥ��������ϡ�32�ӥåȤ������� */
	char *p; /* p�Ȥ��������ϡ�BYTE [...]�äη��� */

	for (i = 0xa0000; i <= 0xaffff; i++) {

		p = (char*)i; /* ���ؤ���� */
		*p = i & 0x0f;

		/* ����� write_mem8(i, i & 0x0f); �δ����ˤʤ� */
	}
}

int main()
{
    printf("Hello,Calvin");
    HariMain();
    return 0;
}
