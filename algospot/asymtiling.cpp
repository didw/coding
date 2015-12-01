#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[101][2];

int tiling(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    int& res = cache[n][0];
    if (res != -1) return res;
    res = tiling(n - 2) + tiling(n - 1);
    res %= 1000000007;
    return res;
}

int symtiling(int n) {
    if (n == 2) return 2;
    if (n == 1) return 1;
    if (n == 0) return 1;
    if (n < 0) return 0;
    int& res = cache[n][1];
    if (res != -1) return res;
    res = symtiling(n - 4) + symtiling(n - 2);
    res %= 1000000007;
    return res;
}

int asymtiling(int n) {
    int a = tiling(n);
    int b = symtiling(n);
    return (a - b + 1000000007) % 1000000007;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(cache, -1, sizeof(cache));
        cout << asymtiling(n) << endl;
    }
}
