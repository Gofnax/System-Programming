#include "airport.h"


int isSameAirport(Airport* pAirport1, Airport* pAirport2)
{
    if(strcmp(pAirport1->code, pAirport2->code))
    {
        return 0;
    }
    return 1;
}

int isAirportCode(Airport* pAirport, char* checkCode)
{
    if(strcmp(pAirport->code, checkCode))
    {
        return 0;
    }
    return 1;
}

Airport* initAirport(Airport* pAirport)
{
    char* name = getAirportName(name);

}

char* getAirportName(char* name)
{
    char nameInput[MAX_STR];
    printf("Enter the airport's name:\n");
    gets(nameInput);
    name = (char*)realloc(name, strlen(nameInput) + 1);
    cleanWhiteSpaces(name);
    capitalizeFirstLetters(name);
    size_t wordCount = getNumOfWords(name);
    if(wordCount == 1)
    {
        name = capitalizeAllLetters(name);
    }
    else if(wordCount % 2 == 0)
    {
        name = makeTwoSpaces(name);
    }
    else
    {

    }
}

char* makeOneSpace(char* str)
{
    char newStr[MAX_STR];
    size_t i = 0, j = 0;
    while(str[j] != '\0')
    {
        while(isspace(str[j]) == 0)
        {
            newStr[i] = str[j];
            i++;
            j++;
        }
        newStr[i++] = ' ';
        while(isspace(str[j]))
        {
            j++;
        }
    }
    i--;
    newStr[i] = '\0';
    return strcpy(str, newStr);
}

char* makeTwoSpaces(char* str)
{
    char newStr[MAX_STR];
    size_t i = 0, j = 0;
    while(str[j] != '\0')
    {
        while(isspace(str[j]) == 0)
        {
            newStr[i] = str[j];
            i++;
            j++;
        }
        for(; i < i + 2; i++)
        {
            newStr[i] = ' ';
        }
        while(isspace(str[j]))
        {
            j++;
        }
    }
    i -= 2;
    newStr[i] = '\0';
    return strcpy(str, newStr);
}

char* capitalizeAllLetters(char* str)
{
    char newStr[2 * strlen(str) + 1];
    for(size_t i = 0, j = 0; i < strlen(str); i++, j += 2)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            newStr[j] = str[i] - 32;
            newStr[j + 1] = '_';
        }
    }
    return strcpy(str, newStr);
}

size_t getNumOfWords(char* str)
{
    size_t wordCount = 0;
    while((char)*str != '\0')
    {
        while(isspace((char)*str) == 0)
        {
            str++;
        }
        wordCount++;
        while(isspace((char)*str))
        {
            str++;
        }
    }
}

void capitalizeFirstLetters(char* str)
{
    if(str != NULL)
    {
        if((char)*str >= 'a' && (char)*str <= 'z')
        {
            *str = *str - 32;   //makes letter uppercase
        }
        for(size_t i = 1; i < strlen(str); i++)
        {
            if((char)*(str + i) >= 'a' && (char)*(str + i) <= 'z' && isspace((char)*(str + i - 1)))
            {
                *(str + i) = *(str + i) - 32;
            }
        }
    }
}

void cleanWhiteSpaces(char* str)
{
    if(str != NULL)
    {
        char *strEnd;
        while(isspace((char)*str))
        {
            str++;
        }
        strEnd = str + strlen(str) - 1;
        while(strEnd > str && isspace((char)*str))
        {
            strEnd--;
        }
        *(strEnd + 1) = '\0';
        str = (char*)realloc(str, strlen(str) + 1);
    }
}