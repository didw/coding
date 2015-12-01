#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

#define MAX_N   100000

inline void setTimes(map<int,int> &times, int n, int sign) {
  if(n <= 0)
    return ;

  int t = sign;
  for(int i = n; i >= 1; --i) {
    times[i] += t;
    t <<= 1;
  }
}

inline void getTimes(map<int,int> &times, map<int,vector<int>> &peg, int N) {
  int idx[4] = {0, 0, 0, 0};
  int i = 0;
  int sign = 1;

  if(!peg[1].empty() && N != peg[1][0]) {
    setTimes(times, N, sign);
    sign = -1;
  }

  while(N > 0) {
    for(i = 1; i <= 3; ++i) {
      if(peg[i].empty())
        continue;

      if(N == peg[i][idx[i]])
        break;
    }

    vector<int> &curPeg = peg[i];
    int &curIdx = idx[i];
    for( ; curIdx + 1 < curPeg.size(); ++curIdx) {
      if(curPeg[curIdx] - curPeg[curIdx+1] != 1)
        break;
    }

    if(curIdx + 1 < curPeg.size()) {
      N = curPeg[curIdx++] - 1;
    } else if(!curPeg.empty()) {
      N = curPeg[curIdx] - 1;
    }

    setTimes(times, N, sign);
    sign *= -1;
  }
}

inline void makeOptimalState(map<int,int> &times, int N, map<int,vector<int>> &peg) {
  function<int(int)> oddFunc, evenFunc;
  bool isOdd;

  if(N % 2 == 1) {
    // odd number of N case
    oddFunc   = [](int t) -> int { return 1 + (t % 3);  };
    evenFunc  = [](int t) -> int {
      int mod = (-t) % 3;
      if(mod < 0) mod += 3;
      return 1 + mod;
    };
    isOdd = true;
  } else {
    // even number of N case
    oddFunc  = [](int t) -> int {
      int mod = (-t) % 3;
      if(mod < 0) mod += 3;
      return 1 + mod;
    };
    evenFunc  = [](int t) -> int { return 1 + (t % 3);  };
    isOdd = false;
  }

  for(int i = N; i > 0; --i, isOdd = !isOdd) {
    int idx = (isOdd)? oddFunc(times[i]): evenFunc(times[i]);
    peg[idx].push_back(i);
  }
}

inline bool isEquals(map<int,vector<int>> &peg1, map<int,vector<int>> &peg2) {
  for(int i = 1; i <= 3; ++i) {
    if(peg1[i].size() != peg2[i].size())
      return false;

    if(!equal(peg1[i].begin(), peg1[i].end(), peg2[i].begin()))
      return false;
  }

  return true;
}

inline bool isOptimal(map<int,int> &times, map<int,vector<int>> &peg, int N) {
  map<int,vector<int>> optPeg;

  getTimes(times, peg, N);
  makeOptimalState(times, N, optPeg);

  return isEquals(peg, optPeg);
}

bool solve(map<int,int> &second, map<int,int> &third, int N) {
  for(int i = 1; i <= N; ++i) {
    int &times2 = second[i];
    int &times3 = third[i];

    if(times2 < times3)
      return true;

    if(times2 > times3)
      return false;
  }

  return false;
}

int main(void)
{
  int T, N, ele;

  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);

    map<int,int> secondTimes, thirdTimes;
    map<int,vector<int>> pegs;
    int pos;

    // input
    for(int i = N; i > 0; --i) {
      scanf("%d", &pos);
      pegs[pos].push_back(i);
    }

    if(!isOptimal(secondTimes, pegs, N)) {
      for(int i = N; i > 0; --i) {
        scanf("%d", &pos);
      }
      printf("0\n");
      continue;
    }

    pegs.clear();
    for(int i = N; i > 0; --i) {
      scanf("%d", &pos);
      pegs[pos].push_back(i);
    }

    if(!isOptimal(thirdTimes, pegs, N)) {
      printf("0\n");
      continue;
    }

    printf("%d\n", solve(secondTimes, thirdTimes, N));
  }

  return 0;
}

