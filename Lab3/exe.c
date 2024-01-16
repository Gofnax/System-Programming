#include <stdio.h>
#include <ctype.h>

#include "exe.h"
#include "arrays.h"
#include "lab3.h"

#define N 5

void q_DivMult()
{
	float num1 = 5.1, num2 = 3.9, num3 = 0;
    float mul, div;
    int res1, res2;

    res1 = calc(num1, num2, &mul, &div);
    printf("For %.2f and %.2f:\n", num1, num2);
    printf("%.2f * %.2f is %.2f\n", num1, num2, mul);
    if(res1)
    {
        printf("%.2f / %.2f is %.2f\n", num1, num2, div);
    }
    else
    {
        printf("The divition wasn't successful.\n");
    }

    res2 = calc(num1, num3, &mul, &div);
        printf("\nFor %.2f and %.2f:\n", num1, num3);
    printf("%.2f * %.2f is %.2f\n", num1, num3, mul);
    if(res2)
    {
        printf("%.2f / %.2f is %.2f\n", num1, num3, div);
    }
    else
    {
        printf("The divition wasn't successful.\n");
    }

    printf("\n");
}

void q_Char()
{
    char ch1 = 'G', ch2 = 'e', ch3 = '7', ch4 = '$';

    printf("For the char %c we get: ", ch1);
    changeChar(&ch1);
    printf("%c\n", ch1);

    printf("For the char %c we get: ", ch2);
    changeChar(&ch2);
    printf("%c\n", ch2);

    printf("For the char %c we get: ", ch3);
    changeChar(&ch3);
    printf("%c\n", ch3);

    printf("For the char %c we get: ", ch4);
    changeChar(&ch4);
    printf("%c\n", ch4);
}

void q_Reverse()
{
    int arr[N];
    initArray(arr, N);
    printArray(arr, N);
    reverseArray(arr, N);
    printArray(arr, N);
}

void q_PrintMat()
{




}

void q_PrintReverse()
{




}

void q_Palindrome()
{




}



