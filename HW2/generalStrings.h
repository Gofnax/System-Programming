#ifndef __GENERAL_STRINGS_H__
#define __GENERAL_STRINGS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 255

char* getStrExactLength(const char* msg);
char* myGets(char* buffer, int size);

#endif