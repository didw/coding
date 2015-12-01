#include <iostream>

using namespace std;


class Student {
    int score[5];
public:
    void Input() {
        for (int i = 0; i < 5; ++i)
            cin >> score[i];
    }
    int CalculateTotalScore() {
        int res = 0;
        for (int i = 0; i < 5; ++i)
            res += score[i];
        return res;
    }
};