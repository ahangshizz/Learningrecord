#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10
void ShellSort(int arr[], int len) {
	int increasement = len;
	int k;
	do 
	{
		increasement = increasement / 3 + 1;
		for (int i = 0; i < increasement; ++i) {
			for (int j = i + increasement; j < len; j += increasement) {
				int tem = arr[j];
				if (arr[j] < arr[j - increasement]) {
					for (k = j - increasement; k >= 0&&tem<arr[k]; k -= increasement) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = tem;
				}
			}
		}
	} while (increasement>1);
}
void Print_ShellSort(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("------------------------------------------\n");
}
int main() {
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; ++i) {
		arr[i] = rand() % MAX;
	}
	Print_ShellSort(arr, MAX);
	ShellSort(arr, MAX);
	Print_ShellSort(arr, MAX);
	system("pause");
	return 0;
} 