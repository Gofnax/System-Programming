#include "lab2.h"

int checkArray(int arr[], int size)
{
    for(int i = 1; i < size; i++)
        if(arr[i] <= arr[i - 1])
            return 0;

    return 1;
}

/*
int countCharInMat(char mat[][COLS], int rows, int cols, char tav)
{

}*/