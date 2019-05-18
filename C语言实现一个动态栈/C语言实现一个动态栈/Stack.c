#include "Stack.h"
void StackInit(Stack* ps) {
	if (ps == NULL) {
		return;
	}
	ps->_capacity = 3;
	ps->_size = 0;
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* ps->_capacity);
	if (ps->_array == NULL) {
		assert(ps->_array);
	}
	for (int i = 0; i < ps->_capacity; ++i) {
		ps->_array[i] = 0;
	}
}
//压栈
void StackPush(Stack* ps, SDataType data) {
	if (ps == NULL) {
		return;
	}
	if (ps->_size == ps->_capacity) {
		//扩大容器
		ps->_capacity = 2 * ps->_capacity;
		//创建新空间
		SDataType* newspace = (SDataType*)malloc(sizeof(SDataType)*ps->_capacity);
		//拷贝数据
		for (int i = 0; i < ps->_size; ++i) {
			newspace[i] = ps->_array[i];
		}
		//释放旧空间
		free(ps->_array);
		//指针指向新空间
		ps->_array = newspace;
	}
	ps->_array[ps->_size] = data;
	ps->_size++;
}
//出栈
void StackPop(Stack* ps) {
	if (ps == NULL) {
		return;
	}
	if (ps->_size == 0) {
		printf("栈已空\n");
		return;
	}
	ps->_size--;
}
//弹出栈顶元素
SDataType StackTop(Stack* ps) {
	if (ps == NULL) {
		return 0;
	}
	if (ps->_size == 0) {
		printf("栈中无元素\n");
		return 0;
	}
	return ps->_array[ps->_size - 1];
}
//返回栈中有效元素个数
int StackSize(Stack* ps) {
	if (ps == NULL) {
		return 0;
	}
	return ps->_size;
}
//判断栈是否为空
int StackEmpty(Stack* ps) {
	if (ps == NULL) {
		return 0;
	}
	if (ps->_size == 0) {
		return 0;
	}
	return 1;
}
//销毁栈
void StackDestroy(Stack* ps) {
	if (ps == NULL) {
		return;
	}
	free(ps->_array);
	ps->_array = NULL;
}