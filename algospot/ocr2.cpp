#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int m, q;
vector<string> words;
vector<double> B;
vector<vector<double>> T, M;
vector<int> Q;
void data_in() {
    cin >> m >> q;
    for (int i = 0; i < m; ++i) {
        string a;
        cin >> a;
        words.push_back(a);
    }

    for (int i = 0; i < m; ++i) {
        double a;
        cin >> a;
        B.push_back(log(a));
    }

    for (int i = 0; i < m; ++i) {
        T.push_back(vector<double>());
        for (int j = 0; j < m; ++j) {
            double a;
            cin >> a;
            T[i].push_back(log(a));
        }
    }
    for (int i = 0; i < m; ++i) {
        M.push_back(vector<double>());
        for (int j = 0; j < m; ++j) {
            double a;
            cin >> a;
            M[i].push_back(log(a));
        }
    }
}

double prob[101][501];
double path[101][501];
int n;
double recognize(int t, int idx) {
    if (t == n) {
        return 0;
    }
    double& res = prob[t][idx];
    if (res < 0) return res;
    res = -1e200;
    for (int i = 0; i < m; ++i) {
        double cand = T[idx][i] + M[i][Q[t]] + recognize(t+1, i);
        if (res < cand) {
            res = cand;
            path[t][idx] = i;
        }
    }
    return res;
}


void initialize() {
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 501; ++j) {
            prob[i][j] = 1;
        }
    }
    double res = -1e200;
    for (int i = 0; i < m; ++i) {
        double cand = B[i] + M[i][Q[0]] + recognize(1, i);
        if (cand > res) {
            res = cand;
            path[0][0] = i;
        }
    }
}

vector<int> keyword;
void reconstruct() {
    keyword.push_back(path[0][0]);
    for (int t = 1; t < n; ++t) {
        keyword.push_back(path[t][keyword.back()]);
    }
}


int main() {
    data_in();
    for (int i = 0; i < q; ++i) {
        cin >> n;
        Q.clear();
        for (int j = 0; j < n; ++j) {
            string s;
            cin >> s;
            Q.push_back(find(words.begin(), words.end(), s) - words.begin());
        }
        keyword.clear();
        initialize();
        reconstruct();
        for (int i = 0; i < n; ++i)
            cout << words[keyword[i]] <<" ";
        cout<<endl;
    }
}
