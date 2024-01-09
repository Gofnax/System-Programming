#include <stdio.h>
#include "arrays.h"
#include "lab2.h"
#include "exe.h"

void q1_A()
{
	int arr[] = {1, 2, 3, 4, 5};

    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    printf("\n");

    int res = checkArray(arr, size);

    if(res)
        printf("Array is growing\n");
    else
        printf("Array is NOT growing\n");
}

void q1_B()
{
	



}

void q2()
{

	

}
