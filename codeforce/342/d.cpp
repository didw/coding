// D. Finals in arithmetic
// http://codeforces.com/contest/625/problem/D

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool possible(vector<int> n, int aaa) {
    vector<int> a(n.size(), 0), ar(n.size(), 0);
    for (int i = 0; i < n.size(); ++i) {
        if (n[i] % 2 == 1) {
            a[i] = (n[i]+aaa) / 2;
            aaa = (aaa+1) % 2;
        } else
            a[i] = n[i]/2;
    }

    for (int i = 0; i < a.size(); ++i) {
        ar[i] = a[a.size()-i-1];
    }

    if (ar[ar.size()-1] == 0)
        ar.pop_back();

    int carry = 0;
    for (int i = n.size()-1; i >= 0; --i) {
        if (n[i] == a[i] + ar[i]) continue;
        if (i < n.size() - 1 && n[i] == a[i] + ar[i] + 1) {
            a[i+1] += 5;
            ar[i+1] += 5;
            continue;
        }
        return 0;
    }
    return 1;

}

int main() {
    string ns;
    cin >> ns;
    vector<int> n(ns.size(), 0);
    vector<int> a(n.size(), 0), ar(n.size(), 0);
    for (int i = 0; i < n.size(); ++i)
        n[i] = ns[i] - '0';
    if (possible(n, 1)) {
        int aaa = 1;
        for (int i = 0; i < n.size(); ++i) {
            if (n[i] % 2 == 1) {
                a[i] = (n[i]+aaa) / 2;
                aaa = (aaa+1) % 2;
            } else
                a[i] = n[i]/2;
        }

        for (int i = 0; i < a.size(); ++i) {
            ar[i] = a[a.size()-i-1];
        }


        int carry = 0;
        for (int i = n.size()-1; i >= 0; --i) {
            if (n[i] == a[i] + ar[i]) continue;
            if (i < n.size() - 1 && n[i] == a[i] + ar[i] + 1) {
                a[i+1] += 5;
                ar[i+1] += 5;
                continue;
            }
            return 0;
        }

    }
    else if (possible(n, 0)) {
        int aaa = 0;
        for (int i = 0; i < n.size(); ++i) {
            if (n[i] % 2 == 1) {
                a[i] = (n[i]+aaa) / 2;
                aaa = (aaa+1) % 2;
            } else
                a[i] = n[i]/2;
        }

        for (int i = 0; i < a.size(); ++i) {
            ar[i] = a[a.size()-i-1];
        }


        int carry = 0;
        for (int i = n.size()-1; i >= 0; --i) {
            if (n[i] == a[i] + ar[i]) continue;
            if (i < n.size() - 1 && n[i] == a[i] + ar[i] + 1) {
                a[i+1] += 5;
                ar[i+1] += 5;
                continue;
            }
            cout << "0";
            return 0;
        }

    }
    else
        return 0;
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i];
    }
    return 0;
}

