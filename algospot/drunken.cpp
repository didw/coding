#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int V, E, adj[601][601];
int delay[601];
int W[601][601];

void solve() {
  vector<pair<int, int>> order;
  for (int i = 0; i < V; ++i)
    order.push_back(make_pair(delay[i], i));
  sort(order.begin(), order.end());
  // 정점을 지나지 않고도 얻을 수 있는 최단 경로
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (i == j) {
        W[i][j] = 0;
      }
      else
        W[i][j] = adj[i][j];
    }
  }
  for (int k = 0; k < V; ++k) {
    int w = order[k].second;
    for (int i = 0; i < V; ++i) {
      if (adj[i][w] >= 1e9) continue;
      for (int j = 0; j < V; ++j) {
        adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
        W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
      }
    }
  }
}

int main() {
  cin >> V >> E;
  for (int i = 0; i < V; ++i)
    for (int j = 0; j < V; ++j)
      adj[i][j] = 1e9;
  for (int i = 0; i < V; ++i)
    cin >> delay[i];
  for (int i = 0; i < E; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a - 1][b - 1] = w;
    adj[b - 1][a - 1] = w;
  }
  solve();
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int a, b;
    cin >> a >> b;
    cout << W[a - 1][b - 1] << endl;
  }
}

