#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
long cache[101];

long tiling(int n) {
    long &res = cache[n];
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (res != -1) return res;
    res = 0;
    res = tiling(n - 1) + tiling(n - 2);
    res = res % 1000000007;
    return res
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(cache, -1, sizeof(cache));
        cout << tiling(n) << endl;
    }
}
