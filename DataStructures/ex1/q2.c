#include "q2.h"

double Tr2(double* vec, int size, int currentIndex)
{
    if (currentIndex == size)
        return 0;
    double sum = vec[currentIndex] + Tr2(vec, size, currentIndex + 1);
    if (currentIndex == 0)
        return sum / size;
    return sum;
}