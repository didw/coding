#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

vector<int> a, b;
int cache[102][102];

int jlis(int x, int y) {
    int& res = cache[x+1][y+1];
    if (res != -1)
        return res;
    res = 0;
    long min_a = (x==-1 ? INT_MIN : a[x]);
    long min_b = (y==-1 ? INT_MIN : b[y]);
    long min_v = max(min_a, min_b);
    for (int i = x + 1; i < a.size(); ++i) {
        if (a[i] > min_v)
            res = max(res, jlis(i, y) + 1);
    }
    for (int i = y + 1; i < b.size(); ++i) {
        if (b[i] > min_v)
            res = max(res, jlis(x, i) + 1);
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        a.clear();
        b.clear();
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < n; ++i) {
            int in;
            cin >> in;
            a.push_back(in);
        }
        for (int i = 0; i < m; ++i) {
            int in;
            cin >> in;
            b.push_back(in);
        }
        cout<<jlis(-1, -1)<<endl;
    }
}

