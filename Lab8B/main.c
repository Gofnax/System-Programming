#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"

#define EMP_COUNT 6

void Q1();
void Q2();

int main()
{
	Q1();
	Q2();

	return 1;
}

void Q1()
{
	Employee arr[] = {
	{ "aaa", 10000, 4.5F }, { "bbb", 9000, 5.1F }, { "ccc", 11000, 3.3F },
	{ "ddd", 15000, 7.0F }, { "eee", 7000, 3.2F } };

	int size = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, size, sizeof(Employee), compareEmployeeBySalary);
	printf("Sort by salary\n");
	printEmployeeArr(arr, size);

	qsort(arr, size, sizeof(Employee), compareEmployeeBySeniority);
	printf("Sort by seniority\n");
	printEmployeeArr(arr, size);

	qsort(arr, size, sizeof(Employee), compareEmployeeByName);
	printf("Sort by name\n");
	printEmployeeArr(arr, size);

	Employee temp;
	printf("enter name to search\n");
	scanf("%s", temp.name);

	Employee* pRes = (Employee*)bsearch(&temp, arr, size, sizeof(Employee), compareEmployeeByName);
	if(!pRes)
	{
		printf("Employee %s not found\n", temp.name);
	}
	else{
		printf("Employee found in index %d\n", pRes->arr);
		printEmployee(pRes);
	}

}

void Q2()
{
	Employee* arrEmp[EMP_COUNT];
	if (!initEmployeeArr(arrEmp, EMP_COUNT))
		return;







}