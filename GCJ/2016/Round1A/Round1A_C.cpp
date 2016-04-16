#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int BFF[1001];

void input() {
	cin >> N;
	//BFF = vector<int>(N);
	for (int i = 1; i <= N; ++i) {
		cin >> BFF[i];
	}
}

bool isCircle(vector<int>& stack, int here) {
	if (stack[0] == here) return true;
	return false;
}

bool isConnected(vector<int>& stack, int here) {
	for (unsigned int i = 0; i < stack.size(); ++i) {
		if (stack[i] == here) return true;
	}
	return false;
}

bool isLine(vector<int>& stack, int here) {
	if (stack.size() >= 2 && stack[stack.size()-2] == here) return true;
	return false;
}

int addLine(int here, vector<bool> &visited) {
	int res = 0;
	for (int i = 1; i <= N; ++i) {
		if (visited[i]) continue;
		if (BFF[i] == here)  {
			visited[i] = true;
			res = max(res, addLine(i, visited)+1);
			visited[i] = false;
		}
	}
	return res;
}

int getCircle(int here, vector<int>& stack, vector<bool> &visited) {
	if (isLine(stack, here)) return addLine(stack.back(), visited);
	if (isCircle(stack, here)) return 0;
	if (isConnected(stack, here)) return -1000;
	int res = 0;
	int next = BFF[here];
	stack.push_back(here);
	visited[here] = true;
	res = getCircle(next, stack, visited) + 1;
	visited[here] = false;
	stack.pop_back();
	return res;
}

void solve() {
	int res = 0;
	for (int i = 1; i <= N; ++i) {
		vector<int> stack;
		vector<bool> visited(N+1, false);
		stack.push_back(i);
		visited[i] = true;
		res = max(res, getCircle(BFF[i], stack, visited)+1);
		stack.pop_back();
		visited[i] = false;
	}
	for (int i = 1; i <= N; ++i) {
		vector<int> stack;
		stack.push_back(i);
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
	return 0;
}

