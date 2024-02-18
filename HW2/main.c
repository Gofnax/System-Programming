#include <stdio.h>
#include "airline.h"
#include "airport.h"
#include "date.h"
#include "flight.h"
#include "plane.h"
#include "airportmanager.h"

int main(void)
{
    //initAirportManager();
    //initAirline();
    char option = 0, buffer = 0;

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

				break;
			case 'a':

				break;
			case 'p':

				break;
			case 'e':
            
				break;
			default:
				printf("Wrong option\n");
		}
		scanf("%c", &buffer);	//buffer cleaning
	}while((option != 'e') && (option != 'E'));
}