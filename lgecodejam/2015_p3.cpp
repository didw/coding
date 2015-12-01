#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;
int n, m;
vector<int> connect[10];
int best;
void search(vector<int>& position, vector<int>& line, int begin, int end, int currDist) {
    if (best <= currDist) return;
    if (line.size() == n) {
        best = min(best, currDist);
        return;
    }
    position[begin] = line.size();
    line.push_back(begin);
    int dist = 0;
    for (int i = 0; i < connect[begin].size(); ++i) {
        int there = connect[begin][i];
        if (position[there] == -1) continue;
        dist += position[begin] - position[there];
    }
    search(position, line, begin + 1, end, currDist + dist);
    line.pop_back();
    position[begin] = -1;

    position[end] = line.size();
    line.push_back(end);
    dist = 0;
    for (int i = 0; i < connect[end].size(); ++i) {
        int there = connect[end][i];
        if (position[there] == -1) continue;
        dist += position[end] - position[there];
    }
    search(position, line, begin, end - 1, currDist + dist);
    line.pop_back();
    position[end] = -1;
}

int solve() {
    best = INF;
    vector<int> line(0);
    vector<int> position(n, -1);
    search(position, line, 0, n-1, 0);
    return best;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            connect[i].clear();
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            connect[a - 1].push_back(b - 1);
            connect[b - 1].push_back(a - 1);
        }
        cout << solve() << endl;
    }
}
