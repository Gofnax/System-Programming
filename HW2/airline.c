#include "airline.h"

int addFlight(Flight* pFlight, Airline* pAirline)
{
    if(pAirline == NULL)
    {
        return 0;
    }
    if(doesFlightExist(pFlight, pAirline->flightArr, pAirline->flightCount))
    {
        return 0;
    }
    pAirline->flightArr[pAirline->flightCount - 1] = pFlight;
    pAirline->flightCount++;
    return 1;
}

int addPlane(Plane* pPlane, Airline* pAirline)
{
    if(pAirline == NULL)
    {
        return 0;
    }
    if(doesPlaneExist(pPlane, pAirline->planeArr, pAirline->planeCount))
    {
        return 0;
    }
    pAirline->planeArr[pAirline->planeCount] = *pPlane;
    pAirline->flightCount++;
    return 1;
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
    for(size_t i; i < planeCount; i++)
    {
        if(planeArr + i == pPlane)
        {
            return 1;
        }
    }
    return 0;
}
