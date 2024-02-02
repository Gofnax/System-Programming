#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include "general.h"

#define N 25

void sudokuGame();
int getSudokuSize(int maxSize);
void initBoard(int* board, int size, const int maxSize);
int checkBoardValidity(const int* board, char* helper, int size, int maxSize);
int checkRowValidity(const int* board, char* helper, int row, int size, int maxSize);
int checkColValidity(const int* board, char* helper, int col, int size, int maxSize);
int checkSubSquareValidity(const int* board, char* helper, int row, int col, int size, int maxSize);
int checkValidity(char* helper, int value, int size);
void printIsBoardValid(const int* board, char* helper, int size, int maxSize);

#endif