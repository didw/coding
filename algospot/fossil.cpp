#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    double x, y;
} point;

vector<point> hull1, hull2;
vector<pair<point, point>> upper, lower;

void decompose(const vector<point>& hull) {
    int n = hull.size();
    for (int i = 0; i < n; ++i) {
        if (hull[i].x < hull[(i+1)%n].x)
            lower.push_back(make_pair(hull[i], hull[(i+1)%n]));
        else
            upper.push_back(make_pair(hull[i], hull[(i+1)%n]));
    }
}

double minX(const vector<point>& p) {
    double res = 1e20;
    for (int i = 0; i < p.size(); ++i)
        res = min(res, p[i].x);
    return res;
}

double maxX(const vector<point>& p) {
    double res = -1e20;
    for (int i = 0; i < p.size(); ++i)
        res = max(res, p[i].x);
    return res;
}

bool between(const point& a, const point& b, double x) {
    return (a.x < x && x < b.x) || (b.x < x && x < a.x);
}

double at(const point& a, const point& b, double x) {
    double dx = b.x - a.x, dy = b.y - a.y;
    return a.y + dy * (x - a.x) / dx;
}

double vertical(double x) {
    double minUp = 1e20, maxLow = -1e20;
    for (int i = 0; i < upper.size(); ++i)
        if (between(upper[i].first, upper[i].second, x))
            minUp = min(minUp, at(upper[i].first, upper[i].second, x));
    for (int i = 0; i < lower.size(); ++i)
        if (between(lower[i].first, lower[i].second, x))
            maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));
    return minUp - maxLow;
}

double solve() {
    double lo = max(minX(hull1), minX(hull2));
    double hi = min(maxX(hull1), maxX(hull2));
    if (hi < lo) return 0;
    for (int it = 0; it < 100; ++it) {
        double aab = (2*lo + hi) / 3;
        double abb = (lo + 2*hi) / 3;
        if (vertical(aab) > vertical(abb))
            hi = abb;
        else
            lo = aab;
    }
    return max(0.0, vertical((lo+hi)/2));
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        hull1.clear(), hull2.clear();
        upper.clear(), lower.clear();
        for (int i = 0; i < n; ++i) {
            point a;
            cin >> a.x >> a.y;
            hull1.push_back(a);
        }
        for (int i = 0; i < m; ++i) {
            point a;
            cin >> a.x >> a.y;
            hull2.push_back(a);
        }
        decompose(hull1);
        decompose(hull2);
        printf("%.10f\n", solve());
    }
}
