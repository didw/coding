#include <iostream>
using namespace std;

string S;

void input() {
	cin >> S;
}

void solve() {
	string res(1, S[0]);
	for (int i = 1; i < S.size(); ++i) {
		if (res[0] <= S[i]) {
			res = S[i] + res;
		}
		else {
			res = res + S[i];
		}
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
