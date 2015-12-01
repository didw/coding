#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int parent[200001];
int n, m;

bool travel(int a, int b) {
    while (a != 0) {
        if (a == b)
            return true;
        a = parent[a];
    }
    return false;
}

int main() {
    int c;
    ifstream fIn;
    ofstream fOut;
    fIn.open("Problem1_SmallSet\\inputS001.txt");
    fOut.open("outputS001.txt");
    
    fIn >> c;
    while (c--) {
        fIn >> n >> m;
        memset(parent, 0, sizeof(parent));
        for (int i = 0; i < n-1; ++i) {
            int c, p;
            fIn >> p >> c;
            parent[c] = p;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            fIn >> a >> b;
            if (travel(a, b) || travel(b, a)) {
                fOut << "1" << endl;
            }
            else
                fOut << "0" << endl;
        }

    }
}