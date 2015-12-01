#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int cache[10000];
string a;

int case1(int b, int n) { //[b..n)
    int num = a[b];
    for (int i = b + 1; i < n; ++i)
        if (a[i] != num)
            return 0;
    return 1;
}

int case2(int b, int n) {
    int d = a[b+1] - a[b];
    if (d != 1 && d != -1)
        return 0;
    for (int i = b + 1; i < n; ++i) {
        if (a[i] != a[i-1] + d)
            return 0;
    }
    return 1;
}

int case3(int b, int n) {
    int num[2];
    num[b%2] = a[b];
    num[(b+1)%2] = a[b+1];
    for (int i = b+2; i < n; ++i) {
        if (num[i%2] != a[i])
            return 0;
    }
    return 1;
}

int case4(int b, int n) {
    int dis = a[b+1] - a[b];
    for (int i = b+2; i < n; ++i) {
        if (a[i] - a[i-1] != dis)
            return 0;
    }
    return 1;
}

int min_memory(int begin) {
    int& res = cache[begin];
    if (res != -1)
        return res;
    if (begin == a.size())
        return 0;
    if (a.size() < begin+3)
        return 10000000;
    res = 10000000;
    for (int i = begin+3; i <= min((size_t)begin+5, a.size()); ++i) {
        int ans = 0;
        if (case1(begin, i))
            ans = 1;
        else if (case2(begin, i))
            ans = 2;
        else if (case3(begin, i))
            ans = 4;
        else if (case4(begin, i))
            ans = 5;
        else
            ans = 10;
        res = min(res, min_memory(i) + ans);
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        a.clear();
        cin >> a;
        memset(cache, -1, sizeof(cache));
        cout << min_memory(0) << endl;
    }
}
