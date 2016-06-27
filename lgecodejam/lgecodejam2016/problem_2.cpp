#include <iostream>
#include <vector>

using namespace std;

bool isSame(vector<int>& a, vector<int> &b) {
    int N = a.size();
    for (int begin = 0; begin < N; ++begin) {
        bool same = true;
        for (int i = 0; i < N; ++i) {
            int ia = (begin + i) % N;
            if (a[ia] != b[i]) {
                same = false;
                break;
            }
        }
        if (same) return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> rec1(N), rec2(N);
        vector<int> rec1rev(N);
        for (int i = 0; i < N; ++i) {
            cin >> rec1[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> rec2[i];
        }
        reverse(rec1.begin(), rec1.end());
        int sign = rec1[0] * rec1[N-1] > 0 ? 1 : -1;
        rec1rev[N-1] = (-rec1[N-1]) * sign;
        for (int i = 0; i < N-1; ++i) {
            int sign = rec1[i] * rec1[i + 1] > 0 ? 1 : -1;
            rec1rev[i] = (-rec1[i]) * sign;
        }
        reverse(rec1.begin(), rec1.end());

        //for (int i = 0; i < N; ++i) {
        //    cout << rec1[i] << " ";
        //}
        //cout << endl;
        //for (int i = 0; i < N; ++i) {
        //    cout << rec1rev[i] << " ";
        //}
        //cout << endl;
        //for (int i = 0; i < N; ++i) {
        //    cout << rec2[i] << " ";
        //}
        //cout << endl;
        //cout << endl;
        

        if (isSame(rec1, rec2))
            cout << "1" << endl;
        else if (isSame(rec1rev, rec2))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
}
