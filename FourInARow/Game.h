#define _CRT_SECURE_NO_WARNINGS

#ifndef Game

#define Game
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define HEIGHT 6
#define WIDTH 7
#define ERROR -1


typedef struct Piece {
	char* color;
	int x;
	int y;
	char* view;
}Piece;


void PrintBoard(Piece board[][WIDTH]);
int GetPos(Piece board[][WIDTH], int* turn);
int AddPiece(int x, Piece board[][WIDTH], Piece p);
void FillEmptyBoard(Piece board[][WIDTH]);
int CheckWin(Piece board[][WIDTH], Piece target);
int Check4(Piece board[][WIDTH], int row, int col, Piece target, int count, int dirX, int dirY);
int IsVaildCell(int row, int col);
int Rematch(Piece board[][WIDTH], int* turn);
int play(Piece board[][WIDTH], int* turn);
int CheckFull(Piece board[][WIDTH]);

#endif //Game