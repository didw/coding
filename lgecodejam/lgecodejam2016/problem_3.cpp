#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string in;
        cin >> in;
        vector<short> str(in.size(), 0);
        int N = in.size();
        for (int i = 0; i < N; ++i) {
            str[i] = in[i] - 'a';
        }
        int res = 0;
        for (int i = 0; i < N; ++i) {
            int out = 0;
            for (int j = i; j < N; ++j) {
                out ^= (1 << str[j]);
                if (out == 0) res++;
            }
        }
        cout << res << endl;
    }
}