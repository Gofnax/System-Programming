#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Airline.h"
#include "Airport.h"
#include "General.h"

static const char* SortTypeStr[eNofSorts]
		= { "Not Sorted", "Sorted by Source Code", "Sorted by Destination Code", "Sorted by Date" };

void	initAirline(Airline* pComp)
{
	//printf("-----------  Init Airline\n");
	pComp->name = getStrExactName("Enter Airline name");
	pComp->flightArr = NULL;
	pComp->flightCount = 0;
	pComp->planeArr = NULL;
	pComp->planeCount = 0;
	pComp->currentSort = eNoSort;
}

int	addFlight(Airline* pComp, const AirportManager* pManager)
{
	int airportCount = getNumOfAirports(pManager);
	if (airportCount < 2)
	{
		printf("There are not enough airport to set a flight\n");
		return 0;
	}
	if(pComp->planeCount == 0)
	{
		printf("There is no plane in company\n");
		return 0;
	}

	Flight* pFlight = (Flight*)calloc(1, sizeof(Flight));
	if (!pFlight)
		return 0;
	
	Plane* thePlane = FindAPlane(pComp);
	printAirports(pManager);
	initFlight(pFlight, thePlane, pManager);

	pComp->flightArr = (Flight**)realloc(pComp->flightArr, (pComp->flightCount + 1) * sizeof(Flight*));
	if (!pComp->flightArr)
	{
		free(pFlight);
		return 0;
	}
	pComp->flightArr[pComp->flightCount] = pFlight;
	pComp->flightCount++;
	return 1;
}

int		addPlane(Airline* pComp)
{
	pComp->planeArr = (Plane*)realloc(pComp->planeArr, (pComp->planeCount + 1) * sizeof(Plane));
	if (!pComp->planeArr)
		return 0;
	initPlane(&pComp->planeArr[pComp->planeCount], pComp->planeArr, pComp->planeCount);
	pComp->planeCount++;
	return 1;
}

Plane* FindAPlane(Airline* pComp)
{
	printf("Choose a plane from list, type its serial Number\n");
	printPlanesArr(pComp->planeArr,pComp->planeCount);
	int sn;
	Plane* temp = NULL;
	do {
		scanf("%d", &sn);
		temp = findPlaneBySN(pComp->planeArr,pComp->planeCount, sn);
		if (!temp)
			printf("No plane with that serial number! Try again!\n");
	} while (temp == NULL);
	 
	return temp;
}


void printCompany(const Airline* pComp)
{
	printf("Airline %s\n", pComp->name);
	printf("\n -------- Has %d planes\n", pComp->planeCount);
	printPlanesArr(pComp->planeArr, pComp->planeCount);
	printf("\n\n -------- Has %d flights %s\n", pComp->flightCount, SortTypeStr[pComp->currentSort]);
	printFlightArr(pComp->flightArr, pComp->flightCount);
}

void	printFlightArr(Flight** arr, int size)
{
	for (int i = 0; i < size; i++)
		printFlight(arr[i]);
}

void	printPlanesArr(Plane* arr, int size)
{
	for (int i = 0; i < size; i++)
		printPlane(&arr[i]);
}

void	doPrintFlightsWithPlaneType(const Airline* pComp)
{
	ePlaneType type = getPlaneType();
	int count = 0;
	printf("Flights with plane type %s:\n", GetPlaneTypeStr(type));
	for (int i = 0; i < pComp->flightCount; i++)
	{
		if (isPlaneTypeInFlight(pComp->flightArr[i], type))
		{
			printFlight(pComp->flightArr[i]);
			count++;
		}
	}
	if(count == 0)
		printf("Sorry - could not find a flight with plane type %s:\n", GetPlaneTypeStr(type));
	printf("\n");
}

int	compareBySrcCodeForQSort(const void* v1, const void* v2)
{
	const Flight* pFlight1 = *(const Flight**)v1;
	const Flight* pFlight2 = *(const Flight**)v2;
	return strcmp(pFlight1->sourceCode, pFlight2->sourceCode);
}

int	compareByDstCodeForQSort(const void* v1, const void* v2)
{
	const Flight* pFlight1 = *(const Flight**)v1;
	const Flight* pFlight2 = *(const Flight**)v2;
	return strcmp(pFlight1->destCode, pFlight2->destCode);
}

int	compareByDstCodeForBSearch(const void* v1, const void* v2)
{
	const Flight* pFlight1 = *(const Flight**)v1;
	const Flight* pFlight2 = *(const Flight**)v2;
	return strcmp(pFlight1->destCode, pFlight2->destCode);
}

int	compareByDateForQSort(const void* v1, const void* v2)
{
	const Flight* pFlight1 = *(const Flight**)v1;
	const Flight* pFlight2 = *(const Flight**)v2;
	return compareDates(&pFlight1->date, &pFlight2->date);
}

void	sortFlightsArr(Airline* pAirline, int (*compare)(const void*, const void*))
{
	if(pAirline == NULL || compare == NULL)
		return;
	qsort(pAirline->flightArr, pAirline->flightCount, sizeof(Flight*), compare);
}

void chooseFlightSortMethod(Airline* pAirline)
{
	if(pAirline == NULL)
		return;
	
	int userChoice;
	do
	{
		printf("How do you want the flights to be sorted:\n");
		for(int i = 1; i < eNofSorts; i++)
		{
			printf("(%d - %s) ", i, SortTypeStr[i]);
		}
		printf("\n");
		scanf("%d", &userChoice);
	} while (userChoice < 1 || userChoice >= eNofSorts);
	switch(userChoice)
	{
		case 1:	//sortBySrc
			sortFlightsArr(pAirline, compareBySrcCodeForQSort);
			break;
		case 2:	//sortByDst
			sortFlightsArr(pAirline, compareByDstCodeForQSort);
			break;
		case 3:	//sortByDate
			sortFlightsArr(pAirline, compareByDateForQSort);
	}
	pAirline->currentSort = (eSortTypes)userChoice;
	printf("Done sorting\n");
}

Flight*	searchForFlight(Airline* pAirline, Flight* pFlight)
{
	if(pAirline == NULL || pFlight == NULL)
		return NULL;
	switch((int)pAirline->currentSort)
	{
		case 1:
			return (Flight*)bsearch(pFlight, pAirline->flightArr, pAirline->flightCount,
					sizeof(Flight*), compareBySrcCodeForQSort);
		case 2:
			return (Flight*)bsearch(&pFlight, pAirline->flightArr, pAirline->flightCount,
					sizeof(Flight*), compareByDstCodeForBSearch);
		case 3:
			return (Flight*)bsearch(pFlight, pAirline->flightArr, pAirline->flightCount,
					sizeof(Flight*), compareByDateForQSort);
		default:
			printf("Unable to perform search for flight\n");
	}
	return NULL;
}

void	freeFlightArr(Flight** arr, int size)
{
	for (int i = 0; i < size; i++)
		free(arr[i]);
}

void	freePlanes(Plane* arr, int size)
{
	for (int i = 0; i < size; i++)
		freePlane(&arr[i]);
}

void	freeCompany(Airline* pComp)
{
	freeFlightArr(pComp->flightArr, pComp->flightCount);
	free(pComp->flightArr);
	free(pComp->planeArr);
	free(pComp->name);
}
