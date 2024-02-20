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

Airport* initAirport()
{
    Airport* pAirport = (Airport*)malloc(sizeof(Airport));
    if(pAirport != NULL)
    {
        pAirport->name = getAirportName();
        pAirport->country = getStrExactLength("Enter the country:\n");
        strcpy(pAirport->code, getCode());
    }
    return pAirport;
}

char* getCode()
{
    int codeValid;
    char* code;
    do
    {
        code = getStrExactLength("Enter the IATA code of the airport:\n");
        codeValid = checkCode(code);
        if(!codeValid)
        {
            printf("Code should be 3 letters\n");
        }
    } while (!codeValid);
    return code;
}

int checkCode(const char* code)
{
    if(code[IATA_LEN] != '\0')
    {
        return 0;
    }
    for (size_t i = 0; i < IATA_LEN; i++)
    {
        if(code[i] < 'A' || code[i] > 'Z')
        {
            return 0;
        }
    }
    return 1;
}

char* getAirportName()
{
    char* name = getStrExactLength("Enter the airport's name:\n");
    name = cleanSpaces(name);
    name = capitalizeFirstLetters(name);
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
        name = makeOneSpace(name);
    }
    return name;
}

char* makeOneSpace(char* str)
{
    char newStr[MAX_STR];
    size_t i = 0, j = 0;
    while(str[j] != '\0')
    {
        while(str[j] != ' ')
        {
            newStr[i] = str[j];
            i++;
            j++;
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

char* makeTwoSpaces(char* str)
{
    char newStr[MAX_STR];
    size_t i = 0, j = 0;
    while(str[j] != '\0')
    {
        while(str[j] != ' ')
        {
            newStr[i] = str[j];
            i++;
            j++;
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
    str = (char*)realloc(str, (strlen(newStr) + 1) * sizeof(char));
    return strcpy(str, newStr);
}

char* capitalizeAllLetters(char* str)
{
    if(str != NULL)
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
        newStr[strlen(newStr)] = '\0';
        str = (char*)realloc(str, (strlen(newStr) + 1) * sizeof(char));
        return strcpy(str, newStr);
    }
    return str;
}

size_t getNumOfWords(char* str)
{
    size_t wordCount = 0;
    while((char)*str != '\0')
    {
        while((char)*str != ' ')
        {
            str++;
        }
        wordCount++;
        while((char)*str == ' ')
        {
            str++;
        }
    }
}

char* capitalizeFirstLetters(char* str)
{
    if(str != NULL)
    {
        if((char)*str >= 'a' && (char)*str <= 'z')
        {
            *str = *str - 32;   //makes letter uppercase
        }
        for(size_t i = 1; i < strlen(str); i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] == ' '))
            {
                *(str + i) = *(str + i) - 32;
            }
        }
    }
    return str;
}

char* cleanSpaces(char* str)
{
    if(str != NULL)
    {
        char *strEnd;
        while((char)*str == ' ')
        {
            str++;
        }
        strEnd = str + strlen(str) - 1;
        while(strEnd > str && (char)*str == ' ')
        {
            strEnd--;
        }
        *(strEnd + 1) = '\0';
        str = (char*)realloc(str, (strlen(str) + 1) * sizeof(char));
    }
    return str;
}

void printAirport(Airport* pAirport)
{
    if(pAirport != NULL)
    {
        printf("Airport name:%s     Country:%s      Code:%s",
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
        free(pAirport);
    }
}