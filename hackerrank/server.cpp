#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int solve(int T, vector<int> jobs) {
    int res = 0;
    for (int i = 0; i < jobs.size(); ++i) {
        if (T > jobs[i]) return res;
        T -= jobs[i];
        res++;
    }
    return res;
}

int main() {
    int N, c = 1, T;
    while (scanf("%d", &N) && !feof(stdin)) {
        scanf("%d", &T);
        vector<int> jobs(N);
        for (int i = 0; i < N; ++i) {
            cin >> jobs[i];
        }
        printf("Case %d: %d\n", c++, solve(T, jobs));
    }
    return 0;
}