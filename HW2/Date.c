#include "Date.h"
#include <stdio.h>
#include "GeneralStrings.h"

//int isDateValid(Date* pDate,char* date)
//{
//	if (strlen(date) != 12)
//		return 0;
//	if(date[2] != '#' || date[3] != '#' || date[6] != '#' || date[7] != '#')
//		return 0;
//	if (sscanf(date, "%d%*c%*c%d%*c%*c%d", &(pDate->day), &(pDate->month), &(pDate->year) != 3))
//		return 0;
//	if (pDate->day <= 0 || pDate->month <= 0 || pDate->month > 12 || pDate->year <= 2022)
//		return 0;
//	if (daysInMonths[pDate->month - 1] < pDate->day)
//		return 0;
//
//	return 1;
//}
void printDate(const Date* date)
{
	 printf("Date: %d/%d/%d", date->day, date->month, date->year);
}
//int initDate(Date* pDate,const char* str)
//{
//	int res;
//
//	res = sscanf(str,"%2d", &(pDate->day));
//	if (res != 1) return 0;
//	res = sscanf(str + 3, "%2d", &(pDate->month));
//	if (res != 1) return 0;
//	res = sscanf(str + 8, "%4d", &(pDate->year));
//	if (res != 1) return 0;
//
//	return 1;
//}
int getCorrectDate(Date* pDate)
{
	char input [MAX_STR];
	int day, month, year;
	do
	{
		printf("Enter Flight Date dd##mm##yyyy  minimum year 2023\n");
		myGets(input, MAX_STR);
		sscanf(input,"%d##%d##%d", &day,&month,&year);
		
	} while (checkDate(day, month, year) == 0);

	pDate->day = day;
	pDate->month = month;
	pDate->year = year;
	return 1;
}

int checkDate(int day, int month, int year) 
{
	const int daysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int isDateCorrect = (month < 1 || month > 12) || (day < 1 || day> daysInMonths[month - 1]) || (year < 2023 || year > 9999);
	if (isDateCorrect)
	{
		printf("Error try again\n");
		return 0;
	}
	return 1;
}