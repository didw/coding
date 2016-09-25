//https://www.hackerrank.com/contests/world-codesprint-7/challenges/inverse-rmq
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> num;

vector<int> build_segment_tree(int n) {
    vector<int> ar(2 * n - 1);
    int idx = 0;
    for (int i = n - 1; i < 2 * n - 1; ++i, ++idx) {
        ar[i] = num[idx];
    }
    for (int i = n - 2; i >= 0; --i) {
        ar[i] = min(ar[2 * i + 1], ar[2 * i + 2]);
    }
    return ar;
}

int main() {
    long long n;
    cin >> n;
    vector<int> ar(2*n-1, 0);
    for (int i = 0; i < 2*n-1; ++i) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    num = vector<int>(n, 0);
    int idx = 1;
    num[0] = ar[0];
    for (int i = 0; i < 2 * n - 1; ++i) {
        if (ar[i] != num[idx-1]) num[idx++] = ar[i];
    }
    vector<int> ar2 = build_segment_tree(n);
    sort(ar2.begin(), ar2.end());
    for (int i = 0; i < 2 * n - 1; ++i) {
        if (ar[i] != ar2[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    ar2 = build_segment_tree(n);
    for (int i = 0; i < 2*n-1; ++i) {
        cout << ar2[i] << " ";
    }
    cout << endl;
    return 0;
}
