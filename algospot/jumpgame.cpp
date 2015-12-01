#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int board[100][100];
int cache[100][100];
int n;

int can_reach(int y, int x) {
    if (y == n-1 && x == n-1) 
        return 1;
    if (y < 0 || y >= n || x < 0 || x >= n)
        return 0;
    int& ret = cache[y][x];
    if (ret != -1)
        return ret;
    ret = can_reach(y+board[y][x], x) || can_reach(y, x + board[y][x]);
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>board[i][j];
            }
        }
        if (can_reach(0, 0))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
