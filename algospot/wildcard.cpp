#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int cache[101][101];
string W, S;

int wildcard(int w, int s) {
    int& res = cache[w][s];
    if (res != -1)
        return res;
    int pos = 0;
    if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
        return res = wildcard(w+1, s+1);
    if (w == W.size() && s == S.size())
        return res = 1;
    if (W[w] == '*')
        return res = wildcard(w+1, s) | wildcard(w, s+1);
    return res = 0;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> ans;
        int n;
        cin >> W;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> S;
            memset(cache, -1, sizeof(cache));
            if (wildcard(0, 0))
                ans.push_back(S);
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i)
            cout<<ans[i]<<endl;
    }
}

