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
	eSortTypes	currentSort;
}Airline;

void	initAirline(Airline* pComp);
int		addFlight(Airline* pComp,const AirportManager* pManager);
int		addPlane(Airline* pComp);
Plane*	FindAPlane(Airline* pComp);
void	printCompany(const Airline* pComp);
void	printFlightArr(Flight** arr, int size);
void	printPlanesArr(Plane* arr,int size);
void	doPrintFlightsWithPlaneType(const Airline* pComp);
int		compareBySrcCode(const void* v1, const void* v2);
int		compareByDstCode(const void* v1, const void* v2);
int		compareByDate(const void* v1, const void* v2);
void	sortFlightsArr(Airline* pAirline, int (*compare)(const void*, const void*));
void 	chooseFlightSortMethod(Airline* pAirline);
void	freeFlightArr(Flight** arr, int size);
void	freePlanes(Plane* arr, int size);
void	freeCompany(Airline* pComp);

#endif

