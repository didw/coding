#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> divider;
void findDivider(int num) {
	int rt = sqrt(num);
	for (int i = 2; i <= rt; ++i) {
		if (num % i == 0) {
			divider.push_back(i);
			if (i == num / i) continue;
			divider.push_back(num / i);
		}
	}
}

int sumDivider(int num) {
	int sum = 1;
	for (int i = 0; i < divider.size() ; ++i) {
		sum += divider[i];
	}
	return sum;
}

int main() {
	int c;
	cin >> c;
	while (c-- ) {
		int a, b, res = 0;
		cin >> a >> b;
		for (int i = a; i <= b; ++i) {
			divider.clear();
			findDivider(i);
			if (i <= sumDivider(i)) res++;
		}
		cout << res << endl;
	}
}