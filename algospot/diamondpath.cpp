#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> diamond;
int cache[200][101];
int n;

int get_max_path(int i, int j) {
    if (j < 0 || j >= diamond[i].size())
        return -1;
    if (i==2*n-2)
        return diamond[i][j];
    int& res = cache[i][j];
    if (res != 0)
        return res;
    res = get_max_path(i+1, j);
    if (i < n-1)
        res = max(res, get_max_path(i+1, j+1));
    else
        res = max(res, get_max_path(i+1, j-1));
    res += diamond[i][j];
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        diamond.clear();
        memset(cache, 0, sizeof(cache));
        cin >> n;
        int idx = 0;
        for (int i = 0; i < 2*n-1; ++i) {
            diamond.push_back(vector<int>());
            if (i < n)
                idx++;
            else
                idx--;
            for (int j = 0; j < idx; ++j) {
                int a;
                cin >> a;
                diamond[i].push_back(a);
            }
        }
        cout<<get_max_path(0, 0)<<endl;
    }
}
