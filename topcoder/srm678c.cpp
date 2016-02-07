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
In order to become a Sith, Anakin Skywalker must descend a dangerous staircase and join his master who waits for him at the bottom. 
The staircase consists of the bottom floor, N-1 floating platforms, and the top floor. 
Hence, Anakin must make exactly N steps in order to get from the top to the bottom. 
(He must step on each platform exactly once.)  

You are given a vector <int> steps that contains N elements: 
    the height differences between consecutive platforms, from the bottom to the top. 
    That is, the bottom floor is currently at height 0, 
    the first floating platform is at steps[0], 
    the second floating platform is at steps[0]+steps[1], and so on, 
    until at the end we get to the top floor which is at height sum(steps). 
    For example, if steps={2,3,5}, the floating platforms are currently at heights 2 and 5 (= 2+3), and the top floor is at height 10 (= 2+3+5).

Whenever Anakin descends a large distance in a single step, he gets hurt and loses some life. 

More precisely, it works as follows: 
    If the height difference H between consecutive platforms is D or less, Anakin can take the step without any harm. 
    If the height difference H is more than D, Anakin will lose (H-D)^2 life points when he takes the step.

Before he starts his descent, Anakin can use the Force to shift at most T of the floating platforms. 
There are some restrictions:
    He is not allowed to shift the bottom floor or the top floor, only the floating platforms between them.
    Each platform can only be shifted up or down.
    Each platform can only be shifted by an integer distance.
At the end, after all the shifting, the entire staircase must still go upwards if you go from the bottom to the top. 
That is, if you list the heights of the bottom floor, all floating platforms in their original order, and then the top floor, you must still get a strictly increasing sequence of integers.
Also note that Anakin can only start his descent after he finishes moving all the platforms.
Continuing the above example, suppose that T=1. 
If Anakin decides to shift the second floating platform (the one that is currently at height 5), he can shift it to one of the following heights: 3, 4, 6, 7, 8, or 9. 
If he had T=2 in the same situation, he could also do many other things. 
For example, he could shift the two platforms from heights 2 and 5 to heights 1 and 2, respectively.
You are given the int steps and the ints D and T as defined above. 
Compute and return the smallest total number of life points Anakin will lose if he uses the Force wisely.

*/
using namespace std;

class RevengeOfTheSith {
public:
    int move(vector <int>, int, int);
};

int RevengeOfTheSith::move(vector <int> steps, int T, int D) {

}

double test0() {
    int t0[] = { 2, 3, 5 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int p1 = 1;
    int p2 = 1;
    RevengeOfTheSith * obj = new RevengeOfTheSith();
    clock_t start = clock();
    int my_answer = obj->move(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p3 = 19;
    cout << "Desired answer: " << endl;
    cout << "\t" << p3 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p3 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test1() {
    int t0[] = { 2, 3, 5 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int p1 = 2;
    int p2 = 1;
    RevengeOfTheSith * obj = new RevengeOfTheSith();
    clock_t start = clock();
    int my_answer = obj->move(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p3 = 17;
    cout << "Desired answer: " << endl;
    cout << "\t" << p3 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p3 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test2() {
    int t0[] = { 1, 2, 3, 4, 5, 6 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int p1 = 1;
    int p2 = 2;
    RevengeOfTheSith * obj = new RevengeOfTheSith();
    clock_t start = clock();
    int my_answer = obj->move(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p3 = 30;
    cout << "Desired answer: " << endl;
    cout << "\t" << p3 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p3 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test3() {
    int t0[] = { 1, 1, 1, 1, 1, 1, 1 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int p1 = 3;
    int p2 = 3;
    RevengeOfTheSith * obj = new RevengeOfTheSith();
    clock_t start = clock();
    int my_answer = obj->move(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p3 = 0;
    cout << "Desired answer: " << endl;
    cout << "\t" << p3 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p3 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test4() {
    int t0[] = { 1, 2, 3 };
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int p1 = 2;
    int p2 = 2;
    RevengeOfTheSith * obj = new RevengeOfTheSith();
    clock_t start = clock();
    int my_answer = obj->move(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p3 = 0;
    cout << "Desired answer: " << endl;
    cout << "\t" << p3 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if (p3 != my_answer) {
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
