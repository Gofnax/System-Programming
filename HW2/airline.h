#ifndef __AIRLINE_H__
#define __AIRLINE_H__

#include "plane.h"
#include "flight.h"

typedef struct
{
    char* name;
    Flight** flightArr;
    int flightCount;
    Plane* planeArr;
    int planeCount;
}Airline;

#endif