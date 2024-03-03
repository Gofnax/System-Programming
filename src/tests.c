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
}