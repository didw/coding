//https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/deque-stl
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

int N, K;
vector<int> A;


void input() {
    cin >> N >> K;
    A = vector<int>(N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
}

class SegmentTree {
public:
    int max_[40000];
    int start;
    SegmentTree(vector<int> arr) {
        start = 1;
        while (start < arr.size()) {
            start *= 2;
        }
        memset(max_, -1, sizeof(max_));
        for (int i = 0; i < arr.size(); ++i) {
            max_[start+i] = arr[i];
        }
        for (int i = start - 1; i > 0; --i) {
            max_[i] = max(max_[2 * i], max_[2 * i + 1]);
        }
    }

    int getMax(int root, int start, int end, int from, int to) {
        if (from <= start && end <= to) return max_[root];
        int mid = (start + end) / 2;
        int maxi = 0;
        if (from <= mid) {
            maxi = getMax(root * 2, start, mid, from, min(mid, to));
        }
        if (mid < to) {
            maxi = max(maxi, getMax(root * 2 + 1, mid+1, end, max(from, mid+1), to));
        }
        return maxi;
    }

    int getMax(int from, int to) {
        return getMax(1, 1, start, from, to);
    }
};

void solve() {
    SegmentTree st = SegmentTree(A);
    for (int i = K; i <= N; ++i) {        
        printf("%d ", st.getMax(i - K + 1, i));
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        input();
        solve();
    }
}