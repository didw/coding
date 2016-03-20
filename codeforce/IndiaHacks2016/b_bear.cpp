#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int n, q;
vector<pair<string, char> > shortcut;

int cache[6][6];

int makeChar(char a, int last) {
	if (last == 1) return 1;
	int &res = cache[a-'a'][last];
	if (res != -1) return res;
	res = 0;
	for (int i = 0; i < q; ++i) {
		if (a == shortcut[i].second) {
			res += makeChar(shortcut[i].first[0], last-1);
		}
	}
	return res;
}

int main() {
	cin >> n >> q;
	shortcut = vector<pair<string, char> >(q);
	for (int i = 0; i < q; ++i) {
		cin >> shortcut[i].first;
		cin >> shortcut[i].second;
	}
	memset(cache, -1, sizeof(cache));
	cout << makeChar('a', n) << endl;
	return 0;
}
