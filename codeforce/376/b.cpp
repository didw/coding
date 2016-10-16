#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            continue;
        }
        if (a[i] % 2 == 1 && i + 1 < n && a[i+1] > 0) {
            a[i + 1]--;
            continue;
        }
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}