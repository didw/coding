#include <iostream>
#include <list>

using namespace std;

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, k;
        cin >> n >> k;
        list<int> surv;
        for (int i = 1; i <= n; ++i) {
            surv.push_back(i);
        }
        list<int>::iterator kill = surv.begin();
        while (n > 2) {
            kill = surv.erase(kill);
            if (kill == surv.end())
                kill = surv.begin();
            for (int i = 0; i < k - 1; ++i) {
                ++kill;
                if (kill == surv.end())
                    kill = surv.begin();
            }
            n--;
        }
        cout << surv.front() << " " << surv.back() << endl;
    }
}
