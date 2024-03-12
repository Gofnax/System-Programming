#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DateTime.h"

void printDate(const Date* pDate)
{



}

void printToFile(const Date* pDate, const char* fileName)
{
	FILE* fp;
	char msg[LEN] = { 0 };

	fp = fopen(fileName, "w");
	if (!fp)
		return;







	fclose(fp);
}

void printToScreen(const Date* pDate)
{




}

void createMsgByCondition(const Date* pDate, char* msg)
{
	PRINT_DATE(pDate, msg);



}

void createMaxMsg(const Date* pDate, char* msg)
{
	createRegMsg(pDate, msg);
	strcat(msg, " ");
	strcat(msg, pDate->sign);
}

void createRegMsg(const Date* pDate, char* msg)
{
	char timeMsg[LEN];
	createMsg(pDate,msg);
	createTimeMsg(&pDate->theTime, timeMsg);
	strcat(msg, " ");
	strcat(msg, timeMsg);
}

void createMsg(const Date* pDate, char* msg)
{
	sprintf(msg, "D:%u M:%u Y:%u", pDate->day, pDate->month, pDate->year);
}

void createTimeMsg(const Time* pTime, char* msg)
{
	sprintf(msg, "%u:%u:%u", pTime->hour,pTime->min,pTime->sec);

}


