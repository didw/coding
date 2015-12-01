// 2014_jam3_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int root;
	int layer;
};

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp, *afp;
	//node *route;
	int *route;
	int T = 0;
	int N = 0;
	int M = 0;
	fopen_s(&fp, "test.txt", "r");
	fopen_s(&afp, "answer.txt", "w");
	fscanf_s(fp, "%d", &T);
	
	while(T-- > 0)
	{
		fscanf_s(fp, "%d %d", &N, &M);
		//route = (node*)malloc(sizeof(node)*N);
		route = (int*)malloc(sizeof(node)*(N+1));
		//route[0].root = 0;
		//route[0].layer = 1;
		route[1] = 0;
		while(--N > 0){
			int i, j;
			fscanf_s(fp, "%d %d", &i, &j);
			route[j] = i;
		}
		while(M-- > 0){
			int i, j, root;
			fscanf_s(fp, "%d %d", &i, &j);
			for(root = route[i]; root != 0; root = route[root])
			{
				if(root == j)
				{
		//			printf("%d\n", 1);
					fputs("1\n", afp);
					break;
				}
			}
			if(root == j)
				continue;
			for(root = route[j]; root != 0; root = route[root])
			{
				if(root == i)
				{
	//				printf("%d\n", 1);
					fputs("1\n", afp);
					break;
				}
			}
			if(root == 0){
//				printf("%d\n", 0);
				fputs("0\n", afp);
			}
		}
	}
	fclose(afp);
	return 0;
}

