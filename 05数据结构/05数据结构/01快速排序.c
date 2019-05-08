#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 1
void Quick_Sort(int arr[],int start,int end) {
	int i = start;
	int j = end;
	//基准数
	int tmp = arr[i];
	if (i < j) {
		while(i<j) {
			//从右向左取比基准数小的数
			while (i < j&&arr[j]>=tmp) {
				j--;
			}
			if (i < j) {
				arr[i] = arr[j];
				//i++;
			}
			//从左向右取比基准数大的数
			while (i < j&&arr[i] < tmp) {
				i++;
			}
			if (i < j) {
				arr[j] = arr[i];
				//j--;
			}
		}
			arr[i] = tmp;
			//分为左边一般继续执行
			Quick_Sort(arr, start, j - 1);
			//右边一半继续执行
			Quick_Sort(arr, i + 1, end);
	}
	else {
		return;
	}
}
void Print_arr(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[] = { 4,2,12,1,5,6,3,7,8,3 };
	Print_arr(arr, 10);
	Quick_Sort(arr, 0, 9);
	Print_arr(arr, 10);
	system("pause");
	return 0;
}
#endif


#if 0
void Insert_Sort(int arr[], int len) {
	for (int i = 1; i < len; ++i) {
		if (arr[i] < arr[i - 1]) {
			int tmp = arr[i];
			for (int j = i - 1; j >= 0 && tmp < arr[j]; --j) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
		}
	}
}


void Shell_Sort(int arr[], int len) {
	int increasement = len;
	do 
	{
		increasement = increasement / 3 + 1;
		for (int i = 0; i < increasement; ++i) {
			for (int j = i + increasement; j < len; j+=increasement) {
				if (arr[j] < arr[j - increasement]) {
					int tmp = arr[j];
					for (int k = j - increasement; k >= 0 && tmp < arr[k]; k -= increasement) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = tmp;
				}
			}
		}
	} while (increasement>1);
}


void Quick_Sort(int arr[],int start, int end) {
	int i = start;
	int j = end;
	if (i < j) {
		int tmp = arr[i];
		while (i < j) {
			while (i<j&&arr[j]>tmp) {
				--j;
			}
			if (i < j) {
				arr[i] = arr[j];
				i++;
			}
			while (i < j&&arr[i] < tmp) {
				++i;
			}
			if (i < j) {
				arr[j] = arr[i];
				j--;
			}
		}
		arr[i] = tmp;
		Quick_Sort(arr, start, j - 1);
		Quick_Sort(arr, i + i, end);
	}
}
#endif 