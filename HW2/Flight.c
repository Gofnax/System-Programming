
#include <stdio.h>
#include <stdlib.h>

#include "Flight.h"

void   initFlight(Flight* pFlight, Plane* pPlane,const AirportManager* pManager)
{
	if(pFlight == NULL || pPlane == NULL || pManager == NULL)
		return;
	Airport* srcAirport;
	Airport* desAirport;
	char* code;

	while (1)
	{
		printf("Enter code of origin airport:   \n");
		code = myGets(code, IATA_LEN + 2);
		if (checkCode(code) != 0 && findAirportByCode(pManager, code) != NULL)
		{
			srcAirport = findAirportByCode(pManager, code);
			strcpy(pFlight->srcCode, srcAirport->code);
			break;
		}
		else
			printf("No airport with this code - try again\n");
	}
	while (1)
	{
		printf("Enter code of destination airport: \n");
		code = myGets(code, IATA_LEN + 2);
		if (checkCode(code) != 0 && findAirportByCode(pManager, code) != NULL)
		{
			if(strcmp(pFlight->srcCode, code))
			{
				desAirport = findAirportByCode(pManager, code);
				strcpy(pFlight->desCode, desAirport->code);
				break;
			}
			else
			{
				printf("Same origin and destination airport\n");
			}
		}
		else
			printf("No airport with this code - try again\n");
	}

	
	getCorrectDate(&pFlight->theDate);

	if (isPlaneValid(pPlane))
		memcpy(&pFlight->thePlane, pPlane, sizeof(Plane));
	else
		printf("Invalid plane for initFlight\n");

}

void freeFlight(Flight* pFlight)
{
	if (pFlight != NULL)
	{
		free(pFlight);
	}
}

int isFlightFromSourceAirport(const Flight* pFlight, char* code)
{
	if (pFlight->srcCode == code)
		return 1;
	else return 0;
}

int isFlightToDesAirport(const Flight* pFlight, char* code)
{
	if (pFlight->desCode == code)
		return 1;
	else return 0;
}

int isPlaneTypeInFlight(const Flight* pFlight, planeType type)
{
	if (pFlight->thePlane.type == type)
		return 1;
	else return 0;
}

void printFlight(const Flight* pFlight)
{
	Date date = pFlight->theDate;
	printf("Flight From %s To %s\t",pFlight->srcCode, pFlight->desCode);
	printDate(&date);
	printf(" ");
	printPlane(&pFlight->thePlane);
}

//int setSrcAirport(Airport* airport, Flight* pFlight,const AirportManager* pManager)
//{
//	if (doesAirportExist(pManager, airport) == 1)
//	{
//		int airportIndex = doesAirportExist(pManager, airport);
//		pFlight->srcCode == pManager->airportArr[airportIndex]->code;
//		return 1;
//	}
//	else return 0;
//}

//int setDesAirport(Airport* airport, Flight* pFlight, const AirportManager* pManager)
//{
//	if (doesAirportExist(pManager, airport) == 1)
//	{
//		int airportIndex = doesAirportExist(pManager, airport);
//		pFlight->desCode == pManager->airportArr[airportIndex]->code;
//		return 1;
//	}
//	else return 0;
//}

//int setDesAirport(char* code,Airport* airport, Flight* pFlight, const AirportManager* pManager)
//{
//	
//	if (findAirportByCode(pManager, code) != NULL)
//	{
//		airport = findAirportByCode(pManager, code);
//		pFlight->desCode == airport->code;
//		return 1;
//	}
//	else return 0;
//}

//int setSrcAirport(char* code, Airport* airport, Flight* pFlight, const AirportManager* pManager)
//{
//
//	if (findAirportByCode(pManager, code) != NULL)
//	{
//		airport = findAirportByCode(pManager, code);
//		pFlight->srcCode == airport->code;
//		return 1;
//	}
//	else return 0;
//}