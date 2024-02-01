#ifndef __PICTURELINES_H__
#define __PICTURELINES_H__

#include "general.h"

#define ROWS 50
#define COLS 50

void addLines();
void printMatDimensions(int rows, int cols);
void getEffectiveMatDimensions(int* rows, int* cols, int maxRows, int maxCols);
void linesInput(int rows, int cols);
void inputCoodrdination(int* num);
int getLine(int rows, int cols, int* pX1, int* pY1, int* pX2, int* pY2);


#endif