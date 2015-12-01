#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int cache[1001][5];
// state1: 모두 비어있음. state2: 위에 두개만 비어있음. state3: 가운데 두개만 비어있음. state4: 아래 두개만 비어있음. state5: 맨위와 맨아래가 비어있음.
int grid(int w, int state) {
    if (w == 0) {
        if (state == 1) return 1;
        else return 0;
    }
    if (w < 0) return 0;
    int& res = cache[w][state];
    if (res != -1) return res;
    res = 0;
    switch (state) {
    case 1:
        res = grid(w - 1, 1) + grid(w - 1, 2) + grid(w - 1, 3) + grid(w - 1, 4) + grid(w - 2, 1);
        break;
    case 2:
        res = grid(w - 1, 1) + grid(w - 1, 4);
        break;
    case 3:
        res = grid(w - 1, 1) + grid(w - 1, 5);
        break;
    case 4:
        res = grid(w - 1, 1) + grid(w - 1, 2);
        break;
    case 5:
        res = grid(w - 1, 3);
        break;
    default:
        cout << "case that didn't consider" << endl;
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int w;
        cin >> w;
        memset(cache, -1, sizeof(cache));
        cout << i + 1 <<" "<<grid(w, 1) << endl;
    }
    return 0;
}
