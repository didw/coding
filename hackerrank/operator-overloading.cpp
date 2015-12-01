//https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/operator-overloading

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    vector<vector<int>> a;
    Matrix operator+ (Matrix b) {
        Matrix res;
        for (int i = 0; i < a.size(); ++i) {
            vector<int> c(a[0].size());
            for (int j = 0; j < a[0].size(); ++j) {
                c[j] = a[i][j] + b.a[i][j];
            }
            res.a.push_back(c);
        }
        return res;
    }
};
