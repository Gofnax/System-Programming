#include <stdio.h>

#include "q3.h"
#include "q4.h"
#include "q5.h"
#include "q6.h"

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

    //check for question 5
    int num5;
    printf("Insert a number:\n");
    scanf("%d", &num5);
    printf("%s\n", makeNumIntoHexadecimal(num5));

    //cheack for question 6
    int num6n = 3;
    double num6p = 0.3;
    printf("The prob of odd successes is %f\n", oddSuccessRec(num6p, num6n, num6n));
}
