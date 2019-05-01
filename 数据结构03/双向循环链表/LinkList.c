#include "LinkList.h"


//初始化链表
LinkList* InitList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->Pre = list->head;
	list->head->Next = list->head;
	list->size = 0;
	return list;
}
//尾插
void ListPushBack(LinkList* list, int x) {
	if (list == NULL) {
		return;
	}
	//创建新结点
	LinkNode* pNew = (LinkNode*)malloc(sizeof(LinkNode));
	pNew->value = x;
	//插入
	//创建辅助指针变量
	LinkNode* pCur = list->head->Pre;
	pNew->Pre = pCur;
	pNew->Next = list->head;
	pCur->Next = pNew;
	list->head->Pre = pNew;
	list->size++;
}
//尾删
void ListPopBack(LinkList* list) {
	if (list == NULL) {
		return;
	}
	//创建辅助指针
	LinkNode* pCur = list->head->Pre;
	LinkNode* pPre = pCur->Pre;
	list->head->Pre = pPre;
	pPre->Next = list->head;
	free(pCur);
	list->size--;
}
//头插
void ListPushFront(LinkList* list, int x) {
	if (list == NULL) {
		return;
	}
	//创建新结点
	LinkNode* pNew = (LinkNode*)malloc(sizeof(LinkNode));
	pNew->value = x;
	//创建辅助指针变量
	LinkNode* pCur = list->head->Next;
	pNew->Next = pCur;
	pNew->Pre = list->head;
	pCur->Pre = pNew;
	list->head->Next = pNew;
	list->size++;
}
//头删
void ListPopFront(LinkList* list) {
	if (list == NULL) {
		return;
	}
	//辅助指针
	LinkNode* pCur = list->head->Next;
	LinkNode* pPre = pCur->Next;
	//删除
	list->head->Next = pPre;
	pPre->Pre = list->head;
	list->size--;
}
//查找函数
LinkNode* ListFind(LinkList* list, int x) {
	if (list == NULL) {
		return NULL;
	}
	if (list->size == 0) {
		return NULL;
	}
	LinkNode* pCur = list->head->Next;
	while (list->size) {
		if (pCur->value == x) {
			return pCur;
		}
		pCur = pCur->Next;
		--list->size;
	}
}
// 在pos的前面进行插入
void ListInsert(LinkList* list,LinkNode* pos, int x) {
	if (pos == NULL) {
		return;
	}
	//创建新结点
	LinkNode* pNew = (LinkNode*)malloc(sizeof(LinkNode));
	pNew->value = x;
	//辅助指针
	LinkNode* pPre = pos->Pre;
	pNew->Next = pos;
	pNew->Pre = pPre;
	pPre->Next = pNew;
	pos->Pre = pNew;
	list->size++;
}
// 删除pos位置的节点
void ListErase(LinkList* list,LinkNode* pos) {
	if (list == NULL) {
		return;
	}
	if (pos == NULL) {
		return;
	}
	//创建辅助指针
	LinkNode* pPre = pos->Pre;
	LinkNode* pNext = pos->Next;
	pPre->Next = pNext;
	pNext->Pre = pPre;
	free(pos);
	list->size--;
}
//销毁链表
void ListRemove(LinkList* list) {
	if (list == NULL) {
		return;
	}
	free(list);
}
//打印链表
void ListPrint(LinkList* list) {
	if (list == NULL) {
		return;
	}
	LinkNode* pCur = list->head->Next;
	while (pCur!= list->head) {
		printf("%d-->", pCur->value);
		pCur = pCur->Next;
	}
}