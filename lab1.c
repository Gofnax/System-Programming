#include "lab1.h"
#include <stdio.h>

void helloWorld()
{
    printf("Hello world\n");
}

void printTriangle(int base)
{
    for(int i = 1; i <= base; i++)
    {
        for(int j = 1; j <= base -i; j++)
            printf(" ");
        for(int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}
