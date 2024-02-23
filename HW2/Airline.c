#include "Airline.h"

Airline* initAirline(Airline* pAirline)
{
    if(pAirline != NULL)
    {
        char* name = getStrExactLength("Enter the airline's name:\n");
        pAirline = (Airline*)malloc(sizeof(Airline));
        pAirline->name = name;
        pAirline->flightCount = 0;
        pAirline->flightArr = NULL;
        pAirline->planeCount = 0;
        pAirline->planeArr = NULL;
    }
    return pAirline;
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
    return 0;
}

int addPlane(Plane* pPlane, Airline* pAirline)
{
    if(pAirline != NULL && pPlane != NULL)
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

void printAirline(Airline* pAirline)
{
    if(pAirline != NULL)
    {
        printf("Airline %s, has %ld planes:\n", pAirline->name, pAirline->planeCount);
        for(size_t i = 0; i < pAirline->planeCount; i++)
        {
            printPlane(pAirline->planeArr + i);
        }
        printf("Has %ld flights:\n", pAirline->flightCount);
        for(size_t i = 0; i < pAirline->flightCount; i++)
        {
            printFlight(pAirline->flightArr[i]);
        }
    }
    else
    {
        printf("Invalid airline pointer.\n");
    }
}

void freeAirline(Airline* pAirline)
{
    if(pAirline != NULL)
    {
        for(size_t i = 0; i < pAirline->flightCount; i++)
        {
            //freeFlight(pAirline->flightArr[i]);
        }
        for(size_t i = 0; i < pAirline->planeCount; i++)
        {
            freePlane(pAirline->planeArr + i);
        }
        free(pAirline->name);
        free(pAirline);
    }
}
