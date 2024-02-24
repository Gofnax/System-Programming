#include "AirportManager.h"

int initManager(AirportManager* manager)
{
	manager->numOfAirports = 0;
	manager->airportArr = NULL;
	return 1;
}

int addAirport(AirportManager* pManager)
{
	if(pManager == NULL)
		return 0;

	pManager->airportArr = realloc(pManager->airportArr, (pManager->numOfAirports + 1) * sizeof(Airport*));
	if (pManager->airportArr == NULL)
		return 0;

	Airport* pAirport = (Airport*)malloc(sizeof(Airport));
	if(pAirport == NULL)
		return 0;

	int codeInUse = 0;
	do
	{
		getAirportCode(pAirport->code);
		codeInUse = doesAirportExist(pManager, pAirport);
		if(codeInUse)
		    printf("This code already in use - enter a different code\n");
	}while(codeInUse);
	
	initAirportNoCode(pAirport);
	pManager->airportArr[pManager->numOfAirports++] = pAirport;
	return 1;
}

Airport* findAirportByCode(const AirportManager* manager, char* code)
{
	for (int i = 0; i < manager->numOfAirports; i++) {
		if (manager->airportArr[i]->code == code)
		{
			return manager->airportArr[i];
		}
	}
	return NULL;
}
void printAirports(const AirportManager* pManager)
{
	printf("there are %d airports\n", pManager->numOfAirports);
	for (int i = 0; i < pManager->numOfAirports; i++)
	{
		printAirport(pManager->airportArr[i]);
	}
}
int doesAirportExist(const AirportManager* pManager,Airport* pAirport)
{
    if(pManager == NULL || pAirport == NULL)
        return 0;
    
	for (int i = 0; i < pManager->numOfAirports; i++)
	{
		if (isSameAirport(pAirport, pManager->airportArr[i]) == 1)
		{
			return 1;
		}
		else return 0;
	}
}

void freeAirportManager(AirportManager* pManager)
{
	if (pManager != NULL)
	{
		for (int i = 0; i < pManager->numOfAirports; i++)
		{
			freeAirport(pManager->airportArr[i]);
		}
	}
}

void freeManager(AirportManager* pManager)
{
	freeAirportManager(pManager);
}