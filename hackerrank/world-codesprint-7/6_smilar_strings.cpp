//https://www.hackerrank.com/contests/world-codesprint-7/challenges/similar-strings
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;



int is_similar(string a, string b) {
    vector<int> alp1(10, -1);
    vector<int> alp2(10, -1);
    for (int i = 0; i < a.size(); ++i) {
        if (alp1[a[i] - 'a'] != alp2[b[i] - 'a'])
            return 0;
        if (alp1[a[i] - 'a'] == -1) alp1[a[i] - 'a'] = i;
        if (alp2[b[i] - 'a'] == -1) alp2[b[i] - 'a'] = i;
    }
    return 1;
}

int solve(string str, int l, int r) {
    string substr = str.substr(l - 1, r - l + 1);
    int len = r - l + 1;
    int res = 0;
    for (int i = 0; i <= str.size() - len; ++i) {
        res += is_similar(substr, str.substr(i, len));
    }
    return res;
}

int main() {
    int n, q;
    string str;
    cin >> n >> q;
    cin >> str;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << solve(str, l, r) << endl;
    }
    return 0;
}
