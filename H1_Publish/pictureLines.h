#ifndef __PICTURELINES_H__
#define __PICTURELINES_H__

#include "general.h"

#define ROWS 50
#define COLS 50

void addLines();
void printMatDimensions(int rows, int cols);
void getEffectiveMatDimensions(int* rows, int* cols, int maxRows, int maxCols);

#endif