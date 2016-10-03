// http://codeforces.com/contest/721/problem/D
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool possible(vector<int>& a, int n, int k, int x) {
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res += (n - a[i] - 1) / x + 1 > 0 ? (n - a[i] - 1) / x + 1 : 0;
    }
    return res <= k;
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    int sum_minus = 0;
    int min_value = 987654321, min_idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) sum_minus++;
        if (min_value > abs(a[i])) {
            min_value = abs(a[i]);
            min_idx = i;
        }
    }
    bool next = false;
    if (sum_minus % 2 == 1) next = true;
    while (k > 0 && !next) {
        if (a[min_idx] >= 0) {
            a[min_idx] -= x;
            if (a[min_idx] < 0) next = true;
        }
        else {
            a[min_idx] += x;
            if (a[min_idx] > 0) next = true;
        }
        k--;
    }

    vector<int> b;
    for (int i = 0; i < a.size(); ++i) {
        b.push_back(abs(a[i]));
    }
    sort(b.begin(), b.end());
    int left = 0, right = 1e7;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (possible(b, mid, k, x)) {
            left = mid;
        }
        else {
            right = mid - 1;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (abs(a[i]) < left) {
            if (a[i] >= 0) {
                a[i] += (left - a[i] - 1) / x * x;
            }
            else {
                a[i] -= (left + a[i] - 1) / x * x;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i+1 < n)
            cout << " ";
    }
    cout << endl;
    return 0;
}