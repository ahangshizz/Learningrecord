#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(int* a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//快速排序
void Quick_Sort(int* arr, int begain, int end) {
	int i = begain;
	int j = end;
	if (i < j) {
		int temp = arr[i];
		while (i < j) {
			while (i<j&&arr[j]>temp) {
				--j;
			}
			if (i < j) {
				arr[i] = arr[j];
				++i;
			}
			while (i < j&&arr[i] < temp) {
				++i;
			}
			if (i < j) {
				arr[j] = arr[i];
				--j;
			}
		}
		arr[i] = temp;
		Quick_Sort(arr, begain, j-1);
		Quick_Sort(arr, i+1, end);
	}
}
//希尔排序
void Shell_Sort(int* arr, int len) {
	int gap = len;
	int j, k;
	do 
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; ++i) {
			for (j = i + gap; j < len; j += gap) {
				int tem = arr[j];
				for (k = j - gap; k>=0&&arr[k]>tem; k -= gap) {
					arr[k + gap] = arr[k];
				}
				arr[k + gap] = tem;
			}
		}
	} while (gap>1);
}
//插入排序
void Insert_Sort(int* arr, int len) {
	int i, j;
	for (i = 1; i < len; ++i) {
		int temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; --j) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}
//冒泡排序
void Bubble_Sort(int* arr, int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
//归并排序
void Merge_Array(int* arr, int begain, int mid, int end, int* temp) {
	int i = begain, j = mid;
	int m = mid + 1, n = end;
	int k = 0;
	//格外注意这里的循环条件
	while (i <= j&&m <= n) {
		if (arr[i] < arr[m]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[m++];
		}
	}
	while (i <= j) {
		temp[k++] = arr[i++];
	}
	while (m <= n) {
		temp[k++] = arr[m++];
	}
	for (int i = 0; i < k; ++i) {
		arr[begain + i] = temp[i];
	}
}
void Merge_Sort(int* arr, int begain, int end, int* temp) {
	if (begain < end) {
		int mid = (end+begain)/2;
		Merge_Sort(arr, begain, mid,temp);
		Merge_Sort(arr, mid + 1, end, temp);
		Merge_Array(arr, begain, mid, end, temp);
	}
}
//打印函数
void Print_Arr(int* arr, int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d  ,", arr[i]);
	}
	printf("\n");
}
//堆排序
void AdJustDown(int* arr, int parent, int len) {
	int child = 2 * parent + 1;
	while (child < len) {
		if (arr[child + 1] > arr[child]) {
			child = child + 1;
		}
		if (arr[child] > arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
	}
}
void Heap_Sort(int arr[], int len) {
	int root = len / 2 - 1;
	for (; root >= 0; --root) {
		AdJustDown(arr, root, len);
	}
	for (int i = len; i > 0; --i) {
		Swap(&arr[0], &arr[i]);
		//注意传参的参数值
		AdJustDown(arr, 0, i-1);
	}
}

//测试代码
int main() {
	int arr[] = { 3,4,2,5,7,1,9,6,8,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int temp[10] = { 0 };
	Print_Arr(arr, len);
	//Quick_Sort(arr, 0, len - 1);
	//Shell_Sort(arr, len);
	//Insert_Sort(arr, len);
	//Bubble_Sort(arr, len);
	//Merge_Sort(arr, 0, len - 1, temp);
	//Heap_Sort(arr, len - 1);
	Print_Arr(arr, len);
	system("pause");
	return 0;
}