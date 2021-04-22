#include <stdio.h>
#include <stdlib.h>

void HariMain(void)
{
    int i; /* 変数宣言。iという変数は、32ビットの整数型 */
	char *p; /* pという変数は、BYTE [...]用の番地 */

	for (i = 0xa0000; i <= 0xaffff; i++) {

		p = (char*)i; /* 番地を代入 */
		*p = i & 0x0f;

		/* これで write_mem8(i, i & 0x0f); の代わりになる */
	}
}

int main()
{
    printf("Hello,Calvin");
    HariMain();
    return 0;
}
