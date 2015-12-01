#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int numbers[50], cache[50][50];
const int EMPTY = -50001;

int numbergame(int left, int right) {
    if (right < left) return 0;
    int& res = cache[left][right];
    if (res != EMPTY) return res;
    res = max(numbers[left] - numbergame(left+1, right), 
        numbers[right] - numbergame(left, right-1));
    if (right - left > 0) {
        res = max(res, -numbergame(left+2, right));
        res = max(res, -numbergame(left, right-2));
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cache[i][j] = EMPTY;
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }
        cout<<numbergame(0, n-1)<<endl;
    }
}
