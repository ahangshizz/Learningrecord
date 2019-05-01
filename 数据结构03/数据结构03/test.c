#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"
typedef struct MyChar {
	LinkNode node;
	char c;
}MyChar;
//是否为数字
int Is_Num(char p) {
	return p >= '0'&&p <= '9';
}
//打印数字
void Print_Num(char* p) {
	printf("%c", *p);
}
//是否为左括号
int Is_Left(char p) {
	return p == '(';
}
//是否为右括号
int Is_Right(char p) {
	return p == ')';
}
//右括号操作
void RightOperator(LinkStack* stack) {
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		if (mychar->c == '(') {
			Pop_LinkStack(stack);
			break;
		}
		printf("%c", mychar->c);
		Pop_LinkStack(stack);
		free(mychar);
	}
}
//是否为运算符
int Is_Operator(char p) {
	return p == '+' || p == '-' || p == '*' || p == '/';
}
//左括号直接进站,进站函数;
void Insert_stack(LinkStack* stack, LinkNode* node) {
	Push_LinkStack(stack, node);
}
//返回运算符号优先级
int GetPorioty(char c) {
	if (c == '*' || c == '/') {
		return 2;
	}
	if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}
//运算符操作
void OperatorOperator(LinkStack* stack, char* p) {
	//先取出栈顶元素进行比较
	MyChar* mychar = (MyChar*)Top_LinkStack(stack);
	if (mychar == NULL) {
		MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
		mychar->c = *p;
		Push_LinkStack(stack, (LinkNode*)mychar);
		return;
	}
	//如果栈顶优先级低于当前字符优先级,入栈
	if (GetPorioty(mychar->c) < GetPorioty(*p)) {
		MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
		mychar->c = *p;
		Push_LinkStack(stack, (LinkNode*)mychar);
		return;
	}//如果栈顶优先级高
	else {
		while (Size_LinkStack(stack) > 0) {
			MyChar* mychar2 = (MyChar*)Top_LinkStack(stack);
			if (GetPorioty(mychar2->c) < GetPorioty(*p)) {
				MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
				mychar->c = *p;
				Push_LinkStack(stack, (LinkNode*)mychar);
				break;
			}
			printf("%c", mychar2->c);
			Pop_LinkStack(stack);
			free(mychar2);
		}
	}
}
int main() {
	char* str = "8+(3-1)*5";
	char* p = str;
	LinkStack* stack = Init_LinkStack();
	while (*p != '\0') {
		if (Is_Num(*p)) {
			Print_Num(p);
		}
		if (Is_Left(*p)) {
			MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
			mychar->c = *p;
			Push_LinkStack(stack, (LinkNode*)mychar);
		}
		if (Is_Right(*p)) {
			RightOperator(stack);
		}
		if (Is_Operator(*p)) {
			OperatorOperator(stack, p);
		}
		p++;
	}
	while (Size_LinkStack(stack) > 0) {
		MyChar* mychar = (MyChar*)Top_LinkStack(stack);
		printf("%c", mychar->c);
		Pop_LinkStack(stack);
	}
	system("pause");
	return 0;
}