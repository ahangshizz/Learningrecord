#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0
//malloc  动态开辟内存空间
int main() {
	char buf[20] = "welcome to xian";
	char* name;
	name = (char*)malloc(sizeof(char) * 20);
	strcpy(name, buf);
	printf("%s\n", name);
	free(name);
	if (name != NULL) {
		name = NULL;
	}
	return 0;
}
#endif
#if 0
//calloc动态开辟内存空间

int main() {
	int* p;
	p = (int*)calloc(10, 4);
	for (int i = 0; i < 10; ++i) {
		p[i] = 2 * i + 1;
		printf("p[%d]=%d\n", i, p[i]);
	}
	free(p);
	if (p != NULL) {
		p = NULL;
	}
	return 0;
}
#endif

//realloc重新规定分配的内存

int main() {
	char*p = (char*)malloc(sizeof(char) * 2);
	strcpy(p, "p");
	//realloc参数中的指针必须是malloc,calloc,realloc的返回值
	//如果realloc分配的内存大小大于旧指针大小,则重新分配新内存,
	//旧的指针自动释放,成为野指针,后续操作野指针属于非法操作
	char* p2=realloc(p, sizeof(char) * 30);
	//条件判定一下,如果分配失败直接返回
	if (p2 == NULL) {
		printf("动态内存分配失败\n");
		return -1;
	}
	strcpy(p2, "welcome to xian!");
	printf("%s\n", p2);
	//free(p);//后续操作旧指针,属于非法操作
	//p = NULL;
	free(p2);
	p2 = NULL;
	return 0;
}