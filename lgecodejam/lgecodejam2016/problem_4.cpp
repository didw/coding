#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Tree {
	int p;
	int w;
	int d;
	long long z;
	vector<int> children;
} Tree;

Tree tree[100001];

void updateZ(int root) {
	for (int i = 0; i < tree[root].children.size(); ++i) {
		int next = tree[root].children[i];
		tree[next].z = min(tree[next].z, tree[root].z + tree[next].w);
		updateZ(next);
	}
}

long long findPathA(int a, int b) {
	long long res = 0;
	while (a != b) {
		if (tree[a].d == tree[b].d) {
			res += tree[a].w;
			res += tree[b].w;
			a = tree[a].p;
			b = tree[b].p;
		}
		else if (tree[a].d > tree[b].d) {
			res += tree[a].w;
			a = tree[a].p;
		}
		else {
			res += tree[b].w;
			b = tree[b].p;
		}
	}
	return res;
}

long long findPathB(int a, int b) {
	// case1: a-p-b (same with A)
	// case2: a-1-b
	// case3: a-1-p-b
	// case4: a-p-1-b
	long long pathA = tree[a].z;
	long long pathB = tree[b].z;
	return pathA + pathB;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, Q;
		cin >> N >> Q;
		vector<bool> leaf(N+1, true);
		tree[1].d = 0;
		tree[1].z = 0;

		for (int i = 1; i <= N; ++i) {
			tree[i].children.clear();
		}

		for (int i = 1; i < N; ++i) {
			int p, w;
			cin >> p >> w;
			tree[i+1].p = p;
			tree[i+1].w = w;
			tree[i+1].d = tree[p].d + 1;
			tree[i+1].z = tree[p].z + w;
			tree[p].children.push_back(i+1);
			leaf[p] = false;
		}

		int M = 0;
		for (int i = 1; i <= N; ++i) {
			if (leaf[i] == true) M++;
		}
		int next = 1;
		for (int i = 0; i < M; ++i) {
			while(leaf[++next] == false);
			cin >> tree[next].z;
			long long score = tree[next].z;
			int pp = next;
			while (pp > 1) {
				score += tree[pp].w;
				pp = tree[pp].p;
				tree[pp].z = min(score, tree[pp].z);
			}
		}

		updateZ(1);

		long long resA = 0, resB = 0;
		for (int i = 0; i < Q; ++i) {
			int a, b;
			cin >> a >> b;
			long long scoreA = findPathA(a, b);
			long long scoreB = min(scoreA, findPathB(a, b));
			resA += scoreA;
			resB += scoreB;
		}
		cout << resA << " " << resB << endl;
	}
}

