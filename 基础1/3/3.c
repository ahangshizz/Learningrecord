//#include <stdio.h>
//int  main()
//{
//	int a;
//	int b;
//	int c;
//	printf("请输入一个数字：");
//	scanf("%c", &a);                           //%c和%d   对scanf输入的影响不同     %c只是单个字符
//	printf("a=%c\n",a);
//
//	scanf("%c", &b);
//	printf("b=%c\n", b);
//	scanf("%c", &c);
//	printf("c=%c", c);
//
//	return  0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 90;
//	int b = 80;
//	int c ;
//	c = a < b ? a : b;
//	printf("c=%d\n",c);
//	return 0;
//}





//
//include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 1;
//	int c = 2;
//	int d = 3;
//	int f;
//	f = a>b ? (a>c ? c : (a>d ? c : d)) : (b>c?c:)     //三目运算符     数目较多是脑子混乱，逻辑不明确
//	printf("f=%d\n", f);
//	return 0;
//}                                                    //运算失败      


//
//#include <stdio.h>
//int main()
//{
//	int 爷=1;
//	int a=0;
//	while (a!=爷)
//	{
//		printf("叫爷！\n");
//		scanf("%d", &a);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	while (a > 0)
//	{
//		printf("请输入一个数字：");
//		scanf("%d", &a);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i;
//	int a=0;
//	for (i = 1; i <= 100; i++)
//	{
//		a =a+ i;
//	}printf("a=%d\n", a);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i*j);
//		}printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	int i = 0;
//	while ( a <= 100)
//	{
//		i = i + a;
//		a++;
//	}
//	printf("i=%d", i);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	for (;;)
//	{
//		printf("我是死循环\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (5 == i)
//		{
//			continue;
//		}
//		printf("i=%d\n", i);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i == 5)
//		{
//			goto a;
//		}
//	}
//a:
//	printf("i=%d\n", i);
//
//
//	return 0;
//}