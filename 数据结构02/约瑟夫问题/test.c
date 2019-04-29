#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleLinkList.h"
#define M 8
#define N 3

typedef struct MyNum {
	CircleLinkNode node;
	int val;
}MyNum;
void MyPrint(CircleLinkNode* data) {
	MyNum* p = (MyNum*)data;
	printf("%d ", p->val);
}
int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2) {
	MyNum* p1 = (MyNum*)data1;
	MyNum* p2 = (MyNum*)data2;
	if (p1->val == p2->val) {
		return 0;
	}
}
int main() {
	//创建循环链表
	CircleLinkList* list = Init_CircleLinkList();
	//插入数据
	MyNum num[M];
	for (int i = 0; i < M; ++i) {
		num[i].val = i + 1;
		Insert_CircleLinkList(list,i, (CircleLinkNode*)&num[i]);
	}
	Print_CircleLinkList(list, MyPrint);
	//解决问题
	int count = 1;
	CircleLinkNode* Pcur = list->head.next;
	while (list->size>1) {
		if (count == N) {
			MyNum* tmp = (MyNum*)Pcur;
			printf("%d  ", tmp->val);
			//缓存待删除结点的下一个结点
			CircleLinkNode* Pnext = Pcur->next;
			RemoveByValue_CircleLinkList(list, Pcur, MyCompare);
			Pcur = Pnext;
			if (Pcur == &(list->head)) {
				Pcur = Pcur->next;
			}
			count = 1;
		}
		Pcur = Pcur->next;
		if (Pcur == &(list->head)) {
			Pcur = Pcur->next;
		}
		count++;
	}
	printf("\n");
	if (list->size == 1) {
		MyNum* num = (MyNum*)Pcur;
		printf("%d ", num->val);
	}
	//释放链表内存
	Free_CircleLinkList(list);
	system("pause");
	return 0;
}