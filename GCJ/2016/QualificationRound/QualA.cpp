#include <iostream>
#include <vector>
using namespace std;

int N;
int num[10];
bool debug = false;

void input() {
	cin >> N;
}

bool finish(){
	for (int i = 0; i < 10; ++i) {
		if (num[i] == 0) return false;
	}
	return true;
}

void solve() {
	for (int i = 0; i < 10; ++i)
		num[i] = 0;
	for (int i = 1; i <= 1000000; ++i) {
		long long count = N*i;
		while(count) {
			num[count%10]++;
			count /= 10;
		}
		if (debug) {
			for (int j = 0; j < 10; ++j) {
				cout << num[j] << " ";
			}
			cout << endl;
		}
		if (finish()) {
			cout << N*i << endl;
			return;
		}
	}
	cout << "INSOMNIA" << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();
		cout << "Case #" << i << ": ";
		solve();
	}
}
