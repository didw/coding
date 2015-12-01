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

int N;
int M;
string S;

int cnt(int last, int idx, long long visited) {
    if (idx == N-1) return 1;
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (visited & (1 << i)) continue;
        if ((S[idx] == 'G' && i > last) || (S[idx] == 'L' && i < last))
            continue;
        res += cnt(i, idx + 1, visited | (1 << i));
        res %= M;
    }
    return res;
}

int solve() {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res += cnt(i, 0, 1 << i);
        res %= M;
    }
    return res;
}

int main(){
    cin >> N >> M;
    cin >> S;
    cout << solve() << endl;
    return 0;
}
