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

void initialize() {
    for (int i = 0; i < m; ++i) {
        prob[0][i] = B[i] + M[i][Q[0]];
    }
}

int n;
void recognize(int t, int idx) {
    if (t == n) {
        double res = -1e200;
        for (int i = 0; i < m; ++i) {
            if (res < prob[t-1][i]) {
                path[t][0] = i;
                res = prob[t-1][i];
            }
        }
        return;
    }
    prob[t][idx] = -1e200;
    for (int i = 0; i < m; ++i) {
        double cand = prob[t-1][i] + T[i][idx] + M[idx][Q[t]];
        if (prob[t][idx] < cand) {
            prob[t][idx] = cand;
            path[t][idx] = i;
        }
    }
}

vector<int> keyword;
void reconstruct() {
    keyword.push_back(path[n][0]);
    for (int t = n-1; t > 0; --t) {
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
        for (int t = 1; t <= n; ++t) {
            for (int j = 0; j < m; ++j) {
                recognize(t, j);
            }
        }
        reconstruct();
        for (int i = keyword.size()-1; i >= 0; --i)
            cout << words[keyword[i]] <<" ";
        cout<<endl;
    }
}
