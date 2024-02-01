#include "pictureLines.h"

void addLines()
{
    int mat[ROWS][COLS] = { 0 };
    int rows = 0, cols = 0;
    printMatDimensions(ROWS, COLS);
    getEffectiveMatDimensions(&rows, &cols, ROWS, COLS);
    linesInput((int*)mat, rows, cols);
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

void linesInput(int* mat, int rows, int cols)
{
    int option = 1, isLegalLine;
    int x1, y1, x2, y2;

    while(option)
    {
        isLegalLine = getLine(rows, cols, &x1, &y1, &x2, &y2);
        if(!isLegalLine)
        {
            repeatLegalInput(rows, cols, &x1, &y1, &x2, &y2);
        }
        printf("Do you want to insert another line? 1 - yes, 0 - no:\n");
        scanf("%d", &option);
    }

    if(checkLineValid(mat, rows, cols, x1, y1, x2, y2))
    {
        
    }
}

void repeatLegalInput(int rows, int cols, int* pX1, int* pY1, int* pX2, int* pY2)
{
    int isLegalLine;
    do
    {
        printf("Illegal line. Insert again\n");
        isLegalLine = getLine(rows, cols, pX1, pY1, pX2, pY2);
    } while (!isLegalLine);
}

void inputCoodrdination(int* num)
{
    int buff;
    scanf("%d", &num);
    scanf("%d", &buff);
}

int getLine(int rows, int cols, int* pX1, int* pY1, int* pX2, int* pY2)
{
    printf("Insert line parameters x1, y1, x2, y2");
    //inputCoodrdination(pX1);
    //inputCoodrdination(pY1);
    //inputCoodrdination(pX2);
    //inputCoodrdination(pY2);
    scanf("%d", pX1);
    scanf("%d", pY1);
    scanf("%d", pX2);
    scanf("%d", pY2);
    if(*pX1 >= 0 && *pX1 < rows)
    {
        if(*pY1 >= 0 && *pY1 < cols)
        {
            if(*pX2 >= 0 && *pX2 < rows)
            {
                if(*pY2 >= 0 && *pY2 < cols)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int checkLineValid(int* mat, int rows, int cols, int x1, int y1, int x2, int y2)
{
    
}
