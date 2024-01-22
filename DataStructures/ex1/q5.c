#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "q5.h"
char *s;

char * makeNumIntoHexadecimal(int num)
{
    char dig2;
    int dig1;
    if(num == 0)
    {
        s = (char *)malloc(1);
        *s = '\0';
        return s;
    }
    dig1 = num % 16;
    if(dig1 <= 9)
        dig2 = dig1 + 48;
    else   
        dig2 = dig1 + 65 - 10;
    s = makeNumIntoHexadecimal(num / 16);
    s = (char *)realloc(s, strlen(s) + 2);
    int len = strlen(s);
    s[len] = dig2;
    s[len + 1] = '\0';
    return s;
}
