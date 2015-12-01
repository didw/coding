#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int n;
double dist[100][100];

bool decision(double gap) {
    queue<int> q;
    bool visited[100] = {0};
    q.push(0);
    visited[0] = true;
    int selected = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        selected++;
        for (int next = 0; next < n; ++next) {
            if (!visited[next] && dist[here][next] <= gap) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return selected == n;
}

double optimize() {
    double lo = 0, hi = 2000;
    for (int i = 0; i < 100; ++i) {
        double mid = (lo + hi) / 2;
        if (decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        cin >> n;
        double camp[100][2];
        for (int i = 0; i < n; ++i) {
            cin >> camp[i][0] >> camp[i][1];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] =  sqrt((camp[i][0]-camp[j][0])*(camp[i][0]-camp[j][0]) +
                                   (camp[i][1]-camp[j][1])*(camp[i][1]-camp[j][1]));
            }
        }
        printf("%.2lf\n", optimize());
    }
}
