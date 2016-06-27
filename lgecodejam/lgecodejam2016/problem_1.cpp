#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> children[50001];
        vector<int> depth(N+1, 1);
        vector<bool> findRoot(N+1, true);
        for (int i = 0; i < N-1; ++i) {
            int a, b;
            cin >> a >> b;
            children[a].push_back(b);
            findRoot[b] = false;
        }
        int root = 0;
        for (int i = 1; i <= N; ++i) {
            if (findRoot[i]) {
                root = i;
                break;
            }
        }
        queue<int> q;
        q.push(root);



        int res = 0;
        //cout << root << endl;
        while (!q.empty()) {
            int cand = q.front();
            q.pop();
            int cur_depth = depth[cand];
            for (int i = 0; i < children[cand].size(); ++i) {
                int next = children[cand][i];
                q.push(next);
                depth[next] = cur_depth + 1;
                res = max(res, depth[next]);
                //cout << next << "(" << children[next].size() << ") ";
            }
            //cout << endl;
        }
        cout << res << endl;
    }
}