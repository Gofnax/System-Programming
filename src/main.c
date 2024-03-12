
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "exe.h"

int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;
	//change to be a main param!!!
	printf("Enter option\n");
	int opt;
	scanf("%d",&opt);
	
	switch(opt)
	{
	case  1:
		Q1();
		break;

	case 2:
		Q2();
		break;

	case 3:
		Q3();
		break;

	default:
		printf("Error in params\n");
		system("pause");
		return -2;
		break;
	}

	system("pause");
	return 1;

}
