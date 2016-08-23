#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool goControl = true;

vector<string> room;

int cache[100][200];
int R; // number of rows.
int C; // number of columns.
int A; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.

void recControl() {
    queue<int> q;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (room[i][j] == 'C') {
                cache[i][j] = 0;
                q.push(i*C + j);
            }
            if (room[i][j] == '?') {
                cache[i][j] = 1000;
                q.push(i*C + j);
            }
        }
    }
    while (!q.empty()) {
        int there = q.front();
        q.pop();
        int tr, tc;
        tr = there/C;
        tc = there%C;
        if (tr+1 < R && cache[tr][tc] + 1 < cache[tr+1][tc] && room[tr+1][tc] != '#' && room[tr+1][tc] != '?') {
            q.push((tr+1)*C + tc);
            cache[tr+1][tc] = cache[tr][tc] + 1;
        }
        if (tr > 0 && cache[tr][tc] + 1 < cache[tr-1][tc] && room[tr-1][tc] != '#' && room[tr-1][tc] != '?') {
            q.push((tr-1)*C + tc);
            cache[tr-1][tc] = cache[tr][tc] + 1;
        }
        if (tc+1 < C && cache[tr][tc] + 1 < cache[tr][tc+1] && room[tr][tc+1] != '#' && room[tr][tc+1] != '?') {
            q.push(tr*C + tc+1);
            cache[tr][tc+1] = cache[tr][tc] + 1;
        }
        if (tc > 0 && cache[tr][tc] + 1 < cache[tr][tc-1] && room[tr][tc-1] != '#' && room[tr][tc-1] != '?') {
            q.push(tr*C + tc-1);
            cache[tr][tc-1] = cache[tr][tc] + 1;
        }
    }
}

void recControl2() {
    queue<int> q;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cache[i][j] = 1e9;
        }
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (room[i][j] == 'C') {
                cache[i][j] = 1e9;
                q.push(i*C + j);
            }
            if (room[i][j] == '?') {
                cache[i][j] = 1000;
                q.push(i*C + j);
            }
        }
    }
    while (!q.empty()) {
        int there = q.front();
        q.pop();
        int tr, tc;
        tr = there/C;
        tc = there%C;
        if (tr+1 < R && cache[tr][tc] + 1 < cache[tr+1][tc] && room[tr+1][tc] != '#' && room[tr+1][tc] != '?') {
            q.push((tr+1)*C + tc);
            cache[tr+1][tc] = cache[tr][tc] + 1;
        }
        if (tr > 0 && cache[tr][tc] + 1 < cache[tr-1][tc] && room[tr-1][tc] != '#' && room[tr-1][tc] != '?') {
            q.push((tr-1)*C + tc);
            cache[tr-1][tc] = cache[tr][tc] + 1;
        }
        if (tc+1 < C && cache[tr][tc] + 1 < cache[tr][tc+1] && room[tr][tc+1] != '#' && room[tr][tc+1] != '?') {
            q.push(tr*C + tc+1);
            cache[tr][tc+1] = cache[tr][tc] + 1;
        }
        if (tc > 0 && cache[tr][tc] + 1 < cache[tr][tc-1] && room[tr][tc-1] != '#' && room[tr][tc-1] != '?') {
            q.push(tr*C + tc-1);
            cache[tr][tc-1] = cache[tr][tc] + 1;
        }
    }
}

bool foundControl() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (room[i][j] == 'C')
                return true;
        }
    }
    return false;
}

bool notPath() {
    int tr = -1, tc = -1;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (room[i][j] == 'T') {
                tr = i;
                tc = j;
                break;
            }
        }
        if (tr != -1) break;
    }
    return cache[tr][tc] > A;
}

string findControl(int r, int c) {
    string direct[] = {"UP", "DOWN", "LEFT", "RIGHT"};
    recControl();
    if (foundControl() && notPath()) {
        recControl2();
    }
    int dist = 1e9;
    int cand = -1;
    if (dist > cache[r-1][c]) {
        dist = cache[r-1][c];
        cand = 0;
    }
    if (dist > cache[r+1][c]) {
        dist = cache[r+1][c];
        cand = 1;
    }
    if (dist > cache[r][c-1]) {
        dist = cache[r][c-1];
        cand = 2;
    }
    if (dist > cache[r][c+1]) {
        dist = cache[r][c+1];
        cand = 3;
    }
    fprintf(stderr, "%9d %9d %9d\n", 0, cache[r-1][c], 0);
    fprintf(stderr, "%9d %9d %9d\n", cache[r][c-1], cache[r][c], cache[r][c+1]);
    fprintf(stderr, "%9d %9d %9d\n", 0, cache[r+1][c], 0);
    return direct[cand];
}

void recBegin() {
    queue<int> q;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (room[i][j] == 'T') {
                cache[i][j] = 0;
                q.push(i*C + j);
            }
            if (room[i][j] == '?') {
                cache[i][j] = 1000;
                q.push(i*C + j);
            }
        }
    }
    while (!q.empty()) {
        int there = q.front();
        q.pop();
        int tr, tc;
        tr = there/C;
        tc = there%C;
        if (tr+1 < R && cache[tr][tc] + 1 < cache[tr+1][tc] && room[tr+1][tc] != '#' && room[tr+1][tc] != '?') {
            q.push((tr+1)*C + tc);
            cache[tr+1][tc] = cache[tr][tc] + 1;
        }
        if (tr > 0 && cache[tr][tc] + 1 < cache[tr-1][tc] && room[tr-1][tc] != '#' && room[tr-1][tc] != '?') {
            q.push((tr-1)*C + tc);
            cache[tr-1][tc] = cache[tr][tc] + 1;
        }
        if (tc+1 < C && cache[tr][tc] + 1 < cache[tr][tc+1] && room[tr][tc+1] != '#' && room[tr][tc+1] != '?') {
            q.push(tr*C + tc+1);
            cache[tr][tc+1] = cache[tr][tc] + 1;
        }
        if (tc > 0 && cache[tr][tc] + 1 < cache[tr][tc-1] && room[tr][tc-1] != '#' && room[tr][tc-1] != '?') {
            q.push(tr*C + tc-1);
            cache[tr][tc-1] = cache[tr][tc] + 1;
        }
    }
}

string findBegin(int r, int c) {
    string direct[] = {"UP", "DOWN", "LEFT", "RIGHT"};
    recBegin();
    int dist = 1e9;
    int cand = -1;
    if (dist > cache[r-1][c]) {
        dist = cache[r-1][c];
        cand = 0;
    }
    if (dist > cache[r+1][c]) {
        dist = cache[r+1][c];
        cand = 1;
    }
    if (dist > cache[r][c-1]) {
        dist = cache[r][c-1];
        cand = 2;
    }
    if (dist > cache[r][c+1]) {
        dist = cache[r][c+1];
        cand = 3;
    }
    fprintf(stderr, "go back\n");
    fprintf(stderr, "%9d %9d %9d\n", 0, cache[r-1][c], 0);
    fprintf(stderr, "%9d %9d %9d\n", cache[r][c-1], cache[r][c], cache[r][c+1]);
    fprintf(stderr, "%9d %9d %9d\n", 0, cache[r+1][c], 0);
    return direct[cand];
}

int main()
{
    cin >> R >> C >> A; cin.ignore();
    room = vector<string>(R);

    // game loop
    while (1) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cache[i][j] = 1e9;
            }
        }
        
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