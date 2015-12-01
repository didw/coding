#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_N		200001

int find_node(const int *nodes, const int _a, const int _b)
{
	int a = _a;
	int b = _b;

	while (a != 0)
	{
		if (nodes[a] == b)
			return 1;
		a = nodes[a];
	}

	a = _b;
	b = _a;

	while (a != 0)
	{
		if (nodes[a] == b)
			return 1;
		a = nodes[a];
	}
	return 0;
}

int main(int argc, const char* argv[])
{
	FILE *fin = NULL;
	FILE *fout = NULL;
	const char *fin_name = "A-small.in";
	const char *fout_name = "CON";

	int test_set;
	int t, i;
	int n, m;
	int a, b;
	int *nodes;

	if (argc >= 2)
		fin_name = argv[1];
	if ((fin = fopen(fin_name, "rt")) == NULL)
	{
		return 0;
	}

	if (argc >= 3)
		fout_name = argv[2];
	if ((fout = fopen(fout_name, "wt")) == NULL)
	{
		fclose(fin);
		return 0;
	}

	nodes = (int *)malloc(sizeof(int) * MAX_N);
	fscanf(fin, "%d", &test_set);

	for (t = 0; t < test_set; t++)
	{
		memset(nodes, 0, sizeof(int) * MAX_N);

		fscanf(fin, "%d %d", &n, &m);
		for (i = 1; i < n; i++)
		{
			fscanf(fin, "%d %d", &a, &b);
			nodes[b] = a;
		}

		for (i = 0; i < m; i++)
		{
			fscanf(fin, "%d %d", &a, &b);
			fprintf(fout, "%d\n", find_node(nodes, a, b));
		}
	}

	free(nodes);
	fclose(fin);
	fclose(fout);
	return 0;
}

