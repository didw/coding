#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int find_parent(vector<int>& root, int n) {
    while (root[n] != -1) {
        int p = n;
        n = root[n];
        root[p] = find_parent(root, n);
    }
    return n;
}

void set_root(vector<int>& root, int a, int b) {
    while (root[a] != -1) {
        int p = a;
        a = root[a];
        root[p] = b;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> colors(n + 1);
    vector<int> root(n + 1, -1);
    vector<int> sz(n + 1, 1);

    for (int i = 0; i < n; ++i) {
        cin >> colors[i+1];
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        if (colors[a] != colors[b]) {
            int pa = find_parent(root, a);
            int pb = find_parent(root, b);
            if (pa == pb) continue;
            if (sz[pa] > sz[pb]) {
                swap(pa, pb);
            }
            set_root(root, a, pb);
            sz[pb] += sz[pa];
            sz[pa] = 0;
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (root[i] != -1)
            root[i] = find_parent(root, i);
    }
    map<pair<int, int>, int> gc;
    map<int, set<int>> gc_set;
    for (int i = 1; i <= n; ++i) {
        int p = find_parent(root, i);
        gc_set[p].insert(colors[i]);
        gc[make_pair(p, colors[i])]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (sz[i] < 2) continue;
        int mn = 0;
        for (auto j : gc_set[i]) {
            mn = max(mn, gc[make_pair(i, j)]);
        }
        res += sz[i] - mn;
    }
    cout << res << endl;
}
