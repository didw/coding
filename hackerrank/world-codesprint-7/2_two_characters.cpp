//https://www.hackerrank.com/contests/world-codesprint-7/challenges/two-characters

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    int len;
    cin >> len;
    string s;
    cin >> s;
    int res = 0;
    if (s.length() <= 1) {
        cout << "0" << endl;
        return 0;
    }

    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            if (i == j) continue;
            int cand = 0, idx = 0;
            for (int k = 0; k < s.length(); ++k) {
                if (s[k] != i && s[k] != j)
                    continue;
                if (s[k] == i && idx == 0) {
                    cand = 0;
                    break;
                }
                if (s[k] == j && idx == 1) {
                    cand = 0;
                    break;
                }
                idx ^= 1;
                cand++;
            }
            res = max(res, cand);
        }
    }
    cout << res << endl;
    return 0;
}
