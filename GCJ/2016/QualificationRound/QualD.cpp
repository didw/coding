//https://code.google.com/codejam/contest/6254486/dashboard#s=p3
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int K, C, S;
bool debug = false;


void input() {
	cin >> K >> C >> S;
}

long long getGold(int k, int c, int begin, int end) {
	long long res = 0;
	for (int i = begin; i <= end; ++i) {
		res += (long long)pow(k, c-1) * (i);
		c--;
	}
	return res;
}

void solve() {
	if ((K-1)/C+1 > S) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	for (int i = 0; i < (K-1)/C+1; ++i) {
		int begin = C*i;
		int end = min(C*(i+1)-1, K-1);
		cout << getGold(K, C, begin, end) +1 << " ";
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

