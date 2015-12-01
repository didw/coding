#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

bool visited[200003];
int node_depth[200003];

int parent[200003];
vector<int> tree[200003];

void dfs(int now, int depth) {

  if (visited[now]) return;
  visited[now] = true;
  node_depth[now] = depth;

  int sz = (int)tree[now].size();
  for (int i = 0; i < sz; i++) {
    if( !visited[tree[now][i]] ) {
      dfs(tree[now][i], depth+1);
    }
  }
}

bool isParent(int p, int c) {

  int tmp = parent[c];
  while(tmp != -1 || node_depth[p] <= node_depth[tmp]) {
    if (tmp == p) return true;
    tmp = parent[tmp];
  }

  return false;
}

int main() {

  int tc;

  cin >> tc;

  while(tc--) {
    int n, m;
    cin >> n >> m;

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    memset(node_depth, -1, sizeof(node_depth));

    for (int i = 0; i < n-1; i++) {
      int a, b;
      cin >> a >> b;
      
      tree[a].push_back(b);
      parent[b] = a;
    }

    parent[1] = -1;
    dfs(1, 1);
    
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;

      int result = 0;
      if (node_depth[a] > node_depth[b]) {
	result = isParent(b, a);
      } else if (node_depth[a] < node_depth[b]) {
	result = isParent(a, b);
      }
      cout << result << endl;
    }

    for (int i = 0; i < 200003; i++) {
      tree[i].clear();
    }
  }
  
  return 0;
}

