#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"
int main01()
{//加密
	unsigned char buf[] = "161a561ag56es156";
	int str = strlen(buf);
	unsigned char dst[100] = { 0 };
	int dstlen = strlen(dst);
	int ret = 0;
	ret=DesEnc(buf, str, dst, &dstlen);
	if (ret!=0)
	{
		printf("加密失败");
		return -1;
	}
	printf("buf=%s\n", buf);
	printf("dst=%s\n", dst);

	//解密
	memset(buf, 0, sizeof(buf));
	int n = 0;
	ret = DesDec(dst, dstlen, buf, &n);
	if (ret != 0)
	{
		printf("加密失败");
		return -1;
	}
	printf("dst=%s\n", dst);
	printf("buf=%s\n", buf);
	system("pause");
	return 0;
}

void Encfile()
{

}

void Decfile()
{

}
int main()
{
	while (1)
	{ 
		printf("==================\n");
		printf("|1.加密文件      |\n");
		printf("|2.解密文件      |\n");
		printf("|3.清屏          |\n");
		printf("|4.退出          |\n");
		printf("==================\n");
		printf("cmd:");
		int cmd;
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1:
			Encfile();
			break;
		case 2:
			Decfile();
			break;
		case 3:
			system("cls");
			break;
		case 4:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}