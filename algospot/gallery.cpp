#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 1000;
vector<int> adj[MAX_V];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
int installed, V;

// here의 서브트리를 탐색하고 here의 정보를 반환한다.
int dfs(int here) {
    visited[here] = true;
    int children[3] = {0, 0, 0};
    // here의 서브트리의 정보를 가져온다.
    for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        if (!visited[there]) {
            ++children[dfs(there)];
        }
    }
    // 카메라가 필요한 subtree가 있으면 설치
    if (children[UNWATCHED]) {
        ++installed;
        return INSTALLED;
    }
    // 설치된 서브트리가 있으면 WATCHED 리턴
    if (children[INSTALLED])
        return WATCHED;
    return UNWATCHED;
}

int installCamera() {
    installed = 0;
    visited = vector<bool>(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i] && dfs(i) == UNWATCHED)
            ++installed;
    }
    return installed;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int g, h;
        cin >> g >> h;
        V = g;
        for (int i = 0; i < MAX_V; ++i)
            adj[i].clear();
        for (int i = 0; i < h; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << installCamera() << endl;
    }
}
