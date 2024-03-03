#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AirportManager.h"
#include "General.h"

int	initManager(AirportManager* pManager)
{
	return L_init(&pManager->airportsList);
}

int	addAirport(AirportManager* pManager)
{
	Airport* pPort  = (Airport*)calloc(1, sizeof(Airport));
	if (!pPort)
		return 0;

	if (!initAirport(pPort, pManager))
	{
		freeAirport(pPort);
		free(pPort);
		return 0;
	}

	NODE* tmp = &pManager->airportsList.head;
	while(tmp->next != NULL && strcmp(pPort->code, ((Airport*)(tmp->next->key))->code) >= 0)
	{
		tmp = tmp->next;
	}
	tmp = L_insert(tmp, pPort);
	if(!tmp)
	{
		freeAirport(pPort);
		free(pPort);
		return 0;
	}
	
	return 1;
}

int  initAirport(Airport* pPort, AirportManager* pManager)
{
	while (1)
	{
		getAirportCode(pPort->code);
		if (checkUniqeCode(pPort->code, pManager))
			break;

		printf("This code already in use - enter a different code\n");
	}

	return initAirportNoCode(pPort);
}

Airport* findAirportByCode(const AirportManager* pManager, const char* code)
{
	Airport tmpAirport = {.name = "tmp", .country = "tmp"};
	(void)strcpy(tmpAirport.code, code);

	const NODE* tmp = L_find(&(pManager->airportsList.head), (Airport*)&tmpAirport, isSameAirport);
	if(tmp != NULL)
		return (Airport*)(tmp->key);
	return NULL;
}

int checkUniqeCode(const char* code,const AirportManager* pManager)
{
	Airport* port = findAirportByCode(pManager, code);

	if (port != NULL)
		return 0;

	return 1;
}

void	printAirports(const AirportManager* pManager)
{
	if(pManager == NULL)
		return;
	const NODE* tmp = &pManager->airportsList.head;
	int airportCount = getNumOfAirports(pManager);
	printf("there are %d airports\n", airportCount);
	for (int i = 0; i < airportCount; i++)
	{
		tmp = tmp->next;
		printAirport((Airport*)(tmp->key));
		printf("\n");
	}
}

int	getNumOfAirports(const AirportManager* pManager)
{
	if(pManager == NULL)
		return 0;
	int airportCount = 0;
	const NODE* tmp = &pManager->airportsList.head;
	while(tmp->next != NULL)
	{
		airportCount++;
		tmp = tmp->next;
	}
	return airportCount;
}

void	freeManager(AirportManager* pManager)
{
	(void)L_free(&pManager->airportsList, freeAirport);
}