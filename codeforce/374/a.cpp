#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> res;
    
    int i = 0;
    while (i < s.size()) {
        while (s[i] == 'W') { i++; }
        int cand = 0;
        while (s[i] == 'B') { cand++; i++; }
        if (cand != 0)
            res.push_back(cand);
    }
    cout << res.size() << endl;
    if (res.size() == 0) return 0;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i+1 != res.size())
            cout << " ";
    }
    cout << endl;
    return 0;
}