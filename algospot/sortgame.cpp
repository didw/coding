#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n;
map<int, int> seq;

int incr(int src) { return src > 0 ? src + 1 : src - 1; }
int sgn(int src) {	return src > 0 ? 1 : -1;}

int reverse(unsigned int here, int begin, int end) {
	int des = here;
	for (int i = begin; i <= end; ++i) {
		int rev_i = end + begin - i;
		des &= ~(7 << (3 * rev_i));
		des |= (((7 << (3 * i)) & here) >> (3 * i)) << (3 * rev_i);
	}
	return des;
}

int bidirectional(int start, int end) {
	if (start == end) return 0;
	seq[start] = 1;
	seq[end] = -1;
	queue<int> q;
	q.push(start);
	q.push(end);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				int there = reverse(here, i, j);
				if (seq[there] == 0) {
					seq[there] = incr(seq[here]);
					q.push(there);
				}
				else if (sgn(seq[there]) != sgn(seq[here]))
					return abs(seq[there]) + abs(seq[here]) - 1;
			}
		}
	}
	return 0;
}

vector<int> shrink(vector<int> src) {
	vector<int> des;
	for (int i = 0; i < src.size(); ++i) {
		int odr = 0;
		for (int j = 0; j < src.size(); ++j) {
			if (src[i] > src[j])
				odr++;
		}
		des.push_back(odr);
	}
	return des;
}

int vec2int(vector<int> src) {
	int des = 0;
	for (int i = 0; i < src.size(); ++i) {
		des = des << 3;
		des |= src[i];
	}
	return des;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		vector<int> init;
		seq.clear();
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			init.push_back(a);
		}
		init = shrink(init);
		vector<int> end;
		for (int i = 0; i < n; ++i) {
			end.push_back(i+1);
		}
		end = shrink(end);
		int init2 = vec2int(init);
		int end2 = vec2int(end);
		cout << bidirectional(init2, end2) << endl;
	}
}
