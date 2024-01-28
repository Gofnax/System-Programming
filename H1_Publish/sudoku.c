#include sudoku.h

int checkSudoku()
{
    int board[N][N];    //the MAX sized sudoku matrix
    int helper[N];      //an array to help with the validy checks
    int maxSize = N;
    int size = getSudokuSize();
    initBoard(board, size);
}

int getSudokuSize()
{
    int size = 0;
    do
    {
        printf("Enter Sudoku size, sqrt(size) need to be an integer less then %d\n", N);
        scanf("%d", &size);
    }while((sqrt(size) != (int)(sqrt(size))) && (sqrt(size) > 0) && (size <= 25));
    return size;
}

void initBoard(int* board, int size, int maxSize)
{
    int num = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("enter element %2d %2d", i, j);
            scanf("%d", num);
            if(num > 0 && num <= maxSize)
            {
                *(board + i * maxSize + j) = num;
            }
            else
            {
                printf("Invalid value\n");
                j--;
            }
        }
    }
}



