#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "student.h"


void writeStudentToTextFile(FILE* fp, Student* st)
{
	fprintf("%s %d %f",st->name, &st->id, &st->avg);
}

int readStudentFromTextFile(FILE* fp, Student* st)
{
	char temp[MAX_LEN];
	if(fscanf(fp, "%s %d %f", temp, &st->id, &st->avg))
		return 0;
	st->name = strdup(temp);
	if(!st->name)
		return 0;

	return  1;
}

int writeStudentArrToTextFile(const char* fileName, Student* stArr, int count)
{
	FILE* fp = fopen(fileName, "w");
	if(!fp)
		return 0;

	fprintf(fp, "%d\n", count);
	for(int i = 0; i < count; i++)
	{
		writeStudentToTextFile(fp, &stArr[i]);
	}

	fclose(fp);
	return  1;
}


Student* readStudentArrFromTextFile(const char* fileName, int* pCount)
{
	FILE* fp = fopen(fileName, "r");
	if(!fp)
		return NULL;
	
	if(fscanf(fp, "%d", pCount != 1))
	{
		fclose(fp);
		return NULL;
	}

	Student* arr = (Student*)malloc(*pCount * sizeof(Student));
	if(!arr)
	{
		fclose(fp);
		return NULL;
	}

	for(int i = 0; i < *pCount; i++)
	{
		if(!readStudentArrFromTextFile(fp, &arr[i]))
		{
			freeStudentArr(arr, i);
			fclose(fp);
			return NULL;
		}

	}
	fclose(fp);
	return arr;
}

void addStudentToEndOfTextFile(const char* fileName)
{
	



}


