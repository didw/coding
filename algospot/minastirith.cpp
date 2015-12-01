#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
const double PI = 3.141592;
pair<double, double> tower[100];
int n;


int minastirith(){
    int res = 1000;
    sort(tower, tower+n);
    for (int idx = 0; idx < n; ++idx) {
        if (idx != 0) {
            tower[idx-1].first += 2*PI;
            tower[idx-1].second += 2*PI;
        }
        double begin = tower[idx].second;
        double end = tower[idx].first + 2 * PI;
        int select = 1;
        while (begin < end) {
            double cand = -100;
            for (int i = 0; i < n; ++i) {
                if (tower[i].first < begin) {
                    cand = max(cand, tower[i].second);
                }
            }
            if (cand > begin) {
                begin = cand;
                select++;
            } else {
                select = 1000;
                break;
            }
        }
        res = min(res, select);
    }
    return res;
}

int main () {
    int c;
    cin >> c;
    while (c--) {
        cin >> n;
        memset(tower, 0, sizeof(tower));
        for(int i = 0; i < n; ++i) {
            double y, x, r;
            cin >> y >> x >> r;
            double c = atan2(y, x);
            double l = 2*asin(r/16);
            tower[i] = make_pair(c-l, c+l);
        }
        int res = minastirith();
        if (res != 1000)
            cout << minastirith() << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
}
