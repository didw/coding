#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int lunchbox(vector<int> heat, vector<int> eat) {
    vector<pair<int, int>> order;
    for (int i = 0; i < heat.size(); ++i) {
        order.push_back(make_pair(eat[i], heat[i]));
    }
    sort(order.begin(), order.end(), greater<pair<int, int>>());
    int remain_eat = 0;
    int time = 0;
    for (int i = 0; i < order.size(); ++i) {
        time += order[i].second;
        remain_eat = max(remain_eat - order[i].second, order[i].first);
    }
    return time + remain_eat;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        vector<int> heat;
        vector<int> eat;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            heat.push_back(a);
        }
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            eat.push_back(a);
        }
        cout << lunchbox(heat, eat) << endl;
    }
}
