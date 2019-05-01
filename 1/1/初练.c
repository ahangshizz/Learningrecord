/*#include<stdio.h>
int main();
{
	//printf("Hello World!/n");
	printf（"%d/n", sizeof(char)）;
	printf("%d/n", sizeof(short));
	printf("%d/n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(long double));
	
	return 0;*/
//#include<stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(char));//1
//	printf("%d\n", sizeof(short));//2
//	printf("%d\n", sizeof(int));//4
//	printf("%d\n", sizeof(float));//4
//	printf("%d\n", sizeof(long long));//8
//	printf("%d\n", sizeof(long double));//8
//	return	0;
//}
//#include <stdio.h>
//int	main()
//{
////	//const int	a = 10;
////	//a = 20;
////	//const int	n = 10;
////	//int	arr[n];
//	volatile const	int	n = 10;
//	int	*p = (int *)&n;
//	*p = 20;
//	printf("%d\n", n);
//	return	0;
//}
//#include <stdio.h>
//int	main()
//{
//	volatile const int	n = 10;
//	int	*p = (int *)&n;
//	*p = 20;
//	printf("%d\n",n  );
//	return	0;
//}
//#include	<stdio.h>
//int	main(void)
//{
//	int	i;
//	int	sum = 0;
//	for (i = 1; i <= 100; ++i)
//	{
//		sum = sum + i;
//	}
//	printf("sum=%d\n", sum);
//	return	0;
//}
//#include<stdio.h>
//int	main()
//{
//	int	i;
//	int	sum = 0;
//	for (i = 1; i <=100; i++)
//	{
//		sum = sum + i;
//
//	}
//	printf("%d\n", sum);
//	return	0;
//}
//#include<stdio.h>
//int	main()
//{
//	int	i;
//	int	sum = 0;
//		for ( i = 1; i <= 100; i++)
//
//		{
//		sum = sum + i;
//		}
//		printf("%d\n", sum);
//	return	0;
//}
//#include<stdio.h>
//int	main()
//{
//	int	i;
//	int	sum = 0;
//	for (i = 1; i <= 1000; i++)
//	{
//		sum = sum + i;
//	}
//	printf("%d", sum);
//		return	0;
//}
//#include<stdio.h>
//int	main()
//{
//	//int	a = 0;
//	int	num = 0;
//	printf("输入一个整数：");
//	
//	return	0;
//}
//#include<stdio.h>
//int	main()
//{
//	int	i;
//		scanf("%d", &i);
//		printf("i=%d\n", num);
//	return	0;
//
//}
//#define _CRT_SECURE_NO_WARNINGS # include <stdio.h>
//int main(void)
//{
//	int i;
//	printf("输入一个数字：");
//	scanf("%d", &i);
//	printf("i = %d\n", i);
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS #include <stdio.h>
//int	main()
//{
//	int a = 0;
//	int num = 0;
//	printf("输入一个整数：");
//	scanf("%d", &num);
//	for (int i = 2; i < num; i++)
//	{
//		if (num%i == 0){
//			a++;
//		}
//	}
//	if (a == 0){
//		printf("%d是素数",num);
//	}
//	else{
//		printf("%d不是素数", num);
//	}
//	return	0;
//}
#define _CRT_SECURE_NO_WARNINGS #include <stdio.h>
int	main()
{
	int	a = 0;
	int	num = 0;
	printf("请输入一个整数：");
	scanf("%d", &num);
	for (int i = 2; i < num; i++)
	{
		if (num%i == 0){
			a++;
		}
	}
		if (a == 0){
			printf("%d是素数",num);
		}
		else{
			printf("%d不是素数", num);

	}
	return	0;
}