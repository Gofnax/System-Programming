#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <math.h>

#define N 25

int checkSudoku();
int getSudokuSize();
void initBoard(int* board, int size, int maxSize);

#endif