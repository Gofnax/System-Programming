#include <stdio.h>
#include <stdlib.h>
#include "functions.h"



int* getEvenNumbers(const int* arr, int size, int* newSize)
{
	int* newArr = NULL;
	int i;
	int count = 0, index;

	//Pass 1 - find how many evens
	for (i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
			count++;
	}
	*newSize = count;
	if (count == 0) //no evens!!!
		return NULL;

	//create the new array in the correct size
	newArr = (int*)malloc(count * sizeof(int));
	if (!newArr)			//if(newArr == NULL)
		return NULL;

	//Pass 2 - copy the evens
	index = 0;
	for (i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			newArr[index] = arr[i];
			index++;
		}
	}

	return newArr;
}

int	 getMax(const int* arr, int count)
{
	int max = arr[0];
	for (int i = 1; i < count; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void* getGeneralMax(const void* arr, int count, size_t typeSize, int (*compare)(const void*, const void*))
{
	const void* maxAddress = arr;
	const void* element;
	for(int i = 1; i < count; i++)
	{
		element = (char*)arr + i * typeSize;
		if(compare(element, maxAddress) > 0)
		{
			maxAddress = element;
		}
	}
	return maxAddress;
}