#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define  ROW_MAX 3//宏定义棋盘的行
#define  COL_MAX 3//宏定义棋盘的列
char Chess[ROW_MAX][COL_MAX] = {0};//定义一个二维数组的棋盘
int neum() {//设置游戏菜单
	int chooice = 0;
	printf("******************\n");
	printf("**1.开始游戏******\n");
	printf("**2.退出游戏******\n");
	printf("******************\n");
	printf("请输入您的选择 ");
	scanf("%d", &chooice);
	return chooice;
}
void Print() {//打印棋盘
	for (int ROW=0; ROW < ROW_MAX; ROW++) {
		printf("| %c | %c | %c |\n", Chess[ROW][0], Chess[ROW][1], Chess[ROW][2]);
		if (ROW != ROW_MAX-1) {
		printf("|---|---|---|\n");
		}
	}
}
void Playermove() {
	while (1) {

		printf("玩家落子\n");
		printf("请输入落子位置(ROW,COL) ");
		int ROW = 0;
		int COL = 0;
		scanf("%d %d", &ROW, &COL);
		//检测用户输入的坐标是否合法
		
		if (ROW>2 || COL > 2||ROW<0||COL<0) {
			printf("您输入的坐标有误请重新输入\n");
			continue;
		}
		if (Chess[ROW][COL] != ' ') {
			printf("您输入的坐标已经被他人占用请重新输入\n");
			continue;
		}
		Chess[ROW][COL] = 'X';
		break;
		printf("玩家落子完毕\n");
	}

}
void Computermove() {
	srand((unsigned int)time(NULL));
		printf("电脑落子\n");
	while (1) {
		int ROW = rand() % 3;
		int COL = rand() % 3;
		if (Chess[ROW][COL] != ' ') {
			continue;
		}
		Chess[ROW][COL] = 'O';
		break;
	}

	printf("电脑落子完毕\n");
}
char Cheekwinner() {
	//检查所有行是否连成一条线
	for (int ROW = 0; ROW < ROW_MAX; ++ROW) {
		if (Chess[ROW][0] == Chess[ROW][1] && Chess[ROW][0] == Chess[ROW][2]) {
			return Chess[ROW][0];
		}
	}
	for (int COL = 0; COL < COL_MAX; ++COL) {
		if (Chess[0][COL] == Chess[1][COL] && Chess[0][COL] == Chess[2][COL]) {
			return Chess[0][COL];
		}
	}
	if (Chess[0][0] == Chess[1][1] && Chess[0][0] == Chess[2][2]) {
		return Chess[0][0];
	}
	else if (Chess[0][2] == Chess[1][1] && Chess[0][2] == Chess[2][0]) {
		return Chess[0][2];
	}
	else if (IsFull()){
		return 'q';//返回q表示和棋
	}
	return ' ';//返回空格表示未分胜负
}
//棋盘满返回1否则返回0
int IsFull() {
	for (int ROW = 0; ROW < ROW_MAX; ++ROW) {
		for (int COL = 0; COL < COL_MAX; ++COL) {
			if (Chess[ROW][COL] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
void Cheek_body() {
	int ROW=0;
	int COL=0;
	for (ROW = 0; ROW < ROW_MAX; ++ROW) {
		for (COL = 0; COL < COL_MAX; ++COL) {
			Chess[ROW][COL] = ' ';
		}
	}
}
void GAME() {
	char winner = ' ';
	//初始化棋盘
	Cheek_body();
	while (1) {
		//打印棋盘
		Print();
		//玩家落子
		Playermove();
		Print();
		//判断胜负
		winner=Cheekwinner();
		if (winner != ' ') {
			break;
		}
		//电脑落子
		Computermove();
		//判断胜负
		winner=Cheekwinner();
		if (winner != ' ') {
			break;
		}
	}
	if (winner == 'X') {
		printf("您赢了!\n");
	}
	else if (winner == 'O') {
		printf("您真菜!\n");
	}
	else if (winner == 'q') {
		printf("您和电脑五五开");
	}
}



int main() {

	while (1)
	{
		int ret=neum();
		if (ret == 1) {
			GAME();
		}
		else if (ret == 2) {
			printf("GOODBAY\n");
			return;
		}
		else {
			printf("您输入的选项有误");
		}
	}
	system("pause");
	return 0;
}