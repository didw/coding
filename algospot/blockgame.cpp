#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

char cache[1<<25];
vector<int> words;

inline int cell(int y, int x) { return 1 << (5 * y + x); }

void precalc() {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            vector<int> cells;
            for (int dy = 0; dy < 2; ++dy) {
                for (int dx = 0; dx < 2; ++dx) {
                    cells.push_back(cell(y + dy, x + dx));
                }
            }
            int square = cells[0] + cells[1] + cells[2] + cells[3];
            for (int i = 0; i < cells.size(); ++i)
                words.push_back(square - cells[i]);
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            words.push_back(cell(i, j) + cell(i, j+1));
            words.push_back(cell(j, i) + cell(j+1, i));
        }
    }
}

char play(int board) {
    char& res = cache[board];
    if (res != -1) return res;
    res = 0;
    for (int i = 0; i < words.size(); ++i) {
        if (board & words[i]) continue;
        if (play(board + words[i]) == 0)
            return res = 1;
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    precalc();
    while (c--) {
        int board = 0;
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < 5; ++i) {
            string a;
            cin >> a;
            for (int j = 0; j < a.size(); ++j) {
                if (a[j] == '#')
                    board += 1<<(5*i + j);
            }
        }
        if (play(board))
            cout<<"WINNING"<<endl;
        else
            cout<<"LOSING"<<endl;
    }
}
