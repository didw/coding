#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int cache[2001][2001];

int maxEnergy(vector<pair<bool, int> >& snake, int b, int e) {
	if (b >= e) return 0;
	int &res = cache[b][e];
	if (res != -1) return res;
	res = 0;
	//res = maxEnergy(snake, b+1, e);
	for (int i = b+1; i <= e; ++i) {
		int score = snake[b].second * snake[i].second;
		if (snake[b].first == snake[i].first)
			continue;
		res = max(res, maxEnergy(snake, b+1, i-1) + maxEnergy(snake, i+1, e) + score);
	}
	//printf("%d %d = %d\n", b, e, res);
	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		memset(cache, -1, sizeof(cache));
		vector<pair<bool, int> > snake(N+1);
		for (int i = 0; i < N; ++i) {
			cin >> snake[i].second;
		}
		for (int i = 0; i < N; ++i) {
			cin >> snake[i].first;
		}
		cout << maxEnergy(snake, 0, N-1) << endl;
	}
}
