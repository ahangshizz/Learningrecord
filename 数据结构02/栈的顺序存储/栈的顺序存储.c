﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pch.h"
typedef struct Person {
	char name[64];
	int age;
}Person;
int main() {
	//创建栈
	SEQSTACK* stack = Init_SeqStack();
	//创建数据
	Person p1 = { "aaa",10 };
	Person p2 = { "bbb",20 };
	Person p3 = { "ccc",30 };
	Person p4 = { "ddd",40 };
	Person p5 = { "eee",50 };
	//入栈
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);

	//输出
	while (Size_SeqStack(stack) > 0) {
		//访问栈顶元素
		Person* person=(Person*)Top_SeqStack(stack);
		printf("name=%s age=%d\n", person->name, person->age);
		Pop_SeqStack(stack);
	}
	Free_SeqStack(stack);
	system("pause");
	return 0;
}