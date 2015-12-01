#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist;
int const INF = 1e5;
int V, E, n, m;

void dijkstra() {
    vector<bool> visited(V, false);
    while (true) {
        int closest = INF, here;
        for (int i = 0; i < V; ++i) {
            if (!visited[i] && closest > dist[i]) {
                closest = dist[i];
                here = i;
            }
        }
        if (closest == INF) break;
        visited[here] = true;
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            if (visited[there]) continue;
            int nextDist = closest + adj[here][i].second;
            dist[there] = min(dist[there], nextDist);
        }
    }
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> V >> E >> n >> m;
        dist.clear();
        adj.clear();
        dist = vector<int>(V, INF);
        adj = vector<vector<pair<int, int>>>(V, vector<pair<int, int>>());
        for (int i = 0; i < E; ++i) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a - 1].push_back(make_pair(b - 1, w));
            adj[b - 1].push_back(make_pair(a - 1, w));
        }
        vector<int> fire;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            fire.push_back(a-1);
        }
        for (int i = 0; i < m; ++i) {
            int a;
            cin >> a;
            dist[a-1] = 0;
        }
        dijkstra();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += dist[fire[i]];
        }
        cout << res << endl;
    }
}
