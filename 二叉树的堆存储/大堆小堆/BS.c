
#include "BS.h"

int Less(HPDataType Left, HPDataType Right) {
	return Left < Right;
}
int Greater(HPDataType Left, HPDataType Right) {
	return Left > Right;
}
//交换函数
void Swap(HPDataType* Left, HPDataType* Right) {
	//使用指针进行操作,******传值传址
	HPDataType temp = *Left;
	*Left = *Right;
	*Right = temp;
}
//向下排序
void adjustdown(HPDataType* array, int size, int parent,PCOM compare) {
	//根据堆的性质,对于完全二叉树,若从上至下,从左至右编号,则编号为i的结点,
	//其左孩子编号必为2i,其右孩子编号必为2i+1,其双亲编号必为i/2(根节点除外)
	int child = 2 * parent + 1;
	while (child < size) {
		//判断堆的左右孩子的大小
		if (compare(array[child+1] , array[child]) && child + 1 < size) {

			child = child + 1;
		}
		//用最小的孩子和根节点进行比较,如果小于根节点,交换两个节点
		if (compare(array[child] , array[parent])) {
			Swap(&array[parent], &array[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			return;
		}
	}
}
//向上排序
void adjustup(HPDataType* array, int size, int child,PCOM compare) {
	int parent = ((child - 1) >> 1);
	while (parent >= 0) {
		if (compare(array[child] , array[parent])) {
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else {
			return;
		}
	}
}
//扩容函数
void CheckCapacity(Heap* hp) {
	assert(hp);
	if (hp->_size == hp->_capacity) {
		//默认扩容倍数为2倍,扩容的四步走
		int newcapacity = hp->_capacity * 2;
		//创建新数组
		HPDataType* newarray = (HPDataType*)malloc(sizeof(HPDataType)*newcapacity);
		if (newarray == NULL) {
			assert(newarray);
			return;
		}
		//把旧堆元素,转移到新堆
		for (int i = 0; i < hp->_size; ++i) {
			newarray[i] = hp->_array[i];
		}
		//释放旧堆
		free(hp->_array);
		//指针指向新堆
		hp->_array = newarray;
		//改变堆的容量
		hp->_capacity = newcapacity;
	}
}
// 用数组初始化堆
void InitHeap(Heap* hp, HPDataType* array, int size,PCOM compare) {
	assert(hp);
	//给堆的数组开辟空间
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (hp->_array == NULL) {
		assert(hp->_array);
		return;
	}
	//把数组中的元素,全部转移到堆的数组中
	hp->_capacity = size;
	for (int i = 0; i < size; ++i) {
		hp->_array[i] = array[i];
	}
	hp->_size = size;
	hp->compare = compare;

	//对这个数组进行调整,使其成为一个堆
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root) {
		adjustdown(hp->_array, size, root,hp->compare);
	}
}

// 初始化一个空堆
void InitEmptyHeap(Heap* hp, int capacity,PCOM compare) {
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*hp->_capacity);
	if (hp->_array == NULL) {
		assert(hp->_array);
		return;
	}
	hp->_size = 0;
	hp->_capacity = capacity;
	hp->compare = compare;
}

// 在堆中插入值为data的元素
void InsertHeap(Heap* hp, HPDataType data) {
	assert(hp);
	//判断是否需要扩容
	CheckCapacity(hp);
	//插入元素,默认堆尾插入
	hp->_array[hp->_size] = data;
	hp->_size++;
	//给元素进行位置调整
	adjustup(hp->_array, hp->_size, hp->_size - 1,hp->compare);
}

// 删除堆顶元素
void EraseHeap(Heap* hp) {
	assert(hp);
	//把堆顶元素和堆的最后一个元素交换位置
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	//有效元素减一,即最后一个元素被去除
	hp->_size--;
	adjustdown(hp->_array, hp->_size, 0,hp->compare);
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