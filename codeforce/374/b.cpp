//http://codeforces.com/contest/721/problem/B

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> passwords(n);
    string answer;
    for (int i = 0; i < n; ++i) {
        cin >> passwords[i];
    }
    cin >> answer;

    int len = answer.size();
    int shorter = 0, longer = 0;
    for (int i = 0; i < n; ++i) {
        if (passwords[i].size() < len)
            shorter++;
    }
    for (int i = 0; i < n; ++i) {
        if (passwords[i].size() > len)
            longer++;
    }
    int best = shorter + 1;
    best += (int((best - 1) / k) * 5) >= 0 ? (int((best - 1) / k) * 5) : 0;
    int worst = n - longer;
    worst += int((worst - 1) / k) * 5 >= 0 ? int((worst - 1) / k) * 5 : 0;
    printf("%d %d\n", best, worst);
}