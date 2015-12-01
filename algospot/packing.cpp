#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

typedef struct {
    string name;
    int weight;
    int importance;
}stuff;

vector<stuff> pack;
int cache[101][1001];
int carrier[1001];

int packing(int n, int w) {
    if (w < 0) return -1000;
    if (w == 0) return 0;
    if (n == pack.size()) return 0;
    int& res = cache[n][w];
    if (res != -1) return res;
    res = packing(n+1, w);
    int cand = packing(n+1, w-pack[n].weight)+pack[n].importance;
    if (res < cand) {
        carrier[w] = n;
        res = cand;
    }
    return res;
}


void reconstruct(int w, int n, vector<string>& picked) {
    if (n == pack.size()) return;
    if (packing(n, w) == packing(n+1, w)) {
        reconstruct(w, n+1, picked);
    } else {
        picked.push_back(pack[n].name);
        reconstruct(w - pack[n].weight, n+1, picked);
    }
}


void construct(int n, int w) {
    cout<<packing(0, w)<<" ";
    vector<string> picked;
    reconstruct(w, 0, picked);
    cout<<picked.size()<<endl;
    for (int i = 0; i < picked.size(); ++i) {
        cout<<picked[i]<<endl;
    }
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, w;
        cin >> n >> w;
        memset(cache, -1, sizeof(cache));
        memset(carrier, 0, sizeof(carrier));
        pack.clear();
        for (int i = 0; i < n; ++i) {
            stuff t;
            cin >> t.name >> t.weight >> t.importance;
            pack.push_back(t);
        }
        construct(0, w);
    }
}
