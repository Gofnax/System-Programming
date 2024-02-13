#ifndef __FUNCTIONS__
#define __FUNCTIONS__


int* getEvenNumbers(const int* arr, int size, int* newSize);
int	 getMax(const int* arr, int count);
void* getGeneralMax(const void* arr, int count, size_t typeSize, int (*compare)(const void*, const void*));



#endif