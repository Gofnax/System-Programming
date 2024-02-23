
#include <stdio.h>
#include <stdlib.h>

#include "Flight.h"

void   initFlight(Flight* pFlight, Plane* thePlane,const AirportManager* pManager)
{
	Airport* srcAirport;
	Airport* desAirport;
	char code[IATA_LEN + 1];
	/*char inDate[13];*/

	while (1)
	{
		printf("Enter code of origin airport: \n");
		fgets(code, sizeof(code), stdin);
		if (checkCode(code) != 0 && findAirportByCode(pManager ,code ) != NULL)
		{
			//strncpy(pFlight->srcCode, code, IATA_LEN);
			srcAirport = findAirportByCode(pManager, code);
			//setSrcAirport(code, srcAirport, pFlight, pManager);
			strcpy(pFlight->srcCode, srcAirport->code);
			//pFlight->srcCode == srcAirport->code;
			break;
		}
		else printf("No airport with this code - try again");
	}
	while (1)
	{
		printf("Enter code of destination airport: \n");
		fgets(code, sizeof(code), stdin);
		if (checkCode(code) != 0 && findAirportByCode(pManager, code) != NULL)
		{
			//strncpy(pFlight->desCode, code, IATA_LEN);
			desAirport = findAirportByCode(pManager, code);
			//setDesAirport(code, desAirport, pFlight, pManager);
			strcpy(pFlight->desCode, desAirport->code);
			//pFlight->desCode == desAirport->code;
			break;
		}
		else printf("No airport with this code - try again");
	}

	
	getCorrectDate(&pFlight->theDate);
	/*while (1)
	{
		printf("Enter Flight Date dd##mm##yyyy  minimum year 2022\n");
		fgets(inDate, sizeof(inDate), stdin);
		initDate(&(pFlight->theDate), inDate);
		if (isDateValid(&pFlight->theDate, inDate))
			break;
		else printf("Error try again\n");
	}*/

	if (isPlaneValid(thePlane))
		pFlight->thePlane = *thePlane; //missing else , in case the plane isn't valid

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