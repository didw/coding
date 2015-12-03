#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class OrderOfOperationsDiv2{
public:
    int NumberOfSetBits(int i)
    {
        // Java: use >>> instead of >>
        // C or C++: use uint32_t
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
    int minTime(vector <string> s) {
        vector<bool> taken(s.size(), false);
        int computer = 0;
        vector<int> instruction(s.size());
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s[i].size(); ++j) {
                instruction[i] <<= 1;
                if (s[i][j] == '1')
                    instruction[i] += 1;
            }
        }
        int cand = -1;
        int cand_bit = 100;
        int res = 0;
        while (1) {
            for (int i = 0; i < instruction.size(); ++i) {
                if (taken[i]) continue;
                if (cand_bit > __popcnt(instruction[i] & ~computer)) {
                    cand_bit = __popcnt(instruction[i] & ~computer);
                    cand = i;
                }
            }
            if (cand_bit == 100)
                break;
            taken[cand] = true;
            res += cand_bit*cand_bit;
            computer |= instruction[cand];
            cand = -1;
            cand_bit = 100;
        }
        return res;
    }
};

vector<string> a;

void input() {
    int N;
    cin >> N;
    a = vector<string>(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
}

int solve() {
    OrderOfOperationsDiv2 name;
    return name.minTime(a);
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        input();
        cout << solve() << endl;
    }
}