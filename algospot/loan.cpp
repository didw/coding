#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m;
double n, p;

bool decision(double c) {
    double res = n;
    for (int i = 0; i < m; ++i) {
        res += (res * p/1200);
        res -= c;
    }
    return res <= 0;
}

double optimize() {
    double lo = 0, hi = 1e10;
    for (int i = 0; i < 100; ++i) {
        double mid = (lo + hi) /2;
        if (decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m >> p;
        printf("%.10f\n", optimize());
    }
}
