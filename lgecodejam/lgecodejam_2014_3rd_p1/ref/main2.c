#include <stdio.h>
#include <stdlib.h>

int index_t[200000];

void main(){
     int T, i, j, N, M, parent, child, temp, search1, search2;
     int result = 0;
     FILE* fp, *ofp;
     
     fp = fopen("A-small.in", "r");
     ofp = fopen("result.txt", "w+");
     
     fscanf(fp, "%d", &T);
     
     for(i = 0; i < T; i++)
     {
           memset(index_t, 0, sizeof(index_t));
           fscanf(fp,"%d %d", &N, &M);
           
           // input
           for(j = 0; j < N-1; j++)
           {
            fscanf(fp, "%d %d", &parent, &child);
            index_t[child-1] = parent;
           }
           
           // output
           for(j = 0; j < M; j++)
           {
                 result = 0;
                 fscanf(fp,"%d %d", &search1, &search2);
                 
                 if(search1 == 1 || search2 == 1)
                 {
                   result = 1;
                   fprintf(ofp,"%d\n",result);
                   continue;
                 }
                 temp = search1;
                 do{
                      if(index_t[temp-1] == search2)
                      {
                        result = 1;
                        fprintf(ofp,"%d\n",result);
                        break;
                      }
                      temp = index_t[temp-1];
                 }while(index_t[temp-1]!=0);
                 
                 if(result == 0)
                 {
                   temp = search2;
                   do{
                        if(index_t[temp-1]==search1)
                        {
                           result = 1;
                           fprintf(ofp,"%d\n",result);
                           break;
                        }
                        temp = index_t[temp-1];
                   }while(index_t[temp-1]!=0);
                   
                   if(result == 0)
                    fprintf(ofp,"%d\n", result);
                 }
           }
     }
     
     fclose(fp);
     fclose(ofp);
     system("pause");
}
