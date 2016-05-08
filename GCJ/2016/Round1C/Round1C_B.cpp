#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long B, M;

void input() {
	cin >> B >> M;
}

void solve() {
	vector<long long> cnt(B);
	cnt[0] = cnt[1] = 1;
	for (int i = 2; i < B; ++i) {
		cnt[i] = 2 * cnt[i-1];
	}

	vector<vector<int> > mat(B, vector<int>(B, 0));
	for (int i = 0; i < B; ++i) {
		for (int j = i+1; j < B-1; ++j) {
			mat[i][j] = 1;
		}
	}


	for (int i = B-2; i >= 0; i--) {
		if (M >= cnt[i]) {
			M -= cnt[i];
			mat[i][B-1] = 1;
		}
	}

	if (M == 0) {
		cout << "POSSIBLE" << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	for (int i = 0; i < B; ++i) {
		for (int j = 0; j < B; ++j) {
			cout << mat[i][j];
		}
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();
		printf("Case #%d: ", i);
		solve();
	}

}
