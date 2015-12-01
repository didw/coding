#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node(int n) : no(n), parent(NULL) {}
    int no;
    Node* parent;
};

int inSamePath(vector<Node*>& nodes, int from, int to)
{
    // from 'from' to 'to'
    Node* cur = nodes[from];
    while (cur && cur->no != nodes[to]->no)
        cur = cur->parent;
    if (cur)
        return 1;

    // from 'to' to 'from'
    cur = nodes[to];
    while (cur && cur->no != nodes[from]->no)
        cur = cur->parent;
    if (cur)
        return 1;

    return 0;
}

int main()
{
    int ncase;
    cin >> ncase;
    while (ncase--) {
        int nnode, nquery;
        cin >> nnode >> nquery;

        vector<Node*> nodes(nnode + 1);
        for (int i = 0; i < nnode + 1; i++)
            nodes[i] = new Node(i);

        for (int i = 0; i < nnode - 1; i++) {
            int from, to;
            cin >> from >> to;
            nodes[to]->parent = nodes[from];
        }

        for (int i = 0; i < nquery; i++) {
            int from, to;
            cin >> from >> to;

            int ret = inSamePath(nodes, from, to);
            cout << ret << endl;
        }

        for (int i = 0; i < nnode + 1; i++) {
            delete nodes[i];
        }
        nodes.clear();

    }
    return 0;
}

