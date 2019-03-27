#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//1.在屏幕上输出以下图案：
//*
//***
//*****
//*******
//*********
//***********
//*************
//***********
//*********
//*******
//*****
//***
//*
int main1() {
	int i = 0;
	int n;
	int j = 0;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		for (j = 0; j < i + 1; j++) {
			putchar('*');
		}
		putchar('\n');
	}
	for (i = n; i >= 0; i--) {
		for (j = i; j >= 0; j--) {
			putchar('*');
		}
		putchar('\n');
	}
	putchar('\n');
	system("pause");
	return 0;
}
//2.求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
/*
在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），
是指一N位数，其各个数之N次方和等于该数。
例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
153 = 1^3 + 5^3 + 3^3。
370 = 3^3 + 7^3 + 0^3。
371 = 3^3 + 7^3 + 1^3。
407 = 4^3 + 0^3 + 7^3。
*/

int main2() {
	int i = 0;
	for (i = 100; i <= 999; i++) {
		int a = i % 10;
		int b = i / 10 % 10;
		int c = i / 100;
		if ((pow(a , 3) + pow(b , 3) + pow(c , 3)) == i) {
			printf("%d  ", i);
		}
	}
	system("pause");
	return 0;
}

//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222

int main3() {
	int n;
	int i;
	int sum=0;
	scanf("%d", &n);
	int tmp = n;
	for (i = 0; i < 5; i++) {
		sum = sum + n;
		n = n * 10 + tmp;//创建临时变量保存输入的数字
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}


//1.完成猜数字游戏。

void nemu() {//创建一个游戏菜单
	printf("*****************\n");
	printf("****1.开始游戏***\n");
	printf("****2.退出游戏***\n");
	printf("****3.清空屏幕***\n");
	printf("*****************\n");
}
void Game() {//创建一个游戏函数
	int num = 0;
	int g_n = 0;
	srand((unsigned)time(NULL));//随机数种子,产生随机数
	num = rand() % 101;//产生0-100的随机数
	while (1) {//在循环中进行比对
		printf("请输入你猜的数字: ");
		scanf("%d", &g_n);
		if (g_n < num) {
			printf("你输入的数字太小了\n");
		}
		else if (g_n > num) {
			printf("你输入的输在太大了\n");
		}
		else if(g_n==num) {
			printf("恭喜你猜对了!");
			break;
		}
	}
}
int main4() {
	int num=0;
	do//do while语句循环游戏菜单
	{
		nemu();
		printf("请输入选项:  ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			Game();
			break;
		case 2:
			return ;
		case 3:
			system("cls");
			break;
		default://用户可能输入不正确的数字,default语句很有必要
			printf("您输入的数字有误");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}





//2.写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）


int mystr(int arr[20],int len,int a) {
	int i = 0;
	int L = 0;
	int R = len-1;
	while (L <= R) {
		if (arr[(L + R) / 2] > a) {
			R = (L + R) / 2 - 1;
		}
		else if (arr[(L + R) / 2] < a) {
			L = (L + R) / 2 + 1;
		}
		else if (arr[(L + R) / 2] == a) {
			return (L + R) / 2;
		}
		else {
			return -1;
		}

	}
	return -1;
}
int main5() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = mystr(arr, len,6);
	printf("%d\n", ret);
	system("pause");
	return 0;
}




//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。

int main6() {
	int i = 0;
	for (i = 0; i < 3; i++) {
		char arr[10] = { 0 };
		printf("请输入你的密码: \n");
		scanf("%s", arr);
		if (strcmp(arr, "123456") != 0) {
			printf("你输入的密码有误\n");
			continue;
		}
		else {
			printf("密码输入成功!");
			break;
		}
	}
	if (i == 3) {
		printf("密码错误三次,程序退出\n");
	}
	system("pause");
	return 0;
}




//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。


//做题失败
int main7() {
	char buf[20];
	while (gets(buf) != EOF) {
		while (buf != '\0') {
			if (buf > 'a'&&buf < 'z') {
				puts(buf - 32);
			}
			else if (buf>'0'&&buf<'9') {
				continue;
			}
			else if (buf>'A'&&buf < 'Z') {
				puts(buf + 32);
			}
			buf + 1;
		}
	}
	system("pause");
	return 0;
}


//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。


void Print() {//打印乘法口诀表的函数
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d*%2d=%2d  ", j, i, i*j);
		}
		printf("\n");
	}
}
void change(int*a ,int*b) {//交换两个数内容函数
	int c = *a;
	*a = *b;
	*b = c;
}
int Isyear(int year) {//判断是不是闰年的函数
	if (((year % 4 == 0) && year % 100 != 0) || year % 400 == 0) {
		return 1;
	}
	return 0;
}
int main8() {
	int num = 0;
	scanf("%d", &num);
	int ret=Isyear(num);
	if (ret == 1) {
		printf("%d年是闰年\n", num);
	}
	else {
		printf("%d年不是闰年\n", num);
	}
	system("pause");
	return 0;
}


//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。

void init(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = 4 * i + 1;
	}
}
void empty(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		arr[i] = 0;
	}
}

void reverse(int arr[], int len) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		++left;
		--right;
	}
}
void printarr(int arr[],int len) {
	for (int i = 0; i < len; ++i) {
		printf("arr[%d]=%d  ", i, arr[i]);
	}
	printf("\n");
}
int main9() {
	int arrA[10] = { 0 };
	init(arrA, 10);
	printarr(arrA, 10);
	reverse(arrA, 10);
	printarr(arrA, 10);
	empty(arrA, 10);
	printarr(arrA, 10);
	system("pause");
	return 0;
}


void Isprime(int num) {
	int i = 0;
	for (i = 2; i < num; ++i) {
		if (num%i == 0) {
			printf("%d不是素数", num);
			break;
		}
	}
	if (i == num) {

	printf("%d是素数", num);
	}
}
int main10() {
	Isprime(9);
	system("pause");
	return 0;
}

//2.编写一个函数实现n^k，使用递归实现

int mypow(int n, int k) {
	if (k == 1) {
		return n;
	}
	return n*mypow(n, k-1);
}
int main11() {
	int a = mypow(2, 4);
	printf("%d\n", a);
	system("pause");
	return 0;
}


//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19

int DigitSum(int n) {
	if (n < 10) {
		return n;
	}
	return n % 10 + DigitSum(n / 10);
}
int main12() {
	int ret = DigitSum(123456);
	printf("%d", ret);
	system("pause");
	return 0;
}


//5.递归和非递归分别实现strlen

int mystrlen(char* buf) {
	int count = 0;
	while (*buf != '\0') {
		count++;
		*buf++;
	}
	return count;
}
int main13() {
	char buf[] = "welcome to bit";
	int ret = mystrlen(buf);
	printf("%d\n",ret);
	system("pause");
	return 0;
}
//递归的方法实现strlen
int mystrlen2(char* buf) {
	if (*buf == '\0') {
		return 0;
	}
	return 1 + mystrlen2(buf + 1);
}
int main14() {
	char buf[] = "welcome to bit";
	int ret = mystrlen2(buf);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

//递归的方式实现n的阶乘
int jiecheng(int n) {
	if (n == 1) {
		return 1;
	}
	return n*jiecheng(n - 1);
}
int main15() {
	int ret = jiecheng(4);
	printf("%d", ret);
	system("pause");
	return 0;
}
//非递归的方式实现n的阶乘
int main16() {
	int n = 4;
	int tum = 1;
	for (int i = 1; i <= n; ++i) {
		tum = tum*i;
	}
	printf("%d", tum);
	system("pause");
	return 0;
}

void PRINT(int n) {
	if (n == 0) {
		return;
	}
	if (n < 10) {
		printf("%d\n", n);
	}
	if (n>10) {
	PRINT(n / 10);
	printf("%d\n", n % 10);
	}
}
int main17() {
	PRINT(1729);
	system("pause");
	return 0;
}

int main() { 
	int arr[]={-2,5,4,6,3,8}; 
	int i=0; int j=0; 
	int len=sizeof(arr)/sizeof(arr[0]); 
	for(i=0;i<len-1;i++) { 
		for(j=0;j<len-1-i;j++)  { 
			if(arr[j]>arr[j+1]) { 
			int tmp=arr[j]; 
			arr[j]=arr[j+1]; 
			arr[j+1]=tmp;
			} 
		}
	} 
	for(i=0;i<len;i++) { 
		printf("%d",arr[i]);
	} 
	return 0; 
}
