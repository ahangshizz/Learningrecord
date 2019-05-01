#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//定义结点
typedef struct CinaryNode {
	char ch;
	struct CinaryNode* Lchild;
	struct CinaryNode* Rchild;
}CinaryNode;
//用递归进行遍历
void Print_Node(CinaryNode* node) {
	if (node == NULL) {
		return;
	}
	//先序遍历
	printf("%c ", node->ch);//打印
	Print_Node(node->Lchild);//递归左儿子
	Print_Node(node->Rchild);//递归右儿子
//// 		//中序遍历
//// 	Print_Node(node->Lchild);//递归左儿子
//// 	printf("%c ", node->ch);//打印
//// 	Print_Node(node->Rchild);//递归右儿子
//// 		//后序遍历
//// 	Print_Node(node->Lchild);//递归左儿子
//// 	Print_Node(node->Rchild);//递归右儿子
//// 	printf("%c ", node->ch);//打印
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
	Print_Node(&node1);
}
int main() {
	TestCinaryNode();
	system("pause");
	return 0;
}