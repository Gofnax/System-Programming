#include <stdio.h>
#include <stdlib.h>
#include "Airport.h"
#include "Plane.h"
#include "Date.h"

int main()
{
    int opt;
    printf("Please choose one of the following options\n");
    printf("1 - Date\n");
    printf("2 - Plane\n");
    printf("3 - Airport Code\n");
    printf("4 - Airport Name\n");
    printf("5 - Airport\n");
    scanf("%d", &opt);
    getchar();

    Date d;
    Plane p;
    Airport port1;
    switch (opt)
    {
    case 1:
        //A function that gets a pointer to struct date , ask the user for the date
        //and parse 3 ints (day,month,year)
        getCorrectDate(&d);
        printDate(&d);
        printf("\n");
        break;

    case 2:
        //A function that gets a pointer to struct Plane, 
        //the plane array and the planes count in array.
        //The function get from the user the serial number (check that it is ok and unique)
        // and the plane type.
        initPlane(&p, NULL, 0);
        printPlane(&p);
        printf("\n");
        break;

    case 3:
        //A function that init the airport code.
        //The function ask the user for a code 
        //check that the code is 3 upper case letters
        getAirportCode(port1.code);
        printf("%s\n", port1.code);
        break;

    case 4:
        //function get a pointer to a struct Airport.
        //The function ask the user for name
        // The function set the name based on the rule given
        getAirportName(&port1);
        printf("%s\n", port1.name);
        free(port1.name);
        break;

    case 5:
        getAirportCode(port1.code);
        //After setting the code this function get the address of the struct Airport
        //The function ask the user for airport name and country
        //The function init these fields
        initAirportNoCode(&port1);
        printAirport(&port1);
        freeAirport(&port1);
        break;

    }

}