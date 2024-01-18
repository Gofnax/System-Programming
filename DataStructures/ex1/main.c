#include <stdio.h>

#include "q3.h"

int main()
{
    char A[N][N] = {{'f', 'd', 'a', 'a', 'b'},
                    {'f', 'u', 'a', 'b', 'a'},
                    {'f', 'h', 'b', 'a', 'a'},
                    {'s', 'k', 'n', 'b', 's'},
                    {'a', 'b', 'b', 'k', 'n'}};
    printf("Arrow size = %d\n", check(A));
    //getchar();
}


