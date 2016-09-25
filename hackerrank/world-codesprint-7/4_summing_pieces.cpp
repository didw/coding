//https://www.hackerrank.com/contests/world-codesprint-7/challenges/summing-pieces
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
long long cache[1000001];
int cache_comb[1000001];


void prec() {
    cache_comb[0] = 1;
    cache_comb[1] = 1;
    for (int i = 2; i < 1000001; ++i) {
        cache_comb[i] = (cache_comb[i-1] * 2) % MOD;
    }
}

long long comb(int n) {
    if (n <= 1) return 1;
    int &res = cache_comb[n];
    if (res != -1) return res;
    res = comb(n-1) * 2 % MOD;
    return res;
}

vector<int> subsum;

long long solve(vector<int>& ar, int pos) {
    long long& res = cache[pos];
    if (ar.size() == pos) {
        return 0;
    }
    if (res != -1) return res;
    res = 0;
    long long left_sum = 0, num = ar.size() - pos;
    for (int i = ar.size()-1; i >= pos; --i) {
        if (pos == 0)
            left_sum = subsum[i];
        else
            left_sum = subsum[i] - subsum[pos-1];
        res += comb(ar.size() - i - 1)*((left_sum*num) % MOD) + solve(ar, i + 1);
        res %= MOD;
        num--;
    }
    return res % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    subsum = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        if (i == 0)
            subsum[i] = ar[i];
        else
            subsum[i] = (subsum[i - 1] + ar[i])%MOD;
    }
    memset(cache, -1, sizeof(cache));
    memset(cache_comb, -1, sizeof(cache_comb));
    prec();
    cout << solve(ar, 0) << endl;
    return 0;
}
