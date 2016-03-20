#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> ball(n);
	map<int, int> mb;
	for (int i = 0; i < n; ++i) {
		cin >> ball[i];
		mb[ball[i]]++;
	}
	sort(ball.begin(), ball.end());
	for (int i = 0; i < n; ++i) {
		if (mb[ball[i]+1] > 0 && mb[ball[i]+2] > 0) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
