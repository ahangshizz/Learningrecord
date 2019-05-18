#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


typedef int SDataType;

typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _size; // 表示栈中有效元素的个数 代表栈顶位置
}Stack;

//实现栈的API操作
//初始化一个栈
void StackInit(Stack* ps);
//压栈
void StackPush(Stack* ps, SDataType data);
//出栈
void StackPop(Stack* ps);
//弹出栈顶元素
SDataType StackTop(Stack* ps);
//返回栈中有效元素个数
int StackSize(Stack* ps);
//判断栈是否为空
int StackEmpty(Stack* ps);
//销毁栈
void StackDestroy(Stack* ps);