/*
 ============================================================================
 Name        : Problem1.c
 Copyright   : Copyright(c) 2014 by LG Electronics Inc.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define DEBUG

int main(void) {

    unsigned int T = 0, N = 0, M = 0;
    unsigned int *P;

	if (fscanf(stdin, "%d", &T) <= 0) {
		fputs("invalid input!\n", stderr);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
    fprintf(stderr, "T=%d\n", T);
#endif

    while (T-- > 0) {
        if (fscanf(stdin, "%d %d", &N, &M) <= 0
                || !(N >= 2 && N <= 200000)
                || !(M >= 2 && M <= 200000)) {
            fputs("invalid input!\n", stderr);
            exit(EXIT_FAILURE);
        }
#ifdef DEBUG
        fprintf(stderr, "N=%d, M=%d\n", N, M);
#endif

        P = (unsigned int*) malloc(sizeof(unsigned int) * (N + 1));
        P[0] = 0;
        P[1] = 0;

        for (int i = 0; i < N - 1; i++) {
            unsigned int x, y;
            if (fscanf(stdin, "%u %u", &x, &y) <= 0 || x > N || y > N ) {
                fputs("invalid data for N\n", stderr);
                exit(EXIT_FAILURE);
            }
            P[y] = x;
        }

        for (int j = 0; j < M; j++) {
            unsigned int a, b, t;
            if (fscanf(stdin, "%u %u", &a, &b) <= 0 || a > N || b > N ) {
                fputs("invalid data for M\n", stderr);
                exit(EXIT_FAILURE);
            }
            t = b;
            int limit = N;
            while (t > 0 && a != t && limit-- > 0) {
                t = P[t];
            }
            if (t == a) {
                fprintf(stdout, "%d\n", 1);
            } else {
                t = a;
                limit = N;
                while (t > 0 && b != t && limit-- > 0) {
                    t = P[t];
                }
                fprintf(stdout, "%d\n", (b == t) ? 1 : 0);
            }
        }

        free(P);
    }
    return EXIT_SUCCESS;
}

