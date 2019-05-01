#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>


int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf==NULL||outbuf==NULL)
	{
		return-1;
	}
	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;
	if (end < 0)
	{
		return -2;
	}
	while (isspace(p[begin]) && p[begin] != 0)
	{
		begin++;
	}
	while (isspace(p[end]) && p[end] > 0)
	{
		end--;
	}
	if (end == 0)
	{
		return -2;
	}
	n = end - begin + 1;
	strncpy(outbuf, p + begin, n);
	outbuf[n] = 0;
	return 0;
}
int ReadcgdFile(char *file, char *key, char *value, int *len)
{
	char linbuf[2048] = { 0 };
	FILE *fp = NULL;
	int ret = 0;
	char  *p=NULL;
	int flag = 0;
	//打开文件
	fp = fopen(file, "r+");
	if (fp == NULL)
	{
		printf("打开失败");
		goto END;
	}
	while (1)
	{
		if (fgets(linbuf, sizeof(linbuf), fp)==NULL)
		{
			break;
		}

		//找key
		p = strstr(linbuf, key);
		if (p == NULL)
		{
			continue;
		}
		//重新设置起点
		p = p + strlen(key);
		//找“=”
		p = strstr(p, "=");
		if (p == NULL)//没有
		{
			continue;//跳出本次循环
		}
		//重新设置起点
		p = p + strlen("=");
		//获取非空字符
		ret = trimSpace(p, value);
		if (ret == 0)
		{
			*len = strlen(value);
			flag = 1;
			goto END;
		}
		else
		{
			goto END;
		}
	}
END:
	fclose(fp);
	fp = NULL;
	if (0 == flag)
	{
		printf("没有找到对应的值");
	}
	return ret;
}
int WritecgdFile(char *file, char *key, char *value, int len)
{
	return 0;
}