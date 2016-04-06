#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstring>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

string line[20]; // One line of the map ('.' = free, '0' = you, otherwise the id of the opponent)
int cache[35][20];

double getRatio() {
    double res = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 35; ++j) {
            if (line[i][j] != '.') res += 1;
        }
    }
    res = 700 / (400 + res);
    if (res > 1.5) res = 1.5;
    if (res < 0.5) res = 0.5;
    return res;
}

double getScore(int cx, int cy, int tx, int ty) {
    int bx = min(cx, tx), ex = max(cx, tx);
    int by = min(cy, ty), ey = max(cy, ty);
    double res = 0;
    for (int i = by; i <= ey; ++i) {
        for (int j = bx; j <= ex; ++j) {
            if (line[i][j] == '.')
                res += 1;
        }
    }
    pow(res / ((ey-by+1)*(ex-bx+1)), getRatio());
}

int getMaxRoute(int cx, int cy, int tx, int ty) {
    if (cx == tx && cy == ty) return 0;
    int &res = cache[cx][cy];
    if (res != -1) return res;
    res = 0;
    int delta = 0;
    if (line[cy][cx] == '.') delta = 1;
    if (ty > cy) res = max(res, getMaxRoute(cx, cy+1, tx, ty) + delta);
    if (ty < cy) res = max(res, getMaxRoute(cx, cy-1, tx, ty) + delta);
    if (tx > cx) res = max(res, getMaxRoute(cx+1, cy, tx, ty) + delta);
    if (tx < cx) res = max(res, getMaxRoute(cx-1, cy, tx, ty) + delta);
    return res;
}

void goToTarget(int x, int y, int tx, int ty) {
    
    memset(cache, -1, sizeof(cache));

    // choose best route to get the target.
    if (ty == y || tx == x) {
        cout << tx << " " << ty << endl;
        return;
    }
    if (ty > y && tx > x) {
        if (getMaxRoute(x+1, y, tx, ty) < getMaxRoute(x, y+1, tx, ty))
            cout << x << " " << y+1 << endl;
        else
            cout << x+1 << " " << y << endl;
        return;
    }

    if (ty > y && tx < x) {
        if (getMaxRoute(x-1, y, tx, ty) < getMaxRoute(x, y+1, tx, ty))
            cout << x << " " << y+1 << endl;
        else
            cout << x-1 << " " << y << endl;
        return;
    }

    if (ty < y && tx < x) {
        if (getMaxRoute(x-1, y, tx, ty) < getMaxRoute(x, y-1, tx, ty))
            cout << x << " " << y-1 << endl;
        else
            cout << x-1 << " " << y << endl;
        return;
    }

    if (ty < y && tx > x) {
        if (getMaxRoute(x+1, y, tx, ty) < getMaxRoute(x, y-1, tx, ty))
            cout << x << " " << y-1 << endl;
        else
            cout << x+1 << " " << y << endl;
        return;
    }
    
    cout << tx << " " << ty << endl;
}

int main()
{
    int opponentCount; // Opponent count
    cin >> opponentCount; cin.ignore();
    srand((unsigned int)time(NULL));

    int arx[7] = {20, 5,  3, 28, 30, 15, 21};
    int ary[7] = { 5, 3, 16, 15,  2, 18,  1};
    int arn = 0;
    int tx = 0, ty = 0;
    // game loop
    while (1) {
        int gameRound;
        cin >> gameRound; cin.ignore();
        int x; // Your x position
        int y; // Your y position
        int backInTimeLeft; // Remaining back in time
        cin >> x >> y >> backInTimeLeft; cin.ignore();
        for (int i = 0; i < opponentCount; i++) {
            int opponentX; // X position of the opponent
            int opponentY; // Y position of the opponent
            int opponentBackInTimeLeft; // Remaining back in time of the opponent
            cin >> opponentX >> opponentY >> opponentBackInTimeLeft; cin.ignore();
        }
        for (int i = 0; i < 20; i++) {
            cin >> line[i]; cin.ignore();
        }
        if (arn < 0) {
            if (arn != 0 && (x != tx || y != ty)) {
                goToTarget(x, y, tx, ty);
                continue;
            }
            if (arn == 7) {
                cout << tx << " " << ty << endl;
                arn++;
                continue;
            }
            tx = arx[arn];
            ty = ary[arn];
            
            cout << tx << " " << ty << endl;
            arn++;
            continue;
        }

        // find new target point
        cerr << "tx: " << tx << ", ty: " << ty << endl;
        if (line[ty][tx] != '.' || (tx == x && ty == y)) {
            vector<pair<int, int>> cand;
            for (int i = 0; i < 200; ++i) {
                tx = rand() % 35;
                ty = rand() % 20;
                if (line[ty][tx] == '.') {
                    cand.push_back(make_pair(tx, ty));
                }
                int maxScore = 0;
                if (cand.size() == 10) {
                    for (int j = 0; j < cand.size(); ++j) {
                        if (maxScore < getScore(x, y, cand[j].first, cand[j].second)) {
                            maxScore = getScore(x, y, cand[j].first, cand[j].second);
                            tx = cand[j].first; ty = cand[j].second;
                        }
                    }
                    break;
                }
            }
            if (cand.size() < 10) {
                int maxScore = 0;
                for (int j = 0; j < cand.size(); ++j) {
                    if (maxScore < getScore(x, y, cand[j].first, cand[j].second)) {
                        maxScore = getScore(x, y, cand[j].first, cand[j].second);
                        tx = cand[j].first; ty = cand[j].second;
                    }
                }
            }
        }
        
        memset(cache, -1, sizeof(cache));

        // choose best route to get the target.
        goToTarget(x, y, tx, ty);
        
        // action: "x y" to move or "BACK rounds" to go back in time
    }
}

