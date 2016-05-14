#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

size_t N, M, K;
vector<pair<int, int> > vote;

void input() {
	cin >> N >> M >> K;
	vote = vector<pair<int, int> >(N);
	for (size_t i = 0; i < N; ++i) {
		cin >> vote[i].first >> vote[i].second;
	}
	sort(vote.begin(), vote.end(), greater<pair<int, int> >());
}

int getMinVote(int A, int B, int C, int i) {
	if (C == 0) return 1e9;
	int res = ((vote[0].first - vote[i].first) * A + (vote[0].second - vote[i].second) * B + C) / C;
	return res < 0 ? 0 : res;
}

bool isAvailable(int A, int begin) {
	for (int B = 0; A + B <= 100; ++B) {
		size_t C = 100 - A - B;
		//size_t needs = 0;
		vector<int> needs;
		for (size_t i = begin; i< N; ++i) {
			needs.push_back(getMinVote(A, B, C, i));
		}
		sort(needs.begin(), needs.end());
		int res = 0;
		for (int i = 0; i < M; ++i)
			res += needs[i];
		if (res <= K) return false;
	}
	return true;
}

void solve() {
	int top = vote[0].first;
	size_t begin = 0;
	while (vote[begin].first == top) {begin++;}
	if (begin + M > vote.size()) {
		cout << "0" << endl;
		return;
	}
	for (int A = 0; A < 100; ++A) {
		if (isAvailable(A, begin)) {
			cout << A << endl;
			return;
		}
	}
	cout << "100" << endl;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		input();
		solve();
	}
}

