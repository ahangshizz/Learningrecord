#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10

//插入排序
void InsertSort(int arr[], int len) {
	int j;
	for (int i = 1; i < len; ++i) {
		if (arr[i] < arr[i - 1]) {
			int tmp = arr[i];//保存以防丢失数据
			for (j = i - 1; j >= 0 && tmp < arr[j]; --j) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
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
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; ++i) {
		arr[i] = rand() % MAX;
	}
	Print_Arr(arr, MAX);
	InsertSort(arr, MAX);
	Print_Arr(arr, MAX);
	system("pause");
	return 0;
}