#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, w;
vector<pair<int, int>> walls;

map<int, int> subSide;
map<int, int> numSide;
map<int, int> numInside;
map<int, int> subInside;
map<int, int> numTop;
map<int, int> numBottom;
map<int, int> numAll;
map<int, int> subAll;
int minX = 0x7fffffff, maxX = 0x80000000;

bool isSide(int idx) {
    if ((minX <= walls[idx].second && walls[idx].second <= minX + w) ||
        (maxX - w <= walls[idx].second && walls[idx].second <= maxX))
        return true;
    return false;
}


void preCalc() {
    minX = 0x7fffffff; maxX = 0x80000000;

    for (int i = 0; i < n; ++i) {
        minX = min(minX, walls[i].second);
        maxX = max(maxX, walls[i].second);
    }
    int subside = 0;
    int subinside = 0;
    int idxtop = 0, idxbottom = 0, numtop = 0, numbottom = 0;
    for (int i = 0; i < n; ++i) {
        int numside = 0, numinside = 0;
        if (isSide(i)){
            numside++;
            subside++;
        }
        else {
            numinside++;
            subinside++;
            numtop++;
        }
        numSide[walls[i].first] += numside;
        subSide[walls[i].first] = subside;
        numInside[walls[i].first] += numinside;
        subInside[walls[i].first] = subinside;

        while (walls[idxtop].first < walls[i].first - w) {
            if (!isSide(idxtop)) numtop--;
            idxtop++;
        }
        while (idxbottom < n && walls[idxbottom].first <= walls[i].first + w) {
            if (!isSide(idxbottom)) numbottom++;
            idxbottom++;
        }

        numTop[walls[i].first] = numtop;
        numBottom[walls[i].first] = numbottom;


        subAll[walls[i].first] = i + 1;
        numAll[walls[i].first]++;
        if (!isSide(i)) numbottom--;
    }
}

int countAll(int bottom) {
    return n - subAll[bottom] + numAll[bottom];
}

int countInside(int bottom, int top) {
    int res = 0;
    return subInside[top] - subInside[bottom] + numInside[bottom];
}

int countWalls(int bottom, int bi, int top, int ti) {
    int res = 0;
    res += subSide[top] - subSide[bottom] + numSide[bottom];
    if (top > bottom + 2 * w) {
        res += numTop[top];
        res += numBottom[bottom];
    }
    else {
        res += countInside(bottom, top);
    }
    return res;
}

bool isAncientCity() {
    // 남쪽벽을 기준으로 순환
    int t1 = 1, t2 = 1;
    for (int b = 0; b < n; ++b) {
        // 가지치기
        if (countAll(walls[b].first) < n - k) break;
        int t = t1;
        int minTop = walls[b].first + w;
        // 북쪽 벽의 아랫면(t1)을 찾는다
        while (t < n && (walls[t].first <= minTop || isSide(t))) t++;
        // 북쪽벽이 모두 유실됐을 경우 가상의 벽으로 설정
        if (t >= n) t = n-1;
        t1 = t;
        // 북쪽 벽의 윗면(t2)을 찾는다
        int maxTop = walls[t].first + w;
        t = t2;
        while (t < n && walls[t].first <= maxTop) {
            t2 = t;
            t++;
        }
        //t = n - 1;
        //while (walls[t].first > maxTop) t--;
        if (countWalls(walls[b].first, b, walls[t2].first, t2) >= n - k)
            return true;
    }
    return false;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        numAll.clear();
        subAll.clear();
        numSide.clear();
        subSide.clear();
        numTop.clear();
        numBottom.clear();
        numInside.clear();
        subInside.clear();
        walls.clear();
        cin >> n >> k >> w;
        //cout << "size: " << n << ", except: " << k << ", wall: " << w << endl;
        walls = vector<pair<int, int>>(n);
        for (int i = 0; i < n; ++i) {
            cin >> walls[i].second >> walls[i].first;
        }
        sort(walls.begin(), walls.end());
        preCalc();
        //cout << "precalc end" << endl;
        if (isAncientCity())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
