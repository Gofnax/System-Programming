#include "plane.h"

void initPlane(Plane* pPlane, Plane* planeArr, int planeCount)
{
    int type, serialNum;
    int serialNumExists = 0, isSerialNumValid;
    printf("Enter a plane type: (0 - Commercial, 1 - Cargo, 2 - Military)\n");
    (void)scanf("%d", &type);
    printf("Enter a serial number for the plane:\n");
    (void)scanf("%d", &serialNum);

    while(!serialNumExists || checkSerialNumValidity(pPlane))
    {
        
    }
}

int checkSerialNumValidity(Plane* pPlane)
{
    if(pPlane == NULL)
    {
        return 0;
    }
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