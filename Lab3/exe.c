#include <stdio.h>
#include <ctype.h>

#include "exe.h"
#include "lab3.h"

void q_DivMult()
{
	float num1 = 5.17, num2 = 3.94, num3 = 0;
    float mul, div;
    int res1, res2;

    res1 = calc(num1, num2, &mul, &div);
    printf("%f * %f is %f\n", num1, num2, mul);
    if(res1)
    {
        printf("The divition was successful.\n");
        printf("%f / %f is %f\n", num1, num2, div);
    }
    else
    {
        printf("The divition wasn't successful.\n");
    }

    res2 = calc(num1, num3, &mul, &div);
    printf("%f * %f is %f\n", num1, num2, mul);
    if(res2)
    {
        printf("The divition was successful.\n");
        printf("%f / %f is %f\n", num1, num3, div);
    }
    else
    {
        printf("The divition wasn't successful.\n");
    }

}

void q_Char()
{



}

void q_Reverse()
{
	



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



