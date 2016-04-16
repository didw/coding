#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
vector<vector<int> > soldiers;
vector<int> heights;

void input() {
	cin >> N;
	soldiers = vector<vector<int> >(2*N-1, vector<int>(N, 0));
	for (int i = 0; i < 2*N - 1; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> soldiers[i][j];
	}
}

void solve() {
	heights = vector<int>(2501, 0);
	for (int i = 0; i < 2*N-1; ++i) {
		for (int j = 0; j < N; ++j) {
			heights[soldiers[i][j]] += 1;
		}
	}
	vector<int> cand;
	for (int i = 0; i < 2501; ++i) {
		if (heights[i]%2 == 1) {
			cand.push_back(i);
		}
	}

	sort(cand.begin(), cand.end());
	for (int i = 0; i < N; ++i) {
		cout << cand[i];
		if (i!=N-1) cout << " ";
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();
		cout << "Case #" << i << ": ";
		solve();
	}
}
