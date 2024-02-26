#include <stdio.h>
#include "lab1.h"

int main(void)
{
    int basis = 1;

    helloWorld();
    
    printf("Please enter a number:\n");
    int ret = scanf("%d", &basis);
    printTriangle(basis);
    printf("\n");
    return ret;
}