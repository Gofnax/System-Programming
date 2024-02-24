#ifndef __AIRLINE_H__
#define __AIRLINE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Plane.h"
#include "Flight.h"
#include "GeneralStrings.h"

typedef struct
{
    char* name;
    size_t flightCount;
    Flight** flightArr;
    Plane* planeArr;
    size_t planeCount;
}Airline;

int addFlight( Airline* pAirline, AirportManager* pManager);
Plane* getPlaneBySerialNum(Airline* pAirline, int serialNum);
int addPlane(Airline* pAirline);   //return 1 if the plane added successfully, 0 otherwise
void doPrintFlightsWithPlaneType(Airline* pAirline);
int doesPlaneExistBySerial(Airline* pAirline, int serilNum);
int doesFlightExist(Flight* pFlight, Flight** flightArr, size_t flightCount);   //return 1 if flight exists, 0 otherwise
void initAirline(Airline* pAirline);
void printAirline(Airline* pAirline);
void freeAirline(Airline* pAirline);
void printPlanesArr(Plane* planeArr, int planeCount);
void freeCompany(Airline* pAirline);
void initPlane(Plane* pPlane, Airline* pAirline);
void printCompany(Airline* pAirline);

#endif