#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printDecimal(int a, int b) {
  cout << a/b;
  if (a != 0) cout << ".";
  else return;
  a = (a%b)*10;
  vector<int> rem, dig;
  for (int i = 0; i < b+1; ++i) {
    dig.push_back(a/b);
    rem.push_back(a);
    a = (a%b)*10;
  }

  for (int i = 0; i < b+1; ++i) {
    int beg = 0, end = 0;
    for (int j = i+1; j < b+1; ++j) {
      if (rem[i] == rem[j]) {
        beg = i; end = j;
        break;
      }
    }
    if (end == 0) {
      cout << dig[i]; continue;
    }
    cout << "(";
    for (int j = beg; j < end; ++j) {
      cout << dig[j];
    }
    cout << ")";
    return;
  }

}


int main() {
  printDecimal(4,3);
  return 0;
}
