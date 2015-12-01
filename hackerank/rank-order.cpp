#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n;
vector<int> judge1, judge2;

int solve() {
    set<int> J1, J2;
    vector<int> order1 = judge1, order2 = judge2;
    sort(order1.begin(), order1.end());
    sort(order2.begin(), order2.end());
    int res = n;
    for (int i = 0; i < n; ++i) {
        int cand1 = upper_bound(order1.begin(), order1.end(), judge1[i]) - order1.begin();
        int cand2 = upper_bound(order2.begin(), order2.end(), judge2[i]) - order2.begin();
        if (cand1 != cand2) {
            res = min(res, min(n-cand1, n-cand2));
        }
    }
    return res;
}

int main() {
    int t = 1;
    while (scanf("%d", &n) && !feof(stdin)) {
        for (int i = 0; i < n; ++i) {
            int j;
            scanf("%d", &j);
            judge1.push_back(j);
        }
        for (int i = 0; i < n; ++i) {
            int j;
            scanf("%d", &j);
            judge2.push_back(j);
        }
        int res = solve();
        if (res == n)
            printf("Case %d: agree\n", t++);
        else 
            printf("Case %d: %d\n", t++, res+1);
        judge1.clear();
        judge2.clear();
    }
}
