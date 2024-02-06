#ifndef __FAMILY_H
#define __FAMILY_H

typedef struct 
{
	char* lastName;
    Person* perArr;
    int count;
} Family;

int	 initFamily(Family* theFamily);
int  addPersonToFamily(Family* theFamily);
void printFamily(const Family* theFamily);
void freeFamily(Family* theFamily);



#endif __FAMILY_H
