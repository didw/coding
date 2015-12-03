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

class FoxAndMp3Easy {
public:
    vector <string> playList(int);
};

vector <string> FoxAndMp3Easy::playList(int n) {
    vector<string> name(n);
    for (int i = 0; i < n; ++i) {
        char nn[100];
        sprintf(nn, "%d.mp3", i+1);
        name[i] = nn;
    }
    sort(name.begin(), name.end());
    vector<string> res;
    int end = min(50, n);
    for (int i = 0; i < end; ++i)
        res.push_back(name[i]);
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        FoxAndMp3Easy fa;
        vector<string> res = fa.playList(n);
        for (int i = 0; i < res.size(); ++i)
            cout << res[i] << endl;
    }
}