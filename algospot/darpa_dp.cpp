#include <iostream>
#include <vector>

using namespace std;

int n, m;
double location[240];
double cache[240][100];

double optimize(int begin, int cameras) {
    if (cameras == 1)
        return 1000;
    if (begin == m)
        return 0;
    double& res = cache[begin][cameras];
    if (res >= 0) return res;
    res = 0;
    for (int i = begin; i < m; ++i) {
        double cand = min(location[i+1] - location[begin], optimize(i+1, cameras-1));
        res = max(cand, res);
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m;
        for (int i = 0; i < 240; ++i) {
            for (int j = 0; j < 100; ++j) {
                cache[i][j] = -1;
            }
        }
        for (int i = 0; i < m; ++i) {
            cin >> location[i];
        }
        printf("%.2f\n", optimize(0, n));
    }
}
