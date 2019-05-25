#include <iostream>
using namespace std;



void Swap(int* arr,int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void AdJust(int* arr, int parent, int len) {
	//孩子的标号等于父亲标号的二倍加一
	int child = 2 * parent + 1;
	while (child<len) {
		//左孩子和右孩子进行比较
		if (child + 1 < len&&arr[child + 1] > arr[child]) {
			//如果右孩子大,则孩子标号到右孩子身上
			child = child + 1;
		}
		//如果孩子比父亲大
		if (arr[child] > arr[parent]) {
			//交换父子身份
			Swap(arr,child,parent);
			//因为交换身份打乱后面的排序,需要对后面重新排序,
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
		
	}

}
void Print(int arr[],int  len) {
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << "   ";
	}
	cout << endl;
}
void HeapSort(int* arr, int len) {
	//堆的最后一个非叶子结点算法
	//因为len是元素个数并非,编号,所以需要多减一个1
	int root = ((len-1-1)>>1);
	//从最后一个非叶子结点向前一直排序
	//把堆排成一个大堆
	for (root; root >= 0; --root) {
		AdJust(arr, root, len);
	}
	//成为大堆以后需要进行排序,把堆顶元素和最后一个结点进行交换,然后重复调整堆的位置
	//
	for (int i = len - 1; i > 0; --i) {
		Swap(arr, i, 0);
		AdJust(arr, 0, i);
	}
	return;
}

int main() {

	int array[] = { 4,2,8,5,0,9,3,1 };
	int len = sizeof(array) / sizeof(array[0]);
	Print(array, len);
	HeapSort(array, len);
	Print(array, len);
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}



//熟能生巧
#if 0
void Print(int* arr,int  len) {
	for (int i = 0; i < len; ++i) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void Swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void AdJust(int arr[], int parent, int len) {
	int child = 2 * parent + 1;
	while (child < len) {
		if (child + 1 < len&&arr[child + 1] > arr[child]) {
			child = child + 1;
		}
		if (arr[parent] < arr[child]) {
			Swap(arr, parent, child);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			return;
		}
	}
	return;
}
void HeapSort(int arr[], int len) {
	//构成堆
	int root = ((len - 1 - 1) >> 1);
	for (; root >= 0; --root) {
		AdJust(arr, root, len);
	}
	for (int i = len - 1; i > 0; --i) {
		Swap(arr, i, 0);
		AdJust(arr, 0, i);
	}
}
int main() {
	int arr[] = { 4,6,3,8,1,0,2,5,9,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Print(arr, len);
	HeapSort(arr, len);
	Print(arr, len);
	system("pause");
	return 0;
}
#endif