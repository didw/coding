#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int p, int q) {
	if (q == 0) return p;
	return gcd(q, p%q);
}

void get_ratio(vector<int>& r) {
	int p = r[0];
	for (int i = 1; i < r.size(); ++i) {
		p = gcd(p, r[i]);
	}
	for (int i = 0; i < r.size(); ++i) {
		r[i] /= p;
	}
}

vector<int> potion(const vector<int>& r, const vector<int>& p, int t) {
	vector<int> res;
	int m = 0;
	for (int i = 0; i < p.size(); ++i) {
		m = max(m, int((p[i] + r[i] - 1) / r[i]));
	}
	for (int i = 0; i < p.size(); ++i) {
		res.push_back((r[i] * m) - p[i]);
	}
	return res;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, total = 0;
		cin >> n;
		vector<int> r, p;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			r.push_back(a);
			total += a;
		}
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			p.push_back(a);
		}
		get_ratio(r);
		vector<int> res = potion(r, p, total);
		for (int i = 0; i < res.size(); ++i)
			cout << res[i] << " ";
		cout << endl;
	}
}
