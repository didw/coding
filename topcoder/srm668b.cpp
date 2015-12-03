#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

const string SQUARE = "It's a square";
const string NOTSQUARE= "Not a square";
class IsItASquare{
public:
    vector<double> getDist(vector<int> x, vector<int> y, int n) {
        vector<double> line(4);
        for (int i = 0; i < 4; ++i) {
            line[i] = sqrt((x[n] - x[i])*(x[n] - x[i]) + (y[n] - y[i])*(y[n] - y[i]));
        }
        sort(line.begin(), line.end());
        return line;
    }
    string isSquare(vector <int> x, vector <int> y) {
        vector<double> line[4];
        for (int i = 0; i < 4; ++i) {
            line[i] = getDist(x, y, i);
        }
        double sline = line[0][1];
        for (int i = 0; i < 4; ++i) {
            if (sline != line[i][1] || sline != line[i][2])
                return NOTSQUARE;
        }
        return SQUARE;
    }
};