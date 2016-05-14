#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lookfor(int n, vector<int> &arr) {
    for (int i = n+1; i < arr.size(); ++i) {
        if (arr[i] != 0 && arr[i] == arr[n]) return true;
    }
    return false;
}
void printDecimal(int a, int b) {
    int iter = 0;
    cout << a/b << ".";
    a = (a%b)*10;
    vector<int> remains;
    for (int i = 0; i < b+1; ++i) {
        remains.push_back(a/b);
        a = (a%b)*10;
        if (a==0) {
            remains.push_back(-1);
            break;
        }
    }
    int start = 0;
    for (int i = 0; i < remains.size(); ++i) {
        if (remains[i] == -1) break;
        if (start == 0) {
            if (lookfor(i, remains)) {
                cout << "(" << remains[i];
                for (int j = i+1; j < remains.size(); ++i) {
                    if (remains[j] == remains[i]) {
                         cout << ")"; return;
                    }
                    cout << remains[i];
                }
            }
        }
        cout << remains[i];
    }
}


int main(int argv, char* argc[]) {
    printDecimal(1,11);
    cout << endl;
    return 0;
}
