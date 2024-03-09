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

int addPlane(Airline* pComp)
{
	pComp->planeArr = (Plane*)realloc(pComp->planeArr, (pComp->planeCount + 1) * sizeof(Plane));
	if (!pComp->planeArr)
		return 0;
	initPlane(&pComp->planeArr[pComp->planeCount], pComp->planeArr, pComp->planeCount);
	pComp->planeCount++;
	pComp->currentSort = eNoSort;
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

int	compareBySrcCode(const void* v1, const void* v2)
{
	const Flight* pFlight1 = *(const Flight**)v1;
	const Flight* pFlight2 = *(const Flight**)v2;
	return strcmp(pFlight1->sourceCode, pFlight2->sourceCode);
}

int	compareByDstCode(const void* v1, const void* v2)
{
	const Flight* pFlight1 = *(const Flight**)v1;
	const Flight* pFlight2 = *(const Flight**)v2;
	return strcmp(pFlight1->destCode, pFlight2->destCode);
}

int	compareByDate(const void* v1, const void* v2)
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

void sortFlight(Airline* pComp)
{
	if(pComp == NULL)
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
			sortFlightsArr(pComp, compareBySrcCode);
			break;
		case 2:	//sortByDst
			sortFlightsArr(pComp, compareByDstCode);
			break;
		case 3:	//sortByDate
			sortFlightsArr(pComp, compareByDate);
	}
	pComp->currentSort = (eSortTypes)userChoice;
	printf("Done sorting\n");
}

Flight*	searchForFlight(const Airline* pAirline, Flight** pFlight)
{
	if(pAirline == NULL || pFlight == NULL)
		return NULL;
	switch((int)pAirline->currentSort)
	{
		case 1:
			return *(Flight**)bsearch(pFlight, pAirline->flightArr, pAirline->flightCount,
					sizeof(Flight*), compareBySrcCode);
			break;
		case 2:
			return *(Flight**)bsearch(pFlight, pAirline->flightArr, pAirline->flightCount,
					sizeof(Flight*), compareByDstCode);
			break;
		case 3:
			return *(Flight**)bsearch(pFlight, pAirline->flightArr, pAirline->flightCount,
					sizeof(Flight*), compareByDate);
			break;
		default:
			printf("The search cannot be perdormed, array not sorted 3\n");
	}
	return NULL;
}

void findFlight(const Airline* pComp)
{
	if(pComp == NULL)
		return;

	Flight tmpFlight;
	Flight** res = NULL;
	Flight* pTmpFlight;
	switch((int)pComp->currentSort)
	{
		case 1:
			printf("Origin: ");
			getAirportCode(tmpFlight.sourceCode);
			pTmpFlight = &tmpFlight;
			res = (Flight**)bsearch(&pTmpFlight, pComp->flightArr, pComp->flightCount, sizeof(Flight*), compareBySrcCode);
			break;
		case 2:
			printf("Destination: ");
			getAirportCode(tmpFlight.destCode);
			pTmpFlight = &tmpFlight;
			res = (Flight**)bsearch(&pTmpFlight, pComp->flightArr, pComp->flightCount, sizeof(Flight*), compareByDstCode);
			break;
		case 3:
			printf("Date: ");
			getCorrectDate(&tmpFlight.date);
			pTmpFlight = &tmpFlight;
			res = (Flight**)bsearch(&pTmpFlight, pComp->flightArr, pComp->flightCount, sizeof(Flight*), compareByDate);
			break;
		default:
			printf("The search cannot be perdormed, array not sorted\n");
	}
	if(res == NULL)
	{
		printf("Flight not found\n");
	}
	else
	{
		printf("Flight found:\n");
		printFlight(*res);
	}
}

int saveAirlineToFile(const Airline* pComp, const char* fileName)
{
	FILE* fp = fopen(fileName, "wb");
	if(!fp)
		return 0;
	int len = (int)strlen(pComp->name) + 1;
	if(fwrite(&len, sizeof(int), 1, fp) != 1)
	{
		fclose(fp);
		return 0;
	}
	if((int)fwrite(pComp->name, sizeof(char), len, fp) != len)
	{
		fclose(fp);
		return 0;
	}
	if(fwrite(&pComp->planeCount, sizeof(int), 1, fp) != 1)
	{
		fclose(fp);
		return 0;
	}
	for(int i = 0; i < pComp->planeCount; i++)
	{
		if(savePlaneToBinaryFile(fp, pComp->planeArr[i]) == 0)
		{
			fclose(fp);
			return 0;
		}
	}
	if(fwrite(&pComp->flightCount, sizeof(int), 1, fp) != 1)
	{
		fclose(fp);
		return 0;
	}
	for(int i = 0; i < pComp->planeCount; i++)
	{
		if(saveFlightToBinaryFile(fp, pComp->flightArr[i]) == 0)
		{
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	return 1;
}

int initAirlineFromFile(Airline* pComp, AirportManager* pManager, const char* fileName)
{
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL)
		return 0;
	int len = 0;
	if((int)fread(&len, sizeof(int), 1, fp) != 1)
		return 0;
	pComp->name = (char*)malloc(len * sizeof(char));
	if ((int)fread(pComp->name, sizeof(char), len, fp) != len)
	{
		free(pComp->name);
		return 0;
	}
	if((int)fread(&pComp->planeCount, sizeof(int), 1, fp) != 1)
	{
		free(pComp->name);
		return 0;
	}
	pComp->planeArr = (Plane*)malloc(pComp->planeCount * sizeof(Plane));
	if(pComp->planeArr == NULL)
		return 0;
	for(int i = 0; i < pComp->planeCount; i++)
	{
		if(initPlaneFromFile(fp, &pComp->planeArr[i]) == 0)
		{
			free(pComp->name);
			free(pComp->planeArr);
			return 0;
		}
	}
	if((int)fread(&pComp->flightCount, sizeof(int), 1, fp) != 1)
	{
		free(pComp->name);
		free(pComp->planeArr);
		return 0;
	}
	pComp->flightArr = (Flight**)malloc(pComp->flightCount * sizeof(Flight*));
	if(pComp->flightArr == NULL)
		return 0;
	for(int i = 0; i < pComp->flightCount; i++)
	{
		pComp->flightArr[i] = (Flight*)calloc(1, sizeof(Flight));
		if(initFlightFromFile(fp, pComp->flightArr[i], pComp->planeArr, pComp->planeCount) == 0)
		{
			free(pComp->name);
			free(pComp->planeArr);
			freeFlightArr(pComp->flightArr, i);
			free(pComp->flightArr);
			return 0;
		}
		Flight* tmpPFlight = pComp->flightArr[i];
		Airport* srcAirport = findAirportByCode(pManager, tmpPFlight->sourceCode);
		Airport* dstAirport = findAirportByCode(pManager, tmpPFlight->destCode);
		if(srcAirport == NULL || dstAirport == NULL)
			return 0;
	}
	fclose(fp);
	return 1;
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
