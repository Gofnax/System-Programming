#ifndef __PICTUREMANIPULATION_H__
#define __PICTUREMANIPULATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "general.h"

#define X 8
#define MIN 1
#define MAX 99

void transposeMat(int* mat, int n, int maxSize);
void rotateClockwise(int* mat, int n);
void rotateCounterClockwise(int* mat, int n);
void flipHorizontal(int* mat, int n);
void flipVertical(int* mat, int n);
void initMatQ3(int* mat, int size, int maxSize);
void pictureManipulation();



#endif
