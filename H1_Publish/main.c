#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#include "sudoku.h"
#include "pictureLines.h"
#include "pictureManipulation.h"


int main()
{

	char option = 0;
	srand((unsigned)12345); //just for testing

	printf("\n\n");
	printf("Please choose one of the following options:\n");
	printf("S/s - Sudoku\n");
	printf("A/a - All Lines\n");
	printf("P/p - Picture Manipulation\n");
	printf("E/e - Exit\n");

	scanf("%c", &option);
	
	switch (option)
	{
	case 1:
		sudokuGame();
		break;

	case 2:
		addLines();
		break;

	case 3:
		pictureManipulation();
		break;

	case -1:
		break;
	}
}
