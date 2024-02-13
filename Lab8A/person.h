#pragma once

#define LEN 20


typedef enum { Man, Woman, Boy, Girl, NofTypes } Type;
const char* typeTilte[NofTypes];

typedef struct
{
	char	name[LEN];
	Type	theType;
} Person;


void	initPerson(Person* pPer);
Type	getTypeFromUser();
void	printPersonArr(const Person* pPer,int count);
void	printPerson(const Person* pPer);
int comparePersonByNameLength(const void* v1, const void* v2);
