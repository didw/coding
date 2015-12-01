#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;
int N;
int64 mx, my;
vector<int64> wx, wy;

int delta(int64 a, int64 b) {
	if (a < b) return 1;
	if (a > b) return -1;
	return 0;
}

int distFromMan(int64 x, int64 y) {
	return max(abs(mx - x), abs(my - y));
}

int64 solve() {
	int64 day = 0;
	int64 dx, dy;
	int64 cx = wx[0], cy = wy[0];
	for (int i = 1; i <= N; ++i) {
		dx = delta(wx[i - 1], wx[i]);
		dy = delta(wy[i - 1], wy[i]);
		while (cx != wx[i] || cy != wy[i]) {
			cx += dx;
			cy += dy;
			day++;
			if (distFromMan(cx, cy) <= day)
				return day+1;
		}
	}
	return -1;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> N;
		cin >> mx >> my;
		wx = wy = vector<int64>(N + 1, 0);
		int64 a, b;
		for (int i = 0; i < N; ++i)
			cin >> a >> b;
		for (int i = 0; i <= N; ++i)
			cin >> wx[i] >> wy[i];
		cout << solve() << endl;
	}
}