#include <iostream>
#include <array>

using namespace std;

const int MAX_N = 200000;
const int MAX_M = 200000;

array<int, MAX_N+10> up{0, };
//array<int, MAX_N+10> level;

void add_node(int parent, int child) {

	up[child] = parent;
}

bool check(int parent, int child) {

	for ( int p=up[child]; p != 0; p = up[p] ) {
		if ( p == parent )
			return true;
	}

	return false;
}

int main(int argc, char* argv[]) {

	int T;

	cin >> T;

	while (T--) {

//		cout << "T: " << T << endl;

		int N, M;

		cin >> N >> M;

		for (int idx=1; idx < N; idx++) {

			int val, val2;

			cin >> val >> val2;
			add_node(val, val2);
		}

//		for (int idx=1; idx < N+1; idx++) {
//			cout << idx << " : " << up[idx] << endl;
//		}

		for (int idx=0; idx < M; idx++) {

			int val, val2;
			bool result;

			cin >> val >> val2;

			if ( check(val, val2) || check(val2, val))
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
	}

	return 0;
}
