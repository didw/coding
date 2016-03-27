//http://codeforces.com/contest/651/problem/A
//Codeforces Round #345 (Div. 2)
#include <iostream>

using namespace std;

int main() {
    int a, b, m=0;
    cin >> a >> b;
    while (a != 0 && b != 0) {
        if (a <= 2 && b <= 2) {
            break;
        }
        while (a - 2 > 0) {
            a -= 2;
            b++;
            m++;
        }
        while (b - 2 > 0) {
            b -= 2;
            a++;
            m++;
        }
    }
    if (a >= 2 || b >= 2)
        cout << m + 1 << endl;
    else
        cout << m << endl;
    return 0;
}