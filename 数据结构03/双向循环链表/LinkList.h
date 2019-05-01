#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//创建链表结点
typedef struct LinkNode {
	struct LinkNode* Pre;
	struct LinkNode* Next;
	int value;
}LinkNode;

//创建链表
typedef struct LinkList {
	LinkNode* head;
	int size;
}LinkList;

//初始化链表
LinkList* InitList();
//尾插
void ListPushBack(LinkList* list,int x);
//尾删
void ListPopBack(LinkList* list);
//头插
void ListPushFront(LinkList* list, int x);
//头删
void ListPopFront(LinkList* list);
//查找函数
LinkNode* ListFind(LinkList* list,int x);
// 在pos的前面进行插入
void ListInsert(LinkList* list,LinkNode* pos, int x);
// 删除pos位置的节点
void ListErase(LinkList* list,LinkNode* pos);
//销毁链表
void ListRemove(LinkList* list);
//打印链表
void ListPrint(LinkList* list);