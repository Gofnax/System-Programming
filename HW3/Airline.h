#ifndef __COMP__
#define __COMP__

#include <string.h>
#include "Flight.h"
#include "AirportManager.h"

typedef enum {
	eNoSort, eSortBySrc, eSortByDst, eSortByDate, eNofSorts
} eSortTypes;

typedef struct
{
	char*		name;
	int			flightCount;
	Flight**	flightArr;
	int			planeCount;
	Plane*		planeArr;
}Airline;

void	initAirline(Airline* pComp);
int		addFlight(Airline* pComp,const AirportManager* pManager);
int		addPlane(Airline* pComp);
Plane*	FindAPlane(Airline* pComp);
void	printCompany(const Airline* pComp);
void	printFlightArr(Flight** arr, int size);
void	printPlanesArr(Plane* arr,int size);
void	doPrintFlightsWithPlaneType(const Airline* pComp);
int		compareBySrcCode(const Flight* pFlight1, const Flight* pFlight2);
int		compareByDstCode(const Flight* pFlight1, const Flight* pFlight2);
int		compareByDate(const Flight* pFlight1, const Flight* pFlight2);
void	sortFlightsArr(Airline* pAirline, int (*compare)(const void*, const void*));
void	freeFlightArr(Flight** arr, int size);
void	freePlanes(Plane* arr, int size);
void	freeCompany(Airline* pComp);

#endif

