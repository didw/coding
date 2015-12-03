#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PointDistance {
public:
    int dist(int x, int y, int xx, int yy) {
        return (x - xx)*(x - xx) + (y - yy)*(y - yy);
    }
    vector <int> findPoint(int x1, int y1, int x2, int y2) {
        for (int x = -100; x <= 100; ++x) {
            for (int y = -100; y <= 100; ++y) {
                if (dist(x, x1, y, y1) > dist(x, x2, y, y2)) {
                    vector<int> res;
                    res.push_back(x);
                    res.push_back(y);
                    return res;
                }   
            }
        }
        return vector<int>();
    }
};