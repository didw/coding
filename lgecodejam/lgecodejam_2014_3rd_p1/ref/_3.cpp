//
//  main.cpp
//  p1
//
//  Created by dohyun.lee on 2014. 8. 29..
//  Copyright (c) 2014년 dohyun.lee. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

static int parent[200000];
typedef pair<int, int> Question;
static Question question[200000];
static unordered_map<int, int> pathAA;
static unordered_map<int, int> pathBB;

class Solution {
    int mNumCase;
    int mNumNode;
    int mNumQuestion;
    ifstream mFs;

public:
    Solution(string& input) {
        mFs.open(input);
        mFs >> mNumCase;
    }
    
    void parseCase() {
        mFs >> mNumNode >> mNumQuestion;
        
        // zero index is intentionally ignored;
        parent[0] = 0;
        
        // node 1 is root
        parent[1] = 1;
        
        // declare parent and child
        int p, c;
        for (int ii = 0, N = mNumNode-1; ii < N; ii++) {
            mFs >> p >> c;
            parent[c] = p;
        }
        
        for (int ii = 0; ii < mNumQuestion; ii++) {
            Question q;
            mFs >> q.first >> q.second;
            //question.push_back(q);
            question[ii] = q;
        }
    }
    
    void process(string& out) {
        ofstream ofs(out);
        cout << "# of Case : " << mNumCase << endl;
        for (int ii = 0; ii < mNumCase; ii++) {
            parseCase();
            cout << "# of Question : " << mNumQuestion << endl;
            for (int jj = 0; jj < mNumQuestion; jj++) {
                Question q(question[jj]);
                int result = isInPath(q.first, q.second) ? 1:0;
                ofs << result << endl;
                //cout << result << endl;
            }
            
            clear();
        }
        ofs.close();
    }
    
    bool isInPath(int nodeA, int nodeB) {
        if (nodeA == 1 || nodeB == 1) return true;
        
        // for A, find the path from the root to nodeA
        bool result = traverseAndFind(nodeA, nodeB);
        if (result) return true;
        
        result = traverseAndFind(nodeB, nodeA);
        return result;
    }
    
    bool traverseAndFind(int traverseNode, int findNode) {
        int p;
        int tmp = traverseNode;
        while ((p = parent[tmp]) != 1) {
            if (p == findNode) return true;
            tmp = p;
        }
        return false;
    }
    
    void clear() {
        memset(parent, 0, sizeof(int)*200000);
        memset(question, 0, sizeof(Question)*200000);
    }

    void print() {
        cout << mNumCase << endl;
        cout << mNumNode << ", " << mNumQuestion << endl;
        
        for (int ii = 1; ii <= mNumNode; ii++) {
            cout << ii << parent[ii] << endl;
        }
        
        for (Question q : question) {
            cout << q.first << q.second << endl;
        }
    }
};

int main(int argc, const char * argv[])
{
    if (argc < 3) {
        cout << "Usage : " << argv[0] << " <input.txt> <output.txt> " << endl;
        return 1;
    }
    
    string in(argv[1]);
    Solution s(in);
    
    string out(argv[2]);
    s.process(out);
    
    return 0;
}

