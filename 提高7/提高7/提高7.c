//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <windows.h>
//typedef struct teacher {
//	int id;
//	struct teacher *next;
//}teacher;
////创建头节点
//teacher *SListCreat() {
//	teacher* head = NULL;//定义一个头节点，头节点作为一个标志，不存储有效数据
//	head = (teacher*)malloc(sizeof(teacher));
//	head->id = -1;
//	head->next = NULL;
//	teacher* Pcur = head;
//	teacher* Pnew = NULL;
//	int data;
//	while (1) {
//		printf("请输入数据：");
//		scanf("%d", &data);
//		if (data == -1) {//输入-1退出
//			break;
//		}
//		Pnew = (teacher*)malloc(sizeof(teacher));//新节点动态分配空间
//		Pnew->id = data;//给Pnew的成员进行赋值
//		Pnew->next = NULL;
//		//链表建立关系
//		Pcur->next = Pnew;
//		//Pnew的下一个节点指向空
//		Pnew->next = NULL;
//		Pcur = Pnew;
//	}
//	return head;
//}
////链表的遍历
//int SListprint(teacher* head) {
//	if (head == NULL) {
//		return -1;
//	}
//	//取出头节点的next
//	teacher* Pcur = head->next;
//	printf("head->");
//	while (Pcur != NULL) {
//		printf("%d->", Pcur->id);
//		Pcur = Pcur->next;//把当前节点向后移动
//	}
//	printf("->NULL");
//	return 0;
//}
//int main() {
//	teacher* head = NULL;
//	head = SListCreat();//创建头节点
//	SListprint(head);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct node {
	int id;
	struct node* next;
}node;

node* SListcreat() {
	node*head = NULL;
	head = (node*)malloc(sizeof(node));
	if (head == NULL) {
		return -1;
	}
	head->id = -1;
	head->next = NULL;
	int data;
	node* Pnew = NULL;
	node* Pcrt = head;
	while (1) {
		printf("请输入数据");
		scanf("%d", &data);
		if (data == -1) {
			break;
		}
		Pnew = (node*)malloc(sizeof(node));
		Pnew->id = data;
		Pnew->next = NULL;
		Pcrt->next = Pnew;
		Pnew->next = NULL;
		Pcrt = Pnew;
	}
	return head;
}
//链表的遍历
int SListprint(node* head) {
	if (head == NULL) {
		return -1;
	}
	node* Pcrt = head->next;
	printf("head->");
	while (Pcrt != NULL) {
		printf("%d->", Pcrt->id);
		Pcrt = Pcrt->next;
	}
	printf("->NULL");
	return 0;
}
//清空链表
int SListdestory(node* head) {
	int i = 0;
	node* tmp = NULL;
	while (head != NULL) {
		tmp = head->next;
		free(head);
		head = NULL;
		head = tmp;
		i++;
	}
	printf("%d\n",i);
	return 0;
}
int SListnodedel(node* head, int x) {
	node* Ppre = head;
	node* Pcur = head->next;
	int flag = 0;
	while (Pcur != NULL) {
		if (Pcur->id == x) {
			flag = 1;
			break;
		}
		Ppre = Pcur;
		Pcur = Pcur->next;
	}
	if (flag == 1) {
		Ppre->next = Pcur->next;
		free(Pcur);
		Pcur = NULL;
	}
	else {
		return -2;
	}
	return 0;
}
int SListnodeinsert(node* head, int x, int y) {
	node* Ppre = head;
	node* Pcur = head->next;
	while (Pcur!=NULL) {
		if (Pcur->id == x) {//找到了匹配的节点
			break;
		}
		Ppre = Pcur;//两个指针的指向同时向后移动
		Pcur = Pcur->next;
	}
	//两种情况1.找到匹配的节点2.Pcur指向了NULL即没有找到节点
	//给新节点动态分配空间，
	node* Pnew = (node*)malloc(sizeof(node));
	Pnew->id = y;
	Ppre->next = Pnew;
	Pnew->next = Pcur;
	return 0;
}
int main() {
	node* head = NULL;
	head = SListcreat();
	SListprint(head);
	printf("在5前面插入4\n");
	SListnodeinsert(head, 5, 4);
	SListprint(head);
	printf("删除5之后\n");
	SListnodedel(head,5);
	SListprint(head);
	SListdestory(head);
	head = NULL;
	system("pause");
	return 0;
}