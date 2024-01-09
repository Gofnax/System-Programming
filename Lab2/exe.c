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

#define ROWS 4
void q2()
{
    char mat[ROWS][COLS];
    initMat(mat, ROWS, 3);
    printMat(mat, ROWS, 3);

    char tav = 'B';
    int c = countCharInMat(mat, ROWS, 3, tav);
	
    if(c != -1)
        printf("%c is %d in matrix\n", tav, c);

}
