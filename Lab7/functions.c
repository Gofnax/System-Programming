#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "generalStrings.h"

#define END_STR "Bye"
#define CHAR_SEP "$"
#define MAX_STR 200

char* createCombineStrings()
{
    char temp[MAX_STR];
    char* longStr = NULL;
    size_t len, totalLen = 0;

    while(1)
    {
        printf("Please enter a string or %s to exit\n", END_STR);
        myGets(temp, sizeof(temp));
        if(strcmp(temp, END_STR) == 0)
        {
            break;
        }
        
        len = strlen(temp);
        totalLen += len;

        if(longStr == NULL)
        {
            longStr = (char*)malloc((len + 1) * sizeof(char));
            if(!longStr)
                return NULL;
            strcpy(longStr, temp);
        } else {
            longStr = (char*)realloc(longStr,  (totalLen + 1) * sizeof(char));
            if(!longStr)
                return NULL;
            strcat(longStr, CHAR_SEP);
            strcat(longStr, temp);
            totalLen++;
        }
        return longStr;
    }
}

