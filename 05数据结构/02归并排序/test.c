#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10

void mergearray(int arr[], int start, int mid, int end, int temp[]) {
	int i = start, j = mid + 1;
	int m = mid, n = end;
	int k = 0;
	while (i <= m&&j <= n) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= m) {
		temp[k++] = arr[i++];
	}
	while (j <= n) {
		temp[k++] = arr[j++];
	}
	for (i = 0; i < k; ++i) {
		arr[start + i] = temp[i];
	}
}

void mergesort(int arr[], int start, int end,int temp[]) {
	if(start<end) {
		int mid = (start + end) / 2;
		//×ó±ß
		mergesort(arr, start, mid,temp);
		//ÓÒ±ß
		mergesort(arr, mid + 1, end,temp);
		mergearray(arr, start, mid, end, temp);
	}
}
int main() {
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; ++i) {
		arr[i] = rand() % MAX;
	}
	//int* tmp = (int*)malloc(sizeof(int)*MAX);
	int tmp[MAX] = { 0 };
	mergesort(arr, 0, MAX-1, tmp);
	for (int j = 0; j < MAX; ++j) {
		printf("%d ", tmp[j]);
	}
	//free(tmp);
	system("pause");
	return 0;
}

#if 0
//²åÈëÅÅĞò
void Insert_Sort(int arr[], int len) {
	int j;
	for (int i = 1; i < len; ++i) {
		if (arr[i] < arr[i - 1]) {
			int tmp = arr[i];
			for (j = i - 1; j >= 0 && tmp < arr[j]; --j) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
		}
	}
}
//Ã°ÅİÅÅĞò
void Bubble_Sort(int arr[], int len) {
	int i, j;
	for (i = 0; i < len - 1; ++i) {
		for (j = 0; j < len - i - 1; ++j) {
			if (arr[j] < arr[j + 1]) {
				swap();
			}
		}
	}
}
//Ñ¡ÔñÅÅĞò
void Choice_Sort(int arr[], int len) {
	int i, j;
	for (i = 0; i < len; ++i) {
		for (j = i + 1; j < len; ++j) {
			if (arr[i] > arr[j]) {
				swap();
			}
		}
	}
}
//¿ìËÙÅÅĞò
void Quick_Sort(int arr[],int start, int len) {
	int i = start;
	int j = len;
	int mid = (i + j) / 2;
	if (i < j) {
		int tmp = arr[i];
		while (i < j) {
			while (i < j&&arr[j] > tmp) {
				--j;
			}
			if (i < j) {
				arr[i] = arr[j];
				++i;
			}
			while (i < j&&arr[i] < tmp) {
				++i;
			}
			if (i < j) {
				arr[j] = arr[i];
				--j;
			}
		}
		arr[i] = tmp;
		Quick_Sort(arr, start, mid);
		Quick_Sort(arr, mid + 1, len);
	}
}
//Ï£¶ûÅÅĞò
void Shell_Sort(int arr[], int len) {
	int i, j,k;
	int increasement = len;
	do 
	{
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; ++i) {
			for (j = i + increasement; j < len; ++j) {
				if (arr[j] < arr[j - increasement]) {
					int tmp = arr[j];
					for (k = j - increasement; k >= 0 && tmp < arr[k]; --k) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = tmp;
				}
			}
		}   
	} while (increasement>1);
}
#endif