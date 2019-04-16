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
#if 0 
//模拟实现strcat
void Mystrcat(char* des, const char* src) {
	assert(src != NULL);
	while (*des!='\0') {
		des++;//找到目标字符串的'\0',从这里开始拼接
	}
	while (*des++ = *src++) {//把源字符串赋值给目标文件,然后指针向后移
		;//开始拼接
	}
	*des = '\0';//在目标文件的末尾赋值'\0'
}
int main() {
	char array[64] = "i am a";
	char array2[] = " pig";
	Mystrcat(array, array2);
	printf("%s\n", array);
	return 0;
}
#endif
#if 0
//模拟实现strstr
const char* Mystrstr(const char* des,const char* str) {//const修饰指针指向内容不能被改变
	assert(des != NULL);
	assert(str != NULL);//断言,如果目标文件和源文件为NULL直接程序崩溃
	const char* red = des;
	const char* blk = str;
	while (*red) {
		const char* tmp = red;//定义一个临时变量保存已经检测到的位置
		while (*blk == *tmp) {
			blk++;
			tmp++;
		}
		if (*blk == '\0') {//如果黑色指针指向'\0'即已经找到要查找 的字符串
			return red;//查找开始时的指针
		}
		blk = str;//让黑色指针还原到首元素位置
		red++;//开始从下一个元素查找
	}
	return NULL;
}
int main() {
	char buf[] = "hello";
	char str[] = "he";
	const char*ret = Mystrstr(buf, str);
	printf("%s\n", ret);
	return 0;
}
#endif
#if 0
//模拟实现strchr
const char* Mystrchr(const char*dst, const char str) {
	assert(dst != NULL);
	while (*dst!='\0') {//循环条件是指针不指向字符串结尾
		if (*dst == str) {//如果相等,返回开始查找的位置
			return dst;
		}
		dst++;//循环条件加加
	}
	return NULL;
}
int main() {
	char buf[] = "hello world";
	char*p = Mystrchr(buf, 'o');
	printf("%s", p);
	return 0;
}
#endif
#if 0
//模拟实现strcmp
int Mystrcmp(const char* arr1, const char* arr2) {
	while ((*arr1!='\0')&&(*arr2!='\0')) {
		if (*arr1 > *arr2) {
			return 1;
		}
		else if (*arr1 < *arr2) {
			return -1;
		}
		else {
			++arr1;
			++arr2;
		}
	}
	if ((*arr1 == '\0')&&(*arr2!='\0')) {
		return -1;
	}
	else if ((*arr2 == '\0') && (*arr1 != '\0')) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	char arr1[] = "xelcome";
	char arr2[] = "welcome";
	int ret = Mystrcmp(arr1, arr2);
	printf("%d\n", ret);
	return 0;
}
#endif
#if 0
//实现memcpy
//从最后一个字符开始往前拷贝,可以解决内存重叠的部分问题
void* Mymemcpy(void* dest, const void* src, size_t count) {
	assert(dest != NULL);
	assert(src != NULL);
	char* p = (char*)dest+(count-1);//指针强制转换成char*类型,再向后移动到最后一个元素
	const char*p1 = (char*)src+(count-1);//指针强制转换成char*类型,再向后移动到最后一个元素
	while (count--) {
		*p = *p1;
		--p;//从后往前拷贝
		--p1;
	}
	return dest;//返回值为目标字符串
}
int main() {
	char buf1[] = "welcome";
	char buf2[64] = { 0 };
	Mymemcpy(buf2, buf1, 4);
	printf("%s\n", buf2);
	return 0;
}
#endif
