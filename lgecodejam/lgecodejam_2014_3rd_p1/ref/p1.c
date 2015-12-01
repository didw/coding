#include<stdio.h>
 
#define SIZE_N 200000 + 10

void printNP (int *N, int *P, int count)
{
	int i=0;
	
	for (  i=0; i<count; ++i){
		printf ("%d %d\n", P[i], N[i]);
	}
}

void printPath (int *P, int count)
{
	int i=0;
	
	for (  i=0; i<count; ++i){
		printf ("%d ", P[i]);
	}

	printf ("\n");
}


int main() {

	int N[SIZE_N] = {0}, P[SIZE_N] = { 0}, Path1 [SIZE_N] = { 0}, Path2 [SIZE_N] = { 0};

	int i=0, tc =0, c=0, m=0, t1=0, t2=0, index1 =0,index2=0,  flag =0;

	for (  i=0; i<SIZE_N; ++i){
		N[i]=i+2;
	}

	scanf ("%d\n", &tc);

	while (tc)
	{
			--tc;
			scanf ("%d %d\n", &c, &m);

			c=c-1;
			
			for (  i=0; i<c; ++i){
				scanf ("%d %d\n", &t1, &t2);
				P[t2-2] =t1;
			}

			
			for (  i=0; i<m; ++i){
				scanf ("%d %d\n", &t1, &t2);

				if ( (1==t1) || ( 1 == t2 ) || ( t1==t2) )
				{
					printf ("1\n");
					continue;
				}

				index1 = index2 =0;
				flag =0;

#if 1
				Path1 [index1]=t1;
				Path2 [index2]=t2;

				while ( 1 != Path1 [index1] || 1 != Path2 [index2])
				{

					if (1 != Path1 [index1])
					{
						if ( t2== Path1 [index1] )
						{
								flag =1;
								break;
						}

						++index1;
						Path1 [index1] = P[ Path1 [index1-1]-2];

						if ( t2== Path1 [index1] )
						{
								flag =1;
								break;
						}
					}

					if ( 1 != Path2 [index2])
					{
						if ( t1 == Path2 [index2] )
						{
							flag =1;
							break;
						}

							++index2;
						Path2  [index2] = P[ Path2  [index2-1]-2];

						if ( t1== Path2 [index2] )
						{
								flag =1;
								break;
						}
					}
								
				}
#endif
						printf ("%d\n", flag);
						
			}

	}

}
