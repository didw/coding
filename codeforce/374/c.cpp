// http://codeforces.com/contest/721/problem/C

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<pair<int, int> > > edges(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
    }
    vector<int> backtrace(n + 1, -1);
    backtrace[1] = -1;
    vector<int> dist(n + 1, 987654321);
    vector<int> showplace(n + 1, -1);
    dist[1] = 0;
    queue<int> cand;
    int max_route = 0;
    cand.push(1);
    while (!cand.empty()) {
        int here = cand.front();
        cand.pop();
        for (int i = 0; i < edges[here].size(); ++i) {
            int there = edges[here][i].first;
            int length = edges[here][i].second;
            if (dist[here] + length <= t && showplace[here] + 1 >= showplace[there]) {
                dist[there] = dist[here] + length;
                cand.push(there);
                backtrace[there] = here;
                showplace[there] = showplace[here] + 1;
            }
        }
    }

    int next = n;
    vector<int> route;
    while (next != -1) {
        route.push_back(next);
        next = backtrace[next];
    }
    cout << route.size() << endl;
    reverse(route.begin(), route.end());
    for (int i = 0; i < route.size(); ++i) {
        cout << route[i];
        if (i < route.size())
            cout << " ";
    }
    cout << endl;
    return 0;
}
