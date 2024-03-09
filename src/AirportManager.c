#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "AirportManager.h"
#include "General.h"

int	initManagerFromUser(AirportManager* pManager)
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

int		saveManagerToFile(const AirportManager* pManager,const char* fileName)
{
	//char* fileName = "airport_authority.txt";
	int numOfAirports = getNumOfAirports(pManager);
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL)
	{
		printf("failed opening the file\n");
		return 0;
	}
	fprintf(fp, "%d\n", numOfAirports);

	NODE* pAirportNode = pManager->airportsList.head.next;
	while(pAirportNode != NULL)
	{
		Airport* pAirport = (Airport*)pAirportNode->key;
		fprintf(fp, "%s\n", pAirport->name);
		fprintf(fp, "%s\n", pAirport->country);
		fprintf(fp, "%s\n", pAirport->code);
		pAirportNode = pAirportNode->next;
	}

	fclose(fp);
	return 1;
}

int initManager(AirportManager* pManager, const char* fileName)
{
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) 
	{
		return 0;
	}
	if (initManagerFromUser(pManager) == 0) 
	{
		fclose(fp);
		return 0; 
	}
	int numOfAirports = 0;
	if (fscanf(fp, "%d", &numOfAirports) != 1)
	{
		//failed to get number of airports
		fclose(fp);
		if (initManagerFromUser(pManager) == 0)
		{
			return 0;
		}
		return 2;
	}
	L_init(&pManager->airportsList);
	NODE* airportNode = &pManager->airportsList.head;
	for (int i = 0; i < numOfAirports; i++)
	{
		Airport* pAirport = (Airport*)calloc(1, sizeof(Airport));
		if (pAirport == NULL)
		{
			printf("failed to allocate memory for airport");
			fclose(fp);
			return 0;
		}
		
		if (getAirportFromFile(pAirport, fp) == 0)
		{
			printf("Error loading airport from file");
			fclose(fp);
			free(pAirport);
			return 0;
		}
		L_insert(airportNode, pAirport);
		airportNode = airportNode->next;
		
	}
	
	fclose(fp);
	return 1;

}

int getAirportFromFile(Airport* pAirport, FILE* fp)
{
	if (pAirport == NULL || fp == NULL)
		return 0;

	char temp[MAX_STR_LEN] = { 0 };
	if (fscanf(fp, "%s\n", temp) != 1)
	{
		return 0;
	}
	pAirport->name = strdup(temp);
	if (fscanf(fp, "%s\n", temp) != 1)
	{
		return 0;
	}
	pAirport->country = strdup(temp);
	if (fscanf(fp, "%s\n", temp) != 1)
	{
		return 0;
	}
	strncpy(pAirport->code, temp, IATA_LENGTH + 1);

	return 1;
}

void	freeManager(AirportManager* pManager)
{
	(void)L_free(&pManager->airportsList, freeAirport);
}