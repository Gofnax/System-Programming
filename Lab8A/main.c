#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "employee.h"
#include "arrays.h"
#include "person.h"

#define PER_COUNT 6
#define EMP_COUNT 6

int Q1();
int Q2();

void main()
{
	Q1();
	Q2();
	system("pause");
}

int Q1()
{
	int arr[] = { 2,3,4,-7,9,-6,5,1 };
	int size = sizeof(arr) / sizeof(int);
	int newSize = 0;

	int* newArr = NULL;
	//Add call to function with the rule you choose !!!!
	//print result and 






	return 1;
}


int Q2()
{
	Person arrPer[PER_COUNT];
	for (int i = 0; i < PER_COUNT; i++)
		initPerson(&arrPer[i]);

	printPersonArr(arrPer, PER_COUNT);

	//find the person with longest name using generalGetMax and print hime
	Person* maxP = (Person*)getGeneralMax(arrPer, PER_COUNT, sizeof(Person), comparePersonByNameLength);
	printf("Longest name\t");
	printPerson(maxP);
	
	printf("----------------------------\n");
	Employee* arrEmp[EMP_COUNT];
	if (!initEmployeeArr(arrEmp, EMP_COUNT))
		return 0;

	printEmployeeArr(arrEmp, EMP_COUNT);
	printf("\n\n");

	//find the employee with heighest salary using generalGetMax and print him



	return 1;
}