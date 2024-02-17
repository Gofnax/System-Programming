#include "plane.h"

void initPlane(Plane* pPlane, Plane* planeArr, int planeCount)
{

}

//  returns -1 if serial number is too small
//  returns 0 if serial number is valid
//  returns 1 if serial number is too big
int checkSerialNumValidity(Plane* pPlane)
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