#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int n, k;
double rr[1000], cc[1000];

// (n-k)를 제외하여 r보다 작은 누적 등수를 만들 수 있는가?
bool decision(double r) {
	vector<double> v;
	for (int i = 0; i < n; ++i) {
		v.push_back(r*cc[i] - rr[i]);
	}
	sort(v.begin(), v.end(), greater<double>());
	double res = 0;
	for (int i = 0; i < k; ++i)
		res += v[i];
	return res >= 0;
}

double optimize() {
	double lo = 0.0, hi = 1.0;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> rr[i] >> cc[i];
		}
		printf("%.10f\n", optimize());
	}
}
