#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    int begin = 1, matched = 0;
    vector<int> pi(m, 0);
    while (begin < m - matched) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0)
                begin ++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}

vector<int> kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int begin = 0, matched = 0;
    while(begin < n - m) {
        if (matched < m && H[begin + matched] == N[matched]) {
            ++matched;
            if (matched == m) ret.push_back(begin);
        }
        else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}
