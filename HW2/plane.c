#include "plane.h"

void initPlane(Plane* pPlane, Plane* planeArr, int planeCount)
{
    int type, serialNum;
    int serialNumExists;
    do
    {
        printf("Enter a plane type: (0 - Commercial, 1 - Cargo, 2 - Military)\n");
        (void)scanf("%d", &type);
    }while(type < 0 || type >= NumOfTypes);
    do
    {
        printf("Enter a serial number for the plane:\n");
        (void)scanf("%d", &serialNum);
        for(size_t i = 0; i < planeCount; i++)
        {
            if(serialNum == planeArr[i].serialNumber)
            {
                serialNumExists = 1;
            }
        }
        if(serialNumExists || checkSerialNumValidity(pPlane))
        {
            printf("Invalid serial number\n");
        }
    }while(serialNumExists || checkSerialNumValidity(pPlane));
}

int checkSerialNumValidity(Plane* pPlane)
{
    if(pPlane != NULL)
    {
        if(pPlane->serialNumber > SERIAL_MAX)
        {
            return 1;
        }
        else if(pPlane->serialNumber < SERIAL_MIN)
        {
            return -1;
        }
        return 0;   
    }
    return -2;
}

int isPlaneValid(Plane* pPlane)
{
    if(pPlane->type < 0 || pPlane->type > NumOfTypes || pPlane->serialNumber < 1 || pPlane > 9999)
    {
        return 0;
    }
    return 1;
}

int doesPlaneExist(Plane* pPlane, Plane* planeArr, size_t planeCount)
{
    if(planeArr == NULL)
    {
        return 0;
    }
    for(size_t i = 0; i < planeCount; i++)
    {
        if(memcmp(planeArr + i, pPlane, sizeof(Plane)) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void printPlane(Plane* pPlane)
{
    if(pPlane != NULL)
    {
        printf("Plane serial number: %d, of type: ", pPlane->serialNumber);
        switch(pPlane->type)
        {
            Commercial:
                printf("Commercial\n");
                break;
            Cargo:
                printf("Cargo\n");
                break;
            Military:
                printf("Military\n");
                break;
            default:
                printf("No valid type\n");
        }
    }
    else
    {
        printf("No valid plane pointer\n");
    }
}

void freePlane(Plane* pPlane)
{
    free(pPlane);
}