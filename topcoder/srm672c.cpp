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
#include <cstring>

using namespace std;

int N;
int cache[18][1 << 18];
vector<vector<int>> S;

class Tdetectived2 {
public:
    int reveal(vector <string>);
};

int f(int k, int mask) {
    int& res = cache[k][mask];
    if (res != -1) return res;

    int susp = -1;
    for (int i = 1; i < N; ++i) {
        int susp_i = 0;
        if ((1 << i) & mask) continue;
        for (int j = 0; j < N; ++j) {
            if ((1<<j) & mask)
                susp_i = max(susp_i, S[j][i]);
        }
        int cand = 1 + ((i == k) ? 0 : f(k, mask | (1 << i)));
        if (susp_i > susp) {
            susp = susp_i;
            res = cand;
        }
        else if (susp_i == susp) {
            res = min(res, cand);
        }
    }
    return res;
}

int Tdetectived2::reveal(vector <string> s) {
    memset(cache, -1, sizeof(cache));
    int res = 0;
    N = s.size();
    S = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < s.size(); ++i)
        for (int j = 0; j < s.size(); ++j)
            S[i][j] = s[i][j] - '0';

    for (int i = 1; i < s.size(); ++i) {
        res += i*f(i, 1);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> s(N);
        for (int i = 0; i < N; ++i) {
            cin >> s[i];
        }
        Tdetectived2 t2;
        cout << t2.reveal(s) << endl;
    }
}

/* input
5
4
0224
2011
2104
4140
3
000
000
000
7
0313131
3030020
1301132
3010031
1010003
3233003
1021330
9
064675511
603525154
430262731
652030511
726302420
552020464
517544052
153126500
141104200
17
00101011110101100
00010001101011111
10010001010001000
01100011011000110
10000101000111101
00001010101010000
10010101010000010
11111010001011110
11000100000101110
10110010000010000
01010101000010111
10001000100011001
01001101011100111
11101001100100100
11011001101011000
01010011101010001
01001000001110010
*/

/* output
10
3
37
170
198
*/