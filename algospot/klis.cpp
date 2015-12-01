#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, S[502];
int cacheLen[502], cacheCnt[502];

int lis(int start) {
    int& res = cacheLen[start + 1];
    if (res != -1) return res;
    res = 1;
    for (int next = start + 1; next < n; ++next) {
        if (start == -1 || S[start] < S[next])
            res = max(res, lis(next) + 1);
    }
    return res;
}

int count(int start) {
    if (lis(start) == 1) return 1;
    int& res = cacheCnt[start + 1];
    if (res != -1) return res;
    res = 0;
    for (int next = start + 1; next < n; ++next) {
        if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
            res = min<long long>(2000000000, (long long)res + count(next));
    }
    return res;
}

void reconstruct(int start, int skip, vector<int>& list) {
    if (start != -1) list.push_back(S[start]);
    if (lis(start) == 1) return;
    vector<pair<int, int>> follower;
    for (int next = start + 1; next < n; ++next) {
        if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
            follower.push_back(make_pair(S[next], next));
    }
    sort(follower.begin(), follower.end());
    for (int i = 0; i < follower.size(); ++i) {
        int idx = follower[i].second;
        int cnt = count(idx);
        if (skip >= cnt)
            skip -= cnt;
        else{
            reconstruct(idx, skip, list);
            break;
        }   
    }
}


int main() {
    int c;
    cin >> c;
    while (c--) {
        int k;
        cin >> n >> k;
        memset(cacheLen, -1, sizeof(cacheLen));
        memset(cacheCnt, -1, sizeof(cacheCnt));
        memset(S, 0, sizeof(S));
        for (int i = 0; i < n; ++i) {
            cin >> S[i];
        }
        count(-1);
        cout << lis(-1) - 1 << endl;
        vector<int> list;
        reconstruct(-1, k-1, list);
        for (int i = 0; i < list.size(); ++i) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
}
