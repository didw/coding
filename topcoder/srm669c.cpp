#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class LineMSTDiv2{
    long long cache[17][17];
    const long long MOD = 1000000007;
public:
    LineMSTDiv2() {
        memset(cache, -1, sizeof(cache));
    }
    long long factorial(long long N) {
        if (N <= 1) return 1;
        return N * factorial(N - 1);
    }

    long long combi(int n, int k) {
        if (k == 0 || k == n) return 1;
        long long& res = cache[n][k];
        if (res != -1) return res;
        res = (combi(n - 1, k - 1) + combi(n - 1, k)) % MOD;
        return res;
    }

    int count(int N) {
        long long sequence = factorial(N) / 2;
        long long res = sequence;
        if (N >= 3) res += sequence;
        for (int i = 1; i < N; ++i) {
            res += sequence*combi(N - 1, i);
            res %= MOD;
        }
        return res;
    }
};