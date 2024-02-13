#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#define MAX_LENGTH 21

typedef struct
{
	char	name[MAX_LENGTH];
	int		salary;
	float	seniority;
}Employee;

int initEmployeeArr(Employee** arr, int count);
void initEmployee(Employee* pEmp);
void printEmployeeArr(const Employee** arr, int size);
void printEmployee(const Employee* pEmp);
void freeEmployeeArr(Employee** arr, int size);
int compareEmployeeBySalary(const void* v1, const void* v2);


#endif