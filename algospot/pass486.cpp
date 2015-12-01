#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 1000*1000*10;
int minFactor[MAX+1];
int minFactorPower[MAX+1];
int factors[MAX+1];

void eratosthenes() {
    minFactor[0] = minFactor[1] = -1;
    for (int i = 2; i <= MAX; ++i)
        minFactor[i] = i;
    int sqrtn = int(sqrt(MAX));
    for (int i = 2; i < sqrtn; ++i)
        if (minFactor[i] == i)
            for (int j = i*i; j <= MAX; j+=i)
                if (minFactor[j] == j)
                    minFactor[j] = i;
}

void getFactorSmart() {
    minFactorPower[1] = 0;
    for (int i = 2; i <= MAX; ++i) {
        if (minFactor[i] == i) {
            minFactorPower[i] = 1;
            factors[i] = 2;
            continue;
        }
        int p = minFactor[i];
        int m = i / p;
        if (p != minFactor[m])
            minFactorPower[i] = 1;
        else
            minFactorPower[i] = minFactorPower[m] + 1;
        int a = minFactorPower[i];
        factors[i] = factors[m] / a * (a+1);
    }
}

int solve(int n, int lo, int hi) {
    int res = 0;
    for (int i = lo; i <= hi; ++i) {
        if (factors[i] == n)
            res++;
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    eratosthenes();
    getFactorSmart();
    while (c--) {
        int n, lo, hi;
        cin >> n >> lo >>hi;
        cout << solve(n, lo, hi) << endl;
    }
}
