#include <stdio.h>

#include "q3.h"
#include "q4.h"

int main()
{
    //check for question 3
    char A[N][N] = {{'f', 'd', 'a', 'a', 'b'},
                    {'f', 'u', 'a', 'b', 'a'},
                    {'f', 'h', 'b', 'a', 'a'},
                    {'s', 'k', 'n', 'b', 's'},
                    {'a', 'b', 'b', 'k', 'n'}};
    printf("Arrow size = %d\n", check(A));
    //getchar();

    //check for question 4
    int num4 = 4;
    int res4 = decToBiRec(num4);
    printf("The binary rep of %d is %d\n", num4, res4);
}


