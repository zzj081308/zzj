#define _CRT_SECURE_NO_WARNINGS 1
#include "szq.h"
void initboard(char board[ROW][COL], int row, int col)//初始化棋盘
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i, j; 
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void player(char board[ROW][COL], int row, int col)//玩家
{
	int x, y;
	printf("该你走了：\n");
	while (1)
	{
		printf("请输入要下的坐标(x_y)：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标错误，请重试！\n");
		}
	}
}
void computer(char board[ROW][COL], int row, int col)
{
	printf("电脑走：\n");
	while (1)
	{
		int x, y;
		x = rand() % row;//随机数
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int full(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char win(char board[ROW][COL], int row, int col)
{
	int i;
	for (i = 0; i < row; i++)//横
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//纵
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//捺
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[3][1] && board[1][1] != ' ')//撇
	{
		return board[1][1];
	}
	if (1 == full(board, ROW, COL))//满
	{
		return 'P';
	}
	return 'C';
}