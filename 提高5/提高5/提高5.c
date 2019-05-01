#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "cgd.h"
#define CGDNAME "my.ini"
void memu()
{
	printf("********************\n");
	printf("*1.读配置文件      *\n");
	printf("*2.写配置文件      *\n");
	printf("*3.清屏            *\n");
	printf("*4.退出            *\n");
	printf("********************\n");
}

void Myread()
{
	int len = 0;
	int ret = 0;
	char key[256] = { 0 };
	char value[1024] = { 0 };
	printf("请输入key的值:");
	scanf("%s", key);
	ret=ReadcgdFile(CGDNAME, key, value, &len);
	if (ret!=0)
	{
		printf("ReadcgdFile 错误");
		return -1;
	}
	printf("key=%s\n", key);
	printf("value=%s\n", value);
	printf("len=%d\n", len);
}
void Mywrite()
{
	int ret = 0;
	char key[256] = { 0 };
	char value[1024] = { 0 };
	printf("请输入key的值:");
	scanf("%s", key);
	printf("请输入value的值:");
	scanf("%s", value);
	ret = WritecgdFile(CGDNAME, key, value, strlen(value));
	if (ret != 0)
	{
		printf("WritecgdFile 错误");
		return -1;
	}
	printf("key=%s\n", key);
	printf("value=%s\n", value);
	printf("len=%d\n", strlen(value));
}
int main()
{
	int cmd;
	while (1)
	{
		memu();
		printf("cmd:");
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1:
			Myread();
			break;
		case 2:
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