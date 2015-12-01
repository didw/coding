#include<stdlib.h>

#include<stdio.h>

int FindTree(int *Array, int q1, int q2)
{
	int q11, ret = 0;
	q11 = q1;
	while (1)
	{
		if (Array[q1] != q2)
		{
			if (Array[q1] == 0)
			{
				ret = 0;
				break;
			}
			q1 = Array[q1];
		}
		else
		{
			return 1;
		}
	}
	q1 = q11;
	while (1)
	{
		if (Array[q2] != q1)
		{
			if (Array[q2] == 0)
			{
				ret = 0;
				return 0;
			}
			q2 = Array[q2];
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

void initArray(int *Array, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		Array[i] = 0;
	}
}

void ProcessNode(char *filename)
{
	FILE *fp;
	FILE *f2;
	static int count = 0;
	f2 = fopen("result.txt", "w");
	int T, N, M, t, n, m;
	int num1, num2, q1, q2;
	int *Array = NULL;
	fp = fopen(filename,"r");
	fscanf(fp, "%d", &T);
	for (t = 0; t < T; t++)
	{
		fscanf(fp, "%d %d", &N, &M);
		printf("T: %d, N:%d, M:%d\n", T, N, M);
//		fprintf(f2, "T: %d, N:%d, M:%d\n", T, N, M);
		if (Array == NULL)
		{
			Array = (int *)malloc(sizeof(int *)* (N+1));
		}
		initArray(Array, N);
		for (n = 1; n < N; n++)
		{
			fscanf(fp, "%d %d", &num1, &num2);
			Array[num2] = num1;
		}
		for (m = 0; m < M; m++)
		{
			int ret;
			fscanf(fp,"%d %d",&q1,&q2);
			ret = FindTree(Array, q1,q2);
			fprintf(f2, "%d\n", ret);
		}
		free(Array);
		Array = NULL;
	}
	if (fp != NULL)
		fclose(fp);
	fp = NULL;
	fclose(f2);
}

void main(int argc, char *argv[]){
	char *filename;
	if (argv[1] != NULL)
		filename = argv[1];
	else
		return;
	ProcessNode(filename);
}