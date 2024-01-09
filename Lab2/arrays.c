#include <stdio.h>
#include <ctype.h>
#include "arrays.h"

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%5d", arr[i]);
}

void initArray(int arr[], int size)
{
    printf("Please enter %d numbers\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void printMat(char mat[][COLS], int rows, int cols)
{
    if(cols > COLS)
    {
        printf("Error!!\n");
        return;
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            printf("%c", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void initMat(char mat[][COLS], int rows, int cols)
{
    if(cols > COLS)
    {
        printf("Error!!\n");
        return;
    }

    printf("Please enter %d chars to matrix\n", rows * cols);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            do{//a loop to make sure we don't get whitespaces into the matrix
                scanf("%c", &mat[i][j]);
            }while(isspace(mat[i][j]));
        }
    }
}
