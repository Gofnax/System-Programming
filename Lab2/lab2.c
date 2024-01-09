#include <stdint.h>
#include <ctype.h>
#include "lab2.h"

int checkArray(int arr[], int size)
{
    for(int i = 1; i < size; i++)
        if(arr[i] <= arr[i - 1])
            return 0;

    return 1;
}

int countCharInMat(char mat[][COLS], int rows, int cols, char tav)
{
    if(cols > COLS)
    {
        printf("Error\n");
        return -1;
    }

    int count = 0;
    char checkTav = tolower(tav);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(checkTav == tolower(mat[i][j]))
                count++;
        }
    }

    return count;
}
