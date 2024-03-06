#include <stdio.h>
#include <stdlib.h>
#include "Airline.h"
#include "AirportManager.h"
#include "General.h"

int main(void)
{
    AirportManager	manager;
	Airline			company;

	initManager(&manager);
	initAirline(&company);

    addAirport(&manager);
    addAirport(&manager);
    addAirport(&manager);

    printAirports(&manager);

    addPlane(&company);
    addPlane(&company);
    addPlane(&company);

    addFlight(&company, &manager);
    addFlight(&company, &manager);
    addFlight(&company, &manager);

    printFlightArr(company.flightArr, company.flightCount);
    chooseFlightSortMethod(&company);
    printFlightArr(company.flightArr, company.flightCount);

    Flight* tmp = company.flightArr[2];
    if(searchForFlight(&company, tmp))
    {
        printFlight(searchForFlight(&company, tmp));
    }
    

    // Flight pFlight1 = {"AAA", "BBB", {1, 1}, {11, 11, 2111}};
    // Flight pFlight2 = {"BBB", "CCC", {2, 1}, {11, 11, 2112}};
    // Flight pFlight3 = {"CCC", "AAA", {3, 1}, {11, 11, 2113}};
    // Flight* flightArray[] = {&pFlight1, &pFlight2, &pFlight3};

    // qsort(flightArray, 3, sizeof(Flight*), compareByDstCode);
    // printFlightArr(flightArray, 3);

    // Flight** found = (Flight**)bsearch(&flightArray[2], flightArray, 3,
    //                  sizeof(Flight*), compareByDstCode);
    // if(found)
    // {
    //     printFlight(*found);
    // }
    // else
    // {
    //     printf("not found\n");
    // }
}