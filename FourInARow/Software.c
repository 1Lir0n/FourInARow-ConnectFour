#define _CRT_SECURE_NO_WARNINGS
#include "Software.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

void printASCII() {
	for (int i = 0; i <= 255; i++) {
		printf("%d: %c\n", i, i);
	}
}

void ClearConsole() {
	system("cls");
}

void clear() {
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF);//remove any lingering data in line
}

