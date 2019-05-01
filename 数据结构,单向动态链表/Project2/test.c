#include <stdio.h>
#include <stdlib.h>
#include "Linklist.h"

void test01() {
	//初始化
	LinkList* list = Init_LinkList();
	//插入新结点
	for (int i = 0; i < 15; ++i) {
		Insert_LinkList(list, i, 2 * i);
	}
	//打印结点
	Printf_LinkList(list);
	//删除结点
	Remove_LinkList(list, 5);
	Printf_LinkList(list);
	//查找
	Find_LinkList(list, 10);
	//释放内存
	Free_LinkList(list);
}
int main() {

	test01();
	system("pause");
	return 0;
}