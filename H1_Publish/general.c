#include "general.h"

void printMat(const int* mat, int rows, int cols, int maxRows)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%5d", *(mat + i * maxRows + j));
        }
        printf("\n");
    }
    //printf("\n");
}