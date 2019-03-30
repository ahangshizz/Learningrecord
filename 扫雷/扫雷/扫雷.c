#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 9//宏定义二维数组的行数
#define MAX_COL 9//宏定义二维数组的列数
#define MINE_count 10//宏定义地雷的个数
void init(char show_map[MAX_ROW][MAX_COL], char  mine_map[MAX_ROW][MAX_COL]) {//初始化函数,初始化两个二维数组
	int row;
	int col;
	for (row = 0; row < MAX_ROW; ++row) {
		for (col = 0; col < MAX_COL; ++col) {
			show_map[row][col] = '*';
		}
	}
	for (row = 0; row < MAX_ROW; ++row) {
		for (col = 0; col < MAX_COL; ++col) {
			mine_map[row][col]='0';
		}
	}
}
void Mine_count(char mine_map[MAX_ROW][MAX_COL]) {//初始化地雷的随机分布图
	int n = MINE_count;
	while (n> 0) {
		int row = rand() % 9;//随机坐标
		int col = rand() % 9;
		if (mine_map[row][col] != '1') {//判断地雷的合法性,重复则重新随机
			mine_map[row][col] = '1';
			--n;
		}
		else {
			continue;
		}
	}
}
void Print_map(char map[MAX_ROW][MAX_COL]) {//打印地图函数,打印出地图
	int row;
	int col;
	for (col = 0; col < MAX_COL; ++col) {
		printf("    %d", col);
	}
	printf("\n");
	for (col = 0; col < MAX_COL; ++col) {
		printf("-----");
	}
	printf("\n");
	for (row = 0; row < MAX_ROW; ++row) {
		printf("%d | ", row);
		for (col = 0; col < MAX_COL; ++col) {
			printf("%c    ", map[row][col]);
		}
		printf("\n");
	}
}
void Show_Mine(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL], int row, int col) {//判断周围的地雷个数
	int count=0;
	if (row-1 >= 0 && row-1 <= MAX_ROW&&col-1 >= 0 && col-1 <= MAX_COL&&mine_map[row-1][col-1]=='1') {
		count++;
	}
	if (row-1 >= 0 && row-1 <= MAX_ROW&&col >= 0 && col <= MAX_COL&&mine_map[row-1][col] == '1') {
		count++;
	}
	if (row-1 >= 0 && row-1 <= MAX_ROW&&col+1 >= 0 && col+1 <= MAX_COL&&mine_map[row-1][col+1] == '1') {
		count++;
	}
	if (row >= 0 && row <= MAX_ROW&&col-1 >= 0 && col-1 <= MAX_COL&&mine_map[row][col-1] == '1') {
		count++;
	}
	if (row >= 0 && row <= MAX_ROW&&col+1 >= 0 && col+1 <= MAX_COL&&mine_map[row][col+1] == '1') {
		count++;
	}
	if (row+1 >= 0 && row+1 <= MAX_ROW&&col-1 >= 0 && col-1 <= MAX_COL&&mine_map[row+1][col-1] == '1') {
		count++;
	}
	if (row+1 >= 0 && row+1 <= MAX_ROW&&col >= 0 && col <= MAX_COL&&mine_map[row+1][col] == '1') {
		count++;
	}
	if (row+1 >= 0 && row+1 <= MAX_ROW&&col+1 >= 0 && col+1 <= MAX_COL&&mine_map[row+1][col+1] == '1') {
		count++;
	}
	show_map[row][col] = '0'+count;//判断完地雷个数显示在坐标上
}
int Is_Win(char show_map[MAX_ROW][MAX_COL]) {//判断玩家是否胜利
	int row;
	int col;
	int count=0;
	for (row = 0; row < MAX_ROW; ++row) {
		for (col = 0; col < MAX_COL; ++col) {
			if (show_map[row][col] == '*') {
				count++;//如果有未翻开的牌子则计数加一
			}
		}
	}
	return count;//返回计数值
}
void GAME(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {//游戏函数
	init(show_map, mine_map);//先初始化数组
	Mine_count(mine_map);//初始化地雷
	//Print_map(mine_map);//TODO     为了测试添加的地雷分布图
	while (1) {
		Print_map(show_map);
		printf("请输入您的坐标(行 列):");
		int row;
		int col;
		int i;//遍历时候的行
		int j;//遍历时候的列
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {//判断坐标的合法性
			printf("您输入的坐标有误,请重新输入");
			continue;
		}
		else if (mine_map[row][col] == '1'){//如果踩雷直接结束游戏
			printf("您失败了\n");
			Print_map(mine_map);
			break;
		}
		else if (show_map[row][col] != '*') {//判断输入坐标的合法性
			printf("您输入的坐标已经翻开过,请重新输入\n");
			continue;
		}
		int IsWin = Is_Win(show_map);//接收函数的返回值,如果返回值大于0则继续游戏,如果返回值等于零,玩家胜利
		if (IsWin == 0) {
			printf("恭喜你胜利了!");
		}
		Show_Mine(show_map, mine_map, row, col);
		system("cls");//输入完以后清屏
	}
}

void menu() {
	printf("==============\n");
	printf("==1.开始游戏==\n");
	printf("==0.退出游戏==\n");
	printf("==============\n");
	printf("请输入您的选项:");
}
int main() {
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	while (1) {
		int ret;
		menu();
		scanf("%d", &ret);
		if (ret == 1) {
		GAME(show_map, mine_map);
		}
		else if (ret == 0) {
			printf("Goodbay");
			return 0;
		}
		else {
			printf("您输入的选项有误,请重新输入");
			continue;
		}
	}
	system("pause");
	return 0;
}