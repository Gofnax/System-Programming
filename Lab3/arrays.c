#include <stdio.h>
#include <ctype.h>
#include "arrays.h"


void printArray(const int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%5d", *(arr++));

	printf("\n");
}

void initArray(int* arr, int size)
{
	int i;
	printf("Please enter %d elemnts for array\n", size);
	for (i = 0; i < size; i++)
		scanf("%d", arr++);
}