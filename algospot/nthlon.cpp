#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 정점의 개수
int V = 402;
// 그래프의 인접 리스트. (연결된 정점 번호. 간선 가중치) 쌍을 담는다.
vector<pair<int, int>> adj[410];
const int START = 401, INF = 1e5;

vector<int> dijkstra(int src) {
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    dist[src] = 0;
    visited[src] = false;
    while (true) {
        int closest = INF, here;
        for (int i = 0; i < V; ++i) {
            if (closest > dist[i] && !visited[i]) {
                closest = dist[i];
                here = i;
            }
        }
        if (closest == INF) break;
        visited[here] = true;
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second;
            if (visited[there]) continue;
            dist[there] = min(dist[there], closest + nextDist);
        }
    }
    return dist;
}
// (A국 선수의 예상 시간 - B국 선수의 예상시간)의 정점 번호를 반환한다.
int vertex(int delta) {
    return delta + 200;
}
// a[] = A국 선수의 종목별 예상 시간
// b[] = B국 선수의 종목별 예상 시간
int solve(const vector<int>& a, const vector<int>& b) {
    // 그래프를 만든다.
    V = 402;
    for (int i = 0; i < V; ++i) adj[i].clear();
    for (int i = 0; i < a.size(); ++i) {
        int delta = a[i] - b[i];
        adj[START].push_back(make_pair(vertex(delta), a[i]));
    }
    // 현재 차이
    for (int delta = -200; delta <= 200; ++delta) {
        // i번 종목을 뒤에 붙인다면?
        for (int i = 0; i < a.size(); ++i) {
            int next = delta + a[i] - b[i];
            // 시간 차이의 절대 값이 200을 넘는 정점은 만들 필요가 없다.
            if (abs(next) > 200) continue;
            adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
        }
    }
    vector<int> shortest = dijkstra(START);
    int ret = shortest[vertex(0)];
    if (ret == INF) return -1;
    return ret;
}
