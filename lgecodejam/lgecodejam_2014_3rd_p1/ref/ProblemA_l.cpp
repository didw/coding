/*
    Compiler : Visual C++ 2010
    Usage : ProgramName <input file> <output file>
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int gN, gM;
int link[210000];

int check(int x, int y)
{
    do
    {
        if (x == y)
            return 1;
        x = link[x];
    } while (x >= 1);

    return 0;
}

void process(FILE* pfIn, FILE* pfOut)
{
    int i, j, x, y, count;

    fscanf(pfIn, "%d", &count);
    for (i = 1; i <= count; i++)
    {
        fscanf(pfIn, "%d %d", &gN, &gM);
        link[1] = 0;
        for (j = 1; j < gN; j++)
        {
            fscanf(pfIn, "%d %d", &x, &y);
            link[y] = x;
        }

        for (j = 0; j < gM; j++)
        {
            fscanf(pfIn, "%d %d", &x, &y);
            fprintf(pfOut, "%d\n", check(x, y) || check(y, x));
        }
    }
}

//-----------------------------------------------------------------------------

void process(const char* pcszInFile, const char* pcszOutFile)
{
    FILE* pfIn = fopen(pcszInFile, "rt");
    if (pfIn == NULL)
    {
        printf("file not found! \"%s\"\n", pcszInFile);
        exit(-2);
    }

    FILE* pfOut = fopen(pcszOutFile, "wt");
    if (pfOut == NULL)
    {
        printf("can't create file! \"%s\"\n", pcszOutFile);
        exit(-3);
    }

    process(pfIn, pfOut);

    fclose(pfIn);
    fclose(pfOut);
}

void main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage : %s <input_file> <output_file>\n", argv[0]);
        exit(-1);
    }

    process(argv[1], argv[2]);
}
