#include "Dam_array.h"

Damarray* Init_array() {
	//申请内存,先给结构体申请
	Damarray* myarray = (Damarray*)malloc(sizeof(Damarray));
	myarray->size = 0;
	myarray->capacity = 20;
	//给最大容量开辟内存
	myarray->p_array = (int*)malloc(sizeof(int)*myarray->capacity);
	return myarray;
}
//插入元素
void Pushback_array(Damarray* arr, int value) {
	if (arr == NULL) {
		return;
	}
	//判断容量是否已满
	if (arr->size == arr->capacity) {
		//四步走战略
		//第一步创建一个更大的新内存,新的内存空间是旧内存空间的两倍
		int* newspace = (int*)malloc(sizeof(int)*arr->capacity * 2);
		//第二步把旧内存的数据,全部拷贝给新内存空间
		memcpy(newspace, arr->p_array, arr->capacity * sizeof(int));
		//第三步释放旧内存
		free(arr->p_array);
		//第四步更新容量
		arr->capacity = 2 * arr->capacity;
		arr->p_array = newspace;
	}
	//插入元素
	arr->p_array[arr->size] = value;
	++arr->size;
}
//根据位置删除
void RemoveBypos_array(Damarray* arr, int pos) {
	if (arr == NULL) {
		return;
	}
	if (pos<0 || pos>=arr->size) {
		printf("你输入的位置是不合法位置,请重新输入\n");
		return;
	}
	//删除元素
	arr->p_array[pos] = arr->p_array[arr->size-1];
	--arr->size;
}
//根据值删除
void RemoveByvalue_array(Damarray* arr, int value) {
	if (arr == NULL) {
		return;
	}
	//找到值得位置
	int pos = 0;
	for (int i = 0; i < arr->size; ++i) {
		if (arr->p_array[i] == value) {
			pos = i;
			break;
		}
	}
	RemoveBypos_array(arr, pos);
}
//查找
void Find_array(Damarray* arr, int value) {
	if (arr == NULL) {
		return;
	}
	int i;
	for (i = 0; i < arr->size; ++i) {
		if (arr->p_array[i] == value) {
			printf("找到了!!\n");
			printf("%d是第%d个元素\n", value, i+1);
			break;
		}
	}
	if (arr->size == i) {
		printf("没有找到要找的元素\n");
	}
}
//打印数组
void Printf_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	for (int i = 0; i < arr->size; ++i) {
		printf("%d ", arr->p_array[i]);
		printf("\n");
	}
}
//释放动态数组的内存
void FreeSpace_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	if (arr->p_array != NULL) {
		free(arr->p_array);
		arr->p_array = NULL;
	}
	free(arr);
	arr = NULL;
}
//清空数组
void Clear_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	//根据size插入的值,把size置为0,自然就清空数组
	arr->size = 0;
}
//获得动态数组的容量
void Capacity_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	printf("当前动态数组的容量是%d \n", arr->capacity);
}
//获得动态数组当前元素个数
void Size_array(Damarray* arr) {
	if (arr == NULL) {
		return;
	}
	printf("当前动态数组的有效元素个数是%d个 \n", arr->size);
}
//获取某个位置的当前元素
void At_array(Damarray* arr, int pos) {
	if (arr == NULL) {
		return;
	}
	printf("%p \n", arr->p_array[pos]);
}