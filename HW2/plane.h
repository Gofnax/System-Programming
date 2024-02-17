#ifndef __PLANE_H__
#define __PLANE_H__

#define SERIAL_MAX 9999
#define SERIAL_MIN 1

typedef enum {Commercial, Cargo, Military, NumOfTypes} planeType;

typedef struct
{
    planeType type;
    int serialNumber;
}Plane;

void initPlane(Plane* pPlane, Plane* planeArr, int planeCount);
int checkSerialNumValidity(Plane* pPlane);

#endif