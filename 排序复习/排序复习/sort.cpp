#include <iostream>
using namespace std;

//¿ìËÙÅÅĞò
void Quick_Sort(int* arr, int begin, int end) {
	if (begin < end) {
		int i = begin, j = end;
		int tmp = arr[i];
		while (i < j) {
			while (i<j&&arr[j]>tmp)
				--j;
			if (i < j) {
				arr[i] = arr[j];
				++i;
			}
			while (i < j&&arr[i] < tmp)
				++i;
			if (i < j) {
				arr[j] = arr[i];
				--j;
			}
		}
		arr[i] = tmp;
		Quick_Sort(arr, begin, j-1);
		Quick_Sort(arr, i+1, end);
	}
}

//Ï£¶ûÅÅĞò
void Shell_Sort(int*arr, int len) {
	int gap = len;
	int j, k;
	do 
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; ++i) {
			for (int j = i + gap; j < len; j += gap) {
				int tmp = arr[j];
				for (k = j - gap; k >= 0 && arr[k] > tmp; k -= gap)
					arr[k + gap] = arr[k];
				arr[k + gap] = tmp;
			}
		}
	} while (gap>1);
}
//¹é²¢ÅÅĞò

void MergeArr(int* arr, int begin, int mid, int end, int* tmp) {
	int i = begin, m = mid + 1;
	int j = mid, n = end;
	int k = 0;
	while (i <= j && m <= n) {
		if (arr[i] < arr[m])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[m++];
	}
	while (i <= j)
		tmp[k++] = arr[i++];
	while (m <= n)
		tmp[k++] = arr[m++];
	for (i = 0; i < k; ++i)
		arr[begin + i] = tmp[i];
}
void Merge_Sort(int* arr, int begin, int end, int* tmp) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		Merge_Sort(arr, begin, mid, tmp);
		Merge_Sort(arr, mid + 1, end, tmp);
		MergeArr(arr, begin, mid, end, tmp);
	}
}

//¶ÑÅÅĞò
void AdJustDown(int*arr, int root,int len) {
	int child = root * 2 + 1;
	while (child < len) {
		if (arr[child + 1] > arr[child])
			child = child + 1;
		if (arr[root] < arr[child])
			swap(arr[child], arr[root]);
		root = child;
		child = root * 2 + 1;
	}
}
void Heap_Sort(int*arr, int len) {
	int root = len / 2;
	for (; root >= 0; --root)
		AdJustDown(arr, root, len);
	for (int i = len; i > 0; --i) {
		swap(arr[0], arr[i]);
		AdJustDown(arr, 0, i-1);
	}
}
int main() { 
	int arr[] = { 2,1,7,10,6,3,9,8,5,4 };
	int tmp[10] = { 0 };
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	cout << endl;
	//Quick_Sort(arr, 0, 9);
	Shell_Sort(arr, 10);
	//Merge_Sort(arr, 0, 9, tmp);
	//Heap_Sort(arr, 9);
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}