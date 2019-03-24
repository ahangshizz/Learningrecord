//#include<windows.h>//引入我们最终的，的头文件。windows，因为你要实现windows的窗口啊。 
//int main() 
//{ char modeCommand[1024];
//sprintf(modeCommand, "mode con cols=%d lines=%d", 20, 10);
//system(modeCommand); //这三行实现的功能，就是调整我们exe文件原本黑框框的大小。 
//while(MessageBox(NULL, TEXT("你喜欢我吗？"), TEXT("你愿不愿意做我女朋友？"), MB_YESNO) != IDYES)
//{ 
//	MessageBox(NULL, TEXT("我愿意给你做饭吃啊"), TEXT("我最喜欢你呀"), MB_OK); 
//	MessageBox(NULL, TEXT("我愿意给你系衣服啊"), TEXT("我最喜欢你呀"), MB_OK);
//	MessageBox(NULL, TEXT("我愿意给你讲个事啊"), TEXT("我最喜欢你呀"), MB_OK); 
//	MessageBox(NULL, TEXT("我愿意给你做饭吃啊"), TEXT("我最喜欢你呀"), MB_OK); 
//}
//MessageBox(NULL, TEXT("哈哈哈哈，你答应我啦"), TEXT("我最喜欢你呀"), MB_OK);
//return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a[] = { 8, 7, 5, 6, 2, 1, 0 };
//	int i = 0;
//	int j = 0;
//	int n = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < n; i++)
//	{
//		printf("%d, ", a[i]);
//	}
//	printf("\n");
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n -1 - i; j++)
//		{
//			if (a[j]>a[j + 1])
//			{
//				int tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//	for (j = 0; j < n; j++)
//	{
//		printf("%d, ", a[j]);
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a[] = { 2, 5, 7, 8, 1, 5, 7, 6, 8, 9 };
//	int i = 0;
//	int j = 0;
//	int n = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < n; i++)
//	{
//		printf("%d, ", a[i]);
//	}
//	printf("\n");
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			if (a[i]>a[j])
//			{
//				int tmp = a[i];
//				a[i] = a[j];
//				a[j] = tmp;
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%d, ", a[i]);
//	}
//		return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b[10];
//	printf("int a:%d \n", sizeof(a));//4
//	printf("int a:%d \n", sizeof(int *));//4
//	printf("int b:%d \n", sizeof(b));//40
//	printf("int b:%d \n", sizeof(b[0]));//4
//	printf("int b:%d \n", sizeof(*b));//4
//	printf("hello.....\n");//
//	getchar();
//	return 0;
//}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("&a=%p", &a);
//	printf("&b=%p", &b);
//	return 0;
//}
//	int *p = (int *)malloc(sizeof(int));
//	int *q = (int *)malloc(sizeof(int));
//	printf("*p=%p,*q=%p", p, q);
//	free(p);
//	p = NULL;
//	free(q);
//	q = NULL;
//	return 0;
//}

//int main()
//{
//	char buf[100] = "welcome to bit";
//	char *p = NULL;
//	char *q = NULL;
//	char buf2[100] = "abcdefg";
//	p = buf;
//	q = buf2;
//	int i = 0;
//	for (i = 0; i < strlen(buf); i++)
//	{
//		p = &buf[i];
//		printf("*p=%c,p=%p\n", *p, p);
//		 
//	}
//	for (i = 0; i < strlen(buf2); i++)
//	{
//		p = q + i;
//		printf("*p=%c  ", *p);
//	}
//	system("pause");
//	return 0;
//}

//void fun2(int b)
//{
//	b = 20;
//}
//int fun1()
//{
//	int b = 30;
//	return b;
//}
//void fun3(int *p)
//{
//	*p = 40;
//}
//int main()
//{
//	int b = fun1();
//	printf("b1=%d\n", b);
//	fun2(b);
//	printf("b2=%d\n", b);
//	fun3(&b);
//	printf("b3=%d\n", b);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	char buf[] = { 'a', 'b', 'c' ,'\0'};
//	printf("%s ", buf);
//	system("pause");
//	return 0;
//}

int main()
{
	char buf[] = "jhjwroinvowevpowievm";
	char tmp[100];
	int i = 0;
	for (i = 0; buf[i] != '\0'; i++)
	{
		tmp[i] = buf[i];
	}tmp[i] = 0;
	printf("%s", tmp);
	system("pause");
	return 0;
}