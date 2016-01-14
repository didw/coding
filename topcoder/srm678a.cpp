#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class ThePhantomMenace {
public:
    int find(vector <int>, vector <int>);
};

int ThePhantomMenace::find(vector <int> doors, vector <int> droids) {
    int best = 0;
    for (int i = 0; i < doors.size(); ++i) {
        int cand = 1000;
        for (int j = 0; j < droids.size(); ++j) {
            cand = min(cand, abs(doors[i] - droids[j]));
        }
        best = max(best, cand);
    }
    return best;
}

double test0() {
    int t0[] = { 1, 2, 3, 4 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = { 5, 6, 7, 8 };
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    ThePhantomMenace * obj = new ThePhantomMenace();
    clock_t start = clock();
    int my_answer = obj->find(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 4;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p2 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test1() {
    int t0[] = { 1 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = { 10 };
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    ThePhantomMenace * obj = new ThePhantomMenace();
    clock_t start = clock();
    int my_answer = obj->find(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 9;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p2 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test2() {
    int t0[] = { 2, 3, 5, 7, 11 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = { 1, 8, 13 };
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    ThePhantomMenace * obj = new ThePhantomMenace();
    clock_t start = clock();
    int my_answer = obj->find(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 3;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p2 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test3() {
    int t0[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    ThePhantomMenace * obj = new ThePhantomMenace();
    clock_t start = clock();
    int my_answer = obj->find(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 1;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p2 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test4() {
    int t0[] = { 2, 1 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = { 4, 3 };
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    ThePhantomMenace * obj = new ThePhantomMenace();
    clock_t start = clock();
    int my_answer = obj->find(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 2;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p2 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
int main() {
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout << "You're a stud (at least on the example cases)!" << endl;
    else
        cout << "Some of the test cases had errors." << endl;
}
