#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创建链栈的结点
typedef struct LinkNode {
	struct LinkNode* next;
}LinkNode;
//创建链栈
typedef struct LinkStack {
	LinkNode head;
	int size;
}LinkStack;

//写链栈的API

//初始化 
LinkStack* Init_LinkStack();
//入栈
void Push_LinkStack(LinkStack* stack,LinkNode* data);
//出栈
void Pop_LinkStack(LinkStack* stack);
//返回栈顶元素
LinkNode* Top_LinkStack(LinkStack* stack);
//返回栈的元素个数
int Size_LinkStack(LinkStack* stack);
//清空栈
void Clear_LinkStack(LinkStack* stack);
//销毁栈
void Free_LinkStack(LinkStack* stack);