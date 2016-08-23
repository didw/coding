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

bool goControl = true;

vector<string> room;

int cache[100][200];

int recControl(int r, int c) {
    if (room[r][c] == 'C') return 0;
    if (room[r][c] == '#') return 1e8;
    if (room[r][c] == '?') return 1e2;
    
    int &res = cache[r][c];
    if (res != -1) return res;
    res = 1e9;
    res = min(res, recControl(r-1, c) + 1);
    res = min(res, recControl(r+1, c) + 1);
    res = min(res, recControl(r, c-1) + 1);
    res = min(res, recControl(r, c+1) + 1);
    return res;
}

string findControl(int r, int c) {
    string direct[] = {"UP", "DOWN", "LEFT", "RIGHT"};
    int dist = 1e9;
    int cand = -1;
    if (dist > recControl(r-1, c)) {
        dist = recControl(r-1, c);
        cand = 0;
    }
    if (dist > recControl(r+1, c)) {
        dist = recControl(r+1, c);
        cand = 1;
    }
    if (dist > recControl(r, c-1)) {
        dist = recControl(r, c-1);
        cand = 2;
    }
    if (dist > recControl(r, c+1)) {
        dist = recControl(r, c+1);
        cand = 3;
    }
    fprintf(stderr, "%9d %9d %9d\n", 0, recControl(r-1, c), 0);
    fprintf(stderr, "%9d %9d %9d\n", recControl(r, c-1), recControl(r, c), recControl(r, c+1));
    fprintf(stderr, "%9d %9d %9d\n", 0, recControl(r+1, c), 0);
    return direct[cand];
}

int recBegin(int r, int c) {
    if (room[r][c] == 'T') return 0;
    if (room[r][c] == '#') return 1e8;
    if (room[r][c] == '?') return 1e2;
    
    int &res = cache[r][c];
    if (res != -1) return res;
    res = 1e9;
    res = min(res, recBegin(r-1, c) + 1);
    res = min(res, recBegin(r+1, c) + 1);
    res = min(res, recBegin(r, c-1) + 1);
    res = min(res, recBegin(r, c+1) + 1);
    return res;
}

string findBegin(int r, int c) {
    string direct[] = {"UP", "DOWN", "LEFT", "RIGHT"};
    int dist = 1e9;
    int cand = -1;
    if (dist > recBegin(r-1, c)) {
        dist = recBegin(r-1, c);
        cand = 0;
    }
    if (dist > recBegin(r+1, c)) {
        dist = recBegin(r+1, c);
        cand = 1;
    }
    if (dist > recBegin(r, c-1)) {
        dist = recBegin(r, c-1);
        cand = 2;
    }
    if (dist > recBegin(r, c+1)) {
        dist = recBegin(r, c+1);
        cand = 3;
    }
    return direct[cand];
}

int main()
{
    int R; // number of rows.
    int C; // number of columns.
    int A; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
    cin >> R >> C >> A; cin.ignore();
    room = vector<string>(R);

    // game loop
    while (1) {
        memset(cache, -1, sizeof(cache));
        
        int KR; // row where Kirk is located.
        int KC; // column where Kirk is located.
        cin >> KR >> KC; cin.ignore();
        for (int i = 0; i < R; i++) {
            cin >> room[i];
            cerr << room[i] << endl;
        }
        
        if (room[KR][KC] == 'C')
            goControl = false;
        
        string res;
        if (goControl) {
            res = findControl(KR, KC);
        }
        else {
            res = findBegin(KR, KC);
        }
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << res << endl; // Kirk's next move (UP DOWN LEFT or RIGHT).
    }
}