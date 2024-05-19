#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include "Game.h"
#include "Software.h"




int main() {
	Piece Board[HEIGHT][WIDTH];
	int turn;	
	//printASCII();
	play(Board,&turn);
	return 0;
}

