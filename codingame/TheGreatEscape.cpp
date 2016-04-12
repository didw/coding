#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int x[3]; // x-coordinate of the player
int y[3]; // y-coordinate of the player
int wallsLeft[3]; // number of walls available for the player
int x_prev = 0;

vector<int> wallX(100); // x-coordinate of the wall
vector<int> wallY(100);
vector<int> wallO(100);

int cacheRight[10][10];
int cacheLeft[10][10];
int cacheDown[10][10];

int wallCount; // number of walls on the board
bool blockH = false;
bool debug = false;

bool isBlockedV(int cx, int cy) {
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 2 && wallX[i] == cx && (wallY[i] == cy || wallY[i] == cy-1))
            return true;
    }
    return false;
}

void blockTop(int id) {
    if (id == 1) {
        int cx = x[1], cy = y[1];
        while (isBlockedV(cx, cy)) {
            cy--;
        }
        if (cx == 8) cx--;
        cout << cx << " " << cy+1 << " H BLOCK TOP!" << endl;
    }
    else {
        int cx = x[0], cy = y[0];
        while (isBlockedV(cx+1, cy)) {
            cy--;
        }
        cout << cx << " " << cy+1 << " H BLOCK TOP!" << endl;
    }
}

void blockBottom(int id) {
    if (id == 1) {
        int cx = x[1], cy = y[1];
        while (isBlockedV(cx, cy)) {
            cy++;
        }
        if (cx == 8) cx--;
        cout << cx << " " << cy << " H BLOCK BOTTOM!" << endl;
    }
    else {
        int cx = x[0], cy = y[0];
        while (isBlockedV(cx+1, cy)) {
            cy++;
        }
        cout << cx << " " << cy << " H BLOCK BOTTOM!" << endl;
    }
}

bool blockLeft() {
    int cx = x[1], cy = y[1];
    if (cy > 0 && !isBlockedV(cx, cy) && !isBlockedV(cx, cy-1)) {
        cout << cx << " " << cy-1 << " V Block Left!" << endl;
        return true;
    }
    if (cy < 8 && !isBlockedV(cx, cy) && !isBlockedV(cx, cy+1)) {
        cout << cx << " " << cy << " V Block Left!" << endl;
        return true;
    }
    if (cy+1 < 8 && !isBlockedV(cx, cy+1) && !isBlockedV(cx, cy+2)) {
        cout << cx << " " << cy+1 << " V Block Left!" << endl;
        return true;
    }
    if (cy-1 > 0 && !isBlockedV(cx, cy-1) && !isBlockedV(cx, cy-2)) {
        cout << cx << " " << cy-2 << " V Block Left!" << endl;
        return true;
    }
    return false;
}

bool blockRight() {
    int cx = x[0]+1, cy = y[0];
    if (cy > 0 && !isBlockedV(cx, cy) && !isBlockedV(cx, cy-1)) {
        cout << cx << " " << cy-1 << " V Block Right!" << endl;
        return true;
    }
    if (cy < 8 && !isBlockedV(cx, cy) && !isBlockedV(cx, cy+1)) {
        cout << cx << " " << cy << " V Block Right!" << endl;
        return true;
    }
    if (cy+1 < 8 && !isBlockedV(cx, cy+1) && !isBlockedV(cx, cy+2)) {
        cout << cx << " " << cy+1 << " V Block Right!" << endl;
        return true;
    }
    if (cy-1 > 0 && !isBlockedV(cx, cy-1) && !isBlockedV(cx, cy-2)) {
        cout << cx << " " << cy-2 << " V Block Right!" << endl;
        return true;
    }
    return false;
}

bool canGoRight(int cx, int cy) {
    if (cx == 8) return false;
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 2 && cx+1 == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i])) {
            return false;
        }
    }
    return true;
}

bool canGoLeft(int cx, int cy) {
    if (cx == 0) return false;
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 2 && cx == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i])) {
            return false;
        }
    }
    return true;
}

bool canGoDown(int cx, int cy) {
    if (cy == 8) return false;
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 1 && cy+1 == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i])) {
            return false;
        }
    }
    return true;
}

bool canGoUp(int cx, int cy) {
    if (cy == 0) return false;
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 1 && cy == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i])) {
            return false;
        }
    }
    return true;
}

int goRightRec(int cx, int cy) {
    int &res = cacheRight[cx][cy];
    if (cx == 8) {
        res = 0;
        return 0;
    }
    if (res != -1) return res;
    res = 100;
    if (canGoRight(cx, cy)) res = min(res, goRightRec(cx+1, cy) + 1);
    if (canGoUp(cx, cy))    res = min(res, goRightRec(cx, cy-1) + 1);
    if (canGoDown(cx, cy))  res = min(res, goRightRec(cx, cy+1) + 1);
    if (canGoLeft(cx, cy))  res = min(res, goRightRec(cx-1, cy) + 1);
    return res;
}

int goLeftRec(int cx, int cy) {
    int &res = cacheLeft[cx][cy];
    if (cx == 0) {
        res = 0;
        return res;
    }
    if (res != -1) return res;
    res = 100;
    if (canGoLeft(cx, cy))  res = min(res, goLeftRec(cx-1, cy) + 1);
    if (canGoUp(cx, cy))    res = min(res, goLeftRec(cx, cy-1) + 1);
    if (canGoDown(cx, cy))  res = min(res, goLeftRec(cx, cy+1) + 1);
    if (canGoRight(cx, cy)) res = min(res, goLeftRec(cx+1, cy) + 1);
    return res;
}

int goDownRec(int cx, int cy) {
    int &res = cacheDown[cx][cy];
    if (cy == 8) {
        res = 0;
        return res;
    }
    if (res != -1) return res;
    res = 100;
    if (canGoDown(cx, cy))  res = min(res, goDownRec(cx, cy+1) + 1);
    if (canGoRight(cx, cy)) res = min(res, goDownRec(cx+1, cy) + 1);
    if (canGoLeft(cx, cy))  res = min(res, goDownRec(cx-1, cy) + 1);
    if (canGoUp(cx, cy))    res = min(res, goDownRec(cx, cy-1) + 1);
    return res;
}

bool blockPlayer(int myId) {
    if (myId == 0) {
        if (wallsLeft[0] == 0) return false;
        if (blockH && x[1] > 6) return false;
        if (x[1]%2 == 1 || x[1] > x_prev || (x[1] != 8 && x[1] > x[0])) return false;
        if (x[1] < 8 && goRightRec(x[0], y[0]) < goLeftRec(x[1], y[1])) return false;
        x_prev = min(x[1], x_prev);
        bool blockedV = isBlockedV(x[1], y[1]);
        if (blockedV) {
            int d, dist = 100;
            blockH = true;
            if (canGoUp(x[1], y[1]) && goLeftRec(x[1], y[1]-1) < dist) {
                d = 1;
                dist = goLeftRec(x[1], y[1]-1);
            }
            if (canGoDown(x[1], y[1]) && goLeftRec(x[1], y[1]+1) < dist) {
                d = 2;
                dist = goLeftRec(x[1], y[1]+1);
            }
            if (debug) {
                cerr << "2nd players position:" << x[1] << " " << y[1] << endl;
                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 9; ++j) {
                        cerr << cacheLeft[j][i];
                    }
                    cerr << endl;
                }
            }
            if (d == 1) {
                if (isBlockedV(x[1], 8)) {
                    blockLeft();
                    return true;
                }
                blockTop(1);
            }
            else {
                if (isBlockedV(x[1], 0)) {
                    blockLeft();
                    return true;
                }
                blockBottom(1);
            }
            x_prev = x[1] - 2;
        }
        else {
            if(!blockLeft()) return false;
        }
    }
    else {
        if (wallsLeft[1] == 0) return false;
        if (blockH && x[0] < 2) return false;
        if (x[0]%2 == 0 || x[0] < x_prev || (x[0] != 1 && x[1] > x[0])) return false;
        if (x[0] > 1 && goRightRec(x[0], y[0])-1 > goLeftRec(x[1], y[1])) return false;
        x_prev = max(x[0], x_prev);
        bool blockedV = isBlockedV(x[0]+1, y[0]);
        if (blockedV) {
            int d, dist = 100;
            blockH = true;
            if (canGoUp(x[0], y[0]) && goRightRec(x[0], y[0]-1) < dist) {
                d = 1;
                dist = goRightRec(x[0], y[0]-1);
            }
            if (canGoDown(x[0], y[0]) && goRightRec(x[0], y[0]+1) < dist) {
                d = 2;
                dist = goRightRec(x[0], y[0]+1);
            }
            if (debug) {
                cerr << "1st players position:" << x[0] << " " << y[0] << endl;
                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 9; ++j) {
                        cerr << cacheRight[j][i];
                    }
                    cerr << endl;
                }
            }
            if (d == 1) {
                if (isBlockedV(x[1]+1, 8)) {
                    blockRight();
                    return true;
                }
                blockTop(0);
            }
            else {
                if (isBlockedV(x[1]+1, 0)) {
                    blockRight();
                    return true;
                }
                blockBottom(0);
            }
            x_prev = x[0] + 2;
        }
        else {
            if (!blockRight()) return false;
        }
    }
    return true;
}

int main()
{
    int w; // width of the board
    int h; // height of the board
    int playerCount; // number of players (2 or 3)
    int myId; // id of my player (0 = 1st player, 1 = 2nd player, ...)
    cin >> w >> h >> playerCount >> myId; cin.ignore();

    if (myId == 0)
        x_prev = 8;
    else
        x_prev = 0;
    // game loop
    while (1) {
        for (int i = 0; i < playerCount; i++) {
            cin >> x[i] >> y[i] >> wallsLeft[i]; cin.ignore();
        }
        cin >> wallCount; cin.ignore();
        for (int i = 0; i < wallCount; i++) {
            string wallOrientation; // wall orientation ('H' or 'V')
            cin >> wallX[i] >> wallY[i] >> wallOrientation; cin.ignore();
            if (wallOrientation[0] == 'H')
                wallO[i] = 1;
            else
                wallO[i] = 2;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        memset(cacheRight, -1, sizeof(cacheRight));
        memset(cacheLeft, -1, sizeof(cacheLeft));
        memset(cacheDown, -1, sizeof(cacheDown));
        
        // blocking when number of player is two
        if (playerCount == 2) {
            if (blockPlayer(myId)) continue;
        }

        // find shortest path
        string direction[4] = {"LEFT GOGOGO!!", "RIGHT GOGOGO!!", "UP UPUP!", "DOWN GOING DOWN!!!"};
        if (myId == 0) {
            // can go right?
            int d = -1, dist = 100;
            if (canGoLeft(x[0], y[0]) && goRightRec(x[0]-1, y[0]) < dist) {
                dist = goRightRec(x[0]-1, y[0]);
                d = 0;
            }
            if (canGoRight(x[0], y[0]) && goRightRec(x[0]+1, y[0]) < dist) {
                dist = goRightRec(x[0]+1, y[0]);
                d = 1;
            }
            if (canGoUp(x[0], y[0]) && goRightRec(x[0], y[0]-1) < dist) {
                dist = goRightRec(x[0], y[0]-1);
                d = 2;
            }
            if (canGoDown(x[0], y[0]) && goRightRec(x[0], y[0]+1) < dist) {
                dist = goRightRec(x[0], y[0]+1);
                d = 3;
            }
            cout << direction[d] << endl;
        }
        else if (myId == 1) {
            // can go left?
            int d = -1, dist = 100;
            if (canGoLeft(x[1], y[1]) && goLeftRec(x[1]-1, y[1]) < dist) {
                dist = goLeftRec(x[1]-1, y[1]);
                d = 0;
            }
            if (canGoRight(x[1], y[1]) && goLeftRec(x[1]+1, y[1]) < dist) {
                dist = goLeftRec(x[1]+1, y[1]);
                d = 1;
            }
            if (canGoUp(x[1], y[1]) && goLeftRec(x[1], y[1]-1) < dist) {
                dist = goLeftRec(x[1], y[1]-1);
                d = 2;
            }
            if (canGoDown(x[1], y[1]) && goLeftRec(x[1], y[1]+1) < dist) {
                dist = goLeftRec(x[1], y[1]+1);
                d = 3;
            }
            cout << direction[d] << endl;
        }
        else {
            // can go Down?
            int d = -1, dist = 100;
            if (debug) {
                goDownRec(x[2], y[2]);
                cerr << "current position: " << x[2] << " " << y[2] << endl;
                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 9; ++j) {
                        cerr << cacheDown[j][i];
                    }
                    cerr << endl;
                }
            }
            if (canGoLeft(x[2], y[2]) && goDownRec(x[2]-1, y[2]) < dist) {
                dist = goDownRec(x[2]-1, y[2]);
                d = 0;
            }
            if (canGoRight(x[2], y[2]) && goDownRec(x[2]+1, y[2]) < dist) {
                dist = goDownRec(x[2]+1, y[2]);
                d = 1;
            }
            if (canGoUp(x[2], y[2]) && goDownRec(x[2], y[2]-1) < dist) {
                dist = goDownRec(x[2], y[2]-1);
                d = 2;
            }
            if (canGoDown(x[2], y[2]) && goDownRec(x[2], y[2]+1) < dist) {
                dist = goDownRec(x[2], y[2]+1);
                d = 3;
            }
            cout << direction[d] << endl;
        }
    }
}


