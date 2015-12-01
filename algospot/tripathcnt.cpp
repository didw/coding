#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> triangle;
int trisum[101][101];
int tripath[101][101];
int get_sum(int y, int x) {
    int& res = trisum[y][x];
    if (res != -1) return res;
    if (y == triangle.size() - 1)
        return res = triangle[y][x];
    res = 0;
    res = max(get_sum(y + 1, x), get_sum(y + 1, x + 1)) + triangle[y][x];
    return res;
}

int get_path(int y, int x) {
    if (y == triangle.size() - 1)
        return 1;
    int& res = tripath[y][x];
    if (res != -1) return res;

    if (trisum[y + 1][x] > trisum[y + 1][x + 1])
        res = get_path(y + 1, x);
    else if (trisum[y + 1][x] < trisum[y + 1][x + 1])
        res = get_path(y + 1, x+1);
    else
        res = get_path(y + 1, x) + get_path(y+1, x+1);
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(trisum, -1, sizeof(trisum));
        memset(tripath, -1, sizeof(tripath));
        triangle.clear();
        for (int i = 0; i < n; ++i) {
            triangle.push_back(vector<int>());
            for (int j = 0; j <= i; ++j) {
                int a;
                cin >> a;
                triangle[i].push_back(a);
            }
        }
        get_sum(0, 0);
        cout << get_path(0, 0) << endl;
    }
}
