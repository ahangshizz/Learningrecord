#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//int main()
//{
//	int a[] = { 0, 1, 2, 3 };
//	int *p[4];
//	int len = sizeof(p) / sizeof(p[0]);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		p[i] = &a[i];
//	}
//	for (i = 0; i < len; i++)
//#include<stdio.h>
//	{
//		printf("%d, ", *p[i]);
//	}
//
//	return 0;
//}




//void skt(int *pa, int *pb)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 2;
//	skt(&a, &b);
//	printf("a=%d b=%d\n", a, b);      //想通过函数改变实参必须是传址；
//	return 0;
//}




//void maopao(int a[], int len)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 0; i < len-1; i++)
//	{
//		for (j = 0; j < len-1 - i; j++)
//		{
//			if (a[j]>a[j + 1])
//			{
//				tmp = a[j];
//				a[j] = a[j+1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	int a[] = { -1, -2, -3, 4, 5, 8, 9, -5 };
//	int len = sizeof(a) / sizeof(a[0]);
//	maopao( a, len);
//	for (i = 0; i < 8; i++)
//	{
//		printf("%d, ", a[i]);
//	}
//	return 0;
//}




//void my_strcpy(char *b, const char *a)
//{
//	while (*a != '\0')
//	{
//		*b++ = *a++;
//	}*b = '\0';
//}
//int main()
//{
//	char a[] = "welcome to bit";
//	char b[100];
//	my_strcpy(b, a);
//	printf("%s\n", b);
//
//
//	return 0;
//}


//int main()
//{
///*	"welcome to bit"
//	printf("%s \n", a);
//	printf("%p\n", a);
//	printf("%s\n", a + 1);
//	printf("%p\n", a + 1);
//	printf("%c\n", *a)*/;
//
////char a[] = "welcome to bit";
//char *p = "welcome to bit";
//	*p = 'h';
//	printf("%s\n", p);             //字符串常量不可以修改   一放在DATA区。    数组定义的字符串是可以修改的
//	return 0;
//}
//int main()
//{
//	char *p = "hello";
//	strcpy(*p, "abc");
//	printf("%s\n", *p);    //err    字符串是一个常量字符串     DaTa是文字常量区，文字常量区的内容只能读不可以修改
//	return 0;


//int main()
//{
//	char *p = "abc123ves123dwaf123aeg123srg123sbrs123";
//	int i = 0;
//	char *tmp = NULL;
//	while (1)
//	{
//		tmp = strstr(p, "123");
//		if (tmp==NULL)
//		{
//			break;
//		}
//		else
//		{
//			i++;
//			p = tmp + strlen("123");
//		}
//	}printf("%d \n", i);
//	return 0;
//}


//int main()
//{
//	char *p = "            123456789            ";
//	char *start = p;
//	char *end = strlen(p) + p - 1;
//	while (*start == ' '&& *start!='\0')
//	{
//		start++;
//	}
//	while (*end == ' '&&*end!=p)
//	{
//		end--;
//	}
//	int n = end - start + 1;
//	char buf[100];
//	strncpy(buf, start, n);
//	//buf[n] = '\0';
//	printf("%s\n", buf);
//	printf("%d\n", n);
//	return 0;
//}
//int main()
//{
//	char a[10];
//	int i = 0;
//	memset(&a,'a', sizeof(a));//只能用来清零
//char b[] = "ajjbskgj\0adaw";
//	/*char c[100];*/
//	//memcpy(c, b, sizeof(b));
//for (i = 0; i < sizeof(a); i++)
//{
//	printf("%c ", a[i]);
//}
//	//printf("%s\n", c);
//	return 0;
//}


//int main()
//{
//	char p[] = "hello\0 bit";
//	char buf[100];
//	memcpy(buf, p, sizeof(p));
//	printf("%s", buf);
//	printf("%s", buf + strlen("hello") + 1);
//	memset(buf, 0, sizeof(buf));
//	strncpy(buf, p, sizeof(p));
//	printf("%s", buf);
//	printf("%s", buf + strlen("hello") + 1);
//	
//	return 0;
//}


int main()
{
	int *p;
	p = (int *)malloc(sizeof(int ));
	if (p == NULL);
	{
		printf("分配失败");
		return -1;
	}
	*p = 10;
	printf("%d\n", *p);
	free(p);
	return 0;
}