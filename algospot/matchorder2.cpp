#include <iostream>
#include <vector>
#include <set>

using namespace std;

int order(vector<int> russians, vector<int> koreans) {
    int win = 0;
    multiset<int> ratings(koreans.begin(), koreans.end());
    for (int i = 0; i < russians.size(); ++i) {
        if (russians[i] > *ratings.rbegin())
            ratings.erase(ratings.begin());
        else {
            ratings.erase(ratings.lower_bound(russians[i]));
            win++;
        }
    }
    return win;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        vector<int> ru, ko;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ru.push_back(a);
        }
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ko.push_back(a);
        }
        cout<<order(ru, ko)<<endl;
    }
}
