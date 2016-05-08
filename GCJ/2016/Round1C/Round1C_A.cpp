#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, char> > num;
int total = 0;

void input() {
	total = 0;
	cin >> N;
	num = vector<pair<int, char> >(N);
	for (int i = 0; i < N; ++i) {
		cin >> num[i].first;
		total += num[i].first;
		num[i].first = -num[i].first;
		num[i].second = (char)(i + 'A');
	}
}

void solve() {
	sort(num.begin(), num.end());
	if (total % 2 == 1) {
		cout << " " << num[0].second;
		num[0].first++;
		total--;
	}

	for (int i = 0; i < total; i+=2) {
		sort(num.begin(), num.end());
		cout << " " << num[0].second << num[1].second;
		num[0].first++;
		num[1].first++;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();
		printf("Case #%d:", i);
		solve();
		cout << endl;
	}

}
