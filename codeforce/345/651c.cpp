//http://codeforces.com/contest/651/problem/C
//Codeforces Round #345 (Div. 2)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;
    map<int, int> wm_x, wm_y;
    map<pair<int, int>, int> wm;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        wm_x[x]++;
        wm_y[y]++;
        wm[make_pair(x, y)]++;
    }
    int res = 0;
    for (auto x : wm_x) {
        if (x.second > 1)
            res += x.second * (x.second - 1) / 2;
    }
    for (auto x : wm_y) {
        if (x.second > 1)
            res += x.second * (x.second - 1) / 2;
    }
    for (auto m : wm) {
        if (m.second > 1)
            res -= m.second * (m.second - 1) / 2;
    }
    cout << res << endl;
    return 0;
}