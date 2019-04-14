#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#if 0
//关于库函数   strtok的使用方法;
int main() {
	char str[] = "welcome to beijing";
	char* p = strtok(str," ");
	while (p != NULL) {
		printf("%s\n", p);
		p=strtok(NULL, " ");
	}
	return 0;
}
#endif
#if 0
//实现一个库函数   strcpy
void Mystrcpy(char* des, const char*src) {
	assert(src != NULL);
	//把源字符串的指针指向内容赋值给目标指针,然后指针后置加加,即指针向后移动一位
	while ((*des++ = *src++)!= '\0') {
		//do nothing 
	}
		*des = '\0';//最后给目标指针指向的最后一个内容赋值0
}
int main() {
	char name[1024] = "welcome to beijing";
	char buf[1024] = { 0 };
	Mystrcpy(buf, name);
	printf("%s\n", buf);
	return 0;
}
#endif
