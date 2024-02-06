#include "q2.h"

//vec holds the array of number we calculate the average for
//size is used to know when we got to the end of vec
//currentIndex is used to know the current index we check in vec
double Tr2(double* vec, int size, int currentIndex)
{
    if (currentIndex == size)
        return 0;
    double sum = vec[currentIndex] + Tr2(vec, size, currentIndex + 1);
    if (currentIndex == 0)
        return sum / size;
    return sum;
}