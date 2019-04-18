#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#if 0
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
#endif
#if 0
char IsBigletter(ch) {
	return ch + 32;
}
char IsSmallletter(ch) {
	return ch - 32;
}
int main() {
	char ch = 0;
	while (1) {
		ch = getchar();
		if (ch >= 'a'&&ch <= 'z') {
			putchar(ch-32);
		}
		else if (ch>='A'&&ch <= 'Z') {
			
			putchar(ch+32);
		}
		else if (ch == '$') {
			break;
		}
		else if (ch>'0'&&ch < '9') {
			//do nothing
		}
		else {
			putchar(ch);
		}
	}
	system("pause");
	return 0;
}
#endif
#if 0
//不使用(a+b)/2,求两个数的平均数

int Average(int a, int b) {
	if (a > b) {
		return (b)+((a - b) / 2);
	}
	else
	{
		return (a + (b - a) / 2);
	}

}
int main() {
	int a = 10;
	int b = 20;
	int ret=Average(a, b);
	printf("%d", ret);
	return 0;
}
#endif
#if 0
//字符串的翻转
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//	student a am i
//	i ma a tneduts
//	i am a student

void Flip(char*array,int len) {
	int left = 0;
	int right = len;
	while (left <= right) {
		char tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
		left++;
		right--;
	}
}
int main() {
	char array[] = "tneduts a ma i";
	int len = strlen(array)-1;
	Flip(array, len);
	for (int i = 0; i <= len; ++i) {
		printf("%c", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
#endif
#if 0
//1.
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; ++a) {
		for (b = 1; b <= 5; ++b) {
			for (c = 1; c <= 5; ++c) {
				for (d = 1; d <= 5; ++d) {
					for (e = 1; e <= 5; ++e) {
						if (b == 2 || a == 3) {
							if (b == 2 || e == 4) {
								if (c == 1 || d == 2) {
									if (c == 5 || d == 3) {
										if (e == 4 || a == 1) {
											if (a*b*c*d*e == 120) {
												printf("%d %d %d %d %d\n", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
#endif

#if 0
//打印杨辉三角
int main() {
	int array[100][100] = { 1 };//应该把初始值全部赋值为1,赋值为0没法计算
	int i = 0;//i表示行数
	int j = 0;//j表示第几个元素
	int n = 0;
	while (1) {
		printf("请输入要打印的行数");
		scanf("%d", &n);
		if (n < 0 || n>100) {//判断用户输入的合法性
			continue;
		}
		else {
			for (i = 1; i <= n; ++i) {
				for (j = 1; j <= i; ++j) {
					array[i][j] = array[i - 1][j - 1] + array[i - 1][j];//当前二维数组元素等于上一行的两个元素相加
					printf("%2d ", array[i][j]);
				}
				printf("\n");
			}
		}
		return 0;
	}
	return 0;
}
#endif

#if 0
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
int main() {
	int killer;
	for (killer = 'A'; killer <= 'D'; ++killer) {
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3) {
			printf("%c\n", killer);
		}
	}
	system("pause");
	return 0;
}
#endif 
#if 0
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
unsigned int reverse_bit(unsigned int value) {
	int sum = 0;
	for (int i = 0; i < 32; ++i) {
		int ret = ((value >> i) & 1)*pow(2, 31 - i);
		sum += ret;
	}
	printf("%u\n", sum);
}
int main() {
	int value = 25;
	reverse_bit(value);
	return 0;
}
#endif	
#if 0
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）

int main() {
	int array[] = { 3,4,5,1,1,5,4 };
	int len = sizeof(array) / sizeof(array[0]);
	for (int i = 1; i < len; ++i) {
		array[0] = array[0] ^ array[i];//异或没有搞明白
	}
	printf("%d\n", array[0]);
	return 0;
}
#endif	
#if 0
//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
int main() {
	int buf[10] = { 0};//把数组全部初始化为0
	int i = 0;
	int len = 9;//数组的下标
	for (i = 0; i < 10; ++i) {//循环输入数组
		scanf("%d", &buf[i]);
	}
	for (i = 0; i <= len; ++i) {//循环条件是重点
		if (buf[i] % 2 == 0) {
			int tmp = buf[len];
			buf[len] = buf[i];
			buf[i] = tmp;//交换数组
			len = len-1;//即控制循环跳出条件,又控制数组下边往前移动一.
			i = i - 1;//因为不知道交换的元素是否为偶数,所以把这次循环再进行一次
		}
	}
	for (i = 0; i < 10; ++i) {
		printf("%d ", buf[i]);
	}
	return 0;
}
#endif 
#if 0
//杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
int mystr(int arr[][3], int row, int col,int key) {
	int i = 0;
	int j = col-1;
	while (j>=0&&i<row) {
		if (key == arr[i][j]) {
			return 1;
		}
		else if (key > arr[i][j]) {
			++i;//查找的元素大于这个值,在下一行查找
		}
		else {
			--j;//如果小于这个数,则二维数组的列下标减一
		}
	}
	return 0;
}
int main() {
	int arr[][3] = { 1,2,3,
					 2,3,4,
					 3,4,5 };
	int ret=mystr(arr, 3, 3, 4);
	if (ret == 1) {
		printf("找到了");
	}
	else if (ret == 0) {
		printf("没有找到");
	}
	return 0;
}
#endif 

#if 0
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。

int main() {
	int money = 20;//有20块钱
	int count = 0;//记录喝汽水的个数
	count = 20 / 1;
	int tmp = 0;//空瓶个数
	tmp = 20;
	while(1) {
		int num = tmp / 2;//空瓶换的汽水
		count += num;//把空瓶换的汽水加到喝汽水个数上面
		tmp = tmp/2+tmp%2;
		if (tmp == 1) {//当最后只剩下一个空瓶时,退出循环
			break;
		}
	}
	printf("%d\n", count);
	return 0;
}
//输出结果,20块钱可以喝39瓶汽水
#endif
#if 0
//3.模拟实现strcpy

void Mystrcpy(char best[], char src[]) {//把目标字符串和源字符串传进函数
	if (src == NULL) {//如果源字符串为NULL直接程序结束
		return -1;
	}
	//数组的形参会隐式转换成指针,解引用指针的到第一个字符进行赋值,
	//在进行判定是否为反斜杠0,指针后置加加指向下一个元素
	while ((*best++ = *src++) != '\0') {
		//do nothing;
	}
	*best = '\0';//最后给指针最后一个元素赋值'\0';
}
int main() {
	char buf[] = "welcome to xian";
	char arr[64] = {0};
	Mystrcpy(arr, buf);
	printf("%s\n", arr);
	return 0;
}
#endif
#if 0
char* Mystrcat(char buf[], char arr[]) {
	char* ret = buf;//定义一个临时指针,存储buf的指针
	while (*ret != '\0') {
		ret++;//把指针指向buf的最后即'\0';
	}
	while ((*ret++ = *arr++) != '\0') {//从'\0'开始给buf进行后续拼接
		;//do nothing
	}
	*ret = '\0';//最后给赋值'\0'
	return (char*)ret;//返回这个定义的指针
}
int main() {
	char buf[64] = "i am ";
	char arr[] = "cat";
	Mystrcat(buf, arr);
	printf("%s\n", buf);
	return 0;
}
//输出结果i am cat
#endif
#if 0
//一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个数字，编程实现。

int main() {
	int arr[] = { 3,5,4,2,5,4,2,9 };
	int i = 0;//第一次循环
	int j = 0;//内层循环
	int count=0;//计数
	int len = sizeof(arr) / sizeof(int);
	for (i = 0; i < len; ++i) {//用数组的一个元素与其他每个元素进行比较
		for (j = 0; j < len; ++j) {
			if (arr[i] == arr[j]) {
			//如果两个数相等,count就自加,一个数出现一次那循环结束,
			//count就是1,如果数字出现两次count出循环值为2
				count++;
			}
		}
		if (count == 1) {//判断count,如果为1则打印这个数
			printf("%d ", arr[i]);
		}
		count = 0;//内层循环完毕一定要给count清零
	}
	return 0;
}
#endif
//2.实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：
//姓名、性别、年龄、电话、住址
//
//提供方法：
//1. 添加联系人信息
//2. 删除指定联系人信息
//3. 查找指定联系人信息
//4. 修改指定联系人信息
//5. 显示所有联系人信息
//6. 清空所有联系人
//7. 以名字排序所有联系人
//8. 保存联系人到文件
//9. 加载联系人
enum Sex {
	man,
	women
};
typedef struct Person {
	char name[1024];
};
int main() {


	return 0;
}