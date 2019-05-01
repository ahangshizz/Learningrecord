//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };//没有typedef是一个数组变量
//	int b[100] = { 1, 2, 3, 4 };//没有赋值的都为0
//	int i = 0;
//	int n = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < n; i++)
//	{
//		//printf("%d ", a[i]);
//		printf("%d ", *(a + i));              //a[i]==*(a+i)
//	}
//	printf("a:%d,a+1:%d", a, a + 1);
//	printf("&a:%d,&a+1:%d", &a, &a + 1);
//
//	typedef int A[8];//有typedef的数组是一个数组类型
//	A n;//等价于int b[8];
//	int j = 0;
//	for (j = 0; j < 8; j++)
//	{
//		n[j] = j++;
//	}
//	for (j = 0; j < 8; j++)
//	{
//		printf("%d ", n[j]);
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	typedef int A[8];
//	A b;
//	int i = 0;
//	for (i = 0; i < 8; i++)
//	{
//		b[i] = i + 1;
//	}
//	for (i = 0; i < 8; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	return 0;
//}

#include <stdio.h>
#include <windows.h>
int main01()
{
	//指针数组是一个数组，只是数组中的每一个元素都是指针；
	char *a[] = { "aaaaa", "bbbbb", "ccccc" };

	return 0;
}

int main02()
{
	//数组指针他是一个指针，指向一个数组
	//先定义数组类型，根据类型定义指针变量
	//数组指针是指向整个一维数组的，不是指向某一个元素
	int a[10] = { 0 };
	int i = 0;
	typedef int A[10];
	A *p = NULL;//p就是一个数组指针类型变量；
	//p = a;//a代表数组首元素地址
	p = &a;//&a代表数组首地址；指向一行
	for (i = 0; i < 10; i++)
	{
		(*p)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*p)[i]);
	}
	system("pause");
	return 0;
}

int main03()
{
	int a[10] = { 0 };
	int i = 0;
	typedef (*P)[10];
	P p;
	p = &a;
	for (i = 0; i < 10; i++)
	{
		(*p)[i] = i + 1;
	}
	for (i = 0; i < 10; i++)
	{

		printf("%d ", (*p)[i]);
	}
	return 0;
}


int main04()
{
	int a[3][4] = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12}
	};
	int a2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int a3[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%2d ", a3[i][j]);
		}printf("\n");
	}
	printf("a3:%d,a3+1:%d\n", a3, a3 + 1);//二维数组的数组名代表第0行的首地址，（区别于第0行首元素地址，虽然值一样，但步长不相同）；
	printf("&a3:%d,&a3+1:%d\n", &a3, &a3 + 1);
	printf("%d,%d\n", *(a3 + 0), *(a3 + 1));
	printf("%d,%d\n", a3[0], a3[0]+1);//*（a3+i）==a3【i】；
	return 0;
}
//void printA(int*a, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}printf("\n");
//}
//int main04()
//{
//	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	printA((int*)a, sizeof(a) / sizeof(int));
//	return 0;
//}

//int main()
//{
//	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	int(*p)[4];
//	p = a;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		for (j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j++)
//		{
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}



void printarry(int(*a)[4])//数组指针   做形参
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	printarry(a);
	return 0;
}