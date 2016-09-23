// http://codeforces.com/contest/719/problem/C
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, t;
    string num;
    cin >> n >> t;
    cin >> num;
    int begin = 0, end = 0;
    while (num[begin++] != '.') {
    }
    end = num.length() - 1;
    bool changed = true;
    while (t-- && changed) {
        changed = false;
        for (int i = begin; i <= end; ++i) {
            if (num[i] - '0' >= 5) {
                changed = true;
                end = i-1;
                int j = i-1;
                if (num[j] == '.') {
                    j--;
                }
                while (j >= 0) {
                    num[j]++;
                    if (num[j] != 0) {
                        break;
                    }
                }
            }
        }
    }
    if (num[0] == 0)
        cout << "1";
    for (int i = 0; i <= end; ++i) {
        cout << num[i];
    }
    cout << endl;
}