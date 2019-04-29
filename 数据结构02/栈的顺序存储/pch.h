#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//用数组去模拟栈的顺序存储
#define MAX_SIZE 1024
#define ISEMPTY_TURE 1
#define ISEMPTY_FAILE 0
typedef struct SEQSTACK {
	void* data[MAX_SIZE];
	int size;//标识元素中的个数
}SEQSTACK;

//初始化
SEQSTACK* Init_SeqStack();
//入栈
void Push_SeqStack(SEQSTACK* stack, void* data);
//返回栈顶元素
void* Top_SeqStack(SEQSTACK* stack);
//出栈
void Pop_SeqStack(SEQSTACK* stack);
//判断是否为空
void IsEmpty_SeqStack(SEQSTACK* stack);
//返回栈中元素个数
int Size_SeqStack(SEQSTACK* stack);
//销毁
void Free_SeqStack(SEQSTACK* stack);
//清空栈
void Clear_SeqStack(SEQSTACK* stack);