#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"

static const char* DegreeStr[eNofTypes] = { "First", "Second" };



Student* createStudentArrFromFile(const char* fileName, int* pSize)
{
	FILE* fp = fopen(fileName, "rb");
	if(!fp)
		return NULL;

	BYTE size;
	if(fread(&size, sizeof(BYTE), 1, fp) != 1)
	{
		fclose(fp);
		return NULL;
	}

	Student* arr = (Student*)malloc(size * sizeof(Student));
	if(!arr)
	{
		fclose(fp);
		return NULL;
	}

	*pSize = size;
	for(int i = 0; i < size; i++)
	{
		if(!readStudentFromBinaryFileCompressed(&arr[i], fp))
		{
			free(arr);
			fclose(fp);
			return NULL;
		}
	}
	return arr;
}

int		saveStudentArrToBinaryFile(const char* fileName, const Student* arr, int size)
{
	FILE* fp = fopen(fileName, "wb");
	if(!fp)
		return 0;

	BYTE count = (BYTE)size;
	if(fwrite(&count, sizeof(BYTE), 1, fp) != 1)
	{
		fclose(fp);
		return 0;
	}
	
	for(int i = 0; i < size; i++)
	{
		if(saveStudentToBinaryFileCompressed(&arr[i], fp) == 0)
		{
			fclose(fp);
			return 0;
		}
	}

	fclose(fp);

	return 1;
}



int		saveStudentToBinaryFileCompressed(const Student* pSt, FILE* fp)
{
	int len = (int)strlen(pSt->name);
	BYTE data[2] = {0};
	data[0] = pSt->grade;
	data[0] = data[0] | (pSt->year << 7);
	data[1] = (pSt->year >> 1);
	data[1] = data[1] | (pSt->type << 2);
	data[1] = data[1] | (len << 3);

	if(fwrite(data, sizeof(BYTE), 2, fp) != 2)
		return 0;

	if(fwrite(pSt->name, sizeof(char), len, fp) != len)
		return 0;
	
	return 1;
}

int		readStudentFromBinaryFileCompressed(Student* pSt, FILE* fp)
{
	BYTE data[2] = { 0 };
	if(fread(data, sizeof(BYTE), 2, fp) != 2)
		return 0;
	
	int mask = 0;
	int len = data[1] >> 3;
	mask = 1;
	pSt->type = data[1] >> 2 & mask;
	mask = 3;
	pSt->year = data[0] >> 7 | (data[1] & mask) << 1; 
	pSt->name = (char*)calloc(len + 1, sizeof(char));
	if(!pSt->name)
		return 0;
	
	if(fread(pSt->name, sizeof(char), len, fp) != len)
	{
		free(pSt->name);
		return 0;
	}
	return 1;
}

void	initStudentArr(Student* arr, int size)
{
	for (int i = 0; i < size; i++)
		initStudent(&arr[i]);
}

void	showStudentArr(const Student* arr, int size)
{
	for (int i = 0; i < size; i++)
		showStudent(&arr[i]);
}

void	freeStudentArr(Student* arr, int size)
{
	for (int i = 0; i < size; i++)
		free(arr[i].name);
}

void	showStudent(const Student* pSt)
{
	printf("Name: %s Type: %s Year: %d Grade: %d\n", 
		pSt->name, DegreeStr[pSt->type],pSt->year, pSt->grade);
}

void	initStudent(Student* pSt)
{
	pSt->name = createDynStr("Enter student name");
	pSt->type = getStudentTypeFromUser();
	printf("enter student year and grade\n");
	scanf("%d %d", &pSt->year, &pSt->grade);
	getchar();
}


eDegreeType getStudentTypeFromUser()
{
	int temp;
	do {
		for (int i = 0; i < eNofTypes; i++)
			printf("enter %d for type %s\n", i, DegreeStr[i]);
		scanf("%d", &temp);
	} while (temp < 0 || temp >= eNofTypes);
	return (eDegreeType)temp;
}

char*	createDynStr(const char* msg)
{
	char* str;
	char temp[100];
	printf("Enter %s: ", msg);
	fgets(temp,sizeof(temp),stdin);
	temp[strcspn(temp, "\n")] = '\0';
	str = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	if (!str)
		return NULL;
	strcpy(str, temp);

	return str;
}

