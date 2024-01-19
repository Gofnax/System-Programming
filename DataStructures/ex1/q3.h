#ifndef __Q3_H__
#define __Q3_H__

#define N 5
typedef char mat[N][N];
typedef enum {FALSE, TRUE} boolean;
mat A;

int check(mat A);
int arrowMat(mat A, int currLine);

#endif