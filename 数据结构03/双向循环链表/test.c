#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"
int main() {
	//创建链表
	LinkList* list = InitList();
	//创建数据
	int a, b, c, d, e;
	a = 10;
	b = 20;
	c = 30;
	d = 40;
	e = 50;
	//数据入链表
	ListPushBack(list, a);
	ListPushBack(list, b);
	ListPushBack(list, c);
	ListPushBack(list, d);
	ListPushBack(list, e);
	//打印链表
	ListPrint(list);
	printf("\n");
	//头插
	int i = 100;
	ListPushFront(list, i);
	ListPrint(list);
	printf("\n");
	//头删
	ListPopFront(list);
	ListPrint(list);
	printf("\n");
	//尾删
	ListPopBack(list);
	ListPrint(list);
	//销毁链表
	ListRemove(list);
	system("pause");
	return 0;
}