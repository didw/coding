#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int,int>  parentMap;
map<int,vector<int>> cache;

bool isParent(int parent, int child) {
  vector<int> &parentList = cache[child];

  if(parentList.size() != 0)
    return binary_search(parentList.begin(), parentList.end(), parent);

  int p = child;
  while(p != 0) {
    parentList.push_back(p);
    p = parentMap[p];
  }
  sort(parentList.begin(), parentList.end());

  return binary_search(parentList.begin(), parentList.end(), parent);
}

int main(void)
{
  int T, N, M;
  int a, b;

  scanf("%d", &T);
  while(T--) {
    parentMap.clear();
    cache.clear();

    scanf("%d %d", &N, &M);
    for(int i = 1; i < N; ++i) {
      scanf("%d %d", &a, &b);
      parentMap[b] = a;
    }

    for(int i = 0; i < M; ++i) {
      scanf("%d %d", &a, &b);
      printf("%d\n", (isParent(a, b) || isParent(b, a)));
    }
  }

  return 0;
}

