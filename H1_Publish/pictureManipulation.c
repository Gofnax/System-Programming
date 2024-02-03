#include "pictureManipulation.h"

void pictureManipulation()
{
	int mat[X][X]={0};
	int n;
	printf("Max mat size is: %d\n", X);
	do
	{
		printf("Insert picture size between 1 and %d\n", X);
		scanf("%d",&n);
	}while (n < 1 || n > 8);
	printf("effecive mat size is: %d\n", n);
	initMatQ3((int*)mat, n, X);
	printMat((int*)mat, n, n, X);
	int option = 0;
	do
	{
		printf("Please choose one of the following options\n");
		printf("1 - 90 degree clockwise\n");
		printf("2 - 90 degree counter clockwise\n");
		printf("3 - Flip Horizontal\n");
		printf("4 - Flip Vertical\n");
		printf("-1 - Quit\n");
		printf("\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			rotateClockwise((int*)mat, n);
			printf("--------- picture after manipulation ---------\n");
			printMat((int*)mat, n, n, X);
			break;
		case 2:
			rotateCounterClockwise((int*) mat, n);
			printf("--------- picture after manipulation ---------\n");
			printMat((int*)mat, n, n, X);
			break;
		case 3:
			flipHorizontal((int*) mat, n);
			printf("--------- picture after manipulation ---------\n");
			printMat((int*)mat, n, n, X);
			break;
		case 4:
			flipVertical((int*) mat, n);
			printf("--------- picture after manipulation ---------\n");
			printMat((int*)mat, n, n, X);
			break;
		case -1:
			printf("Bye bye\n");
			break;
		}
		
	}while(option != -1);

}

void transposeMat(int* mat, int n, int maxSize)
{
	int temp;
	for(int i = 0; i < n ; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			temp = *(mat + i * maxSize + j);
			*(mat + i * maxSize + j) = *(mat + j * maxSize + i);
			*(mat + j * maxSize + i) = temp;
		}
	}

}

void rotateClockwise(int* mat, int n)
{
	transposeMat(mat, n, X);
	flipVertical(mat, n);

}

void rotateCounterClockwise(int* mat, int n)
{
	transposeMat(mat, n, X);
	flipHorizontal(mat,n);	
}

void flipVertical(int* mat, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
		int temp = *(mat + i * X + j);
		*(mat + i * X + j) = *(mat + i * X + n - 1 - j);
		*(mat + i * X + n - 1 - j) = temp;
		}
	}
}
void flipHorizontal(int* mat, int n)
{
	for(int j = 0; j < n; j++)
	{
		for(int i = 0; i < n / 2; i++)
		{
		int temp = *(mat + i*X + j);
		*(mat + i*X + j) = *(mat + (n - 1 - i)*X + j);
		*(mat + (n - 1 - i)*X + j)= temp;
		}
	}
}

void initMatQ3(int* mat, int size, int maxSize)
{
	for(int i = 0; i < size; i++)
	{
	    for(int j = 0; j < size; j++)
	    {
	        *(mat + i*maxSize +j) = MIN + (rand() % (MAX - MIN + 1)); 
	    }
	    
	}
}

