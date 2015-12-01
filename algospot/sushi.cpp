#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX = 201;
int price[20], pref[20];
int C[MAX];
int n;

int sushi(int m) {
    int res = 0;
    for (int budget = 0; budget <= m; ++budget) {
        C[budget % MAX] = 0;
        for (int i = 0; i < n; ++i) {
            if (budget - price[i] < 0) continue;
            C[budget % MAX] = max(C[budget % MAX], C[(budget - price[i]) % MAX] + pref[i]);
        }
        res = max(res, C[budget % MAX]);
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int m;
        cin >> n >> m;
        m /= 100;
        for (int i = 0; i < n; ++i) {
            cin >> price[i] >> pref[i];
            price[i] /= 100;
        }
        cout << sushi(m) << endl;
    }
}
