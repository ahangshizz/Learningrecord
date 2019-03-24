//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a = 1234;
//	char  arr[10];
//	int i =0 ;
//	while (a)
//	{
//		arr[i] = (a % 10)+'0';
//		a /= 10;
//		i++; 
//	}
//	while (i)
//	{
//		printf("%c ", arr[i-1]);
//		i--;
//	}
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int num = 123456789;
//	int i = 0;
//	int tmp = num;
//	int j = 0;
//	while (tmp)
//	{
//		tmp/= 10;
//		i++;
//	}
//	while (num)
//	{
//		printf("%d ", j=num / pow(10, i - 1));
//		num -= j*pow(10,i-1);
//		i--;
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	float sum = 0.0;
//	int i = 0;
//	int j = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum +j* (1.0 / i);
//		j = -j;
//	}printf("%f", sum);
//	return 0;
//
//#include  <stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}printf("%d", count);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	char a = 127;
//	char b = 1;
//	char c;
//	c = a + b;
//	printf("%d", c);
//	return 0;
//}
//#include <stdio.h>
// int IS_sushu(int n)
//{
//	int i = 0;
//	for (i = 2; i <sqrt(n); i++)                                       //   优化   给   数字开平方
//	{
//		if (n%i == 0)
//		{
//			break;
//		}
//	}if (i == n)
//	{
//		return 1;
//	}
//	else{
//		return 0;
//	}
//}
//int main()
//{
//	int a = 13;
//	int ret;
//	ret=IS_sushu(a);
//	printf("%d", ret);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a[] = { 9, 8, 7, 5, 2, 3 };
//	int i = 0;
//	int j = 0;
//	int len = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < len - 1; i++)
//	{
//		for (j = 0; j < len - 1 - i; j++)
//		{
//			if (a[j]>a[j + 1])
//			{
//				int tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//
//			}
//		}
//	}for (i = 0; i < len; i++)
//	{
//		printf("%d", a[i]);
//	}
//	return 0;
//}
//#include <stdio.h>
//void swp(int *pa, int *pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 20;
//	int *p1 = &a;
//	int *p2 = &b;
//	//int tmp = 0;
//	//tmp = a;
//	//a = b;
//	//b = tmp;
//	swp(p1, p2);
//	printf("a=%d b=%d", a, b);
//	return 0;
//}
//#include <stdio.h>
//void  add(int *pn)
//{
//	*pn=*pn+1;
//
//}
//int main()
//{
//	int i = 0;
//	int a = 10;
//	int *p1 = &a;
//	add(p1);
//	add(p1);
//	add(p1);
//	add(p1);
//	add(p1);
//	printf("%d", a);
//	return 0;
//}



//#include <stdio.h>
//static fun(int a)             // static   修饰函数，该函数只可以在本源文件内进行使用。
//{
//	a++;
//}
//static int b = 0;           //  static      修饰全局变量，该变量在内存结束时不会把变量的值进行销毁，存储在静态存储区。  只初始化一次
//int main()
//
//{
//	static int c = 3;//static          修饰局部变量            表示局部变量只初始化一次。
//
//	c++;
//	c++;
//	b++;
//	printf("%d\n", c);
//	printf("%d", b);
//	return 0;
//}