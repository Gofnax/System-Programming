#include <stdio.h>
#include "lab3.h"

int	calc(float num1, float num2, float* pMult, float* pDiv)
{
    *pMult = num1 * num2;
    
    if(num2 == 0)
        return 0;
    
    *pDiv = num1 / num2;

    return 1;
}

void changeChar(char* pTav)
{
    if(*pTav >= 'A' && *pTav <= 'Z')
        *pTav = 'C';
    else if(*pTav >= 'a' && *pTav <= 'z')
        *pTav = 'S';
    else if(*pTav >= '0' && *pTav <= '9')
        *pTav = 'D';
    else
        *pTav = 'O';
}

void reverseArray(int* arr, int size)
{
    int i = 0, j = size - 1;
    int temp;
    while(i <= j)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
        i++;
        j--;
    }
}
