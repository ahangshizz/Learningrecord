//#include <stdio.h>
//int main()
//{
//	int a = 2;
//	int b = 4;
//	int c;
//	c = a;
//	a = b;
//	b = c;
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}
//
//#include <stdio.h>
//int  main()
//{
//	int a = 0;
//	int b = 2;
//	a = a + b;
//	b = a - b;
//	printf("a=%d\nb=%d ", a, b);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1, 3, 4, 5, 6, 7, 8, 9, 10, 12 };
//	int i = 0;
//	int max=arr[0];
//	for (i = 0; i <= sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//
//	}
//	printf("max=%d\n", max);
//	return 0;
//}

// 3          5            8
//	 n = n&(n-1)
//00000000  00000000  00000000  00000011
//00000000  00000000  00000000  00000010
//                                          2
//00000000  00000000  00000000  00000101
//00000000  00000000  00000000  00000100
//                                          4
//00000000  00000000  00000000  00001000
//00000000  00000000  00000000  00000111    8
//
//00000000  00000000  00000000  00001001
//00000000  00000000  00000000  00001000    8




#include <stdio.h>
int count_one_jk(int n){
	int count = 0;
	while (n)
	{
		count++;
		n = n&(n - 1);
	}return count;
}
int main()
{
	int num = 0;
	int ret = 0;
	scanf("%d", &num);
	ret = count_one_jk(num);
	printf("%d", ret);
	return 0;
}                                                      //经典算法题



//#include <stdio.h>
//int count = 0;
//int count_two_yes(int n)
//{
//	
//	while (n)
//	{
//		n % 2 == 0;
//			count++;
//	}return count;
//
//}
//int main()
//{
//	int num = 0;
//	int ret = 0;
//	scanf("%d", &num);
//	ret = count_two_yes(num);
//	if (ret == 1)
//	{
//		printf("是");
//	}
//	else{
//		printf("否");
//	}
//	
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	float a ;
//	float b ;
//	float c ;
//	scanf("%f %f %f", &a, &b, &c);
//	if (a==NULL)
//	{
//		printf(" ")
//	}
//	return 0;
//}





//#include <stdio.h>
//#include <math.h>
//#define ESP 0.00000001
//int main()
//{
//	float a, b, c;
//	scanf("%f%f%f", &a, &b, &c);
//	if ((a > -ESP) &&( a < ESP))
//	{
//		printf("不是一元二次方程");
//	}
//	else
//	{
//		float d = b*b - 4 * a*c;
//
//		if ((d>-ESP) && (d < ESP))
//		{
//			printf("有两个相等的实数根:%f", (-b) / (2 * a));
//		}
//		else if (d > 0.0)
//		{
//			printf("有两个不相等的实数根：%f %f", ((-b) + sqrt(d)) / (2 * a),
//				((-b) - sqrt(d)) / (2 * a));
//		}
//		else
//		{
//			printf("有两个共轭");
//		}
//	}
//	return 0;
//}                                                                                 //在一个if else语句中也可以有无数个else  if  但只能有一个   else   ***
//
//#include <stdio.h>
//int main()
//{
//	int i;
//	for (i = 1; i <= 100; i++)
//	{
//			if (4 == i)
//			{
//				continue;
//			}
//		}
//		printf("i=%d\n", i);
//
//	return 0;
//}

