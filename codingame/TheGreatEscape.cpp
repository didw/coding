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

vector<int> wallX(100); // x-coordinate of the wall
vector<int> wallY(100);
vector<int> wallO(100);

int cacheRight[9][9];
int cacheLeft[9][9];
int cacheDown[9][9];

int wallCount; // number of walls on the board
bool blockH = false;

bool isBlockedH(int cx, int cy) {
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 2 && wallX[i] == cx && (wallY[i] == cy || wallY[i] == cy-1))
            return true;
    }
    return false;
}

void blockTop(int id) {
    if (id == 1) {
        int cx = x[1], cy = y[1];
        while (isBlockedH(cx, cy)) {
            cy--;
        }
        if (cx == 8) cx--;
        cout << cx << " " << cy+1 << " H BLOCK TOP!" << endl;
    }
    else {
        int cx = x[0], cy = y[0];
        while (isBlockedH(cx+1, cy)) {
            cy--;
        }
        cout << cx << " " << cy+1 << " H BLOCK TOP!" << endl;
    }
}

void blockBottom(int id) {
    if (id == 1) {
        int cx = x[1], cy = y[1];
        while (isBlockedH(cx, cy)) {
            cy++;
        }
        if (cx == 8) cx--;
        cout << cx << " " << cy+1 << " H BLOCK BOTTOM!" << endl;
    }
    else {
        int cx = x[0], cy = y[0];
        while (isBlockedH(cx+1, cy)) {
            cy++;
        }
        cout << cx << " " << cy+1 << " H BLOCK BOTTOM!" << endl;
    }
}

bool blockLeft() {
    int cx = x[1], cy = y[1];
    if (cy > 0 && !isBlockedH(cx, cy) && !isBlockedH(cx, cy-1)) {
        cout << cx << " " << cy-1 << " V Block Left!" << endl;
        return true;
    }
    if (cy < 8 && !isBlockedH(cx, cy) && !isBlockedH(cx, cy+1)) {
        cout << cx << " " << cy << " V Block Left!" << endl;
        return true;
    }
    return false;
}

bool blockRight() {
    int cx = x[0]+1, cy = y[0];
    if (cy > 0 && !isBlockedH(cx, cy) && !isBlockedH(cx, cy-1)) {
        cout << cx << " " << cy-1 << " V Block Right!" << endl;
        return true;
    }
    if (cy < 8 && !isBlockedH(cx, cy) && !isBlockedH(cx, cy+1)) {
        cout << cx << " " << cy << " V Block Right!" << endl;
        return true;
    }
    return false;
}

bool canGoRight(int cx, int cy) {
    if (cx == 8) return false;
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 2 && cx+1 == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i]))
            return false;
    }
    return true;
}

bool canGoLeft(int cx, int cy) {
    if (cx == 0) return false;
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 2 && cx == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i]))
            return false;
    }
    return true;
}

bool canGoDown(int cx, int cy) {
    if (cy == 8) return false;
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 1 && cy+1 == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i]))
            return false;
    }
    return true;
}

bool canGoUp(int cx, int cy) {
    if (cy == 0) return false;
    for (int i = 0; i < wallCount; ++i) {
        if (wallO[i] == 1 && cy == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i]))
            return false;
    }
    return true;
}

int goRightRec(int cx, int cy) {
    if (cx == 8) return 0;
    int &res = cacheRight[cx][cy];
    if (res != -1) return res;
    res = 100;
    if (canGoRight(cx, cy)) res = min(res, goRightRec(cx+1, cy) + 1);
    if (canGoUp(cx, cy)) res = min(res, goRightRec(cx, cy-1) + 1);
    if (canGoDown(cx, cy)) res = min(res, goRightRec(cx, cy+1) + 1);
    if (canGoLeft(cx, cy)) res = min(res, goRightRec(cx-1, cy) + 1);
    return res;
}

int goLeftRec(int cx, int cy) {
    if (cx == 0) return 0;
    int &res = cacheLeft[cx][cy];
    if (res != -1) return res;
    res = 100;
    if (canGoRight(cx, cy)) res = min(res, goLeftRec(cx+1, cy) + 1);
    if (canGoUp(cx, cy)) res = min(res, goLeftRec(cx, cy-1) + 1);
    if (canGoDown(cx, cy)) res = min(res, goLeftRec(cx, cy+1) + 1);
    if (canGoLeft(cx, cy)) res = min(res, goLeftRec(cx-1, cy) + 1);
    return res;
}

int goDownRec(int cx, int cy) {
    if (cy == 8) return 0;
    int &res = cacheDown[cx][cy];
    if (res != -1) return res;
    res = 100;
    if (canGoRight(cx, cy)) res = min(res, goDownRec(cx+1, cy) + 1);
    if (canGoUp(cx, cy)) res = min(res, goDownRec(cx, cy-1) + 1);
    if (canGoDown(cx, cy)) res = min(res, goDownRec(cx, cy+1) + 1);
    if (canGoLeft(cx, cy)) res = min(res, goDownRec(cx-1, cy) + 1);
    return res;
}

bool blockPlayer(int myId) {
    if (blockH) return false;
    if (myId == 0) {
        bool blockedV = isBlockedH(x[1], y[1]);
        if (blockedV) {
            int d, dist = 100;
            if (canGoUp(x[1], y[1]) && goLeftRec(x[1], y[1]-1) < dist) {
                d = 1;
                dist = goLeftRec(x[1], y[1]-1);
            }
            if (canGoDown(x[1], y[1]) && goLeftRec(x[1], y[1]+1) < dist) {
                d = 2;
                dist = goLeftRec(x[1], y[1]+1);
            }
            if (d == 1) {
                blockTop(1);
            }
            else {
                blockBottom(1);
            }
            blockH = true;
        }
        else {
            if(!blockLeft()) return false;
        }
    }
    else {
        bool blockedV = isBlockedH(x[0]+1, y[0]);
        if (blockedV) {
            int d, dist = 100;
            if (canGoUp(x[1], y[1]) && goRightRec(x[1], y[1]-1) < dist) {
                d = 1;
                dist = goLeftRec(x[1], y[1]-1);
            }
            if (canGoDown(x[1], y[1]) && goRightRec(x[1], y[1]+1) < dist) {
                d = 2;
                dist = goLeftRec(x[1], y[1]+1);
            }
            if (d == 1) {
                blockTop(0);
            }
            else {
                blockBottom(0);
            }
            blockH = true;
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

        // blocking when number of player is two
        if (playerCount == 2) {
            if (blockPlayer(myId)) continue;
        }

        // find shortest path
        memset(cacheRight, -1, sizeof(cacheRight));
        memset(cacheLeft, -1, sizeof(cacheLeft));
        memset(cacheDown, -1, sizeof(cacheDown));
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
            if (canGoLeft(x[0], y[0]) && goLeftRec(x[0]-1, y[0]) < dist) {
                dist = goLeftRec(x[0]-1, y[0]);
                d = 0;
            }
            if (canGoRight(x[0], y[0]) && goLeftRec(x[0]+1, y[0]) < dist) {
                dist = goLeftRec(x[0]+1, y[0]);
                d = 1;
            }
            if (canGoUp(x[0], y[0]) && goLeftRec(x[0], y[0]-1) < dist) {
                dist = goLeftRec(x[0], y[0]-1);
                d = 2;
            }
            if (canGoDown(x[0], y[0]) && goLeftRec(x[0], y[0]+1) < dist) {
                dist = goLeftRec(x[0], y[0]+1);
                d = 3;
            }
            cout << direction[d] << endl;
        }
        else {
            // can go Down?
            int d = -1, dist = 100;
            if (canGoLeft(x[0], y[0]) && goDownRec(x[0]-1, y[0]) < dist) {
                dist = goDownRec(x[0]-1, y[0]);
                d = 0;
            }
            if (canGoRight(x[0], y[0]) && goDownRec(x[0]+1, y[0]) < dist) {
                dist = goDownRec(x[0]+1, y[0]);
                d = 1;
            }
            if (canGoUp(x[0], y[0]) && goDownRec(x[0], y[0]-1) < dist) {
                dist = goDownRec(x[0], y[0]-1);
                d = 2;
            }
            if (canGoDown(x[0], y[0]) && goDownRec(x[0], y[0]+1) < dist) {
                dist = goDownRec(x[0], y[0]+1);
                d = 3;
            }
            cout << direction[d] << endl;
        }
    }
}

