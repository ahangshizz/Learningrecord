#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"
#define MY_FALSE 0
#define MY_TRUE 1
typedef struct CinaryNode {
	char ch;
	struct CinaryNode* Lchild;
	struct CinaryNode* Rchild;
}CinaryNode;
//创建一个结构体封装结点
typedef struct StackNode {
	LinkNode* node;
	CinaryNode* root;
	int flag;
}StackNode;
StackNode* BuyNode(CinaryNode* root,int flag) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->root = root;
	node->flag = flag;
	return node;
}
//二叉树的非递归遍历
void Print_Tree(CinaryNode* root) {
	//创建栈
	LinkStack* stack = Init_LinkStack();
	//把根节点传入栈中
	Push_LinkStack(stack, (LinkNode*)BuyNode(root, MY_FALSE));
	while (Size_LinkStack(stack) > 0) {
		StackNode* node = (StackNode*)Top_LinkStack(stack);
		Pop_LinkStack(stack);
		if (node->root == NULL) {
			continue;
		}
		if (node->flag == MY_TRUE) {
			printf("%c ", node->root->ch);
		}
		else {
			//当前结点的右结点入栈
			Push_LinkStack(stack, (LinkNode*)BuyNode(node->root->Rchild, MY_FALSE));
			//当前结点的左节点入栈
			Push_LinkStack(stack, (LinkNode*)BuyNode(node->root->Lchild, MY_FALSE));
			//改变当前结点的状态,再入栈
			node->flag = MY_TRUE;
			Push_LinkStack(stack, (LinkNode*)node);
		}
	}
}
void Print_Tree_ByDG(CinaryNode*root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->ch);
	Print_Tree_ByDG(root->Lchild);
	Print_Tree_ByDG(root->Rchild);
}
void TestCinaryNode() {
	//创建数据
	CinaryNode node1 = { 'A',NULL,NULL };
	CinaryNode node2 = { 'B',NULL,NULL };
	CinaryNode node3 = { 'C',NULL,NULL };
	CinaryNode node4 = { 'D',NULL,NULL };
	CinaryNode node5 = { 'E',NULL,NULL };
	CinaryNode node6 = { 'F',NULL,NULL };
	CinaryNode node7 = { 'G',NULL,NULL };
	CinaryNode node8 = { 'H',NULL,NULL };
	CinaryNode node9 = { 'I',NULL,NULL };
	CinaryNode node10 = { 'J',NULL,NULL };
	//建立数据之间的关系
	node1.Lchild = &node2;
	node1.Rchild = &node3;
	node2.Lchild = &node4;
	node2.Rchild = &node5;
	node4.Lchild = &node8;
	node4.Rchild = &node9;
	node5.Lchild = &node10;
	node3.Lchild = &node6;
	node3.Rchild = &node7;
	//二叉树的非递归打印
	{
		Print_Tree(&node1);
		printf("\n");
	}
	Print_Tree_ByDG(&node1);
}
int main() {
	TestCinaryNode();
	system("pause");
	return 0;
}