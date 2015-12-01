#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int cache[505][505];

int lis(vector<int>& seq, int p, int idx) {
    if (idx == seq.size())
        return 0;
    int& res = cache[p][idx];
    if (res != -1) return res;
    if (seq[idx] > seq[p])
        res = lis(seq, idx, idx+1) + 1;
    res = max(res, lis(seq, p, idx+1));
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> seq;
        cin >> n;
        memset(cache, -1, sizeof(cache));
        seq.push_back(-1);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            seq.push_back(a);
        }
        cout<<lis(seq, 0, 1)<<endl;
    }
    return 0;
}
