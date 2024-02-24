#include "Plane.h"

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
    if(pPlane == NULL)
    {
        return -1;
    }
    if(pPlane->type < 0 || pPlane->type > NumOfTypes || pPlane->serialNumber < 1 || pPlane->serialNumber > 9999)
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

void printPlane(const Plane* pPlane)
{
    if(pPlane != NULL)
    {
        printf("Plane: serial number:%d, type ", pPlane->serialNumber);
        switch(pPlane->type)
        {
            case Commercial:
                printf("Commercial\n");
                break;
            case Cargo:
                printf("Cargo\n");
                break;
            case Military:
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