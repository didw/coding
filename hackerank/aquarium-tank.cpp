#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

struct point {
    int x, y;
};

int n;
double liter, breadth;
vector<point> leftSide, rightSide;

int getMaxY(vector<point> p) {
    int res = 0;
    for (int i = 0; i < p.size(); ++i) {
        res = max(res, p[i].y);
    }
    return res;
}

int getZeroIdx(vector<point> p) {
    if (p[0].y == 0 && p[p.size() - 1].y == 0) return p.size() - 1;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i].y == 0) return i;
    }
    return 0;
}

void input() {
    cin >> breadth >> liter;
    liter = liter * 1000 / breadth;
    vector<point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    int maxY = getMaxY(p);
    int idxR = getZeroIdx(p) + 1;
    int idxL = getZeroIdx(p);
    while (1) {
        if (idxR == n) idxR = 0;
        rightSide.push_back(p[idxR]);
        if (p[idxR].y == maxY) {
            break;
        }
        idxR++;
    }
    while (1) {
        if (idxL < 0) idxL = n - 1;
        leftSide.push_back(p[idxL]);
        if (p[idxL].y == maxY) {
            break;
        }
        idxL--;
    }
}

double getVolume(int l, int r) {
    double y0 = max(leftSide[l-1].y, rightSide[r-1].y);
    double y1 = min(leftSide[l].y, rightSide[r].y);
    double leftA = (double)(leftSide[l].x - leftSide[l - 1].x) / (leftSide[l].y - leftSide[l - 1].y);
    double leftB = leftSide[l].x - leftA*leftSide[l].y;
    double rightA = (double)(rightSide[r].x - rightSide[r - 1].x) / (rightSide[r].y - rightSide[r - 1].y);
    double rightB = rightSide[r].x - rightA*rightSide[r].y;
    double A = rightA - leftA;
    double B = rightB - leftB;
    double x0 = A*y0 + B;
    double x1 = A*y1 + B;
    return (x0 + x1) * (y1 - y0) / 2.0;
}

double polyEq(double a, double b, double c) {
    return (-b + sqrt(b*b - 4*a*c)) / (2 * a);
}

double getHeight(int l, int r, double v) {
    double y0 = max(leftSide[l - 1].y, rightSide[r - 1].y);
    double leftA, rightA;
    if (leftSide[l].y == leftSide[l - 1].y)
        leftA = 1e9;
    else
        leftA = (double)(leftSide[l].x - leftSide[l - 1].x) / (leftSide[l].y - leftSide[l - 1].y);
    if (rightSide[r].y == rightSide[r - 1].y)
        rightA = 1e9;
    else
        rightA = (double)(rightSide[r].x - rightSide[r - 1].x) / (rightSide[r].y - rightSide[r - 1].y);
    double leftB = leftSide[l].x - leftA*leftSide[l].y;
    double rightB = rightSide[r].x - rightA*rightSide[r].y;
    double A = rightA - leftA;
    double B = rightB - leftB;
    double x0 = A*y0 + B;
    if (A == 0)
        return y0 + v / x0;
    return polyEq(A, x0 + B - y0*A, -y0*(B + x0) - 2 * v);
}

double solve() {
    int idxL = 1, idxR = 1;
    int maxY = getMaxY(leftSide);
    if (breadth == 0) return maxY;
    while (liter > 0) {
        double vol = getVolume(idxL, idxR);
        if (vol > liter) {
            return getHeight(idxL, idxR, liter);
        }
        else {
            liter -= vol;
            if (leftSide[idxL].y == rightSide[idxR].y) {
                idxL++; idxR++;
            }
            else if (leftSide[idxL].y > rightSide[idxR].y)
                idxR++;
            else
                idxL++;
            if (idxR == rightSide.size() && idxL == leftSide.size()) return maxY;
        }
    }
    return 0;
}

int main() {
    int c = 1;
    while (scanf("%d", &n) && !feof(stdin)) {
        input();
        printf("Case %d: %.4f\n", c++, solve());
        leftSide.clear(); rightSide.clear();
    }
}