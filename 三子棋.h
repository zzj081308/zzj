#include <stdio.h>
#define ROW 3
#define COL 3
#include <stdlib.h>
#include <time.h>
void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void player(char board[ROW][COL], int row, int col);
void computer(char board[ROW][COL], int row, int col);
char win(char board[ROW][COL], int row, int col);
int full(char board[ROW][COL], int row, int col);