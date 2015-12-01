#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<vector<pair<int, double>>> adj;
const double INF = 1e10;

vector<double> dijkstra2(int src) {
    vector<double> dist(n, INF);
    vector<bool> visited(n, false);
    dist[src] = 0;
    visited[src] = false;
    while (true) {
        double closest = INF;
        int here;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dist[i] < closest) {
                here = i;
                closest = dist[i];
            }
        }
        if (closest == INF) break;
        visited[here] = true;
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            if (visited[there]) continue;
            double nextDist = closest + log(adj[here][i].second);
            dist[there] = min(dist[there], nextDist);
        }
    }
    return dist;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int m;
        cin >> n >> m;
        adj.clear();
        adj = vector<vector<pair<int, double>>>(n, vector<pair<int, double>>());
        for (int i = 0; i < m; ++i) {
            int a, b;
            double w;
            cin >> a >> b >> w;
            adj[a].push_back(make_pair(b, w));
        }
        vector<double> ret = dijkstra2(0);
        printf("%.10f\n", exp(ret[ret.size() - 1]));
    }
}
