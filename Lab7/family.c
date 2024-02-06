#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "family.h"
#include "person.h"
#include "generalStrings.h"


int initFamily(Family* theFamily)
{
    theFamily->lastName = getStrExactLength("Enter family name");
    if(!theFamily->lastName)
        return 0;
    theFamily->count = 0;
    theFamily->perArr = NULL;
    return 1;
}

int addPersonToFamily(Family* theFamily)
{
    theFamily->perArr = (Person*)realloc(theFamily->perArr, (theFamily->count + 1) * sizeof(Person));

    if(!theFamily->perArr)
        return 0;

    initPerson(&theFamily->perArr[theFamily->count]);
    theFamily->count++;
	return 1;
}


void printFamily(const Family* theFamily)
{
    printf("Family: %s has %d persons in family\n", theFamily->lastName, theFamily->count);
    for(int i = 0; i < theFamily->count; i++)
    {
        printPerson(&theFamily->perArr[i]);
    }
}

void freeFamily(Family* theFamily)
{
    free(theFamily->lastName);
    free(theFamily->perArr);
}





