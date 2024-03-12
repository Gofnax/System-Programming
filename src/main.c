
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "exe.h"

int main(int argc, char* argv[])
{
	int opt;
	if(argc == 2)
	{
		int res = sscanf(argv[1], "%d", &opt);
	}
	else
	{
		printf("Enter option\n");
		scanf("%d",&opt);
	}
	
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
