#include "airline.h"

#define MAX_STR 255

Airline* initAirline(void)
{
    char name[MAX_STR];
    printf("Enter the airline's name:\n");
    gets(name);
    size_t nameLen = strlen(name) + 1;
    name = (char*)realloc(name, nameLen);
    
}

int addFlight(Flight* pFlight, Airline* pAirline, size_t numOfAirports)
{
    // if(pAirline != NULL && pFlight != NULL)
    // {
    //     if(numOfAirports < 2 || isPlaneInitialized(&(pFlight->thePlane)) == NULL || 
    //         doesFlightExist(pFlight, pAirline->flightArr, pAirline->flightCount))
    //     {
    //         return 0;
    //     }
    //     pAirline->flightArr[pAirline->flightCount - 1] = pFlight;
    //     pAirline->flightCount++;
    //     return 1;
    // }
    // return 0;
}

int addPlane(Plane* pPlane, Airline* pAirline)
{
    if(pAirline != NULL)
    {
        if(doesPlaneExist(pPlane, pAirline->planeArr, pAirline->planeCount))
        {
            return 0;
        }
        pAirline->planeArr[pAirline->planeCount] = *pPlane;
        pAirline->flightCount++;
        return 1;
    }
    return 0;
}

void doPrintFlightsWithPlaneType(void)
{
    int input;
    printf("Enter a plane type: (0 - Commercial, 1 - Cargo, 2 - Military)\n");
    (void)scanf("%d", &input);
    //needs to be updated when 'Flight.c' will be integrated
}

int doesFlightExist(Flight* pFlight, Flight** flightArr, size_t flightCount)
{
    if(flightArr == NULL)
    {
        return 0;
    }
    for(size_t i = 0; i < flightCount; i++)
    {
        if(flightArr[i] == pFlight)
        {
            return 1;
        }
    }
    return 0;
}

int doesPlaneExist(Plane* pPlane, Plane* planeArr, size_t planeCount)
{
    if(planeArr == NULL)
    {
        return 0;
    }
    for(size_t i = 0; i < planeCount; i++)
    {
        if(planeArr + i == pPlane)
        {
            return 1;
        }
    }
    return 0;
}
