// B. War of the Corporations
// http://codeforces.com/contest/625/problem/B

#include <iostream>
#include <string>

using namespace std;

int main () {
    string a, b;
    cin >> a >> b;
    int res = 0;
    int prev_end = -1;
    for (int i = 0; i + b.size() <= a.size();) {
        bool match = true;
        for (int j = 0; j < b.size(); ++j) {
             if (a[i+j] != b[j]) {
                 match = false;
                 break;
             }
        }
        if (match) {
            res++;
            i += b.size();
        } else
            i++;
    }
    cout << res;
}

