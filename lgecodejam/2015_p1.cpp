#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
string num[10000];
int n;

bool isLeft(char a, char b) {
    return ((a == '2' && b == '1') || (a == '3' && b == '2') ||
        (a == '5' && b == '4') || (a == '6' && b == '5') ||
        (a == '8' && b == '7') || (a == '9' && b == '8'));
}
bool isRight(char a, char b) {
    return ((a == '1' && b == '2') || (a == '2' && b == '3') ||
        (a == '4' && b == '5') || (a == '5' && b == '6') ||
        (a == '7' && b == '8') || (a == '8' && b == '9'));
}
bool isUp(char a, char b) {
    return ((a == '4' && b == '1') || (a == '5' && b == '2') ||
        (a == '6' && b == '3') || (a == '7' && b == '4') ||
        (a == '8' && b == '5') || (a == '9' && b == '6') || (a == '0' && b == '8'));
}

bool isDown(char a, char b) {
    return ((a == '1' && b == '4') || (a == '2' && b == '5') ||
        (a == '3' && b == '6') || (a == '4' && b == '7') ||
        (a == '5' && b == '8') || (a == '6' && b == '9') || (a == '8' && b == '0'));
}

bool isCross1(char a, char b) {
    return ((a == '0' && b == '9') || (a == '4' && b == '2') ||
        (a == '5' && b == '3') || (a == '7' && b == '5') ||
        (a == '8' && b == '6'));
}

bool isCross2(int a, int b) {
    return ((a == '5' && b == '1') || (a == '6' && b == '2') ||
        (a == '8' && b == '4') || (a == '9' && b == '5') ||
        (a == '0' && b == '7'));
}

bool isCross3(char a, char b) {
    return ((a == '2' && b == '4') || (a == '3' && b == '5') ||
        (a == '5' && b == '7') || (a == '6' && b == '8') ||
        (a == '9' && b == '0'));
}

bool isCross4(char a, char b) {
    return ((a == '1' && b == '5') || (a == '2' && b == '6') ||
        (a == '4' && b == '8') || (a == '5' && b == '9') ||
        (a == '7' && b == '0'));
}

int howEasy(string n) {
    int d = -1; // 0: not move, 1: left, 2: right, 3: up, 4: down, 5~8: cross1~4
    int score = 0;
    int add = 0;
    for (int i = 1; i < n.size(); ++i) {
        if (i == 1) add = 0;
        else add = 1;
        if (n[i - 1] == n[i]) {
            score += 0;
            d = 0;
        }
        else if (isLeft(n[i - 1], n[i])) {
            if (d == 1) {
                score += 1;
            }
            else {
                score += 1 + add;
                d = 1;
            }
        }
        else if (isRight(n[i - 1], n[i])) {
            if (d == 2) {
                score += 1;
            }
            else {
                score += 1 + add;
                d = 2;
            }
        }
        else if (isUp(n[i - 1], n[i])) {
            if (d == 3) {
                score += 1;
            }
            else {
                score += 1 + add;
                d = 3;
            }
        }
        else if (isDown(n[i - 1], n[i])) {
            if (d == 4) {
                score += 1;
            }
            else {
                score += 1 + add;
                d = 4;
            }
        }
        else if (isCross1(n[i - 1], n[i])) {
            if (d == 5) {
                score += 1;
            }
            else {
                score += 1 + add;
                d = 5;
            }
        }
        else if (isCross2(n[i - 1], n[i])) {
            if (d == 6) {
                score += 1;
            }
            else {
                score += 1 + add;
                d = 6;
            }
        }
        else if (isCross3(n[i - 1], n[i])) {
            if (d == 7) {
                score += 1;
            }
            else {
                score += 1 + add;
                d = 7;
            }
        }
        else if (isCross4(n[i - 1], n[i])) {
            if (d == 8) {
                score += 1;
            }
            else {
                score += 1 + add;
                d = 8;
            }
        }
        else {
            score += 2 + add;
            d = -1;
        }
    }
    return score;
}

string solve() {
    int minValue = 1e5;
    string res;
    for (int i = 0; i < n; ++i) {
        int cand = howEasy(num[i]);
        if (minValue > cand) {
            minValue = cand;
            res = num[i];
        }
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        cout << solve() << endl;
    }
}
