//https://www.hackerrank.com/contests/world-codesprint-7/challenges/gridland-metro
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


typedef struct track_ {
    int r, c1, c2;
} track;

bool myfunction(track i, track j) {
    if (i.r != j.r)
        return i.r < j.r;
    if (i.c1 != j.c1)
        return i.c1 < j.c1;
    if (i.c2 != j.c2)
        return i.c2 < j.c2;
    return 0;
}


int main() {
    long long n, m;
    int k;
    cin >> n >> m >> k;
    vector<track> tr(k);
    for (int i = 0; i < k; ++i) {
        cin >> tr[i].r >> tr[i].c1 >> tr[i].c2;
    }
    sort(tr.begin(), tr.end(), myfunction);

    for (int i = 0; i < k; ++i) {
        printf("r: %d, c1: %d, c2: %d\n", tr[i].r, tr[i].c1, tr[i].c2);
    }
    long long nt = 0;
    for (int i = 0; i < k; ++i) {
        if (i+1 < k && tr[i].r == tr[i + 1].r) {
            if (tr[i].c1 <= tr[i + 1].c1 && tr[i].c2 >= tr[i + 1].c1) {
                tr[i + 1].c1 = min(tr[i].c1, tr[i + 1].c1);
                tr[i + 1].c2 = max(tr[i].c2, tr[i + 1].c2);
                continue;
            }
            if (tr[i + 1].c1 <= tr[i].c1 && tr[i + 1].c2 >= tr[i].c1) {
                tr[i + 1].c1 = min(tr[i].c1, tr[i + 1].c1);
                tr[i + 1].c2 = max(tr[i].c2, tr[i + 1].c2);
                continue;
            }
        }
        nt += tr[i].c2 - tr[i].c1 + 1;
    }
    cout << (n*m - nt) << endl;

    return 0;
}
