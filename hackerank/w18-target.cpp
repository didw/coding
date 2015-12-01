#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

double dist(vector<int>& x) {
    return sqrt((double)x[0] * x[0] + (double)x[1] * x[1]);
}

int scored(vector<int>& R, double r) {
    int lo = 0, hi = R.size() - 1;
    if (r <= R[hi]) return R.size();
    if (r > R[0]) return 0;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (R[mid] < r)
            hi = mid;
        else
            lo = mid;
    }
    return lo + 1;
}

int solve(vector<int>& R, vector<vector<int>>& x) {
    int res = 0;
    for (int i = 0; i < x.size(); ++i) {
        int score;
        double r = dist(x[i]);
        res += scored(R, r);
    }
    return res;
}

int main(){
    int K;
    int N;
    cin >> K >> N;
    vector<int> R(K);
    for (int R_i = 0; R_i < K; R_i++){
        cin >> R[R_i];
    }
    vector< vector<int> > x(N, vector<int>(2));
    for (int x_i = 0; x_i < N; x_i++){
        for (int x_j = 0; x_j < 2; x_j++){
            cin >> x[x_i][x_j];
        }
    }
    cout << solve(R, x) << endl;
    return 0;
}
