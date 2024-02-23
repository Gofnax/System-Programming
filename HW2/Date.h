#ifndef __DATE_H__
#define __DATE_H__

#include "GeneralStrings.h"

typedef struct
{
    int day;
    int month;
    int year;
}Date;

//int isDateValid(Date* pDate,char* date);
void printDate(const Date* date);
//int initDate(Date* pDate,const char* str);
int getCorrectDate(Date* pDate);
int checkDate(int day, int month, int year);
#endif