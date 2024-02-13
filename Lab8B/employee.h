#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#define MAX_LENGTH 21

typedef struct
{
	char	name[MAX_LENGTH];
	int		salary;
	float	seniority;
}Employee;

int compareEmployeeBySalary(const void* v1, const void* v2);
int compareEmployeeBySeniority(const void* v1, const void* v2);
int compareEmployeesByName(const void* v1, const void* v2);


void initEmployee(Employee* pEmp);
void printEmployee(const Employee* pEmp);
int initEmployeeArr(Employee** arr, int count);
void printEmployeeArr(const Employee* arr, int size);

#endif