#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class AnArray {
public:
    int solveProblem(vector <int> A, int K) {
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            long long p1 = A[i] % K;
            for (int j = i + 1; j < A.size(); ++j) {
                long long p2 = A[j] % K;
                p2 *= p1;
                p2 %= K;
                for (int k = j + 1; k < A.size(); ++k) {
                    long long p3 = A[k] % K;
                    p3 *= p2;
                    p3 %= K;
                    if (p3 == 0)
                        res++;
                }
            }
        }
        return res;
    }
};