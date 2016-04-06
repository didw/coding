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

int main()
{
    int opponentCount; // Opponent count
    cin >> opponentCount; cin.ignore();
    srand((unsigned int)time(NULL));

    int arx[7] = {20, 5, 5, 29, 29, 15, 21};
    int ary[7] = {3, 3, 16, 16, 1, 18, 2};
    int arn = 0;
    int tx = 0, ty = 0, tx2 = -1, ty2 = -1;
    string line[20]; // One line of the map ('.' = free, '0' = you, otherwise the id of the opponent)
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
        if (arn < 8) {
            if (arn != 0 && (x != tx || y != ty)) {
                cout << tx << " " << ty << endl;
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
        if (line[ty][tx] == '.' && (tx != x || ty != y)) {
            cout << tx << " " << ty << endl;
            continue;
        }
        
        if (tx2 != -1) {
            tx = tx2; ty = ty2;
            tx2 = -1, ty2 = -1;
            if (line[ty][tx] != '.') {
                cout << tx << " " << ty << endl;
                continue;
            }
        }
        while (1) {
            tx = rand() % 35;
            ty = rand() % 20;
            if (line[ty][tx] == '.')
                break;
        }
        
        // Search best midpoint
        int by = min(ty, y), ey = max(ty, y);
        int maxEmptyCell = 0, cand = by;
        for (int i = by; i <= ey; ++i) {
            int emptyCell = 0;
            int bx = min(tx, x), ex = max(tx, x);
            for (int j = bx; j <= ex; ++j) {
                if (line[i][j] == '.') emptyCell++;
            }
            if (emptyCell > maxEmptyCell) {
                maxEmptyCell = emptyCell;
                cand = i;
            }
        }
        tx2 = tx; ty2 = ty;
        ty = cand;
        cout << tx << " " << ty << endl;
        // action: "x y" to move or "BACK rounds" to go back in time
    }
}

