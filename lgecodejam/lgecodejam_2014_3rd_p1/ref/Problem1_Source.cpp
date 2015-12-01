#include <stdio.h>
#include <stdlib.h>

typedef struct __Tree {
	struct __Tree *pParent;
#ifdef _DEBUG
	unsigned uTag;
#endif
} Tree, *pTree;

int SolveCore0(pTree pT1, pTree pT2)	{
	while(pT2)	{
		if (pT2->pParent == pT1)
			return 1;
		pT2 = pT2->pParent;
	}
	return 0;
}

int SolveCore(pTree pT1, pTree pT2)	{
	return SolveCore0(pT1, pT2) | SolveCore0(pT2, pT1);
}

int SolveCodeJam(const char* szFileOut, const char* szFileIn)	{
	FILE* fp = fopen(szFileIn, "rt");
	if (fp == NULL)	{
		printf("Can't open Input file %s\n", szFileIn);
		return 0;
	}
	printf("Input file %s is opened\n", szFileIn);
	FILE* fpo = fopen(szFileOut, "wt");
	if (fp == NULL)	{
		printf("Can't open Output file %s\n", szFileOut);
		fclose(fp);
		return 0;
	}
	printf("Output file %s is opened\n", szFileOut);

	size_t T, M, N;
	fscanf(fp, "%u", &T);
	printf("Test Case = %d\n", T);	
	for(size_t t = 0; t < T; t++)	{
		fscanf(fp, "%u %u", &N, &M);
		printf("[%d], N = %d, M = %d\n", t, N, M);
		pTree pT = (pTree)malloc(sizeof(Tree)*N);
			
		pT->pParent = NULL;
#ifdef _DEBUG				
		pT->uTag = 1;
#endif
		pT--;

		for(size_t n = 1; n < N; n++)	{
			size_t n1, n2;
			fscanf(fp, "%u %u", &n1, &n2);
			pT[n2].pParent = pT + n1;
#ifdef _DEBUG				
			pT[n2].uTag = n2;
			pT[n1].uTag = n1;
#endif
		}
		for(size_t m = 0; m < M; m++)	{
			size_t m1, m2;
			int nRet = 1;
			fscanf(fp, "%u %u", &m1, &m2);
			if (m1 != 1 && m2 != 1)
				nRet = SolveCore(pT + m1, pT + m2);
			fprintf(fpo, "%d\n", nRet);
		}
		free(pT + 1);
	}
	fclose(fp);
	fclose(fpo);
	return 1;
}

int main(int argc, char* argv[])
{
	if (argc > 1)	{
		for(int n = 2; n < argc; n+=2)	{
			SolveCodeJam(argv[n], argv[n-1]);
		}
	} else {
		printf("Usage : %s Input1 Output1 Input2 Output2 ... InputN OutputN\n", argv[0]);
	}
	return 0;
}

