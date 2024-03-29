#include "Airport.h"

int isSameAirport(Airport* pAirport1, Airport* pAirport2)
{
    if(pAirport1 != NULL && pAirport1 != NULL)
    {
        if(strcmp(pAirport1->code, pAirport2->code))
        {
            return 0;
        }
        return 1;
    }
    return -1;
}

int isAirportCode(Airport* pAirport, char* checkCode)
{
    if(pAirport == NULL)
    {
        return -1;
    }
    if(strcmp(pAirport->code, checkCode))
    {
        return 0;
    }
    return 1;
}

Airport* initAirport()
{
    Airport* pAirport = (Airport*)malloc(sizeof(Airport));
    if(pAirport != NULL)
    {
        getAirportName(pAirport);
        pAirport->country = getStrExactLength("Enter airport country");
        strcpy(pAirport->code, getCode());
    }
    return pAirport;
}

void initAirportNoCode(Airport* pAirport)
{
    if(pAirport != NULL)
    {
        getAirportName(pAirport);
        pAirport->country = getStrExactLength("Enter airport country");
    }
}

char* getCode()
{
    int codeValid;
    char* code;
    do
    {
        printf("Enter the IATA code of the airport:\n");
        code = myGets(code, IATA_LEN + 1);
        codeValid = checkCode(code);
        if(!codeValid)
        {
            printf("Code should be 3 letters\n");
        }
    } while (!codeValid);
    return code;
}

void getAirportCode(char* code)
{
    do
    {
        printf("Enter airport code - 3 UPPER CASE letters\n");
        code = myGets(code, IATA_LEN + 2);
    } while (!checkCode(code));
}

int checkCode(const char* code)
{
    if(code[IATA_LEN] != '\0')
    {
        printf("code should be 3 letters\n");
        return 0;
    }
    for (size_t i = 0; i < IATA_LEN; i++)
    {
        if(code[i] < 'A' || code[i] > 'Z')
        {
            printf("Need to be upper case letter\n");
            return 0;
        }
    }
    return 1;
}

void getAirportName(Airport* pAirport)
{
    char* name = getStrExactLength("Enter airport name");
    name = cleanSpaces(name);
    name = capitalizeFirstLetters(name);
    int wordCount = getNumOfWords(name);
    if(wordCount == 1)
    {
        name = capitalizeAllLetters(name);
    }
    else if(wordCount % 2 == 0)
    {
        name = makeTwoSpaces(name);
    }
    else if(wordCount % 2 == 1)
    {
        name = makeOneSpace(name);
    }
    pAirport->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(pAirport->name, name);
    free(name);
}

char* makeOneSpace(char* str)
{
    if(str != NULL)
    {
        char newStr[MAX_STR];
        size_t i = 0, j = 0;
        while(str[j] != '\0')
        {
            while(str[j] != ' ' && str[j] != '\0')
            {
                newStr[i++] = str[j++];
            }
            newStr[i++] = ' ';
            while(str[j] == ' ')
            {
                j++;
            }
        }
        i--;
        newStr[i] = '\0';
        str = (char*)realloc(str, (strlen(newStr) + 1) * sizeof(char));
        return strcpy(str, newStr);
    }
    return NULL;
}

char* makeTwoSpaces(char* str)
{
    if(str != NULL)
    {
        char newStr[MAX_STR];
        size_t i = 0, j = 0;
        while(str[j] != '\0')
        {
            while(str[j] != ' ' && str[j] != '\0')
            {
                newStr[i++] = str[j++];
            }
            for(size_t k = 0; k < 2; k++)
            {
                newStr[i++] = ' ';
            }
            while(str[j] == ' ')
            {
                j++;
            }
        }
        i -= 2;
        newStr[i] = '\0';
        str = (char*)realloc(str, (i + 1) * sizeof(char));
        strcpy(str, newStr);
    }
    return str;
}

char* capitalizeAllLetters(char* str)
{
    if(str != NULL)
    {
        size_t len = strlen(str);
        char* newStr = (char*)malloc((2 * len + 1) * sizeof(char));
        if(newStr == NULL)
        {
            return NULL;
        }
        for(size_t i = 0, j = 0; i < len; i++, j += 2)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                newStr[j] = str[i] - 32;
            }
            else
            {
                newStr[j] = str[i];
            }
            newStr[j + 1] = '_';
        }
        newStr[len * 2 - 1] = '\0';
        str = (char*)realloc(str, (strlen(newStr) + 1) * sizeof(char));
        strcpy(str, newStr);
        free(newStr);
    }
    return str;
}

int getNumOfWords(const char* str)
{
    if(str == NULL)
    {
        return -1;
    }
    int wordCount = 0;
    while(str[0] != '\0')
    {
        while(str[0] != ' ' && str[0] != '\0')
        {
            str++;
        }
        wordCount++;
        while(str[0] == ' ')
        {
            str++;
        }
    }
    return wordCount;
}

char* capitalizeFirstLetters(char* str)
{
    if(str != NULL)
    {
        size_t len = strlen(str);
        if(str[0] >= 'a' && str[0] <= 'z')
        {
            str[0] = str[0] - 32;   //makes letter uppercase
        }
        for(size_t i = 1; i < len; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] == ' '))
            {
                str[i] = str[i] - 32;
            }
        }
    }
    return str;
}

char* cleanSpaces(char* str)
{
    if(str != NULL)
    {
        size_t i = 0;
        char* newStr = strcpy(newStr, str);
        char *strEnd;
        while(newStr[0] == ' ')
        {
            newStr++;
        }
        strEnd = newStr + strlen(newStr) - 1;
        while(strEnd > newStr + i && strEnd[0] == ' ')
        {
            strEnd--;
        }
        strEnd[1] = '\0';
        str = (char*)realloc(str, (strlen(newStr) + 1) * sizeof(char));
        strcpy(str, newStr);
    }
    return str;
}

void printAirport(Airport* pAirport)
{
    if(pAirport != NULL)
    {
        printf("Airport name:%-25s Country:%-25s Code:%s\n",
            pAirport->name, pAirport->country, pAirport->code);
    }
}

void freeAirport(Airport* pAirport)
{
    if(pAirport != NULL)
    {
        free(pAirport->name);
        free(pAirport->country);
        //free(pAirport->code);
        //free(pAirport);
    }
}