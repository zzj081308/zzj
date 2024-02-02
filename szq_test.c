#define _CRT_SECURE_NO_WARNINGS 1
#include "szq.h"
void menu()//菜单
{
	printf("*************************************\n");
	printf("**********1. play   0. exit**********\n");
	printf("*************************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };//棋盘
	char I;
	initboard(board, ROW, COL);//初始化棋盘
	displayboard(board, ROW, COL);//打印棋盘
	while (1)
	{
		player(board, ROW, COL);//玩家
		displayboard(board, ROW, COL);
		I = win(board, ROW, COL);//判定
		if (I != 'C')
		{
			break;
		}
		computer(board, ROW, COL);///电脑
		displayboard(board, ROW, COL);
		I = win(board, ROW, COL);//判定
		if (I != 'C')
		{
			break;
		}
	}
	if (I == '*')
	{
		printf("你赢了！\n");
	}
	else if (I == '#')
	{
		printf("你输了！\n");
	}
	else if(I == 'P')
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("游戏开始\n");
			game();
			break;
		}
		case 0:
		{
			printf("再见！\n");
			break;
		}
		default:
		{
			printf("输入错误，请重新输入！\n");
			break;
		}
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}