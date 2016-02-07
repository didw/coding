// A. Guest From the Past
// http://codeforces.com/contest/625/problem/A
#include <iostream>

using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    long long res = 0;
    if (b-c < a) {
        res = (n-c)/(b-c);
        n -= res*(b-c);
    }
    res += n/a;
    cout << res;
}

// something wrong.. but I don't know what is wrong..
