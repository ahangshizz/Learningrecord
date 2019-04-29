#include "CircleLinkList.h"




//编写循环链表的API操作
//回调函数,由于不知道,用户使用的类型,使用回调函数,让用户进行操作
//熟悉一下回调函数的使用,具体应用
//比较函数的回调
typedef int(*CompareNode)(CircleLinkNode*, CircleLinkNode*);
//打印函数的回调函数
typedef void(*PrintNode)(CircleLinkNode*);
//初始化函数
CircleLinkList* Init_CircleLinkList() {
	CircleLinkList* list = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	list->head.next = &(list->head);
	list->size = 0;
	return list;
}
//插入结点
void Insert_CircleLinkList(CircleLinkList* list, int pos, CircleLinkNode* data) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	if (pos < 0 || pos > list->size) {
		pos = list->size;
	}
	//根据位置查找结点,查找前一个结点
	//辅助指针变量
	CircleLinkNode* Pcur = &(list->head);
	for (int i = 0; i < pos; ++i) {
		Pcur = Pcur->next;
	}
	//新数据插入链表
	data->next = Pcur->next;
	Pcur->next = data;
	list->size++;
}
//获得第一个结点
CircleLinkNode* Frist_CircleLinkList(CircleLinkList* list) {
	return list->head.next;
}
//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* list, int pos) {
	if (list == NULL) {
		return;
	}
	if (pos < 0 || pos >= list->size) {
		return;
	}
	//根据pos删除元素
	CircleLinkNode* Pcur = list->head.next;
	CircleLinkNode* Ppre = Pcur;
	for (int i = 0; i < pos; ++i) {
		Ppre = Pcur;
		Pcur = Pcur->next;
	}
	Ppre->next = Pcur->next;
	list->size--;
}
//根据值删除结点
void RemoveByValue_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, CompareNode compare) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	CircleLinkNode* Pcur = list->head.next;
	for (int i = 0; i < list->size; ++i) {
		if (compare(Pcur, data) == 0) {
			RemoveByPos_CircleLinkList(list, i);
			break;
		}
		Pcur = Pcur->next;
	}
}
//获得链表的长度
void Size_CircleLinkList(CircleLinkList* list) {
	printf("当前链表的长度是%d\n", list->size);
}
//查找
void Find_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, CompareNode compare) {
	if (list == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	CircleLinkNode* Pcur = list->head.next;
	int i = 0;
	for (i = 0; i < list->size; ++i) {
		if (compare(data, Pcur) == 0) {
			printf("找到了\n");
			printf("所查找的位置是链表的第%d位\n", i);
			break;
		}
	}
	if (i == list->size) {
		printf("你所要查找的结点没有找到\n");
	}
}
//打印结点
void Print_CircleLinkList(CircleLinkList* list, PrintNode Print) {
	if (list == NULL) {
		return;
	}
	CircleLinkNode* Pcur = list->head.next;
	for (int i = 0; i < list->size; ++i) {
		if (Pcur == &(list->head)) {
			Pcur = Pcur->next;
		}
		Print(Pcur);
		Pcur = Pcur->next;
	}
	printf("-------------------------------\n");
}
//判断是否为空
void IsNULL_CircleLinkList(CircleLinkList* list) {
	if (list->size == 0) {
		printf("当前链表不是空链表\n");
	}
}
//释放内存
void Free_CircleLinkList(CircleLinkList* list) {
	if (list == NULL) {
		return;
	}
	free(list);
}