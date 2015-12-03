#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class VampireTreeDiv2 {
public:
    int countMinSamples(vector <int>, vector <int>);
};

int VampireTreeDiv2::countMinSamples(vector <int> A, vector <int> B) {

}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        for (int i = 0; i < n; ++i)
            cin >> B[i];
        VampireTreeDiv2 vt;
        cout << vt.countMinSamples(A, B) << endl;
    }
}