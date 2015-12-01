#include <iostream>


using namespace std;

int main() {
    int c;
    cin >> c;
    while (c--) {
        long long n, m;
        cin >> n >> m;
        long long r = 100*m/n;
        long long lo = 0, hi = 2e9;
        if ((hi+m)*100/(n+hi) <= r) {
            cout << "-1" << endl;
            continue;
        }
        while (lo + 1 < hi) {
            long long mid = (lo + hi) / 2;
            if ((m+mid)*100/(n+mid) > r)
                hi = mid;
            else
                lo = mid;
        }
        cout << hi << endl;
    }
}
