#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

double cache[1001][1001];

double snail(int n, int m) {
    if (n <= 0) return 1;
    if (m == 0) return 0;
    double& ret = cache[n][m];
    if (ret != -1) return ret;
    ret = 0.75*snail(n - 2, m - 1) + 0.25*snail(n - 1, m - 1);
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= 1000; ++i)
            for (int j = 0; j <= 1000; ++j)
                cache[i][j] = -1;
        printf("%.10f\n", snail(n, m));
    }
}
