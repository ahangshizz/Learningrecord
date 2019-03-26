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
int main() {
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