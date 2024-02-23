#ifndef __PLANE_H__
#define __PLANE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SERIAL_MAX 9999
#define SERIAL_MIN 1

typedef enum {Commercial, Cargo, Military, NumOfTypes} planeType;

typedef struct
{
    planeType type;
    int serialNumber;
}Plane;

//  returns -1 if serial number is too small
//  returns 0 if serial number is valid
//  returns 1 if serial number is too big
int checkSerialNumValidity(Plane* pPlane);
void initPlane(Plane* pPlane, Plane* planeArr, int planeCount);
int isPlaneValid(Plane* pPlane);
void printPlane(const Plane* pPlane);
int doesPlaneExist(Plane* pPlane, Plane* planeArr, size_t planeCount);
void freePlane(Plane* pPlane);

#endif