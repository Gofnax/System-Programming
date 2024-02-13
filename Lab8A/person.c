#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "person.h"


const char* typeTilte[NofTypes] = { "Man", "Woman", "Boy","Girl" };

void	initPerson(Person* pPer)
{
	printf("please enter person name\n");
	scanf("%s", pPer->name);
	pPer->theType = getTypeFromUser();
	getchar();
}

Type	getTypeFromUser()
{
	int i, t;
	printf("Enter person type\n");
	do {
		for (i = 0; i < NofTypes; i++)
			printf("Enter %d for %s\n", i, typeTilte[i]);
		scanf("%d", &t);
	} while (t < 0 || t >= NofTypes);
	return (Type)t;
}

void	printPersonArr(const Person* pPer, int count)
{
	for (int i = 0; i < count; i++)
	{
		printPerson(&pPer[i]);
	}
}

void	printPerson(const Person* pPer)
{
	printf("%s name %s\n", typeTilte[pPer->theType], pPer->name);
}

int comparePersonByNameLength(const void* v1, const void* v2)
{
	const Person* p1 = (const Person*)v1;
	const Person* p2 = (const Person*)v2;

	
}