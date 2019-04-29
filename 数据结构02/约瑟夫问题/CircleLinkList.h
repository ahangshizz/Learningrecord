#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//用企业链表的方式,实现循环链表
//链表的结点
typedef struct CircleLinkNode {
	struct CircleLinkNode* next;
}CircleLinkNode;

typedef struct CircleLinkList {
	//使用指针的话需要给head分配内存,直接写实体给  链表分配内存时,head会被分配内存
	CircleLinkNode head;
	int size;
}CircleLinkList;

//编写循环链表的API操作
//回调函数,由于不知道,用户使用的类型,使用回调函数,让用户进行操作
//熟悉一下回调函数的使用,具体应用
//比较函数的回调
typedef int(*CompareNode)(CircleLinkNode*, CircleLinkNode*);
//打印函数的回调函数
typedef void(*PrintNode)(CircleLinkNode*);
//初始化函数
CircleLinkList* Init_CircleLinkList();
//插入结点
void Insert_CircleLinkList(CircleLinkList* list,int pos,CircleLinkNode* data);
//获得第一个结点
CircleLinkNode* Frist_CircleLinkList(CircleLinkList* list);
//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* list, int pos);
//根据值删除结点
void RemoveByValue_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, CompareNode compare);
//获得链表的长度
void Size_CircleLinkList(CircleLinkList* list);
//查找
void Find_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, CompareNode compare);
//打印结点
void Print_CircleLinkList(CircleLinkList* list, PrintNode Print);
//判断是否为空
void IsNULL_CircleLinkList(CircleLinkList* list);
//释放内存
void Free_CircleLinkList(CircleLinkList* list);