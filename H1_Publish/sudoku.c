#include sudoku.h

int checkSudoku()
{
    int board[N][N];    //the MAX sized sudoku matrix
    char helper[N];      //an array to help with the validy checks
    const int maxSize = N;
    int size = getSudokuSize(maxSize);
    initBoard(board, size, maxSize);
    printMat(board, size, size);
}

int getSudokuSize(int maxSize)
{
    int size = 0;
    int maxBoard = maxSize * maxSize;
    do
    {
        printf("Enter Sudoku size, sqrt(size) need to be an integer less then %d\n", maxBoard);
        scanf("%d", &size);
    }while((sqrt((double)size) != (int)(sqrt((double)size))) && (size > maxBoard));
    return (int)size;
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

int checkBoardValidity(const int* board, char* helper, int size, int maxSize)
{
    int res = 1;
    for(int i = 0; i < size && res; i++)
    {
        res = checkRowValidity(board, helper, i, size, maxSize);
    }
    for(int i = 0; i < size && res; i++)
    {
        res = checkColValidity(board, helper, i, size, maxSize);
    }
}

int checkRowValidity(const int* board, char* helper, int row, int size, int maxSize)
{
    memset(helper, '0', maxSize);  //initializes the helper array to have only '0'
    int value = 0;
    for(int i = 0; i < size; i++)
    {
        value = *(board + row * maxSize + i);
        if(!checkValidity(helper, value))
        {
            return 0;   //the row is not valid
        }
    }
    return 1;   //the row is valid
}

int checkColValidity(const int* board, char* helper, int col, int size, int maxSize)
{
    memset(helper, '0', maxSize);   //initializes the helper array to have only '0'
    int value = 0;
    for(int i = 0; i < size; i++)
    {
        value = *(board + i * maxSize + col);
        if(!checkValidity(helper, value))
        {
            return 0;   //the column is not valid
        }
    }
    return 1;   //the column is valid
}

int checkSubSquareValidity(const int* board, char* helper, int row, int col, int size, int maxSize)
{
    memset(helper, '0', maxSize);   //initializes the helper array to have only '0'
    int value = 0, step = (int)(sqrt(size));
    for(int i = 0; i < size; i += step)
    {
        for(int j = 0; j < size; j += step)
        {
            value = *(board + i * maxSize + j);
            if(!checkValidity(helper, value))
            {
                return 0;   //the column is not valid
            }
        }
    }
    return 1;
}

int checkValidity(char* helper, int value)
{
    if(*(helper + value - 1) == '1')
    {
        return 0;
    }
    *(helper + value - 1) = '1';
    return 1;
}