//#include <stdio.h>
//int main()
//{
//	int len = 0;
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	scanf("%d", &len);
//	for (i = 0; i < len; i++)
//	{
//		for (j = 0; j < len - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		for (n = 0; n < 2 * i + 1; n++)
//		{
//				printf("*");
//		}
//                  printf("\n");
//	}
//	for (i = len-1; i>0; i--)
//	{
//		for (j = 0; j < len - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2*i-1; j++)
//		{
//			printf("*");
//		}printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num = 0;
//	for (num = 100; num <=999 ; num++)
//	{
//		int sum = 0;
//		int skt = num;
//		while (skt)
//		{
//			int tmp = skt % 10;
//			sum = sum + tmp*tmp*tmp;
//			skt /= 10;
//		}		
//		if (sum == num)
//		{
//			printf("%d \n", num);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 0;
//	int sum = 0;
//	scanf("%d%d", &m, &n);
//	int next = n;
//	for (i = 0; i < m; i++)
//	{
//		int tmp = n;
//		sum = sum + tmp;
//		n = n * 10 + next;
//	}
//	printf("%d", sum);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int ch = 0;
//	int count=0;
//	while ((ch = getchar()) != EOF)
//	{
//		if ((ch == '}') && (count ==0))
//		{
//			printf("no matched\n");
//			return 0;
//		}
//		else if (ch == '{')
//		{
//			count++;
//		}
//		else if (ch == '}')
//		{
//			count--;
//		}
//		
//	}
//	if (count == 0)
//	{
//		printf("matched\n");
//	}
//	else
//	{
//		printf("no matched\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10];
//	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int *pa = arr;
//	//printf("%p\n", arr[0]);
//	/*printf("%p\n", *pa);
//	//printf("%p\n", *(pa + 1));*/
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]);i++)
//	{
//		*(pa + i) = 10 - i;
//
//		printf("%d ", *(pa + i));
//	}
//	return 0;
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char *p = "abcdef";
//	char arr1[] = "abcdef";
//	char arr2[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(p));          //4              //指针变量的大小只有四个字节
//	printf("%d\n", sizeof(arr1));     //7
//	printf("%d\n", sizeof(arr2));  //6
//	printf("%d\n", strlen (p)); //6
//	printf("%d\n", strlen(arr1));//6
//	printf("%d\n", strlen(arr2));//22              //strlen    和   sizeof的区别在于    strlen遇见\0停止统计。
//	strchr(p, 'd');
//	if (true)
//	{
//
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int arr[3][4];
//	int i = 0;
//	int *pa = &arr[0][0];
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0][0]); i++)
//	{
//		*(pa + i) = i + 1;
//		printf("%d ", *(pa + i));
//	}
//	return 0;
//}
//#include <stdio.h>
//#define link 50
//#define max 20
//int main()
//{
//	char arr[link][max];
//	int i = 0;
//	for ( i = 0; i < 50; i++)
//	{
//		gets(&arr[i][0]);
//		if (arr[i][0] == '\0')
//			break;
//	}
//	for (i = 0; arr[i][0]; i++)
//	{
//		puts(arr[i]);
//	}
//	return 0;
//}