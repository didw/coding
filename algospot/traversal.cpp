#include <iostream>
#include <vector>

using namespace std;

vector<int> slice(const vector<int> &v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int> &pre, const vector<int> &in) {
    int N = pre.size();
    if (N == 0) return;
    int r = 0;
    while (pre[0] != in[r]) r++;
    printPostOrder(slice(pre, 1, r+1), slice(in, 0, r));
    printPostOrder(slice(pre, r+1, N), slice(in, r+1, N));
    cout << pre[0] << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> preOrder(n), inOrder(n);
        for (int i = 0; i < n; ++i)
            cin >> preOrder[i];
        for (int i = 0; i < n; ++i)
            cin >> inOrder[i];
        printPostOrder(preOrder, inOrder);
        cout << endl;
    }
}
