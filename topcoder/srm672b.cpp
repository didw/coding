#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class SubstitutionCipher {
public:
    string decode(string, string, string);
};

string SubstitutionCipher::decode(string a, string b, string y) {
    string res;
    string table;
    int notexist = 0;
    char notA, notB;
    for (int i = 0; i < 26; ++i) {
        auto it = find(b.begin(), b.end(), 'A' + i);
        if (it == b.end()) {
            notexist++;
            notB = 'A' + i;
        }
    }
    if (notexist == 1) {
        b.push_back(notB);
        for (int i = 0; i < 26; ++i) {
            auto it = find(a.begin(), a.end(), 'A' + i);
            if (it == a.end()) {
                notA = 'A' + i;
                a.push_back(notA);
                break;
            }
        }
    }
    for (int i = 0; i < y.size(); ++i) {
        auto it = find(b.begin(), b.end(), y[i]);
        if (it == b.end()) {
            return "";
        }
        res.push_back(a[it - b.begin()]);
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        string a, b, t;
        cin >> a >> b >> t;
        SubstitutionCipher sc;
        cout << sc.decode(a, b, t) << endl;
    }
}