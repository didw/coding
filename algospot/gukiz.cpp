#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
long long box[100000];
long long n, m;

bool gukiz(long long time) {
    long long index = 0;
    long long cp[100000];
    memcpy(cp, box, 100000*sizeof(long long));
    for (int i = 0; i < m; ++i) {
        long long work = time - index - 1;
        while(cp[index] <= work) {
            work -= cp[index];
            work--;
            index++;
            if (index == n)
                return true;
        }
        if (work > 0)
            cp[index] -= work;
    }
    return false;
}

long long search(long long lo, long long hi) {
    while (hi > lo + 1) {
        long long mid = (lo + hi)/2;
        if (gukiz(mid)) {
            hi = mid;
        }
        else
            lo = mid;
    }
    return hi;
}

int main() {
    cin >> n >> m;
    for (long long i = 0; i < n; ++i) {
        cin >> box[i];
    }
    int i = n - 1;
    while (box[i--] == 0) n--;
    cout << search(0, 1e15) << endl;
}
