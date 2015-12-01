//https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/consecutive-numbers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());
        int res = 1, cnt = 1;
        for (int i = 1; i < N; ++i) {
            if (A[i] == A[i - 1] + 1) {
                cnt++;
                res = max(res, cnt);
            }
            else if (A[i] == A[i - 1])
                continue;
            else
                cnt = 1;
        }
        cout << res << endl;
    }
    return 0;
}
