#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> board;

int solve() {
	int res = 0;
	for (int i = 0; i+1 < N; ++i) {
		if (board[0][i] == 1 && board[1][i] == 1) {
			board[0][i] = board[1][i] = 0;
			res++;
		}
		if (board[0][i] == 1) {
			if (board[1][i] == 1) {
				board[0][i] = board[1][i] = 0;
			}
			else {
				board[0][i] = 0;
				board[0][i + 1] = (board[0][i + 1] + 1) % 2;
			}
			res++;
		}
		if (board[1][i] == 1) {
			board[1][i] = 0;
			board[1][i + 1] = (board[1][i + 1] + 1) % 2;
			res++;
		}
	}
	if (board[0][N - 1] == 1 && board[1][N - 1] == 1) return res + 1;
	if (board[0][N - 1] == 1 || board[1][N - 1] == 1) return -1;
	return res;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> N >> M;
		board = vector<vector<int>>(2, vector<int>(N, 0));
		for (int i = 0; i < M; ++i) {
			int y, x;
			cin >> y >> x;
			board[y-1][x-1] = 1;
		}
		cout << solve() << endl;
	}
}