#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LiveConcert {
public:
    int maxHappiness(vector <int> h, vector <string> s) {
        vector<pair<string, int>> maxsong;
        for (int i = 0; i < h.size(); ++i) {
            bool next = false;
            for (int j = 0; j < maxsong.size(); ++j) {
                if (maxsong[j].first == s[i]) {
                    maxsong[j].second = max(maxsong[j].second, h[i]);
                    next = true;
                    break;
                }
            }
            if (!next)
                maxsong.push_back(make_pair(s[i], h[i]));
        }
        int res = 0;
        for (int i = 0; i < maxsong.size(); ++i)
            res += maxsong[i].second;
        return res;
    }
};