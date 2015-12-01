#include <iostream>
#include <queue>

using namespace std;

struct RNG {
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next() {
        unsigned ret = seed;
        seed = (seed * 214013u + 2531011u);
        return ret % 10000 + 1;
    }
};

int main() {
    int c;
    cin >> c;
    while (c--) {
        int k, n;
        cin >> k >> n;
        int begin = 0, end = 0;
        queue<int> q;
        int subsum = 0;
        int res = 0;
        RNG r;
        for (int i = 0; i < n; ++i) {
            q.push(r.next());
            int num = q.back();
            subsum += num;
            while (subsum > k && !q.empty()) {
                subsum -= q.front();
                q.pop();
            }
            if (subsum == k)
                res++;
        }
        cout << res << endl;
    }
}
