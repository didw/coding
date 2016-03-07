//http://codeforces.com/contest/651/problem/C
//Codeforces Round #345 (Div. 2)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int a, b, n, T;
vector<char> photos;

int cacheR[500000];
int cacheL[500000];

int getLeft(int t) {
    if (t < 0) return 0;
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (cacheL[mid] <= t)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int getRight(int t) {
    if (t < 0) return 0;
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (cacheR[mid] <= t)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int main() {
    cin >> n >> a >> b >> T;
    photos = vector<char>(n);
    
    for (int i = 0; i < n; ++i)
        cin >> photos[i];

    if (photos[0] == 'w')
        T -= (b+1);
    if (T < 0) {
        cout << "0" << endl;
        return 0;
    }

    cacheR[0] = cacheL[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (photos[i] == 'w')
            cacheR[i] = cacheR[i - 1] + a + b + 1;
        else
            cacheR[i] = cacheR[i - 1] + a + 1;
    }

    for (int i = n-1; i >= 0; --i) {
        int idx = n - i;
        int prev = idx - 1;
        if (photos[i] == 'w')
            cacheL[idx] = cacheL[prev] + a + b + 1;
        else
            cacheL[idx] = cacheL[prev] + a + 1;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (cacheR[i] <= T)
            res = max(res, i + 1 + getLeft(T - cacheR[i] - a*(i + 1)));
    }
    for (int j = n-1; j >= 0; --j) {
        int i = n - j;
        if (cacheL[i] <= T)
            res = max(res, i + 1 + getRight(T - cacheL[i] - a*(i + 1)));
    }
    cout << min(res, n) << endl;
    return 0;
}
