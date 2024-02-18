#ifndef __AIRPORTMANAGER_H__
#define __AIRPORTMANAGER_H__

#include "airport.h"

typedef struct
{
    Airport** airportArr;
    int count;
}AirportManager;

#endif