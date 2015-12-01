#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME_SIZE 256

void get_file_name(char *input, char *output)
{
	printf("Input File Name : ");
	gets(input);
	printf("Output File Name : ");
	gets(output);
}

void main()
{
	FILE *ifp, *ofp;
	int T, N, M, c1, c2;
	int *parent;	// parent[i]: i+1번째 교차로의 부모
	int *childs;	// childs[i]: i+1번째 교차로의 자식수
	int *map;		// 집으로부터 한 끝점으로 가는 교차로들을 표시(1)한 맵
	int *mc1, *mc2, *answer; 
	int i, j, k;
	char input[FILE_NAME_SIZE], output[FILE_NAME_SIZE];

	printf("Problem1\n");
	get_file_name(input, output);

	ifp = fopen(input, "r");
	ofp = fopen(output, "w");

	if(ifp == NULL || ofp == NULL){
		printf("File Open Error!!!\n");
		return ;
	}

	fscanf(ifp, "%d", &T);

	for(i=0; i<T; i++){
		fscanf(ifp, "%d%d", &N, &M);

		parent = (int*)malloc(sizeof(int)*N);
		childs = (int*)malloc(sizeof(int)*N);
		map = (int*)malloc(sizeof(int)*N);

		for(j=0; j<N; j++){
			parent[j] = 0;
			childs[j] = 0;
		}
		
		for(j=0; j<N-1; j++){
			fscanf(ifp, "%d%d", &c1, &c2);
			parent[c2-1] = c1;
			childs[c1-1]++;
		}
		
		mc1 = (int*)malloc(sizeof(int)*M);
		mc2 = (int*)malloc(sizeof(int)*M);
		answer = (int*)malloc(sizeof(int)*M);

		for(j=0; j<M; j++){
			fscanf(ifp, "%d%d", &mc1[j], &mc2[j]);
			answer[j] = 0;
		}

		for(j=0; j<N; j++){
			if(!childs[j]){
				for(k=0; k<N; k++)
					map[k] = 0;

				for(k=j; k>=0; k=parent[k]-1)
					map[k] = 1;

				for(k=0; k<M; k++){
					if(map[mc1[k]-1] && map[mc2[k]-1])
						answer[k] = 1;
				}

			}
		}

		for(j=0; j<M; j++)
			fprintf(ofp, "%d\n", answer[j]);

		free(parent);
		free(childs);
		free(map);
		free(mc1);
		free(mc2);
		free(answer);
	}
	fclose(ifp);
	fclose(ofp);
}
