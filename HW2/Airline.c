#include "Airline.h"

void initAirline(Airline* pAirline)
{
    if(pAirline != NULL)
    {
        char* name = getStrExactLength(" Enter Airline name");
        pAirline->name = name;
        pAirline->flightCount = 0;
        pAirline->flightArr = NULL;
        pAirline->planeCount = 0;
        pAirline->planeArr = NULL;
    }
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

void initPlane(Plane* pPlane, Airline* pAirline)
{
    if(pPlane == NULL)
    {
        return;
    }
    if(pAirline->planeArr == NULL)
    {
        pAirline->planeArr = (Plane*)malloc(sizeof(Plane));
    }
    pAirline->planeArr = (Plane*)realloc(pAirline->planeArr, sizeof(Plane) * (pAirline->planeCount + 1));
    int type = -1, serialNum = 0;
    int serialNumExists = 0;
    do
    {
        printf("Enter plane serial number - between 1 to 9999\n");
        (void)scanf("%d", &serialNum);
        pPlane->serialNumber = serialNum;
        for(size_t i = 0; i < pAirline->planeCount; i++)
        {
            if(serialNum == pAirline->planeArr[i].serialNumber)
            {
                serialNumExists = 1;
            }
        }
        if(serialNumExists || checkSerialNumValidity(pPlane))
        {
            printf("Invalid serial number\n");
        }
    }while(serialNumExists || checkSerialNumValidity(pPlane));
    do
    {
        printf("Please enter one of the following types\n");
        printf("0 for Commercial\n");
        printf("1 for Cargo\n");
        printf("2 for Military\n");
        (void)scanf("%d", &type);
        pPlane->type = type;
    }while(type < 0 || type >= NumOfTypes);
    memcpy(&pAirline->planeArr[pAirline->planeCount], pPlane, sizeof(Plane));
}

int addPlane(Airline* pAirline)
{
    if(pAirline != NULL)
    {
        Plane* pPlane = (Plane*)malloc(sizeof(Plane));
        initPlane(pPlane, pAirline);
        /*if(doesPlaneExist(pPlane, pAirline->planeArr, pAirline->planeCount))
        {
            return 0;
        }*/
        pAirline->planeCount++;
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

void printPlanesArr(Plane* planeArr, int planeCount)
{
    if(planeArr != NULL)
    {
        for(size_t i = 0; i < planeCount; i++)
        {
            printf("The plane %d:\n", i);
            printPlane(&planeArr[i]);
        }
    }
}

void freeCompany(Airline* pAirline)
{
    freeAirline(pAirline);
}

void freeAirline(Airline* pAirline)
{
    if(pAirline != NULL)
    {
        for(size_t i = 0; i < pAirline->flightCount; i++)
        {
            //freeFlight(pAirline->flightArr[i]);
        }
        /*for(size_t i = 0; i < pAirline->planeCount; i++)
        {
            freePlane(pAirline->planeArr + i);
        }*/
        free(pAirline->planeArr);
        free(pAirline->name);
        //free(pAirline);
    }
}
