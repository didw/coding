#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const double ZERO = 1e-9;
const double INF = 1e15;

class PlaneGame {
public:
    int bestShot(vector <int>, vector <int>);
};

bool isOrthogonal(double a, double b) {
    if (a == 0 && b >= INF) return true;
    if (a >= INF && b == 0) return true;
    if (abs(a*b + 1) <= 1e-9) return true;
    return false;
}

int solve(vector<int> &x, vector<int> &y, pair<double, double> l1, pair<double, double> l2) {
    if (l1 != l2 && !isOrthogonal(l1.first, l2.first)) return 0;
    unsigned long long cand = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (l1.first >= INF && l1.second == x[i]) cand |= ((long long)1 << i);
        if (l2.first >= INF && l2.second == x[i]) cand |= ((long long)1 << i);
        if (l1.first < INF && abs((double)y[i] - l1.first*x[i] - l1.second) < ZERO) cand |= ((long long)1 << i);
        if (l2.first < INF && abs((double)y[i] - l2.first*x[i] - l2.second) < ZERO) cand |= ((long long)1 << i);
    }
    return __popcnt(cand >> 32) + __popcnt((int)cand);
    //return __builtin_popcount(cand) + __builtin_popcount(cand >> 32);
}

int PlaneGame::bestShot(vector <int> x, vector <int> y) {
    if (x.size() < 4) return x.size();
    vector<pair<double, double>> line;
    for (int i = 0; i < x.size(); ++i) {
        for (int j = i+1; j < x.size(); ++j) {
            double a, b;
            if (x[j] == x[i]) {
                a = 2*INF;
                b = x[j];
            }
            else {
                a = (double)(y[j] - y[i]) / (x[j] - x[i]);
                b = (double)y[j] - a*x[j];
            }
            line.push_back(make_pair(a, b));
        }
    }
    int res = 3;
    for (int i = 0; i < line.size(); ++i) {
        for (int j = 0; j < line.size(); ++j) {
            res = max(res, solve(x, y, line[i], line[j]));
        }
    }
    return res;
}

int main() {
    PlaneGame pg;
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
    }
    cout << pg.bestShot(x, y) << endl;
}

/* input
9
0 -3 3 3 -3 0 0 3 -3
0 -3 -3 3 3 3 -3 0 0
5
0 -1 1 1 -1
0 -1 -1 1 1
5
0 0 0 1 -1
0 1 -1 0 0
*/

/*output
5
5
5
*/
