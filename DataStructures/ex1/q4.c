#include "q4.h"

int decToBiRec(int num)
{
    if(num == 0)
        return 0;

    int biDigit = num % 2;
    int res = decToBiRec(num / 2);
    int temp = res, counter = 0;

    while(temp > 0)
    {
        temp /= 10;
        counter++;
    }

    if(!biDigit)
        counter++;

    return res * 10 + biDigit;
}