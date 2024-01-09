#include <stdio.h>
#include "lab1.h"

int main()
{
    int basis;

    helloWorld();
    
    printf("Please enter a number:\n");
    scanf("%d", &basis);
    printTriangle(basis);
}