//#include <stdio.h>
//int main()
//{
//	int	 i = 0;                       //局部变量
//	int count = 0;                    //局部变量
//	int j = 10;                       //局部变量 
//	for (i = 0; i <= 10; i++)
//	{
//		j++;
//		count++;
//		printf("\n%d", j);
//	}printf("\ncount=%d", count);
//	return	0;
//}




//#include <stdio.h>
//int main()
//{
//	int a = 0;//初始化
//	a = 10;//赋值
//
//	return 0;
//}


//
//#include<stdio.h>
//int main()
//{
//	int minture=0;
//	int num = 0;
//	printf("请输入一个分钟" );
//	scanf("%d", &num);
//	printf("%lf hour", num / 60.0);
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//
//{
//	int a = 0;
//	int count = 0;
//	for (a = 1; a <= 100; a++)
//	{
//		if (a % 2 == 1)
//		{
//			count++;
//			printf("%d ", a);
//		}
//	}printf("\ncount=%d", count);
//
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int arr1[] = { 1, 3, 5, 7, 9 };
//	int arr2[] = { 2, 4, 6, 8, 9 };
//	for (i = 0; i <= 4; i++)
//	{
//		for (j = 0; j <= 4; j++)
//		{
//			if (arr1[i] == arr2[j])
//			{
//				printf("\n有");
//			}
//		}
//	}
//	return 0;
//}
//
//
//#include <stdio.h>
//int	main()
//{
//	int i = 0;
//	int j = 0;
//	int arr1[] = { 1, 3, 5, 7, 8 };
//	int arr2[] = { 2, 4, 6, 8, 9 };
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		for (j = 0; j < sizeof(arr2) / sizeof(arr2[0]); j++)
//		{ 
//			if (arr1[i] == arr2[j])
//			printf("yes\n");
//	}
//	}if (i == 4)
//		printf("no\n");
//	return 0;
//}



#include <stdio.h>
int main()
{
	printf("%d", sizeof(char));
	return 0;
}