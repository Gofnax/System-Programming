#include "q3.h"

int check(mat A)
{
    int maxArrowMat = arrowMat(A, 0);
    return maxArrowMat;
}

int arrowMat(mat A, int currLine)
{
    if(currLine >= N)
        return 1;
    
    for(int i = 0; i < currLine; i++)  //goes through the rows
        if(A[i][N - 1 - currLine] != 'a')
            return 0;
    
    for(int i = N - 1; i > N - 1 - currLine; i--)   //goes through the columns
        if(A[currLine][i] != 'a')
            return 0;
    
    if(A[currLine][N - 1 - currLine] != 'b')
        return 0;
    
    return arrowMat(A, currLine + 1) + 1;
}