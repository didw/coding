#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k, m, l;
const int INF = 10000;
const int MAXN = 12;
int prerequisite[MAXN], classes[10], cache[10][1<<MAXN];

// return minimum semester when taken classes in semester
int graduate(int semester, int taken) {
    // base case
    if (__popcnt(taken) >= k) return 0;
    if (semester== m) return INF;
    int& res = cache[semester][taken];
    if (res != -1) return res;
    res = INF;
    // 1. get classes which can take
    int canTake = (classes[semester] & ~taken);
    // 2. remove not take pre-required classes
    for (int i = 0; i < n; ++i) {
        if (taken&(1<<i) ||
            ((taken&prerequisite[i]) != prerequisite[i])) {
                canTake &= ~(1<<i);
        }
    }
    // 3. recursive call all subset
    for (int take = canTake; take; take = (take - 1) & canTake) {
        if (__popcnt(take) > l) continue;
        res = min(res, graduate(semester + 1, taken | take) + 1);
    }
    res = min(res, graduate(semester + 1, taken));
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> k >> m >> l;
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < n; ++i) {
            int r;
            cin >> r;
            prerequisite[i] = 0;
            for (int j = 0; j < r; ++j) {
                int a;
                cin >> a;
                prerequisite[i] |= (1<<a);
            }
        }
        for (int i = 0; i < m; ++i) {
            int c;
            cin >> c;
            classes[i] = 0;
            for (int j = 0; j < c; ++j) {
                int a;
                cin >> a;
                classes[i] |= (1<<a);
            }
        }
        cout << graduate(0, 0) << endl;
    }
}
