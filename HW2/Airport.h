#ifndef __AIRPORT_H__
#define __AIRPORT_H__

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "GeneralStrings.h"

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
void getAirportName(Airport* pAirport);
char* makeOneSpace(char* str);
char* makeTwoSpaces(char* str);
char* capitalizeAllLetters(char* str);
int getNumOfWords(const char* str);
char* capitalizeFirstLetters(char* str);
char* cleanSpaces(char* str);
void freeAirport(Airport* pAirport);
void printAirport(Airport* pAirport);
int checkCode(const char* code);
char* getCode();
void getAirportCode(char* code);
void initAirportNoCode(Airport* pAirport);

#endif