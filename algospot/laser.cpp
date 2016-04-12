#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;


int N;
vector<pair<int, int> > points;
bool debug = false;

void input() {
    cin >> N;
    points = vector<pair<int, int> >(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }
}

void divide(int &a, int &b, int &c) {
    int i = 2;
    if (a < 0) {
        a = -a;
        b = -b;
        c = -c;
    }
    if (a == 0 && b < 0) {
        b = -b;
        c = -c;
    }
    while ((!a || abs(a) >= i) && (!b || abs(b) >= i) && (!c || abs(c) >= i)) {
        while (a%i == 0 && b%i == 0 && c%i == 0) {
            a /= i;
            b /= i;
            c /= i;
        }
        i++;
    }
}

typedef tuple <int, int, int> three;

void solve() {
    map<three, int> res;
    for (int i = 0; i < N; ++i) {
        map<three, int> cand;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            int a = points[j].second - points[i].second;
            int b = points[i].first - points[j].first;
            int c = -points[i].first * a - points[i].second * b;
            divide(a, b, c);
            cand[make_tuple(a, b, c)]++;
            if (debug)
                cout << a << " " << b << " " << c << endl;
        }
        if (debug) cout << endl;
        for (auto it = cand.begin(); it != cand.end(); ++it) {
            if (it->second >= 4) {
                res[it->first]++;
            }
        }
    }
    cout << res.size() << endl;
}

int main() {
    int T;

    cin >> T;
    while (T--) {
        input();
        solve();
    }
}
