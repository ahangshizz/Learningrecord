#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"


typedef struct Person {
	LinkNode node;
	char name[20];
	int age;
	int score;
}Person;
int main() {
	LinkStack* stack = Init_LinkStack();
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");
	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;
	p1.score = 95;
	p2.score = 96;
	p3.score = 97;
	p4.score = 98;
	p5.score = 99;
	//ÈëÕ»
	Push_LinkStack(stack, (LinkNode*)&p1);
	Push_LinkStack(stack, (LinkNode*)&p2);
	Push_LinkStack(stack, (LinkNode*)&p3);
	Push_LinkStack(stack, (LinkNode*)&p4);
	Push_LinkStack(stack, (LinkNode*)&p5);
	while (Size_LinkStack(stack) > 0) {
		Person* person=(Person*)Top_LinkStack(stack);
		printf("name=%s  age=%d  score=%d\n", person->name, person->age, person->score);
		Pop_LinkStack(stack);
	}
	Free_LinkStack(stack);
	system("pause");
	return 0;
}