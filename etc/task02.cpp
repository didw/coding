#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
	vector<int> parent, rank, size;
	UnionFind(const vector<int>& A):parent(A.size()), rank(A.size(), 1), size(A.size(), 1) {
		for (size_t i = 0; i < A.size(); ++i) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}

	int merge(int u, int v) {
		// cout << u << " " << v << endl;

		u = find(u);
		v = find(v);
		// cout << u << " " << v << endl;
		if (u == v) return size[v];
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
		size[v] += size[u];
		return size[v];
	}
};

int solution(vector<int>& A) {
	// write your code in C++14 (g++ 6.2.0)
	UnionFind uf(A);
	int res = 0;
	for (size_t i = 0; i < A.size(); ++i) {
		int siz = uf.merge(i, A[i]);
		// cout << "size: " << siz << endl;
	}
	for (size_t i = 0; i < A.size(); ++i) {
		if (uf.find(i) == A[i]) {
			int size_i = uf.merge(i, A[i]);
			res = max(res, size_i);
		}
	}
	return res;
}

//int main() {
//	int n;
//	cin >> n;
//	vector<int> beads;
//	for (int i = 0; i < n; ++i) {
//		int a;
//		cin >> a;
//		beads.push_back(a);
//	}
//	cout << solution(beads) << endl;
//}
