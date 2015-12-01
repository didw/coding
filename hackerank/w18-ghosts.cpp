#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// The difference between the town number and the street number is divisible by 3.
bool cond1(int a, int b) {
    if (a < b) return cond1(b, a);
    return ((a - b) % 3) == 0;
}

// The sum of the street number and the house number is divisible by 5.
bool cond2(int b, int c) {
    return (b + c) % 5 == 0;
}

// The product of the town number and the house number is divisible by 4.
bool cond3(int a, int c) {
    return a*c % 4 == 0;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

// The greatest common divisor of the town number and the apartment number is 1.
bool cond4(int a, int d) {
    return gcd(a, d) == 1;
}

int main(){
    int A; // town
    int B; // street
    int C; // house
    int D; // apartment
    int res = 0;
    cin >> A >> B >> C >> D;
    for (int a = 1; a <= A; a++)
        for (int b = 1; b <= B; b++)
            for (int c = 1; c <= C; c++)
                for (int d = 1; d <= D; d++)
                    if (cond1(a, b) && cond2(b, c) && cond3(a, c) && cond4(a, d))
                        res++;
    cout << res << endl;
    return 0;
}
