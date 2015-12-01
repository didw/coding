#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> series;
int cache[1001][10];

int min_error(int from, int to) {
    int n = 0;
    for (int i = from; i <= to; ++i) {
        n += series[i];
    }
    int k = 0.5 + (double)n / (to-from+1);
    int res = 0;
    for (int i = from; i <= to; ++i) {
        res += (series[i]-k)*(series[i]-k);
    }
    return res;
}
 
int quantize(int from, int group) {
    int& res = cache[from][group];
    if (res != -1) return res;
    if (from == series.size())
        return 0;
    if (group == 0)
        return 1234567890;
    res = 1234567890;
    for (int i = from; i < series.size(); ++i) {
        res = min(res, min_error(from, i) + quantize(i+1, group-1));
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n, s;
        cin >> n >> s;
        memset(cache, -1, sizeof(cache));
        series.clear();
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            series.push_back(a);
        }
        sort(series.begin(), series.end());
        cout<<quantize(0, s)<<endl;
    }
}
