#include "pictureLines.h"

void addLines()
{
    int mat[ROWS][COLS] = { 0 };
    int rows = 0, cols = 0;
    int numOfLines = 0;
    printMatDimensions(ROWS, COLS);
    getEffectiveMatDimensions(&rows, &cols, ROWS, COLS);
    numOfLines = linesInput((int*)mat, rows, cols, COLS);
    printf("There are %d lines in the matrix.\n", numOfLines);
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

int linesInput(int* mat, int rows, int cols, int maxCols)
{
    int option = 1, isLegalLine;
    int x1, y1, x2, y2;
    int numOfLines = 0;
    while(option)
    {
        isLegalLine = getLine(rows, cols, &x1, &y1, &x2, &y2);
        if(!isLegalLine)
        {
            repeatLegalInput(rows, cols, &x1, &y1, &x2, &y2);
        }

        if(checkLineValid(mat, rows, cols, maxCols, x1, y1, x2, y2))
        {
            insertLineToMat(mat, maxCols, x1, y1, x2, y2);
            numOfLines++;
        }
        else
        {
            printf("The line can't be entered\n");
        }
        
        printf("Do you want to insert another line? 1 - yes, 0 - no:\n");
        scanf("%d", &option);
    }
    return numOfLines;
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

int getLine(int rows, int cols, int* pX1, int* pY1, int* pX2, int* pY2)
{
    printf("Insert line parameters x1, y1, x2, y2\n");
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

int checkLineValid(int* mat, int rows, int cols, int maxCols,  int x1, int y1, int x2, int y2)
{
    if(y1 > y2 || x1 > x2)  //if point 2 is above or to the left of point 1
        return 0;
    if((y1 != y2 && x1 != x2))    //if the line isn't horizontal or vertical
        return 0;
    if(!checkAdjacentRows(mat, rows, maxCols, x1, y1, x2, y2))
        return 0;
    if(!checkAdjacentCols(mat, cols, maxCols, x1, y1, x2, y2))
        return 0;
    if(x1 == x2)    //if vertical line |
    {
        if(y1 != 0 && x1 != 0 && *(mat + (y1 - 1) * maxCols + (x1 - 1)) == 1)   //checks point left and above
            return 0;
        if(y1 != 0 && x1 != cols - 1 && *(mat + (y1 - 1) * maxCols + (x1 + 1)) == 1)    //checks point right and above
            return 0;
        if(y2 != rows - 1 && x2 != 0 && *(mat + (y2 + 1) * maxCols + (x2 - 1)) == 1)    //checks point left and below
            return 0;
        if(y2 != rows - 1 && x2 != cols - 1 && *(mat + (y2 + 1) * maxCols + (x2 + 1)) == 1)    //checks point right and below
            return 0;
    }
    else if(y1 == y2)   //if horizontal line ---
    {
        if(y1 != 0 && x1 != 0 && *(mat + (y1 - 1) * maxCols + (x1 - 1)) == 1)   //checks point left and above
            return 0;
        if(y2 != 0 && x2 != cols - 1 && *(mat + (y2 - 1) * maxCols + (x2 + 1)) == 1)    //checks point right and above
            return 0;
        if(y1 != rows - 1 && x1 != 0 && *(mat + (y1 + 1) * maxCols + (x1 - 1)) == 1)    //checks point left and below
            return 0;
        if(y2 != rows - 1 && x2 != cols - 1 && *(mat + (y2 + 1) * maxCols + (x2 + 1)) == 1)    //checks point right and below
            return 0;
    }
    return 1;
}

int checkAdjacentRows(int* mat, int rows, int maxCols, int x1, int y1, int x2, int y2)
{
    for(int i = x1; i <= x2; i++)
    {
        if(y1 != 0 && *(mat + (y1 - 1) * maxCols + i) == 1) //checks the row above the line
            return 0;
        if(y2 != rows - 1 && *(mat + (y2 + 1) * maxCols + i) == 1)  //checks the row below the line
            return 0;
    }
    return 1;
}

int checkAdjacentCols(int* mat, int cols, int maxCols, int x1, int y1, int x2, int y2)
{
    for(int i = y1; i <= y2; i++)
    {
        if(x1 != 0 && *(mat + (y1 + i) * maxCols + x1 - 1) == 1)    //checks the column to the left of the line
            return 0;
        if(x2 != cols - 1 && *(mat + (y1 + i) * maxCols + x2 + 1) == 1) //check the column to the right of the line
            return 0;
    }
    return 1;
}

void insertLineToMat(int* mat, int maxCols, int x1, int y1, int x2, int y2)
{
    if(x1 == x2)    //if vertical line
    {
        for(int i = y1; i <= y2; i++)
        {
            *(mat + i * maxCols + x1) = 1;
        }
    }
    else    //if horizontal line or single point
    {
        for(int i = x1; i <= x2; i++)
        {
            *(mat + y1 * maxCols + i) = 1;
        }
    }
}