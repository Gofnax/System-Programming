#ifndef __AIRPORT_H__
#define __AIRPORT_H__

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "generalStrings.h"

#define IATA_LEN 3

typedef struct
{
    char* name;
    char* country;
    char code[IATA_LEN + 1];
}Airport;

int isSameAirport(Airport* pAirport1, Airport* pAirport2);
int isAirportCode(Airport* pAirport, char* checkCode);
Airport* initAirport();
char* getAirportName();
char* makeOneSpace(char* str);
char* makeTwoSpaces(char* str);
char* capitalizeAllLetters(char* str);
size_t getNumOfWords(char* str);
char* capitalizeFirstLetters(char* str);
char* cleanSpaces(char* str);
void freeAirport(Airport* pAirport);
void printAirport(Airport* pAirport);

#endif