#ifndef __AIRPORTMANAGER_H__
#define __AIRPORTMANAGER_H__

#include <string.h>
#include "Airport.h"

typedef struct 
{
	Airport** airportArr;
	size_t numOfAirports;
}AirportManager;

int initManager(AirportManager* manager);
int addAirport(AirportManager* pManager);
Airport* findAirportByCode(const AirportManager* manager,char* code);
void printAirports(const AirportManager* pManger);
int doesAirportExist(const AirportManager* pManager, Airport* pAirport);
void freeAirportManager(AirportManager* pManager);
void freeManager(AirportManager* pManager);

#endif

