#ifndef __AIRPORT_H__
#define __AIRPORT_H__

#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_STR 255
#define IATA_LEN 3

typedef struct
{
    char* name;
    char* country;
    char code[IATA_LEN + 1];
}Airport;

int isSameAirport(Airport* pAirport1, Airport* pAirport2);
int isAirportCode(Airport* pAirport, char* checkCode);
char* getAirportName(char* name);
void capitalizeFirstLetters(char* str);
void cleanWhiteSpaces(char* str);

#endif