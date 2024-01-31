#include "pictureLines.h"

void addLines()
{
    //int mat[ROWS][COLS] = { 0 };
    int rows = 0, cols = 0;
    printMatDimensions(ROWS, COLS);
    getEffectiveMatDimensions(&rows, &cols, ROWS, COLS);
}

void printMatDimensions(int rows, int cols)
{
    printf("Mat ROWS: %d , COLS: %d\n", rows, cols);
}

void getEffectiveMatDimensions(int* rows, int* cols, int maxRows, int maxCols)
{
    do
    {
        printf("Insert number of rows for big Matrix between 1 and %d\n", maxRows);
        scanf("%d", rows);
    } while (*rows < 1 || *rows > maxRows);
    
    do
    {
        printf("Insert number of columns for big Matrix: between 1 and %d\n", maxCols);
        scanf("%d", cols);
    }while(*cols < 1 || *cols > maxCols);
    
    printf("Effective size %d*%d\n", *rows, *cols);
}

