#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

 struct Point2D {
 	int x;
 	int y;
 };

bool doubleEqual(double a, double b) {
	double diff = fabs(a - b);
	if (diff < 1e-10) return true;
	return diff < 1e-8 * max(fabs(a), fabs(b));
}

bool isColinear(const Point2D& a, const Point2D& b, const Point2D& c) {
	// vertical
	if (a.y == b.y || a.y == c.y || b.y == c.y) {
		if (a.y == b.y && a.y == c.y) {
			// cout << "vertical" << endl;
			return true;
		}
		else
			return false;
	}

	// horizontal
	if (a.x == b.x || a.x == c.x || b.x == c.x) {
		if (a.x == b.x && a.x == c.x) {
			// cout << "horizontal" << endl;
			return true;
		}
		else
			return false;
	}

	double ratio1 = ((double)a.y - b.y) / ((double)a.x - b.x);
	double ratio2 = ((double)a.y - c.y) / ((double)a.x - c.x);
	// cout << "ratio: " << ratio1 << " " << ratio2 << endl;
	if (doubleEqual(ratio1, ratio2))
		return true;
	return false;
}

int solution(vector<Point2D>& A) {
	// write your code in C++14 (g++ 6.2.0)
	int res = 0;

	for (size_t i = 0; i < A.size(); ++i) {
		for (size_t j = i + 1; j < A.size(); ++j) {
			for (size_t k = j + 1; k < A.size(); ++k) {
				if (isColinear(A[i], A[j], A[k]))
					// cout << i << " " << j << " " << k << endl;
					res++;
			}
		}
	}
	return res;
}


int main() {
	int n;
	cin >> n;
	vector<Point2D> A;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		Point2D pd;
		pd.x = x;
		pd.y = y;
		A.push_back(pd);
	}
	cout << solution(A) << endl;

}