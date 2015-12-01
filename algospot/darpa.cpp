#include <iostream>
#include <vector>

using namespace std;

bool decision(const vector<double>& location, int camera, double gap) {
    double limit = -1;
    int installed = 0;
    for (int i = 0; i < location.size(); ++i) {
        if (location[i] >= limit) {
            limit = location[i] + gap;
            installed++;
        }
    }
    return camera <= installed;
}

double optimize(const vector<double>& location, int cameras) {
    double lo = 0, hi = 241;
    for (int it = 0; it < 100; ++it) {
        double mid = (lo + hi) / 2;
        if (decision(location, cameras, mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        vector<double> location;
        for (int i = 0; i < m; ++i) {
            double a;
            cin >> a;
            location.push_back(a);
        }
        printf("%.2f\n", optimize(location, n));
    }
}
