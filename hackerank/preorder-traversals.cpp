#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<int> tree;

bool checkTree(int root, int begin, int end) {
    bool res = true;
    if (begin > end) return true;
    int leftBegin = begin, leftEnd = end, rightBegin = begin, rightEnd = end;
    while (leftEnd >= 0 && tree[root] < tree[leftEnd]) leftEnd--;
    while (rightBegin < tree.size() && tree[root] > tree[rightBegin]) rightBegin++;
    if (leftEnd > rightBegin) return false;
    if (tree[root] > tree[begin]) {
        res = res & checkTree(leftBegin, leftBegin + 1, leftEnd);
    }
    if (tree[root] < tree[end]) {
        res = res & checkTree(rightBegin, rightBegin + 1, rightEnd);
    }
    return res;
}

char* solve() {
    if (checkTree(0, 1, tree.size()-1)) return "yes";
    return "no";
}

int main() {
    int n, t = 1;
    tree = vector<int>(0);
    while (scanf("%d", &n)) {
        if (n < 0) {
            printf("Case %d: %s\n", t++, solve());
            tree = vector<int>(0);
            if (feof(stdin)) break;
            continue;
        }
        else {
            tree.push_back(n);
        }
    }
    return 0;
}
