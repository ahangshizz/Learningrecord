#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SORT(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		int min = i;
		for (int j = i + 1; j < len; ++j) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			Swap(&arr[min], &arr[i]);
		}
	}
}
int main() {
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; ++i) {
		arr[i] = rand() % MAX;
	}
	SORT(arr, MAX);
	for (int i = 0; i < MAX; ++i) {
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}