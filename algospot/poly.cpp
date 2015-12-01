#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

long cache[101][101];

long poly(int f, int n) {
    if (n == 0)
        return 1;
    long& res = cache[f][n];
    if (res != -1) return res;
    res = 0;
    for (int i = 1; i <= n; ++i) {
        res += poly(i, n - i) * (f+i-1);
        res %= 10000000;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(cache, -1, sizeof(cache));
        long res = 0;
        for (int i = 1; i <= n; ++i) {
            res += poly(i, n - i);
            res %= 10000000;
        }
        cout << res << endl;
    }
}
