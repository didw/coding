// 2014_3_Prob1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int FindJunction(int *Tree, int num1, int num2)
{
	int iter;
	if(num1 == num2) return 1;

	iter = num1;
	while(iter != 1)
	{
		iter = Tree[iter];
		if(iter == num2)
			return 1;
	}

	iter = num2;
	while(iter != 1)
	{
		iter = Tree[iter];
		if(iter == num1)
			return 1;
	}

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp, *fpout;;
	fp = fopen(argv[1], "r");
	fpout = fopen("out.txt", "w");
	if(NULL == fp) return 0;
	
	int *Tree;
	int T, N, M;
	int num1, num2;
	fscanf(fp, "%d", &T);

	for(int t=0; t<T; t++)
	{
		fscanf(fp, "%d %d", &N, &M);

		Tree = (int *)malloc(sizeof(int) * (N+1));

		for(int n=0; n<N-1; n++)
		{
			fscanf(fp, "%d %d", &num1, &num2);
			Tree[num2] = num1;
		}

		for(int m=0; m<M; m++)
		{
			fscanf(fp, "%d %d", &num1, &num2);
						
			fprintf(fpout, "%d\n", FindJunction(Tree, num1, num2));
		}

		free(Tree);
	}

	fclose(fp);
	fclose(fpout);

	return 0;
}

