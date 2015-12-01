#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int bino[201][201];

void calc_bino() {
    memset(bino, 0, sizeof(bino));
    for (int i = 0; i < 201; ++i) {
        bino[i][0] = bino[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            bino[i][j] = min(1000000001, bino[i-1][j-1] + bino[i-1][j]);
        }
    }
}

string morse(int n, int m, int k) {
    if (n == 0) return string(m, 'o');
    if (k <= bino[n+m-1][m])
        return "-" + morse(n-1, m, k);
    return "o" + morse(n, m-1, k - bino[n+m-1][m]);
}

int main() {
    int c;
    cin >> c;
    calc_bino();
    while(c--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout<<morse(n, m, k)<<endl;
    }
}

