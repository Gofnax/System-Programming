#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define FREE_RETURN_0(ptr) {free(ptr); return 0;}

int writeStudentToBFile(FILE* fp, Student* st)
{
	int len = (int)strlen(st->name) + 1;
	if(fwrite(&len, sizeof(int), 1, fp) != 1)
		return 0;
	if(fwrite(st->name, sizeof(char), len, fp) != len)
		return 0;
	if(fwrite(&st->id, sizeof(int), 1, fp) != 1)
		return 0;
	if(fwrite(&st->avg, sizeof(float), 1, fp) != 1)
		return 0;
	
	return  1;
}


int readStudentFromBFile(FILE* fp, Student* st)
{
	int len;
	if(fread(&len, sizeof(int), 1, fp) != 1)
		return 0;

	st->name = (char*)malloc(len * sizeof(char));
	if(!st->name)
		return 0;
	
	if(fread(st->name, sizeof(char), len, fp) != len)
		FREE_RETURN_0(st->name);
	if(fread(&st->id, sizeof(int), 1, fp) != 1)
		return 0;
	if(fread(&st->avg, sizeof(float), 1, fp) != 1)
		return 0;
	
	return  1;
}

int writeStudentArrToBFile(const char* fileName, Student* stArr, int count)
{
	FILE* fp = fopen(fileName, "wb");
	if(!fp)
		return 0;

	//fprintf(fp, "%d\n", count);
	for(int i = 0; i < count; i++)
	{
		writeStudentToTextFile(fp, &stArr[i]);
	}

	fclose(fp);

	return  0;
}


Student* readStudentArrFromBFile(const char* fileName, int* pCount)
{
	

	return NULL;
}


void addStudentToEndOfBFile(const char* fileName)
{
	


}
