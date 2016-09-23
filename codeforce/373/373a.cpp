// http://codeforces.com/contest/719/problem/A
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> in(n);
	for (int i = 0; i < n; ++i) {
		cin >> in[i];
	}
	if (in[n-1] == 0) {
		cout << "UP" << endl;
	}
	else if (in[n-1] == 15) {
		cout << "DOWN" << endl;
	}
	else if (n == 1) {
		cout << "-1" << endl;
	}
	else if (in[n-1] > in[n-2]) {
		cout << "UP" << endl;
	}
	else if (in[n-1] < in[n-2]) {
		cout << "DOWN" << endl;
	}
}