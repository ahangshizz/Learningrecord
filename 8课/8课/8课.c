//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#define ROW 3
//#define COL 3
//void init_body(char arr[ROW][COL])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			arr[i][j] = ' ';
//		}
//	}
//}
//int check_full(char arr[ROW][COL])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if (arr[i][j] == ' ')
//				return 0;
//		}
//	}return 1;
//}
//void display_body(char arr[ROW][COL])
//{
//	int i = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
//		if (i != 2)
//			printf("---|---|---\n");
//	}
//}
//void  player_move(char arr[ROW][COL])
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入坐标：");
//	scanf("%d%d", &x, &y);
//	x--;
//	y--;
//	while (1)
//	{
//		if (arr[x][y] == ' ')
//		{
//			arr[x][y] = 'X';
//			break;
//		}
//		else
//		{
//			printf("您输入的坐标被占用了哦！！\n");
//			break;
//		}
//	}
//}
//void computer_move(char arr[ROW][COL])
//{
//	int x = 0;
//	int y = 0;
//	srand((unsigned int)time(NULL));
//	while (1)
//	{
//		x = rand() % 3;
//		y = rand() % 3;
//		if (arr[x][y] == ' ')
//		{
//			arr[x][y] = '0';
//			break;
//		}
//		else
//		{
//			if (check_full(arr) == 0)
//			{
//				continue;
//			}
//			else
//			{
//				printf("这局游戏你们平局");
//				break;
//			}
//		}
//	}
//}
//char  check_win(char arr[ROW][COL])
//{
//	int i = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]))
//		{
//			return arr[i][0];
//		}
//	}
//	for (i = 0; i < COL; i++)
//	{
//		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
//		{
//			return arr[0][i];
//		}
//	}
//	if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]))
//	{
//		return arr[0][0];
//	}
//	if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]))
//	{
//		return arr[1][1];
//	}
//	return ' ';
//}
//int main()
//{
//	char arr[ROW][COL] = { 0 };
//	char ret = 0;
//	init_body(arr);
//	do
//	{
//		display_body(arr);
//		player_move(arr);
//		display_body(arr);
//		if ((ret = check_win(arr)) != ' ')
//			break;
//		computer_move(arr);
//		ret = check_win(arr);
//	} while (ret == ' ');
//	if (ret == 'X')
//	{
//		printf("恭喜您赢的游戏\n");
//	}
//	else if (ret == '0')
//	{
//		printf("电脑获胜，不要灰心，再接再厉\n");
//	}
//
//	return 0;
//}

#include <stdio.h>
#include <assert.h>
void my_strcpy(char *b, char *a)
{
	assert(b != NULL);//assert   断言，    不满足条件无法向下执行！！！！！！！！！！！
	assert(a != NULL);
	while (*a != '\0')
	{
		*b++ = *a++;
	}*b = *a;
}
int main()
{
	char a[] = "bit-tech";
	char b[10];
	my_strcpy(b,a);
	printf("%s\n", b);
	return 0;
}