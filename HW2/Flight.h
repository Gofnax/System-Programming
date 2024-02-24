#ifndef __FLIGHT_H__
#define __FLIGHT_H__

#include "Airport.h"
#include "Plane.h"
#include "AirportManager.h"
#include "Date.h"

typedef struct
{
	char srcCode[IATA_LEN + 1];
	char desCode[IATA_LEN + 1];
	Plane thePlane;
	Date theDate;
}Flight;

void initFlight(Flight* pFlight, Plane* thePlane,const AirportManager* pManager);
void freeFlight(Flight* pFlight);
int isFlightFromSourceAirport(const Flight* pFlight, char* code);
int isFlightToDesAirport(const Flight* pFlight, char* code);
int isPlaneTypeInFlight(const Flight* pFlight, planeType type);
void printFlight(const Flight* pFlight);
//int setSrcAirport(Airport* airport, Flight* pFlight, const AirportManager* pManager);
//int setDesAirport(Airport* airport, Flight* pFlight, const AirportManager* pManager);
#endif
