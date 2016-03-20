#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<pair<int,int>, int> dup;
vector<int> chk;

bool niceseq(vector<int> &seq, int idx) {
	for (int i = 0; i < chk.size(); ++i) {
		if (chk[i] == 0) {
			if (seq[0] >= seq[1]) return false;
		}
		else if (chk[i] == seq.size()-1) {
			int n = chk[i];
			if (n %2 == 1) {
				if (seq[n] <= seq[n-1]) return false;
			}
			else {
				if (seq[n] >= seq[n-1]) return false;
			}
		}
		else {
			int n = chk[i];
			if (n%2 == 1) {
				if (seq[n] <= seq[n-1]) return false;
				if (seq[n] <= seq[n+1]) return false;
			}
			else {
				if (seq[n] >= seq[n-1]) return false;
				if (seq[n] >= seq[n+1]) return false;
			}
		}
	}
	if (idx == 0) {
		if (seq[0] >= seq[1]) return false;
	}
	else if (idx == seq.size()-1) {
		int n = seq.size()-1;
		if (n %2 == 1) {
			if (seq[n] <= seq[n-1]) return false;
		}
		else {
			if (seq[n] >= seq[n-1]) return false;
		}
	}
	else {
		int n = idx;
		if (n%2 == 1) {
			if (seq[n] <= seq[n-1]) return false;
			if (seq[n] <= seq[n+1]) return false;
		}
		else {
			if (seq[n] >= seq[n-1]) return false;
			if (seq[n] >= seq[n+1]) return false;
		}
	}
	return true;
}

int replace_seq(int idx, vector<int> seq) {
	int res = 0;
	for (int i = 0; i < seq.size(); ++i) {
		if (i == idx) continue;
		swap(seq[i], seq[idx]);
		if (niceseq(seq, i)) {
			int a = i, b = idx;
			if (a > b) swap(a,b);
			if (dup[make_pair(a,b)]==0) {
				res++;
				dup[make_pair(a,b)]++;
			}
		}
		swap(seq[i], seq[idx]);
	}
	return res;
}

int main() {
	int n = 0;
	cin >> n;
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
	}
	int res = 0;



	for (int i = 0; i < n-1; i+=2) {
		if (seq[i] >= seq[i+1]) {
			chk.push_back(i);
			chk.push_back(i+1);
		}
	}
	for (int i = 1; i < n-1; i+=2) {
		if (seq[i] <= seq[i+1]) {
			chk.push_back(i);
			chk.push_back(i+1);
		}
	}

	if (chk.size() > 10) {
		cout << "0" << endl;
		return 0;
	}

	for (int i = 0; i < n-1; i+=2) {
		if (seq[i] >= seq[i+1]) {
			res += replace_seq(i, seq);
			res += replace_seq(i+1, seq);
		}
	}
	for (int i = 1; i < n-1; i+=2) {
		if (seq[i] <= seq[i+1]) {
			res += replace_seq(i, seq);
			res += replace_seq(i+1, seq);
		}
	}
	cout << res << endl;
	return 0;
}
