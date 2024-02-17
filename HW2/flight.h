#ifndef __FILGHT_H__
#define __FILGHT_H__

#include "plane.h"
#include "date.h"
#include "airport.h"

typedef struct
{
    char srcCode[IATA_LEN + 1];
    char desCode[IATA_LEN + 1];
    Plane thePlane;
    Date theDate;
}Flight;

#endif