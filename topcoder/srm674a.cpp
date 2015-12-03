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

using namespace std;

class RelationClassifier {
public:
    string isBijection(vector <int>, vector <int>);
};

string RelationClassifier::isBijection(vector <int> domain, vector <int> range) {
    sort(domain.begin(), domain.end());
    sort(range.begin(), range.end());
    for (int i = 1; i < domain.size(); ++i) {
        if ((domain[i] == domain[i - 1]) || (range[i] == range[i - 1]))
            return "Not";
    }
    return "Bijection";
}
