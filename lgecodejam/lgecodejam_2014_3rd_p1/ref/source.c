#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main()
{
	FILE *in, *out;
	int T;
	int i = 0,j=0;

	//file I/O
	if ((in = fopen("A-large.in", "r")) == 0)
	{
		printf("Input File error!!\n");
		return;
	}

	if((out = fopen("output.txt", "w")) ==0)
	{
		printf("Output File error!!\n");
		return;
	}

	//Read Number of TestCase
	fscanf(in, "%d", &T);
	
	for (i = 0; i < T; i++)
	{
		int N, M;
		int *NodeInfo;

		fscanf(in, "%d %d", &N, &M);
		NodeInfo = (int *)malloc(sizeof(int *)*N);
		memset(NodeInfo, 0x00, sizeof(int *)*N);

		//make tree
		for (j = 0; j < N - 1; j++)
		{
			int num1, num2;
			fscanf(in, "%d %d", &num1, &num2);
			
			NodeInfo[num2 - 1] = num1;
		}

		//query
		for (j = 0; j < M; j++)
		{
			int num1, num2 , temp , re;
			fscanf(in, "%d %d", &num1, &num2);

			if (num1 == num2 || num1 == 1 || num2 == 1)
			{
				fprintf(out, "1\n");
				continue;
			}

			re = 0;
			temp = num2;
			while (NodeInfo[temp - 1] != 0)
			{
				if (NodeInfo[temp - 1] == num1)
				{
					fprintf(out, "1\n");
					re = 1;
					break;
				}
				temp = NodeInfo[temp - 1];
			}

			if (re)
				continue;

			temp = num1;
			while (NodeInfo[temp - 1] != 0)
			{
				if (NodeInfo[temp - 1] == num2)
				{
					fprintf(out, "1\n");
					re = 1;
					break;
				}
				temp = NodeInfo[temp - 1];
			}

			if (re == 0)
				fprintf(out, "0\n");

		}

		//free
		free(NodeInfo);

	}



	//free FD
	if (in != 0)
	{
		fclose(in);
	}

	if (in != 0)
	{
		fclose(out);
	}

	printf("End!!!\n");
	return;
}

