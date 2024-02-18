#ifndef __AIRLINE_H__
#define __AIRLINE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plane.h"
#include "flight.h"

typedef struct
{
    char* name;
    size_t flightCount;
    Flight** flightArr;
    Plane* planeArr;
    size_t planeCount;
}Airline;

int addFlight(Flight* pFlight, Airline* pAirline, size_t numOfAirports);  //returns 1 if the flight added successfully, 0 otherwise
int addPlane(Plane* pPlane, Airline* pAirline);   //return 1 if the plane added successfully, 0 otherwise
void doPrintFlightsWithPlaneType(void);
int doesFlightExist(Flight* pFlight, Flight** flightArr, size_t flightCount);   //return 1 if flight exists, 0 otherwise
int doesPlaneExist(Plane* pPlane, Plane* planeArr, size_t planeCount);  //returns 1 if plane exists, 0 otherwise
Airline* initAirline(void);

#endif