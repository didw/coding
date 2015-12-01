#include <iostream>
#include <map>

using namespace std;

map<int, int> nerd;

bool isDominant(int x, int y) {
    map<int, int>::iterator it = nerd.lower_bound(x);
    if (it == nerd.end()) return false;
    return y < it->second;
}

void removeDominant(int x, int y) {
    map<int, int>::iterator it = nerd.lower_bound(x);
    if (it == nerd.begin()) return;
    --it;
    while (true) {
        if (it->second > y) return;
        if (it == nerd.begin()) {
            nerd.erase(it);
            return;
        }
        else {
            map<int, int>::iterator jt = it;
            --jt;
            nerd.erase(it);
            it = jt;
        }
    }
}

int registered(int x, int y) {
    if (isDominant(x, y)) return nerd.size();
    removeDominant(x, y);
    nerd[x] = y;
    return nerd.size();
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        int res = 0;
        nerd.clear();
        while (n--) {
            int p, q;
            cin >> p >> q;
            res += registered(p, q);
        }
        cout << res << endl;
    }
}
