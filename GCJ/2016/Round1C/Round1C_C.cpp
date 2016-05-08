#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Jackets, Pants, Shirts, K;

void input() {
	cin >> Jackets >> Pants >> Shirts >> K;
}

void solve() {
	vector<vector<int> > combi1(10, vector<int>(10, 0));
	vector<vector<int> > combi2(10, vector<int>(10, 0));
	vector<vector<int> > combi3(10, vector<int>(10, 0));

	int res = 0;
	for (int j = 0; j < Jackets; ++j) {
		for (int p = 0; p < Pants; ++p) {
			for (int s = 0; s < Shirts; ++s) {
				if (combi1[j][p] >= K) continue;
				if (combi2[j][s] >= K) continue;
				if (combi3[p][s] >= K) continue;
				res++;
				combi1[j][p]++;
				combi2[j][s]++;
				combi3[p][s]++;
			}
		}
	}

	cout << res << endl;

	for (int j = 0; j < 10; ++j) {
		for (int p = 0; p < 10; ++p) {
			for (int s = 0; s < 10; ++s) {
				combi1[j][p] = 0;
				combi2[j][s] = 0;
				combi3[p][s] = 0;
			}
		}
	}

	for (int j = 0; j < Jackets; ++j) {
		for (int p = 0; p < Pants; ++p) {
			for (int s = 0; s < Shirts; ++s) {
				if (combi1[j][p] >= K) continue;
				if (combi2[j][s] >= K) continue;
				if (combi3[p][s] >= K) continue;
				cout << j+1 << " " << p+1 << " " << s+1 << endl;
				combi1[j][p]++;
				combi2[j][s]++;
				combi3[p][s]++;
			}
		}
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
