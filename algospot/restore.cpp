#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
const int MAX = 16;
int cache[MAX][1<<MAX], overlap[MAX][MAX];
string words[MAX];
int n;

int restore(int last, int used) {
    if (used == (1<<n)-1) return 0;
    int& res = cache[last+1][used];
    if (res != -1) return res;
    res = 0;
    for (int next = 0; next < n; ++next) {
        if (used & (1<<next)) continue;
        int cand = restore(next, used + (1<<next));
        if (last == -1)
            res = max(res, cand);
        else
            res = max(res, cand + overlap[last][next]);
    }
    return res;
}

string reconstruct(int last, int used) {
    if (used == (1<<n)-1) return "";
    for (int next = 0; next < n; ++next) {
        if (used & (1<<next)) continue;
        int next_overlap;
        if (last == -1)
            next_overlap = 0;
        else
            next_overlap = overlap[last][next];
        if (restore(last, used) == restore(next, used + (1<<next)) + next_overlap)
            return words[next].substr(next_overlap) + reconstruct(next, used + (1<<next));
    }
    return "SOMETHING WRONG";
}

void preCalc() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = words[i].size(); k > 0; --k) {
                int ia = words[i].size() - k, ib = 0;
                while(ia < words[i].size() && ib < words[j].size() &&
                    words[i][ia] == words[j][ib]) {
                        ia++; ib++;
                }
                if (ia == words[i].size() || ib == words[j].size()) {
                    overlap[i][j] = k;
                    break;
                }
            }
        }
    }
}

int isIn(int i, int j) {
    for (int k = 0; k < words[j].size(); ++k) {
        int ia = 0, ib = k;
        while(ia < words[i].size() && ib < words[j].size() &&
            words[i][ia] == words[j][ib]) {
                ia++; ib++;
        }
        if (ia == words[i].size())
            return 1;
    }
    return 0;
}

void delete_words(int k) {
    for (int i = k; i < n; ++i)
        words[i] = words[i+1];
    n--;
}

int delete_dup() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && isIn(i, j)) {
                delete_words(i);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        memset(overlap, 0, sizeof(overlap));
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
        }
        while(delete_dup());
        preCalc();
        cout<<reconstruct(-1, 0)<<endl;
    }
}
