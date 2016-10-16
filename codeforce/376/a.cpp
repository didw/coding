#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int res = 0;
    char prev = 'a';
    for (int i = 0; i < s.size(); ++i) {
        char a, b;
        a = max(s[i], prev);
        b = min(s[i], prev);
        res += min(a - b, b + 26 - a);
        prev = s[i];
    }
    cout << res << endl;
}