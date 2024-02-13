#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "employee.h"

 

void initEmployee(Employee* pEmp)
{
	printf("Please enter name(1 word), salary and seniority\n");
	scanf("%s %d %f", pEmp->name, &pEmp->salary, &pEmp->seniority);
}

void printEmployee(const Employee* pEmp)
{
	printf("Name %s\t Salary %d\t Seniority %10.2f\n",
		pEmp->name, pEmp->salary, pEmp->seniority);
}


int initEmployeeArr(Employee** arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] = malloc(sizeof(Employee));
		if (!arr[i])
			return 0;
		initEmployee(arr[i]);
	}
	return 1;
}

void printEmployeeArr(const Employee* arr, int size)
{
	for (int i = 0; i < size; i++)
		printEmployee(&arr[i]);
}

int compareEmployeeBySalary(const void* v1, const void* v2)
{
	const Employee* e1 = (const Employee*)v1;
	const Employee* e2 = (const Employee*)v2;
	return e1->salary - e2->salary;
}

int compareEmployeeBySeniority(const void* v1, const void* v2)
{
	const Employee* e1 = (const Employee*)v1;
	const Employee* e2 = (const Employee*)v2;
	if(e1->seniority > e2->seniority)
		return 1;
	if(e1->seniority < e2->seniority)
		return -1;
	return 0;
}

int compareEmployeesByName(const void* v1, const void* v2)
{
	const Employee* e1 = (const Employee*)v1;
	const Employee* e2 = (const Employee*)v2;
	
}