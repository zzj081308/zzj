#define _CRT_SECURE_NO_WARNINGS 1
#include "szq.h"
void menu()//�˵�
{
	printf("*************************************\n");
	printf("**********1. play   0. exit**********\n");
	printf("*************************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };//����
	char I;
	initboard(board, ROW, COL);//��ʼ������
	displayboard(board, ROW, COL);//��ӡ����
	while (1)
	{
		player(board, ROW, COL);//���
		displayboard(board, ROW, COL);
		I = win(board, ROW, COL);//�ж�
		if (I != 'C')
		{
			break;
		}
		computer(board, ROW, COL);///����
		displayboard(board, ROW, COL);
		I = win(board, ROW, COL);//�ж�
		if (I != 'C')
		{
			break;
		}
	}
	if (I == '*')
	{
		printf("��Ӯ�ˣ�\n");
	}
	else if (I == '#')
	{
		printf("�����ˣ�\n");
	}
	else if(I == 'P')
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("�����룺");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("��Ϸ��ʼ\n");
			game();
			break;
		}
		case 0:
		{
			printf("�ټ���\n");
			break;
		}
		default:
		{
			printf("����������������룡\n");
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