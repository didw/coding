#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

int wallCount; // number of walls on the board

bool goRight(int myId) {
    bool canGo = true;
    for (int i = 0; i < wallCount; ++i) {
        if (x[myId] == 8) { canGo = false; break; }
        if (wallO[i] == 2 &&
            x[myId]+1 == wallX[i] && (y[myId] == wallY[i] || y[myId]-1 == wallY[i]))
            canGo = false;
    }
    if (canGo) {
        cout << "RIGHT GOGOGO!!" << endl; // action: LEFT, RIGHT, UP, DOWN or "putX putY putOrientation" to place a wall
        return true;
    }
    return false;
}

bool goLeft(int myId) {
    bool canGo = true;
    for (int i = 0; i < wallCount; ++i) {
        if (x[myId] == 0) { canGo = false; break; }
        if (wallO[i] == 2 &&
            x[myId] == wallX[i] && (y[myId] == wallY[i] || y[myId]-1 == wallY[i]))
            canGo = false;
    }
    if (canGo) {
        cout << "LEFT GOGOGO!!" << endl; // action: LEFT, RIGHT, UP, DOWN or "putX putY putOrientation" to place a wall
        return true;
    }
    return false;
}

bool goDown(int myId) {
    bool canGo = true;
    for (int i = 0; i < wallCount; ++i) {
        if (y[myId] == 8) { canGo = false; break; }
        if (wallO[i] == 1 &&
            y[myId]+1 == wallY[i] && (x[myId] == wallX[i] || x[myId]-1 == wallX[i]))
            canGo = false;
    }
    if (canGo) {
        cout << "DOWN GOGOGO!!" << endl; // action: LEFT, RIGHT, UP, DOWN or "putX putY putOrientation" to place a wall
        return true;
    }
    return false;
}

int distUP0() {
    int res = 0;
    int cx = x[0];
    int cy = y[0];
    cerr << "cx: " << cx << ", cy: " << cy << endl;
    while (1) {
        bool end = true;
        for (int i = 0; i < wallCount; ++i) {
            if (wallO[i] == 1 && cy == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i])) {
                cerr << "there is block to UP" << endl;
                return 100;
            }
            if (wallO[i] == 2 && cx+1 == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i])) {
                res++;
                end = false;
            }
        }
        if (end == true) return res;
        if (cy == 0) return 100;
        cy--;
    }
    return 100;
}

int distDOWN0() {
    int res = 0;
    int cx = x[0];
    int cy = y[0];
    while (1) {
        bool end = true;
        cerr << "cx: " << cx << ", cy: " << cy << ", res: " << res << endl;
        
        for (int i = 0; i < wallCount; ++i) {
            if (wallO[i] == 1 && cy+1 == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i])) {
                cerr << "there is block to DOWN" << endl;
                return 100;
            }
            if (wallO[i] == 2 && cx+1 == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i])) {
                res++;
                end = false;
            }
        }
        if (end == true) return res;
        if (cy == 8) return 100;
        cy++;
    }
    return 100;
}

int distUP1() {
    int res = 0;
    int cx = x[1];
    int cy = y[1];
    cerr << "cx: " << cx << ", cy: " << cy << endl;
    while (1) {
        bool end = true;
        for (int i = 0; i < wallCount; ++i) {
            if (wallO[i] == 1 && cy == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i])) {
                cerr << "there is block to UP" << endl;
                return 100;
            }
            if (wallO[i] == 2 && cx == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i])) {
                res++;
                end = false;
            }
        }
        if (end == true) return res;
        if (cy == 0) return 100;
        cy--;
    }
    return 100;
}

int distDOWN1() {
    int res = 0;
    int cx = x[1];
    int cy = y[1];
    while (1) {
        bool end = true;
        cerr << "cx: " << cx << ", cy: " << cy << ", res: " << res << endl;
        
        for (int i = 0; i < wallCount; ++i) {
            if (wallO[i] == 1 && cy+1 == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i])) {
                cerr << "there is block to DOWN" << endl;
                return 100;
            }
            if (wallO[i] == 2 && cx == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i])) {
                res++;
                end = false;
            }
        }
        if (end == true) return res;
        if (cy == 8) return 100;
        cy++;
    }
    return 100;
}

int distRIGHT() {
    int res = 0;
    int cx = x[2];
    int cy = y[2];
    while (1) {
        bool end = true;
        for (int i = 0; i < wallCount; ++i) {
            if (wallO[i] == 2 && cx+1 == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i])) {
                return 100;
            }
            if (wallO[i] == 1 && cy+1 == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i])) {
                res++;
                end = false;
            }
        }
        if (end == true) return res;
        if (cx == 8) return 100;
        cx++;
    }
    return 100;
}

int distLEFT() {
    int res = 0;
    int cx = x[2];
    int cy = y[2];
    while (1) {
        bool end = true;
        
        for (int i = 0; i < wallCount; ++i) {
            if (wallO[i] == 2 && cx == wallX[i] && (cy == wallY[i] || cy-1 == wallY[i])) {
                return 100;
            }
            if (wallO[i] == 1 && cy+1 == wallY[i] && (cx == wallX[i] || cx-1 == wallX[i])) {
                res++;
                end = false;
            }
        }
        if (end == true) return res;
        if (cx == 0) return 100;
        cx--;
    }
    return 100;
}

int main()
{
    int w; // width of the board
    int h; // height of the board
    int playerCount; // number of players (2 or 3)
    int myId; // id of my player (0 = 1st player, 1 = 2nd player, ...)
    cin >> w >> h >> playerCount >> myId; cin.ignore();
    int t = 0;

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
        t++;
        if (myId == 0) {
            // can go right?
            if (goRight(myId)) continue;        
            int distU = distUP0();
            int distD = distDOWN0();
            if (distU == 100 && distD == 100) {
                cout << "LEFT Where to go?" << endl;
                continue;
            }
            if (distU > distD)
                cout << "DOWN OMG!!" << endl;
            else
                cout << "UP SHIT!!" << endl;
        }
        else if (myId == 1) {
            // can go left?
            if (goLeft(myId)) continue;        
            int distU = distUP1();
            int distD = distDOWN1();
            if (distU == 100 && distD == 100) {
                cout << "RIGHT Where to go?" << endl;
                continue;
            }
            if (distU > distD)
                cout << "DOWN OMG!!" << endl;
            else
                cout << "UP SHIT!!" << endl;
        }
        else {
            // can go Down?
            if (goDown(myId)) continue;        
            int distR = distRIGHT();
            int distL = distLEFT();
            if (distR == 100 && distL == 100) {
                cout << "UP Where to go?" << endl;
                continue;
            }
            if (distR > distL)
                cout << "LEFT OMG!!" << endl;
            else
                cout << "RIGHT SHIT!!" << endl;
        }
        
    }
}
