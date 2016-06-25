#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > edges1[100001];
vector<pair<int, int> > edges2[100001];

void dijkstra1(int a, vector<int>& dist) {
	queue<int> q;
	dist[a] = 0;
	q.push(a);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < edges1[here].size(); ++i) {
			pair<int, int> next = edges1[here][i];
			if (dist[next.first] > dist[here] + next.second) {
				dist[next.first] = dist[here] + next.second;
				q.push(next.first);
			}
		}
	}
}

void dijkstra2(int a, vector<int>& dist) {
	queue<int> q;
	dist[a] = 0;
	q.push(a);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < edges2[here].size(); ++i) {
			pair<int, int> next = edges2[here][i];
			if (dist[next.first] > dist[here] + next.second) {
				dist[next.first] = dist[here] + next.second;
				q.push(next.first);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, Q;
		cin >> N >> Q;
		vector<bool> leaf(N+1, true);
		for (int i = 1; i <= N; ++i) {
			edges1[i].clear();
			edges2[i].clear();
		}
		for (int i = 2; i <= N; ++i) {
			int a, w;
			cin >> a >> w;
			edges1[i].push_back(make_pair(a,w));
			edges1[a].push_back(make_pair(i,w));
			leaf[a] = false;
		}
		int M = 0;
		for (int i = 1; i <= N; ++i) {
			edges2[i] = edges1[i];
			if (leaf[i] == true) M++;
		}
		int next = 1;
		for (int i = 0; i < M; ++i) {
			while (leaf[++next] == false);
			int w;
			cin >> w;
			edges2[next].push_back(make_pair(1,w));
			edges2[1].push_back(make_pair(next,w));
		}
		long long resA = 0, resB = 0;
		for (int i = 0; i < Q; ++i) {
			int a, b;
			vector<int> dist(N+1, 987654321);
			cin >> a >> b;
			dijkstra1(a, dist);
			//cout << dist[b] << " ";
			resA += dist[b];
			dist = vector<int>(N+1, 987654321);
			dijkstra2(a, dist);
			//cout << dist[b] << endl;
			resB += dist[b];
		}
		cout << resA << " " << resB << endl;
	}
}

