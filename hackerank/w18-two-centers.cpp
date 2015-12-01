#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 987654321;
int N;
vector<int> edges[5000];
int res = INF;

void max_dist(int c1, int c2) {
    int max_dist = 0;
    vector<int> dist(N, INF);
    queue<int> q;
    q.push(c1);
    q.push(c2);
    dist[c1] = dist[c2] = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (int i = 0; i < edges[here].size(); ++i) {
            int there = edges[here][i];
            if (dist[there] > dist[here] + 1) {
                dist[there] = dist[here] + 1;
                q.push(there);
                max_dist = max(max_dist, dist[there]);
                if (max_dist >= res) return;
            }
        }
    }
    res = max_dist;
}

void solve() {
    for (int c1 = 0; c1 < N - 1; ++c1) {
        for (int c2 = c1 + 1; c2 < N; ++c2) {
            max_dist(c1, c2);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }
    solve();
    cout << res << endl;
    return 0;
}
