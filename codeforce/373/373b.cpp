// http://codeforces.com/contest/719/problem/B
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int conv_r(string str) {
	int i = 0;
	int res = 0;
	while (i < str.length()) {
		if (i%2 == 0) {
			if (i+1 < str.length() && str[i] == 'b' && str[i+1] == 'r') {
				res += 1;
				i += 2;
				continue;
			}
			if (str[i] == 'b') {
				res += 1;
				i += 1;
				continue;
			}
		}
		if (i%2 == 1) {
			if (i+1 < str.length() && str[i] == 'r' && str[i+1] == 'b') {
				res += 1;
				i += 2;
				continue;
			}
			if (str[i] == 'r') {
				res += 1;
				i += 1;
				continue;
			}
		}
	}
	return res;
}

int conv_b(string str) {
	int i = 0;
	int res = 0;
	while (i < str.length()) {
		if (i%2 == 0) {
			if (i+1 < str.length() && str[i] == 'r' && str[i+1] == 'b') {
				res += 1;
				i += 2;
				continue;
			}
			if (str[i] == 'r') {
				res += 1;
				i += 1;
				continue;
			}
		}
		if (i%2 == 1) {
			if (i+1 < str.length() && str[i] == 'b' && str[i+1] == 'r') {
				res += 1;
				i += 2;
				continue;
			}
			if (str[i] == 'b') {
				res += 1;
				i += 1;
				continue;
			}
		}
	}
	return res;
}

int main() {
	int n;
	string str;
	cin >> n;
	cin >> str;
	int res = conv_r(str);
	res = min(res, conv_b(str));
	cout << res << endl;
}