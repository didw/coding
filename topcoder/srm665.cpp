#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class LuckySum {
    const long long INF = 987655432109876LL;
    long long result;
    vector<int> note, A, B, C;
public:
    void backtrace(int p, long long x, long long ten_p) {

    }
    long long construct(string note) {
        int n = note.size();
        this->note.resize(n);
        A.resize(n);
        B.resize(n);
        C.resize(n);
        for (int i = 0; i < n; ++i) {
            this->note[n - i - 1] = note[i] == '?' ? -1 : note[i] - '0';
        }
        result = INF;
        backtrace(0, 0LL, 1);
        return (result >= INF) ? -1 : result;
    }
};