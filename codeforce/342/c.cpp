// C. K-special Tables
// http://codeforces.com/contest/625/problem/C

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a = k-1, b = n-k+1;
    int idx=a*n + 1, res = 0;
    for (int i = 0; i < n; ++i) {
        res += idx;
        idx += b;
    }
    vector< vector<int> > tab(n, vector<int>(n));

    cout << res << endl;

    idx = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a; ++j) {
            tab[i][j] = idx++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < b; ++j) {
            tab[i][j+k-1] = idx++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << tab[i][j] << " ";
        cout << endl;
    }

}
