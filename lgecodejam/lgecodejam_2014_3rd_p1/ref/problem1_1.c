#include <stdio.h>
#include <string.h>

#define MAX_N 200000
#define MAX_M 200000

#define print(VAL) printf(#VAL"=%d\n",VAL);
typedef struct LData_{
	int word;
	int pos;
}LData;

int Check_Cnt(int* Kexp, int* Kcnt, int K);

int main(){

	int T;
	int TestNum=0;
	int i,j,k,l;

	scanf("%d", &T);
//	//printf("%d\n",T);

	int *Path       = (int*)malloc(sizeof(int)*(MAX_N));
    int *Problem0   = (int*)malloc(sizeof(int)*(MAX_M));
    int *Problem1   = (int*)malloc(sizeof(int)*(MAX_M));

	for(TestNum=0;TestNum<T;TestNum++){
		int N,M;
		scanf("%d %d",&N,&M);
		//printf("Test%d N%d K%d\n",TestNum,N,K);
		for(i=0;i<N-1;i++){
            int temp0, temp1;
			scanf("%d %d",&temp0, &temp1);
            Path[temp1] = temp0;
		}
		for(i=0;i<M;i++){
            int temp0, temp1;
			scanf("%d %d",&temp0, &temp1);
            Problem0[i] = temp0;
            Problem1[i] = temp1;
		}
        
        for(i=0;i<M;i++){
            int cur_pos = Problem0[i];
            int target  = Problem1[i];
            int result  = 0;
            while(cur_pos!=1){
//                printf("[%d-0] %d>%d\n",i,cur_pos, Path[cur_pos]);
                cur_pos = Path[cur_pos];
                if(cur_pos == target){
                    result = 1;
                    break;
                }
            }
            cur_pos = Problem1[i];
            target  = Problem0[i];
            if(result == 0){
                while(cur_pos!=1){
//                    printf("[%d-1] %d->%d\n",i,cur_pos, Path[cur_pos]);
                    cur_pos = Path[cur_pos];
                    if(cur_pos == target){
                        result = 1;
                        break;
                    }
                }
            }
//            printf("Result %d\n",result);
            printf("%d\n",result);
        }
	}
}


