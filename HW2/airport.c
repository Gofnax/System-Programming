#include "airport.h"


int isSameAirport(Airport* pAirport1, Airport* pAirport2)
{
    if(strcmp(pAirport1->code, pAirport2->code))
    {
        return 0;
    }
    return 1;
}

int isAirportCode(Airport* pAirport, char* checkCode)
{
    if(strcmp(pAirport->code, checkCode))
    {
        return 0;
    }
    return 1;
}