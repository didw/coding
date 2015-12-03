#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class ShopPositions {
    int n, m;
    vector<int> C;
    int dp[31][31][31];
    int f(int a, int b, int i) {
        int& res = dp[a][b][i];
        if (res != -1) return res;
        res = 0;
        if (i == n) {
            int p = 0;
            if (b != 0)
                p = b*C[(i - 1) * 3*m + a + b - 1];
            res = p;
        }
        else {
            for (int c = 0; c <= m; ++c) {
                int p = 0;
                if (b != 0)
                    p = b*C[(i - 1) * 3 * m + a + b + c - 1];
                p += f(b, c, i + 1);
                res = max(res, p);
            }
        }
        return res;
    }
public:
    int maxProfit(int n, int m, vector<int> c) {
        memset(dp, -1, sizeof(dp));
        this->n = n;
        this->m = m;
        this->C = c;
        int res = 0;
        for (int a = 0; a <= m; ++a) {
            for (int b = 0; b <= m; ++b) {
                int p = 0;
                if (a != 0)
                    p = a*c[a + b-1];
                if (n >= 2)
                    p += f(a, b, 2);
                else if (b != 0)
                    p = -1;
                res = max(res, p);
            }
        }
        return res;
    }
};