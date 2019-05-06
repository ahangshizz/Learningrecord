#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>
#define MAX 50000
long getsystemtime() {
	//系统函数
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}
void My_Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(int arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				My_Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void Print_Arr(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	srand((unsigned int)time(NULL));
	int arr[MAX];
	for (int i = 0; i < MAX; ++i) {
		arr[i] = rand() % MAX;
	}
	//printf("排序前\n");
	//Print_Arr(arr, MAX);
	//获取系统时间,查看冒泡排序的效率
	long start_time = getsystemtime();
	BubbleSort(arr, MAX);
	long end_time = getsystemtime();
	printf("冒泡排序%d个元素所需时间是%d", MAX, end_time - start_time);
	//printf("排序后\n");
	//Print_Arr(arr, MAX);
	system("pause");
	return 0;
}