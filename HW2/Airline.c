#include "Airline.h"

void initAirline(Airline* pAirline)
{
    if(pAirline != NULL)
    {
        char* name = getStrExactLength("Enter Airline name");
        pAirline->name = name;
        pAirline->flightCount = 0;
        pAirline->flightArr = NULL;
        pAirline->planeCount = 0;
        pAirline->planeArr = NULL;
    }
}

int addFlight(Airline* pAirline, AirportManager* pManager)
{
    if(pAirline != NULL && pManager != NULL)
    {
        if(pManager->numOfAirports < 2)
        {
            printf("There are not enough airport to set a flight\n");
            return 0;
        }
        if(pAirline->flightArr == NULL)
        {
            pAirline->flightArr = (Flight**)malloc(sizeof(Flight*));
        }
        else
        {
            pAirline->flightArr = (Flight**)realloc(pAirline->flightArr, sizeof(Flight*) * (pAirline->flightCount + 1));
        }
        
        int planeSerialNumChoice = 0;
        printf("Choose a plane from list, type its serial Number\n");
        printPlanesArr(pAirline->planeArr, pAirline->planeCount);
        int planeChoiceValid = 0;
        do
        {
            scanf("%d", &planeSerialNumChoice);
            planeChoiceValid = doesPlaneExistBySerial(pAirline, planeSerialNumChoice);
            if(!planeChoiceValid)
                printf("No plane with that serial number! Try again!\n");
        } while (!planeChoiceValid);
        
        Plane* pPlane = getPlaneBySerialNum(pAirline, planeSerialNumChoice);
        printAirports(pManager);
        printf("\n");

        Flight* pFlight = (Flight*)malloc(sizeof(Flight));
        initFlight(pFlight, pPlane, pManager);
        pAirline->flightArr[pAirline->flightCount++] = pFlight;
        return 1;
    }
    return 0;
}

Plane* getPlaneBySerialNum(Airline* pAirline, int serialNum)
{
    if(pAirline != NULL)
    {
        for(size_t i = 0; i < pAirline->planeCount; i++)
        {
            if(pAirline->planeArr[i].serialNumber == serialNum)
            {
                return &pAirline->planeArr[i];
            }
        }
    }
    return NULL;
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
        pAirline->planeCount++;
        return 1;
    }
    return 0;
}

void doPrintFlightsWithPlaneType(Airline* pAirline)
{
    int input;
    printf("Enter a plane type: (0 - Commercial, 1 - Cargo, 2 - Military)\n");
    (void)scanf("%d", &input);
    //needs to be updated when 'Flight.c' will be integrated
}

int doesPlaneExistBySerial(Airline* pAirline, int serilNum)
{
    if(pAirline != NULL)
    {
        for(size_t i = 0; i < pAirline->planeCount; i++)
        {
            if(pAirline->planeArr[i].serialNumber == serilNum)
            {
                return 1;
            }
        }
    }
    return 0;
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

void printCompany(Airline* pAirline)
{
    printAirline(pAirline);
}

void printPlanesArr(Plane* planeArr, int planeCount)
{
    if(planeArr != NULL)
    {
        for(size_t i = 0; i < planeCount; i++)
        {
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
            freeFlight(pAirline->flightArr[i]);
        }
        free(pAirline->planeArr);
        free(pAirline->name);
    }
}
