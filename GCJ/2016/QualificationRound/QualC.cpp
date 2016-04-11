//https://code.google.com/codejam/contest/6254486/dashboard#s=p2
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int N, J;
bool debug = false;

void input() {
	cin >> N >> J;
}

bool isPrime(long long num) {
	double a = sqrt(num);
	if (num%2 == 0) return false;
	for (int i = 3; i <= a; i += 2) {
		if (num%i == 0) return false;
	}
	return true;
}

long long conv(long long num, int base) {
	long long power = 1;
	long long res = 0;
	while (num) {
		res += ((num%2) * power);
		power *= base;
		num /= 2;
	}
	return res;
}

bool isJamcoin(long long num) {
	for (int i = 2; i <= 10; ++i) {
		if (isPrime(conv(num, i))) return false;
	}
	return true;
}

int getDiv(long long num) {
	if (num%2 == 0) return 2;

	for (int i = 3; i < num; i += 2) {
		if (num%i == 0) return i;
	}
	return 0;
}

void solve() {
	long long begin = (1 << (N-1)) + 1;
	int res = 0;
	for (long long num = begin; res < J; num += 2) {
		if (isJamcoin(num)) {
			cout << conv(num, 10) << " ";
			for (int i = 2; i <= 10; ++i) {
				cout << getDiv(conv(num, i));
				if (i != 10) cout << " ";
			}
			res++;
			cout << endl;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();
		cout << "Case #" << i << ":" << endl;
		solve();
	}
}

