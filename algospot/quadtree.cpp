#include <iostream>
#include <vector>
#include <string>

using namespace std;

string quadtree(string orig) {
    string dest;
    if (orig[0] == 'x') {
        dest.push_back('x');
        string a = quadtree(&orig[1]);
        string b = quadtree(&orig[1]+a.size());
        string c = quadtree(&orig[1]+a.size()+b.size());
        string d = quadtree(&orig[1]+a.size()+b.size()+c.size());
        dest.append(c);
        dest.append(d);
        dest.append(a);
        dest.append(b);
    } else {
        dest.push_back(orig[0]);
    }

    return dest;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string orig;
        cin >> orig;
        cout << quadtree(orig) << endl;
    }
}

