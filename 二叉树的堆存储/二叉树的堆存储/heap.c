
#include "heap.h"


//交换函数
void Swap(HPDataType* Left, HPDataType* Right) {
	HPDataType temp = *Left;
	*Left = *Right;
	*Right = temp;
}
//向下排序
void adjustdown(HPDataType* array, int size, int parent) {
	int child = 2*parent + 1;
	while (child < size) {
		if (array[child] > array[child + 1]&&child+1<size) {
			child = child + 1;
		}
		if (array[child] < array[parent]) {
			Swap(&array[parent], &array[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			return;
		}
	}
	return;
}
//向上排序
void adjustup(HPDataType* array, int size, int child) {
	int parent = ((child - 1) >> 1);
	while (parent >= 0) {
		if (array[child] < array[parent]) {
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else {
			return;
		}
	}
	return;
}
//扩容函数
void CheckCapacity(Heap* hp) {
	assert(hp);
	if (hp->_size == hp->_capacity) {
		int newcapacity = hp->_capacity * 2;
		HPDataType* newarray = (HPDataType*)malloc(sizeof(HPDataType)*newcapacity);
		if (newarray == NULL) {
			assert(newarray);
			return;
		}
		for (int i = 0; i < hp->_size; ++i) {
			newarray[i] = hp->_array[i];
		}
		free(hp->_array);
		hp->_array = newarray;
		hp->_capacity = newcapacity;
	}
}
// 用数组初始化堆
void InitHeap(Heap* hp, HPDataType* array, int size) {
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (hp->_array == NULL) {
		assert(hp->_array);
		return;
	}
	hp->_capacity = size;
	for (int i = 0; i < size; ++i) {
		hp->_array[i] = array[i];
	}
	hp->_size = size;


	//对这个数组进行调整,使其成为一个堆
	int root = (size - 2) >> 1;
	for (; root >= 0; --root) {
		adjustdown(hp->_array, size, root);
	}
}

// 初始化一个空堆
void InitEmptyHeap(Heap* hp, int capacity) {
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*hp->_capacity);
	if (hp->_array == NULL) {
		assert(hp->_array);
		return;
	}
	hp->_size = 0;
	hp->_capacity = capacity;
}

// 在堆中插入值为data的元素
void InsertHeap(Heap* hp, HPDataType data) {
	assert(hp);
	CheckCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	adjustup(hp->_array, hp->_size, hp->_size - 1);
}

// 删除堆顶元素
void EraseHeap(Heap* hp) {
	assert(hp);
	Swap(hp->_array[0], hp->_array[hp->_size - 1]);
	hp->_size--;
	adjustdown(hp->_array, hp->_size, 0);
}

// 获取堆中有效元素个数
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}

// 检测堆是否为空堆
int HeapEmpty(Heap* hp) {
	assert(hp);
	return 0 == hp->_size;
}

// 获取堆顶元素
HPDataType HeapTop(Heap* hp) {
	assert(hp);
	return hp->_array[0];
}

// 销毁堆
void DestroyHeap(Heap* hp) {
	if (hp == NULL) {
		return;
	}
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = 0;
	hp->_capacity = 0;
}