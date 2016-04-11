//https://code.google.com/codejam/contest/6254486/dashboard#s=p1
#include <iostream>
#include <string>
using namespace std;

int N;
string S;
bool debug = false;

void input() {
	cin >> S;
}

bool finish() {
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '-') return false;
	}
	return true;
}

void solve() {
	int res = 0;
	while(!finish()) {
		int nFlip = 0;
		while (S[nFlip] == S[0]) {
			nFlip++;
		}
		string STemp;
		for (int i = 0; i < nFlip; ++i) {
			STemp.push_back('+' + '-' - S[nFlip - i - 1]);
		}
		for (int i = nFlip; i < S.size(); ++i) {
			STemp.push_back(S[i]);
		}
		S = STemp;
		res++;
	}
	cout << res << endl;
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
