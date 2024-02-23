#include "AirportManager.h"

int initManager(AirportManager* manager)
{
	manager->numOfAirports = 0;
	manager->airportArr = NULL;
	return 1;
}

int addAirpot(AirportManager* pManager, Airport* airport)
{
	if (doesAirportExist(pManager, airport) == 0)
		return 0;

	Airport** newAirportArr = realloc(pManager->airportArr, (pManager->numOfAirports + 1) * sizeof(Airport*));
	if (newAirportArr == NULL)
		return 0;

	strncpy(newAirportArr[pManager->numOfAirports]->name, airport->name, strlen(airport->name));
	strncpy(newAirportArr[pManager->numOfAirports]->country, airport->country, strlen(airport->country));
	strncpy(newAirportArr[pManager->numOfAirports]->code, airport->code, IATA_LEN);

	pManager->airportArr = newAirportArr;
	pManager->numOfAirports++;

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
int doesAirportExist(const AirportManager* pManager,Airport* airport)
{
	for (int i = 0; i < sizeof(pManager->airportArr); i++)
	{
		if (isSameAirport(airport, pManager->airportArr[i]) == 1)
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
		free(pManager);
	}
}
