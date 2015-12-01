#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> fence;

int get_max_fence(int left, int right){
    if (left == right)
        return fence[left];
    int half = (left+right)/2;
    int res = max(get_max_fence(left, half), get_max_fence(half+1, right));
    int lo = half, hi = half+1;
    int height = min(fence[lo], fence[hi]);
    res = max(res, height*2);
    while (left < lo || hi < right) {
        if (hi < right && (lo == left || fence[hi+1] > fence[lo-1])) {
            ++hi;
            height = min(height, fence[hi]);
        } else {
            --lo;
            height = min(height, fence[lo]);
        }
        res = max(res, height*(hi-lo+1));
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        fence.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            fence.push_back(a);
        }
        cout<<get_max_fence(0, n-1)<<endl;
    }
}
