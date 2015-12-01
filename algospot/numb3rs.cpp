#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

vector<vector<int>> town;
vector<int> neig;
double cache[101][51];
int p;

void precalc() {
    for (int i = 0; i < town.size(); ++i) {
        neig.push_back(0);
        for (int j = 0; j < town[i].size(); ++j) {
            if (town[i][j])
                neig[i]++;
        }
    }
}

double numb3rs(int d, int t) {
    if (d==0) {
        if (t == p) return 1;
        else        return 0;
    }
    double& res = cache[d][t];
    if (res != -1) return res;
    res = 0;
    for (int i = 0; i < town.size(); ++i) {
        if (town[t][i])
            res += numb3rs(d-1, i) / neig[i];
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d >> p;
        town.clear();
        neig.clear();
        for (int i = 0; i < 101; ++i)
            for (int j = 0; j < 51; ++j)
                cache[i][j] = -1;

        for (int i = 0; i < n; ++i) {
            town.push_back(vector<int>());
            for (int j = 0; j < n; ++j) {
                int a;
                cin >> a;
                town[i].push_back(a);
            }
        }
        precalc();
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int a;
            cin >> a;
            printf("%.10f ", numb3rs(d, a));
        }
        cout<<endl;
    }
}
