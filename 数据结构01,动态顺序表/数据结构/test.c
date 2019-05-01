#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dam_array.h"

//测试写好的动态数组

void test01() {
	//初始化数组
	Damarray* myarray = Init_array();
	//插入元素
	for (int i = 0; i < 10; ++i) {
		Pushback_array(myarray, 2 * i);
	}
	//打印数组
	Printf_array(myarray);
	//打印容量
	Capacity_array(myarray);
	//获取当前有效元素个数
	Size_array(myarray);
	//删除
	RemoveBypos_array(myarray, 5);
	Printf_array(myarray);
	//查找元素
	Find_array(myarray, 6);
	Find_array(myarray, 7);
	//释放
	FreeSpace_array(myarray);
}
int main() {

	test01();
	system("pause");
	return 0;
}