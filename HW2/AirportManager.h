#ifndef __AIRPORTMANAGER_H__
#define __AIRPORTMANAGER_H__

#include "Airport.h"
typedef struct 
{
	Airport** airportArr;
	size_t numOfAirports;
}AirportManager;

int initManager(AirportManager* manager);
int addAirpot(AirportManager* pManager,Airport* airport);
Airport* findAirportByCode(const AirportManager* manager,char* code);
void printAirports(const AirportManager* pManger);
int doesAirportExist(const AirportManager* pManager, Airport* airport);
void freeAirportManager(AirportManager* pManager);
#endif // !__AIRPORTMANAGER_H__

