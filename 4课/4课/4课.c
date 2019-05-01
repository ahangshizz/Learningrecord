//#include <stdio.h>
//int main()
//{
//	int arrA[] = { 1, 3, 5, 7, 9, 8 };
//	int arrB[] = { 2, 4, 6, 8, 7 ,5};
//	int c;
//	int i = 0;		
//	for (i = 0; i <= 5; i++)
//	{
//		c = arrA[i];
//		arrA[i] = arrB[i];
//		arrB[i] = c;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("arrA[%d]=%d  ", i, arrA[i]);
//	}printf("\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("arrB[%d]=%d  ", i, arrB[i]);
//	}
//	return 0;
//}

//#include  <stdio.h>
//int main()
//{
//	int arr[] = { 1, 2, 3 };
//	int i = 0;
//	int max = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//	}printf("%d", max);
//	return 0;
//}





//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	int i = 0;
//	scanf("%d", &num);
//	for (i = 31; i > 0; i -= 2)
//	{
//		printf("%d", ((num >> i) & 1));
//	}printf("\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", (num >> i) & 1);
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < c)
//	{
//		int n = a;
//		a = c;
//		c = n;
//	}
//	if (a < b)
//	{
//		int m = a;
//		a = b;
//		b = m;
//	}
//	if (b < c)
//	{
//		int i = b;
//		b = c;
//		c = i;
//	}
//	printf("a=%d b=%d c=%d", a, b, c);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num1;
//	int num2;
//	scanf("%d%d", &num1, &num2);
//	while (num1%num2 != 0)
//	{
//		int tmp = num1%num2;
//		num1 = num2;
//		num2 = tmp;
//	}
//	printf("%d", num2);
//	return 0;
//}    //最大公约 数的求法********






//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int k = (a = 10, b = a + 2, a  +b);
//	printf("%d\n",k);
//	return 0;                                        //逗号表达式，从左向右依次计算，取最后一个表达式的结果赋值给变量。






//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	char arr1[] = "welcome to bit !!!";
//	char arr2[] = "******************";
//	int len = strlen(arr1);
//	int left = 0;
//	int right = len-1;
//	printf("%s\n", arr2);
//	while (left <= right)
//
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//		Sleep(1000);
//	}
//	return 0;
//}





//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[5] = { 0 };
//	int i = 0;
//	printf("请输入您的密码：");
//	scanf("%d%d%d%d%d%d", &arr2);
//	for (i = 0; i <= 4; i++)
//	{
//		if (arr2[i] == arr1[i])
//		{
//			printf("您的密码正确！");
//		}
//		else
//		{
//			printf("您的密码输入错误!①");
//			if (arr2[i] == arr1[i])
//			{
//				printf("密码输入正确")
//			}
//		}
//	}
//
//	return 0;
//}









//问题没有解决，密码输入正确显示密码输入错误！！！！！！！！！！！！！！！！
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char input[7];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入您的密码（输错三次系统自动退出）");
//		scanf("%s", &input);
//		if (0 == strcmp ("input", "1,2,3,4,5,6"))
//		{
//			printf("您的密码输入正确！\n");
//			break;
//		}
//
//	}if (i == 3)
//		printf("系统自动退出！！\n");
//	exit(0);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int n= 0;
//	int i = 0;
//	int ret = 1;
//	scanf("%d",&n);
//	for (i = n; i >0; i--)
//	{
//		ret = ret*i;
//		
//	}
//	printf("%d", ret);
//
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//	int ret = 1;
//	int j = 0;
//	int sum = 0;
//	for (i = 0; i <sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		for (j = arr[i]; j > 0; j--)
//		{
//			ret = ret*j;                                 //errerr                       err
//			sum = sum + (ret);
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int ret=1;
//	int sum=0;
//	for (i = 1; i <= 10; i++)
//	{
//		ret = ret*i;
//		sum = sum + ret;
//	}printf("%d", sum);
//	return 0;
//}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int ret;
	int n;
	int m;
	srand((unsigned)time(NULL));
	cxsw:
	ret = rand() % 101;
	printf("请您猜数字\n");
	zlyc:
	scanf("%d", &n);
	while (n != ret)
	{
		if (n > ret)
		{
			printf("你猜的有点大哦！再猜一次\n");
			goto zlyc;
		}
		else if (n < ret)
		{
			printf("你猜的有点小哦！再猜一次\n");
			goto zlyc;
		}

	}
	if (n == ret)
	{
		printf("恭喜你猜对了！\n");
		printf("再玩一次输入1，退出程序输入0\n");
		scanf("%d", &m);
		if (1 == m)
		{
			goto cxsw;
		}
		else{
			exit(0);
		}
	}
   
	return 0;
}