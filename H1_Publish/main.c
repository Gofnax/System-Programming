#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#include "sudoku.h"
#include "pictureLines.h"
//#include "pictureManipulation.h"


int main()
{
	char option = 0, buffer = 0;
	srand((unsigned)12345); //just for testing

	do
	{
		printf("\n\n");
		printf("Please choose one of the following options:\n");
		printf("S/s - Sudoku\n");
		printf("A/a - All Lines\n");
		printf("P/p - Picture Manipulation\n");
		printf("E/e - Exit\n");

		scanf("%c", &option);
		
		switch (option)
		{	
			case 's':
			case 'S':
				checkSudoku();
				break;
			case 'a':
			case 'A':
				addLines();
				break;
			case 'p':
			case 'P':
				//pictureManipulation();
				break;
			case 'e':
			case 'E':
				printf("Bye bye\n");
				break;
			default:
				printf("Wrong option\n");
		}
		scanf("%c", &buffer);	//buffer cleaning
	}while((option != 'e') && (option != 'E'));
}
