#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int HPDataType;
typedef int(*PCOM)(HPDataType, HPDataType);
int Less(HPDataType Left, HPDataType Right);
int Greater(HPDataType Left, HPDataType Right);
typedef struct Heap
{
	//用来存放堆中元素
	HPDataType* _array;
	int _capacity;//堆的容量
	int _size;//堆中有效元素个数
	PCOM compare;
}Heap;
//扩容函数
void CheckCapacity(Heap* hp);
//交换函数
void Swap(HPDataType* Left, HPDataType* Right);
//向下排序
void adjustdown(HPDataType* array, int size, int parent);
//向上排序
void adjustup(HPDataType* array, int size, int child);
// 用数组初始化堆
void InitHeap(Heap* hp, HPDataType* array, int size);

// 初始化一个空堆
void InitEmptyHeap(Heap* hp, int capacity);

// 在堆中插入值为data的元素
void InsertHeap(Heap* hp, HPDataType data);

// 删除堆顶元素
void EraseHeap(Heap* hp);

// 获取堆中有效元素个数
int HeapSize(Heap* hp);

// 检测堆是否为空堆
int HeapEmpty(Heap* hp);

// 获取堆顶元素
HPDataType HeapTop(Heap* hp);

// 销毁堆
void DestroyHeap(Heap* hp);