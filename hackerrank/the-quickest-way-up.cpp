#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> edges[101];
int ladder[101], snake[101];

void make_graph() {
    for (int v = 1; v <= 100; ++v) {
        for (int i = 1; i <= 6; ++i) {
            if (v + i > 100) continue;
            edges[v].push_back(v + i);
        }
    }
}

int solve() {
    queue<int> q;
    int dist[101];
    for (int i = 0; i <= 100; ++i) dist[i] = 987654321;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (int i = 0; i < edges[here].size(); ++i) {
            int there = edges[here][i];
            if (ladder[there]) there = ladder[there];
            if (snake[there]) there = snake[there];
            if (dist[there] > dist[here] + 1) {
                dist[there] = dist[here] + 1;
                q.push(there);
            }
        }
    }
    if (dist[100] == 987654321) return -1;
    return dist[100];
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        for (int i = 0; i <= 100; ++i) {
            edges[i] = vector<int>();
            ladder[i] = 0;
            snake[i] = 0;
        }
        int n, m;
        make_graph();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int start, end;
            cin >> start;
            cin >> ladder[start];
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int start;
            cin >> start;
            cin >> snake[start];
        }
        cout << solve() << endl;
    }
    return 0;
}

