#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int boardH, boardW;
vector<string> board;
vector<vector<pair<int, int>>> rotations;

vector<string> rotate(const vector<string>& arr) {
    vector<string> rot(arr[0].size(), string(arr.size(), ' '));
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[0].size(); ++j) {
            rot[j][arr.size() - 1 - i] = arr[i][j];
        }
    }
    return rot;
}

int blockSize;
void generateRotations(vector<string> block) {
    rotations.clear();
    rotations.resize(4);
    for (int i = 0; i < 4; ++i) {
        int origX = -1, origY = -1;
        for (int y = 0; y < block.size(); ++y) {
            for (int x = 0; x < block[0].size(); ++x) {
                if (block[y][x] == '#') {
                    if (origY == -1) {
                        origY = y;
                        origX = x;
                    }
                    rotations[i].push_back(make_pair(y - origY, x - origX));
                }
            }
        }
        block = rotate(block);
    }
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
    blockSize = rotations[0].size();
}

int covered[11][11];

bool set(int y, int x, const vector<pair<int, int>>& block, int delta) {
    bool ret = true;
    for (int i = 0; i < block.size(); ++i) {
        if (y + block[i].first >= 0 && y + block[i].first < boardH &&
            x + block[i].second >= 0 && x + block[i].second < boardW) {
            covered[y + block[i].first][x + block[i].second] += delta;
            ret = ret && (covered[y + block[i].first][x + block[i].second] == 1);
        }
        else
            ret = false;
    }
    return ret;
}

int best;

bool pruning(int blocked) {
    int cnt = 0;
    for (int i = 0; i < boardH; ++i) {
        for (int j = 0; j < boardW; ++j) {
            cnt += (covered[i][j] == 0 ? 1 : 0);
        }
    }
    return (cnt / blockSize + blocked <= best);
}

void search(int blocked) {
    if (pruning(blocked))
        return;
    int y = -1, x = -1;
    for (int i = 0; i < boardH; ++i) {
        for (int j = 0; j < boardW; ++j) {
            if (covered[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1)
            break;
    }
    if (y == -1) {
        best = max(best, blocked);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (set(y, x, rotations[i], 1))
            search(blocked + 1);
        set(y, x, rotations[i], -1);
    }
    covered[y][x] = 1;
    search(blocked);
    covered[y][x] = 0;
}

int solve(vector<string>& block) {
    best = 0;
    for (int i = 0; i < boardH; ++i) {
        for (int j = 0; j < boardW; ++j) {
            covered[i][j] = (board[i][j] == '#' ? 1 : 0);
        }
    }
    generateRotations(block);
    search(0);
    return best;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int h, w;
        vector<string> block;
        cin >> boardH >> boardW >> h >> w;
        board.clear();
        for (int i = 0; i < boardH; ++i) {
            string a;
            cin >> a;
            board.push_back(a);
        }
        for (int i = 0; i < h; ++i) {
            string a;
            cin >> a;
            block.push_back(a);
        }
        cout << solve(block) << endl;
    }
}
