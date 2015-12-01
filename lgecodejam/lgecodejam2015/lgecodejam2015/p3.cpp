#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int N, M;
vector<int> edges[20000];
map<pair<int, int>, int> friends;

int solve() {
	int res = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < edges[i].size(); ++j) {
			int f1 = edges[i][j];
			for (int k = 0; k < edges[f1].size(); ++k) {
				int f2 = edges[f1][k];
				if (i == f2) continue;
				if (find(edges[f2].begin(), edges[f2].end(), i) == edges[f2].end()) {
					friends[make_pair(i, f2)]++;
					res = max(res, friends[make_pair(i, f2)]);
				}
			}
		}
	}
	return res;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
			edges[i].clear();
		friends.clear();
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			edges[a - 1].push_back(b - 1);
			edges[b - 1].push_back(a - 1);
		}
		cout << solve() << endl;
	}
}