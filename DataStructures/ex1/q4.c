#include "q4.h"

int decToBiRec(int num)
{
    if(num == 0)
        return 0;

    int biDigit = num % 2;
    int res = decToBiRec(num / 2);
    return res * 10 + biDigit;
}