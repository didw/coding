#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int n;
vector<string> dna;
vector<string> res;

int isPalindrom(const string& a) {
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != a[a.size()-1-i])
            return 0;
    return 1;
}

void pdna(int taken, string sdna) {
    if (taken == (1<<n) - 1) {
        if (isPalindrom(sdna)) {
            res.push_back(sdna);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (taken & (1<<i)) continue;
        pdna(taken + (1<<i), sdna + dna[i]);
    }
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        cin >> n;
        dna.clear();
        res.clear();
        for (int i = 0; i < n; ++i) {
            string a;
            cin >> a;
            dna.push_back(a);
        }
        sort(dna.begin(), dna.end());
        pdna(0, "");
        sort(res.begin(), res.end());
        cout<<res[0]<<endl;
    }
}
