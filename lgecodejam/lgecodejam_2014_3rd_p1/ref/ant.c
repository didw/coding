#include <stdio.h>

#define MAXM 200000
#define MAXN 200000

int M, N;
int path[MAXM+1];

int is_in_path(int mp, int mc)
{
	int p, c;
	// p
	c = mc;
	while (1) {
		p = path[c];

		if (p == mp)
			return 1;
		else if (p == 1)
			break;
		c = p;
	}

	// c
	c = mp;
	while (1) {
		p = path[c];

		if (p == mc)
			return 1;
		else if (p == 1)
			break;

		c = p;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	int T = 0, test_case;
	int i, j, p, c, mp, mc;

	//freopen("mytest.txt", "r", stdin);
	freopen("A-large.in", "r", stdin);
	//freopen("A-small.in", "r", stdin);
	freopen("ouput.txt", "w", stdout);

	scanf("%d\n", &test_case);
	for (T = 0; T < test_case; T++) {
		scanf("%d %d\n", &N, &M);

		if (N < 2 || M < 1 || N > MAXN || N > MAXM)
			continue;

		for (i = 0; i <= MAXM; i++)
			path[i] = 0;

		path[1] = path[0] = 1;
		for (i = 0; i < N-1; i++) {
			scanf("%d %d", &p, &c);
			path[c] = p;
		}

		for(i = 0; i < M; i++) {
			scanf("%d %d\n", &mp, &mc);
			printf("%d\n", is_in_path(mp, mc));
		}
	}
	

	return 0;
}