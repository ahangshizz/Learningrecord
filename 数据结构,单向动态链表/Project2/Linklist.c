#include "Linklist.h"
//初始化
LinkList* Init_LinkList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->Value =0;
	list->head->Next = NULL;
	list->size = 0;
	return list;
}
//在指定位置插入结点
void Insert_LinkList(LinkList* list, int pos, int Value) {
	if (list == NULL) {
		return;
	}
	if (pos<0 || pos>list->size) {
		pos = list->size;
	}
	//创建新结点
	LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
	NewNode->Value = Value;
	NewNode->Next = NULL;
	//找结点
	//辅助指针变量
	LinkNode* Pcur = list->head;
	for (int i = 0; i < pos; ++i) {
		Pcur = Pcur->Next;
	}
	//插入结点
	NewNode->Next = Pcur->Next;
	Pcur->Next = NewNode;
	++list->size;
}
//删除指定位置的结点
void Remove_LinkList(LinkList* list, int pos) {
	if (list == NULL) {
		return;
	}
	if (pos < 0 || pos >= list->size) {
		printf("您输入的位置不合法\n");
	}
	//创建辅助指针,需要两个辅助指针
	LinkNode* Pcur=list->head;
	LinkNode* Ppre = Pcur;//用来保存上一个结点的位置
	for (int i = 0; i < pos; ++i) {
		Ppre = Pcur;
		Pcur = Pcur->Next;
	}
	Ppre->Next = Pcur->Next;
	free(Pcur);
	--list->size;
}
//获得链表的长度
void Size_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}
	printf("这个链表现在有%d个结点", list->size - 1);
}
//查找链表位置
void Find_LinkList(LinkList* list, int Value) {
	if (list == NULL) {
		return;
	}
	LinkNode* Pcur = list->head;
	Pcur = Pcur->Next;
	for (int i = 0; i < list->size; ++i) {
		if (Pcur->Value == Value) {
			printf("这个值在第%d个结点上\n", i);
			break;
		}
		Pcur = Pcur->Next;
	}
}
//打印链表
void Printf_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}
	LinkNode* Pcur = list->head;
	for (int i = 0; i < list->size; ++i) {
		Pcur = Pcur->Next;
		printf("%d--->", Pcur->Value);
	}
	printf("NULL\n");
}
//返回第一个结点位置
void* Frist_LinkList(LinkList* list) {
	return list->head->Next;
}
//释放链表内存
void Free_LinkList(LinkList* list) {
	if (list == NULL) {
		return;
	}

	//辅助指针
	LinkNode* Pcur = list->head;
	while (Pcur != NULL) {
		LinkNode* Ppre = Pcur->Next;
		free(Pcur);
		Pcur = Ppre;
	}
	free(list);
}