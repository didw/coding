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

/*
in a galaxy far far away... each week has N days. 
Obi-Wan has exactly N shirts. 
The shirts are numbered 1 through N. 
Each day he wears one of those N shirts. 
Each week he wears each shirt exactly once.  
In different weeks Obi-Wan may wear his shirts in different orders. 
However, not all orders are always possible. 
Whenever Obi-Wan wears a shirt for a day, he has to wash it before he can use it again. 
Washing and drying a shirt takes N-2 full days. 
In other words, if he wears a shirt on day x, the earliest day when he can wear it again is day x+N-1.  
The Jedi council recently sent Obi-Wan on a mission that lasted for some unknown number of full N-day weeks. 
He remembers the order in which he wore his shirts during the first week of the mission. 
He also remembers the order in which he wore his shirts during the last week of the mission. 
You are given this information in vector <int>s firstWeek and lastWeek. 
Each of these vector <int>s contains N elements: the numbers of shirts he wore during that week, 
in order.  For example, assume that N = 4, firstWeek = {1,2,3,4}, and lastWeek = {4,3,2,1}. 
It is possible that this particular mission took four weeks. 
One possible order in which Obi-Wan could have worn his shirts looks as follows:
    week 1: {1,2,3,4}
    week 2: {2,3,4,1}
    week 3: {3,4,2,1}
    week 4: {4,3,2,1}
Given firstWeek and lastWeek, compute and return the smallest number of weeks the mission could have taken.
*/

using namespace std;

class AttackOfTheClones {
public:
    int count(vector <int>, vector <int>);
};

int AttackOfTheClones::count(vector <int> firstWeek, vector <int> lastWeek) {
    int res = 0;
    for (int i = 0; i < lastWeek.size(); ++i) {
        int cand = 1;
        for (int j = i; j < firstWeek.size(); ++j) {
            if (firstWeek[j] == lastWeek[i]) {
                cand = j - i + 1;
            }
        }
        res = max(res, cand);
    }
    return res;
}

double test0() {
    int t0[] = { 1, 2, 3, 4 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = { 4, 3, 2, 1 };
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    AttackOfTheClones * obj = new AttackOfTheClones();
    clock_t start = clock();
    int my_answer = obj->count(p0, p1);
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
    int t0[] = { 1, 2, 3, 4 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = { 1, 2, 3, 4 };
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    AttackOfTheClones * obj = new AttackOfTheClones();
    clock_t start = clock();
    int my_answer = obj->count(p0, p1);
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
double test2() {
    int t0[] = { 8, 4, 5, 1, 7, 6, 2, 3 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = { 2, 4, 6, 8, 1, 3, 5, 7 };
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    AttackOfTheClones * obj = new AttackOfTheClones();
    clock_t start = clock();
    int my_answer = obj->count(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 7;
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

    if (!errors)
        cout << "You're a stud (at least on the example cases)!" << endl;
    else
        cout << "Some of the test cases had errors." << endl;
}
