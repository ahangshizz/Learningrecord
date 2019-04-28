#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LinkNode {
	struct LinkNode* Next;
	int Value;
}LinkNode;
typedef struct LinkList {
	struct LinkNode* head;
	int size;
}LinkList;
//初始化链表
LinkList* Init_LinkList();
//在指定位置插入结点
void Insert_LinkList(LinkList* list, int pos,int Value);
//删除指定位置的结点
void Remove_LinkList(LinkList* list, int pos);
//获得链表的长度
void Size_LinkList(LinkList* list);
//查找链表位置
void Find_LinkList(LinkList* list, int Value);
//打印链表
void Printf_LinkList(LinkList* list);
//返回第一个结点位置
void* Frist_LinkList(LinkList* list);
//释放链表内存
void Free_LinkList(LinkList* list);