#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int christmas(vector<int>& psum, int k) {
    vector<long long> freq(k, 0);
    for (int i = 0; i < psum.size(); ++i) {
        freq[psum[i]]++;
    }
    int res = 0;
    const int mod = 20091101;
    for (int i = 0; i < freq.size(); ++i) {
        if (freq[i] >= 2)
            res = (res + (freq[i]*(freq[i]-1))/2)%mod;
    }
    return res;
}

int christmas2(vector<int>& psum, int k) {
    vector<int> res(psum.size(), 0);
    vector<int> prev(k, -1);
    res[0] = 0;
    prev[0] = 0;
    for (int i = 1; i < psum.size(); ++i) {
        res[i] = res[i-1];
        int loc = prev[psum[i]];
        prev[psum[i]] = i;
        if (loc != -1)
            res[i] = max(res[i], res[loc] + 1);
    }
    return res.back();
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, k;
        cin >> n >> k;
        vector<int> psum;
        psum.push_back(0);
        for (int i = 0; i < n; ++i) {
            int doll;
            cin >> doll;
            psum.push_back((psum.back()+doll)%k);
        }
        cout << christmas(psum, k) << " ";
        cout << christmas2(psum, k) << endl;
    }
}
