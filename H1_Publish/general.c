#include "general.h"

void printMat(const int* mat,int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%3d", *(mat + i * cols + j));
        }
        printf("\n");
    }
    printf("\n");
}