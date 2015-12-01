#include <iostream>
#include <algorithm>

using namespace std;

int V, adj[201][201];

bool update(int a, int b, int c) {
    if (adj[a][b] <= c) return false;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adj[i][j] = min(adj[i][j], adj[i][a] + c + adj[b][j]);
            adj[i][j] = min(adj[i][j], adj[i][b] + c + adj[a][j]);
        }
    }
    return true;
}

void floyd() {
    for (int i = 0; i < V; ++i) adj[i][i] = 0;
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int M, N;
        cin >> V >> M >> N;
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                adj[i][j] = 1e9;
        for (int i = 0; i < M; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] = c;
            adj[b][a] = c;
        }
        floyd();

        int res = 0;
        for (int i = 0; i < N; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            if (!update(a, b, c)) res += 1;
        }
        cout << res << endl;
    }
}
