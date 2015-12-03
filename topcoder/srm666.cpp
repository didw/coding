#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class CollectingTokens {
    int dp[50][50][100][2];
    vector<int> edges[50];
    vector<int> tokens;
public:
    int f(int x, int e, int L, int m) {
        int& res = dp[x][e][L][m];
        if (res != -1) return res;
        res = 0;
        if (e != edges[x].size()) {
            for (int s = 0; s <= L; ++s) {
                if (L-s >= 2) {
                    int tp = f(edges[x][e], 0, s, 1) + f(x, e + 1, L - s - 2, m) + tokens[edges[x][e]];
                    res = max(res, tp);
                }
                if (L-s >= 1 && m == 0) {
                    int tp = f(edges[x][e], 0, s, 0) + f(x, e + 1, L - s - 1, 1) + tokens[edges[x][e]];
                    res = max(res, tp);
                }
            }
            int tp = f(x, e + 1, L, m);
            res = max(res, tp);
        }
        return res;
    }
    void make_graph(vector<int> &A, vector<int>& B, int n) {
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == n && edges[B[i]-1].size() == 0) {
                edges[n - 1].push_back(B[i] - 1);
                make_graph(A, B, B[i]);
            }
            if (B[i] == n && edges[A[i]-1].size() == 0) {
                edges[n - 1].push_back(A[i] - 1);
                make_graph(A, B, A[i]);
            }
        }
    }
    int maxTokens(vector<int> A, vector<int> B, vector<int> tokens, int L) {
        memset(dp, -1, sizeof(dp));
        this->tokens = tokens;
        make_graph(A, B, 1);
        return f(0, 0, L, 0) + tokens[0];
    }
};