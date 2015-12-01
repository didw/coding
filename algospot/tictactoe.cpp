#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[27*27*27];

bool isFinished(vector<string>& board, char turn) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
            return true;
        if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
            return true;
    }
    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
        return true;
    if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
        return true;
    return false;
}

int bijection(vector<string>& board) {
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            res *= 3;
            if (board[i][j] == 'o') res++;
            if (board[i][j] == 'x') res += 2;
        }
    }
    return res;
}

int canWin(vector<string>& board, char turn) {
    if (isFinished(board, 'o'+'x'-turn)) return -1;
    int& res = cache[bijection(board)];
    if (res != -2) return res;
    int minValue = 2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != '.') continue;
            board[i][j] = turn;
            minValue = min(minValue, canWin(board, 'o'+'x'-turn));
            board[i][j] = '.';
        }
    }
    if (minValue == 2 || minValue == 0) return res = 0;
    return res = -minValue;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        for (int i = 0; i < 27*27*27; ++i) {
            cache[i] = -2;
        }
        vector<string> board;
        char turn = 'x';
        for (int i = 0; i < 3; ++i) {
            string a;
            cin >> a;
            board.push_back(a);
            for (int j = 0; j < 3; ++j) {
                if (a[j] == 'o' || a[j] == 'x') turn = 'o' + 'x' - turn;
            }
        }
        int win = canWin(board, turn);
        if (win == 1)
            cout << (char)turn << endl;
        else if (win == -1)
            cout << (char)('o' + 'x' - turn) << endl;
        else
            cout << "TIE" << endl;
    }
}

