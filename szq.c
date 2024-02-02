#define _CRT_SECURE_NO_WARNINGS 1
#include "szq.h"
void initboard(char board[ROW][COL], int row, int col)//��ʼ������
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
void displayboard(char board[ROW][COL], int row, int col)//��ӡ����
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
void player(char board[ROW][COL], int row, int col)//���
{
	int x, y;
	printf("�������ˣ�\n");
	while (1)
	{
		printf("������Ҫ�µ�����(x_y)��");
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
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("������������ԣ�\n");
		}
	}
}
void computer(char board[ROW][COL], int row, int col)
{
	printf("�����ߣ�\n");
	while (1)
	{
		int x, y;
		x = rand() % row;//�����
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
	for (i = 0; i < row; i++)//��
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//��
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//��
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[3][1] && board[1][1] != ' ')//Ʋ
	{
		return board[1][1];
	}
	if (1 == full(board, ROW, COL))//��
	{
		return 'P';
	}
	return 'C';
}