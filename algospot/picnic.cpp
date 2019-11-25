#include <iostream>
#include <vector>

using namespace std;


bool friends[11][11];
bool paired[11];

int solve(int n) {
    int first = -1;
    for (int i = 0; i < n; ++i) {
        if (!paired[i]) {
            first = i;
            break;
        }
    }
    if (first == -1) {
        return 1;
    }
    paired[first] = true;
    int res = 0;
    for (int second = first+1; second < n; ++second) {
        if ((!paired[second]) && friends[first][second]) {
            paired[second] = true;
            res += solve(n);
            paired[second] = false;
        }
    }
    paired[first] = false;
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < 11; ++i) {
            for (int j = 0; j < 11; ++j) {
                friends[i][j] = false;
            }
            paired[i] = false;
        }
        while (m--) {
            int a, b;
            cin >> a >> b;
            friends[a][b] = friends[b][a] = true;
        }
        cout << solve(n) << endl;
    }
}
