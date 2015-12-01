#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <hash_map>
#include <string>
#include <algorithm>
#include <time.h>

FILE* inputfp = stdin;
FILE* outputfp = stdout;

#define DATAINPUT(...) fscanf(inputfp, __VA_ARGS__)
#define RESULTOUTPUT(...) fprintf(outputfp, __VA_ARGS__)

using namespace std;
//using namespace stdext;

int process1();
//int check(hash_map<int, int>& junctionlist, int startjunction, int endjunction);
//int check(map<int, int>& junctionlist, int startjunction, int endjunction);
int check(int* junctionlist, int startjunction, int endjunction);

int main(int argc, char* argv[])
{
//    int starttime = clock();
//    printf("start\n");
//    inputfp = fopen("A-large.in", "r+t");
//    outputfp = fopen("result.txt", "w+t");

	int totalcases;
	DATAINPUT("%d",&totalcases);
    while(totalcases)
    {
        process1();
        --totalcases;
    }

//    fclose(outputfp);
//    fclose(inputfp);
//    int endtime = clock();
//    printf("runtime %d\n", endtime - starttime);

    return 0;
}

int process1()
{
    int junctions;
    int qnum;
	DATAINPUT("%d %d",&junctions, &qnum);

//    hash_map<int, int> junctionlist;
//    map<int, int> junctionlist;
    int* junctionlist = (int* )malloc(sizeof(int) * (junctions + 1));

    int near,far;
    --junctions;
    while(junctions)
    {
 	    DATAINPUT("%d %d",&near, &far);
        junctionlist[far] = near;
        --junctions;
    }

    int junc1, junc2;
    int current;

    while(qnum)
    {
 	    DATAINPUT("%d %d",&junc1, &junc2);

        if(check(junctionlist, junc1, junc2) || check(junctionlist, junc2, junc1))
        {
            RESULTOUTPUT("1\n");
        }
        else
        {
            RESULTOUTPUT("0\n");
        }

        --qnum;
    }

    free(junctionlist);

    return 0;
}

//int check(hash_map<int, int>& junctionlist, int startjunction, int endjunction)
//int check(map<int, int>& junctionlist, int startjunction, int endjunction)
int check(int* junctionlist, int startjunction, int endjunction)
{
    if(startjunction == 1)
    {
        return 1;
    }

    int currentjunction = startjunction;
    while(currentjunction != 1)
    {
        if(currentjunction == endjunction)
            return 1;

        currentjunction = junctionlist[currentjunction];
    }
    return 0;
}
