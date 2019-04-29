#include "pch.h"


//初始化
SEQSTACK* Init_SeqStack() {
	SEQSTACK* stack = (SEQSTACK*)malloc(sizeof(SEQSTACK));
	for (int i = 0; i < MAX_SIZE; ++i) {
		stack->data[i] = NULL;
	}
	stack->size = 0;
	return stack;
}
//入栈
void Push_SeqStack(SEQSTACK* stack, void* data) {
	if (stack == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	if (stack->size == MAX_SIZE) {
		return;
	}
	stack->data[stack->size] = data;
	stack->size++;
}
//返回栈顶元素
void* Top_SeqStack(SEQSTACK* stack) {
	if (stack == NULL) {
		return;
	}
	if (stack->size == 0) {
		return;
	}

	return stack->data[stack->size-1];
}
//出栈
void Pop_SeqStack(SEQSTACK* stack) {

	if (stack == NULL) {
		return;
	}
	if (stack->size == 0) {
		return;
	}
	stack->data[stack->size - 1] = NULL;
	--stack->size;
}


//判断是否为空
void IsEmpty_SeqStack(SEQSTACK* stack) {
	if (stack == NULL) {
		return -1;
	}
	if (stack->size == 0) {
		return ISEMPTY_TURE;
	}
	else {
		return ISEMPTY_FAILE;
	}
}
//返回栈中元素个数
int Size_SeqStack(SEQSTACK* stack) {

	return stack->size;
}
//销毁
void Free_SeqStack(SEQSTACK* stack) {
	if (stack == NULL) {

		return;
	}
	free(stack);
}
//清空栈
void Clear_SeqStack(SEQSTACK* stack) {
	if (stack == NULL) {
		return;
	}
	for (int i = 0; i < MAX_SIZE; ++i) {
		stack->data[i] = NULL;
	}
	stack->size = 0;
}