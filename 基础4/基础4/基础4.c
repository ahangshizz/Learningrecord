//#include <stdio.h>
//int main()
//{
//	char buf[100] = { 0 };
//	char tmp[100] = { 0 };
//	char str[10];
//	scanf("%s", buf);
//	printf("buf=%s", buf);
//	scanf("%s", tmp);          //把所有的字符放入缓冲区，以空格分隔开，一次只取一个
//	printf("tmp=%s", tmp);
//	scanf("%s", str);    //scanf不做越界检查
//	printf("str=%s", str);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	/*char buf[100];
//	gets(buf);
//	return 0;*/
//	char buf[10];
//	fgets(buf, sizeof(buf), stdin);//安全的输入    中间表达式写数组大小    为\0留出一个位置
//	printf("buf=%s\n", buf);
//}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//int main()
//{
//	//char buf[] = "hellomike";
//	char buf[] = "\0hello";
//	int ret = 0;
//	ret = strlen(buf);
//	printf("%d\n", sizeof(buf));//sizeof测数据类型长度，遇到\0不会提前结束。
//	printf("%d\n", ret);//stelen   遇到\0直接结束测试；
//	return 0;
//}
//int main()    //字符串的copy
//{
//	char buf[] = "wel\0come to bit";
//	char tmp[100];
//	///char a = tmp;
//	//strcpy(a, buf);       //strcpy遇见\0自动停止拷贝，和strlen一样
//
//	strncpy(tmp, buf,8);
//	//printf("%s\n", a);
//	printf("%s\n", tmp);  //打印的时候遇见\0自动结束
//	return  0;

//int main()
//{
//	char a[100] = " hello ";
//	char b[] = " bit ";
//    strncat(a, b,strlen(" bi"));
//	printf("%s\n", a);
//	return 0;
//}
//int main()
//{
//	char a[] = "nosnoewinoi";
//	char *p = strstr(a, "won");
//	if (p == NULL)
//	{
//		printf("查询失败\n");
//	}
//	else
//	{
//		printf("%s\n", p);
//	}
//	return 0;
//}
//void fun()
//{
//	printf("hahaha\n");
//	exit(0);
//}
//int main()
//{
//	printf("heheheh\n");
//	while (1)
//	{
//		fun();
//	}
//	return 0;
//}

//自定义一个函数实现strlen的功能
//char my_strlen(char tmp[])
//{
//	int i = 0;
//	while (tmp[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}
//int main()
//{
//	char a[] = "hello bit";
//	int ret = 0;
//	ret = my_strlen(a);
//	printf("%d\n", ret);//输出结果9
//	return 0;
//}
//定义一个函数  实现strcpy的功能
//void my_strcpy(char *b, char *a)
//{
//	while (*a != '\0')
//	{
//		*b = *a;
//		*a++;
//		*b++;
//	}*b = *a;
//}
//int main()
//{
//	char ret[] = "welcome to bit";
//	char tmp[100];
//	my_strcpy(tmp,ret);
//	printf("tmp=%s\n", tmp);
//	return 0;
//}
//int main()
//{
//	int *p=0;
//	*p = 100;
//	return 0;
//}
//int main()
//{
//	printf("%d ", sizeof(char));
//	printf("%d ", sizeof(short));
//	printf("%d ", sizeof(int));
//	printf("%d ", sizeof(long));
//	printf("%d ", sizeof(float));
//	printf("%d ", sizeof(double));//   如果定义一个指针类型  在32位编译器下全部为4字节，在64编译器下全部都为8字节‘’‘
//	return 0;
//}
//int main()
//{
//	void *p = NULL;//可以定义任何类型的变量，，，万能指针。
//	int a = 10;
//	p = &a;
//	printf("*P=%d ",*( int *)p);
//	return 0;
//}
int main()
{
	int a;
	int *p = &a;
	printf("p=%p   p+1=%p ", p, p + 1);
	char b;
	char *q = &b;
	printf("q=%p  q+1=%p  ", q, q + 1);
	return 0;
}