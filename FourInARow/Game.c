#define _CRT_SECURE_NO_WARNINGS

#include "Game.h"
#include "Software.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>


void PrintBoard(Piece board[][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			printf("%s", board[i][j].view);
		}
		printf("\n");
	}
	printf("---------------------\n");
	printf(" 1  2  3  4  5  6  7 \n");
}

int GetPos(Piece board[][WIDTH], int* turn) {
	int x = 0;
	char str[4] = "[O]";
	char str2[4] = "[ ]";
	str2[1] = 254;

	Piece p = { "color",x,0,"[ ]" };
	if (CheckFull(board)) {
		printf("Board is FULL! Game ended with a DRAW!\n");
		return 1;
	}
	if (*turn) {
		printf("Black's Turn:\n");
		printf("Please Enter the number corresponding to the column you want to place a piece.\n");
		scanf("%d", &x);
		if (x < 1 || x > WIDTH) {
			printf("Invalid column. Please try again.\n");
			return 0;
		}
		p.color = "Black";
		p.view = str;
	}
	else {
		printf("White's Turn:\n");
		printf("Please Enter the number corresponding to the column you want to place a piece.\n");
		scanf("%d", &x);
		if (x < 1 || x > WIDTH) {
			printf("Invalid column. Please try again.\n");
			return 0;
		}
		p.color = "White";
		p.view = str2;
	}

	int result = AddPiece(x, board, p);
	if (result == ERROR) {
		printf("Column is full. Please try again.\n");
		return 0;
	}
	else
		*turn = !*turn;

	ClearConsole();
	PrintBoard(board);
	if (CheckWin(board, p)) {
		printf("%s %s Won!", p.color, p.view);
		return 1;
	}
	return 0;
}

int AddPiece(int x, Piece board[][WIDTH], Piece p) {
	for (int i = 0; i < HEIGHT; i++) {
		if (board[i][x - 1].color != "none")
			if (i == 0) return ERROR;
			else {
				p.y = i;
				p.x = x - 1;
				board[i - 1][x - 1] = p;
				return 0;
			}
		if (i == HEIGHT - 1) {
			p.y = i;
			p.x = x - 1;
			board[i][x - 1] = p;
			return 0;
		}
	}
	return ERROR;
}

void FillEmptyBoard(Piece board[][WIDTH]) {
	Piece mt = { "none",0,0,"[ ]" };
	for (int i = 0; i < HEIGHT; i++) {
		mt.y = i;
		for (int j = 0; j < WIDTH; j++) {
			mt.x = j;
			board[i][j] = mt;
		}
	}
}

int CheckWin(Piece board[][WIDTH], Piece target) {
	int directions[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
	int len = sizeof(directions) / sizeof(directions[0]);

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (strcmp(board[i][j].color, target.color) == 0) {
				for (int d = 0; d < len; d++) {
					if (Check4(board, i, j, target, 0, directions[d][0], directions[d][1])) {
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int IsVaildCell(int row, int col) {
	return (row >= 0 && col >= 0 && row < HEIGHT && col < WIDTH);
}

int Check4(Piece board[][WIDTH], int row, int col, Piece target, int count, int dirX, int dirY) {
	if (count == 4)
		return 1;
	if (!IsVaildCell(row, col) || strcmp(board[row][col].color, target.color) != 0)
		return 0;
	return Check4(board, row + dirX, col + dirY, target, count + 1, dirX, dirY);
}

int play(Piece board[][WIDTH], int* turn) {
	*turn = 0;
	ClearConsole();
	FillEmptyBoard(board);
	PrintBoard(board);
	while (!GetPos(board, turn)) {

	}
	Rematch(board, turn);
	return 0;
}

int Rematch(Piece board[][WIDTH], int* turn) {
	char ch = ' ';
	clear();

	printf("\nWant to play again? (y/n)\n");
	scanf("%c", &ch);
	if (ch == 'y') play(board, turn);
	else return 0;
	return 0;
}

int CheckFull(Piece board[][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (strcmp(board[i][j].color, "none") == 0)
				return 0;
		}
	}
	return 1;
}