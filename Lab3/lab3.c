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
