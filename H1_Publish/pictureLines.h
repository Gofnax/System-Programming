#ifndef __PICTURELINES_H__
#define __PICTURELINES_H__

#include "general.h"

#define ROWS 50
#define COLS 50

void addLines();
void printMatDimensions(int rows, int cols);
void getEffectiveMatDimensions(int* rows, int* cols, int maxRows, int maxCols);
int linesInput(int* mat, int rows, int cols, int maxCols);
int getLine(int rows, int cols, int* pX1, int* pY1, int* pX2, int* pY2);
int checkLineValid(int* mat, int rows, int cols, int maxCols,  int x1, int y1, int x2, int y2);
int checkAdjacentRows(int* mat, int rows, int maxCols, int x1, int y1, int x2, int y2);
int checkAdjacentCols(int* mat, int cols, int maxCols, int x1, int y1, int x2, int y2);
void insertLineToMat(int* mat, int maxCols, int x1, int y1, int x2, int y2);


#endif