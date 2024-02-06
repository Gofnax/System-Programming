#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "building.h"


void 	initBuilding(Building* pBuild)
{
    printf("Insert max families in building\n");
    scanf("%d", &pBuild->maxFamilies);
    pBuild->count = 0;
    pBuild->allFamilies = NULL;
}

int		addFamily(Building* pBuild)
{
    Family* pFam = (Family*)malloc(sizeof(Family));
    if(!pFam)
        return 0;
    if(!initFamily(pFam))
    {
        free(pFam);
        return 0;
    }
    pBuild->allFamilies = (Family**)realloc(pBuild->allFamilies, (pBuild->count + 1) * sizeof(Family*));
    if(!pBuild->allFamilies)
    {
        freeFamily(pFam);
        free(pFam);
        return 0;
    }

    pBuild->allFamilies[pBuild->count] = pFam;
    pBuild->count;
    return 1;

}

void 	printBuilding(const Building* pBuild)
{
    printf("There are %d families out of %d\n", pBuild->count, pBuild->maxFamilies);
    for(int i = 0; i < pBuild->count; i++)
    {
        printFamily(pBuild->allFamilies[i]);
    }
}

void 	freeBuilding(Building* pBuild)
{
    for(int i = 0; i < pBuild->count; i++)
    {
        freeFamily(pBuild->allFamilies[i]);
        free(pBuild->allFamilies[i]);
    }
    free(pBuild->allFamilies);
}

