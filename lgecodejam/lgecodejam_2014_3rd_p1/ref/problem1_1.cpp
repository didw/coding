#include <iostream>

using namespace std;

class Node {
public:
    bool isAncestor(Node* node);
    Node* parent;
    int index;
};

bool Node::isAncestor(Node* node) {
    Node* p = parent;
    while (p) {
        if (p == node)
            return true;
        else
            p = p->parent;
    }
    return false;
}

class Solver {
public:
    Solver();
    ~Solver();
    void solve();

private:
    Node* nodes;
    int nNode;
    int nProblem;
};

Solver::Solver() {
    cin >> nNode >> nProblem;
    nodes = new Node[nNode];
    nodes[0].parent = NULL;
    nodes[0].index = 1;

    // read tree
    int p, n;
    for (int i = 1; i < nNode; ++i) {
        cin >> p >> n;
        nodes[n - 1].parent = &nodes[p - 1];
        nodes[n - 1].index = n;
    }
}

Solver::~Solver() {
    delete [] nodes;
}

void Solver::solve() {
    int a, b;
    for (int i = 0; i < nProblem; ++i) {
        // read problem
        cin >> a >> b;

        // if smaller one is root, always true.
        if (a == 1) {
            cout << 1 << endl;
            continue;
        }

        // solve
        Node* aNode = &nodes[a - 1];
        Node* bNode = &nodes[b - 1];
        if (bNode->isAncestor(aNode) || aNode->isAncestor(bNode))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

// main function
int main(int argc, char** args) {
    // get testcase count
    uint nTest;
    cin >> nTest;

    // Solve
    for (int i = 0; i < nTest ; ++i) {
        Solver test;
        test.solve();
    }
    return 0;
}
