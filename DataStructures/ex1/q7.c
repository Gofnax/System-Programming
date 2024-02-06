#include "q7.h"

void printBin(int n)
{
    int* word = (int *)malloc(n * sizeof(int));
    bin(word, n, 0);
}

void bin(int* word, int n, int index)
{
    if(index >= n)
    {
        printWord(word, n);
        printf("\n");
        return;
    }
    *(word + index) = 0;
    bin(word, n, index + 1);
    *(word + index) = 1;
    bin(word, n, index + 1);
    return;
}

//word holds the word needed to be printed
//size indicates the length of word
void printWord(int* word, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d", *(word + i));
    }
}