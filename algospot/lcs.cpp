#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string a, b;
int cache[15][15];

int lcs(int i, int j) {
    if (i >= a.size())
        return 0;
    if (j >= b.size())
        return 0;
    int& res = cache[i][j];
    if (res != -1)
        return res;
    res = 0;
    if (lcs(i+1, j) > res){
        res = lcs(i+1, j);
    }
    if (lcs(i, j+1) > res) {
        res = lcs(i, j+1);
    }
    if (a[i] == b[j]) {
        if (res < lcs(i+1, j+1) + 1) {
            res = lcs(i+1, j+1) + 1;
        }
    }
    return res;
}

string reconstruct() {
    string res;
    int j = 0;
    int i = 0;
    while(i < a.size() && j < b.size()) {
        while(lcs(i, j) == lcs(i+1, j)) i++;
        while(lcs(i, j) == lcs(i, j+1)) j++;
        res.push_back(a[i]);
        i++;
        j++;
    }
    return res;
}


int main() {
    cin >> a;
    cin >> b;
    memset(cache, -1, sizeof(cache));
    cout << lcs(0, 0) << endl;
    cout << reconstruct() << endl;
}
