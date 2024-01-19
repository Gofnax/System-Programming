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

    return res + biDigit * raisePower(10, counter); //(int)pow(10, counter);
}

int raisePower(int num, int exp)
{
    int res = 1;

    for(int i = 0; i < exp; i++)
        res *= num;

    return res;
}