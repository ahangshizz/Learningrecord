//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int i = 0;
//	for (i = 0; i <= 9; i++)
//	{
//		printf("arr1[%d]=%d\n",i, arr1[i]);
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr1[10];
//	int i = 0;
//	for (i = 0; i <= 9; i++)
//	{
//		printf("arr1[%d]=%d\n", i, arr1[i]);
//	}
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 1;
//	int c = 3;
//	int max = 0;
//	max = (a > b ? a : b) > c ? (a > b ? a : b) : c;
//	printf("max=%d", max);
//	return 0;
//}


//#include <stdio.h>
//#include <windows.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	int arr1[6];
//	int i = 0;
//	int len = 5;
//	int left = 0;
//	int right = 4;
//	while (left <= right)
//	{
//		int tmp = arr[left];
//		arr1[left] = arr[right];
//		arr1[right] = tmp;
//		printf("%d", arr1);
//		left++;
//		right--;
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int i = 0;
//	int n = sizeof(arr1)/sizeof(arr1[0]);
//	int j = n - 1;
//	while (i <=j)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr1[j];
//		arr1[j] = tmp;
//		i++;
//		j--;
//	}
//	for (i = 0; i <n; i++)
//	{
//		printf("%d", arr1[i]);
//	}
//	return 0;
//}



//                              Ã°ÅÝÅÅÐò*******
#include <stdio.h>
int main()
{
	int arr[] = { -1, -2, -3, -4, 1, 2, 4, 3, 5 };
	int i = 0;
	int j = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j]>arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}

//#include <stdio.h>
//int main()
//{
//	char a[10] = { 'a', 'b', 'c' };
//	printf("%s",a);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	int i = 0;
//	srand((unsigned int)time (NULL));
//	int num = 0;
//	for (i = 0; i < 100; i++)
//	{
//		num = rand();
//		printf("num=%d\n", num);
//	}
//	return 0;
//}