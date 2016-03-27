//http://codeforces.com/contest/651/problem/B
//Codeforces Round #345 (Div. 2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> paints(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> paints[i];
    }
    sort(paints.begin(), paints.end());
    int prev = paints[0], prev_i = 0, happy = 0, nvisit = 0;
    visited[0] = true;
    for (int j = 1; j < n; ++j) {
        int cand = 1000, cand_i = -1;
        for (int i = prev_i; i < n; ++i) {
            if (visited[i]) continue;
            if (paints[i] > prev) {
                cand = paints[i];
                cand_i = i;
                happy++;
                break;
            }
        }
        if (cand_i == -1) {
            for (int i = 0; i < n; ++i) {
                if (visited[i]) continue;
                cand = paints[i];
                cand_i = i;
                break;
            }
        }
        prev = cand;
        prev_i = cand_i;
        visited[cand_i] = true;
        //cout << paints[cand_i] << " ";
    }
    cout << happy << endl;
}