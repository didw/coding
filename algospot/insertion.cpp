#include <iostream>
#include <vector>
#include <random>

typedef int KeyType;

using namespace std;


struct Node {
    KeyType key;
    int priority, size;
    Node* left, *right;
    Node(KeyType _key) : key(_key), priority(rand()), size(1),
        left(NULL), right(NULL) {
    }
    void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
    void setRight(Node* newRight) { right = newRight; calcSize(); }
    void calcSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
};

typedef pair<Node*, Node*> NodePair;
NodePair split(Node* root, KeyType key);
Node* insert(Node *root, Node *node);
Node* insert(Node *root, KeyType key);
Node* merge(Node* a, Node* b);
Node* erase(Node* root, KeyType key);
Node* kth(Node* root, int k);
int countLessThan(Node* root, KeyType key);

using namespace std;

NodePair split(Node* root, KeyType key) {
    if (root == NULL) return NodePair(NULL, NULL);
    if (root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

Node* insert(Node *root, Node *node) {
    if (root == NULL) return node;
    if (root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    if (root->key > node->key) {
        Node* ret = insert(root->left, node);
        root->setLeft(ret);
        return root;
    }
    Node* ret = insert(root->right, node);
    root->setRight(ret);
    return root;
}

Node* insert(Node *root, KeyType key) {
    return insert(root, new Node(key));
}


Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (a->priority > b->priority) {
        a->setRight(merge(a->right, b));
        return a;
    }
    b->setLeft(merge(a, b->left));
    return b;
}

Node* erase(Node* root, KeyType key) {
    if (root == NULL) return NULL;
    if (root->key == key) {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if (root->key < key)
        root->setRight(erase(root->right, key));
    else
        root->setLeft(erase(root->left, key));
    return root;
}

Node* kth(Node* root, int k) {
    if (root == NULL) return NULL;
    int leftSize = root->left ? root->left->size : 0;
    if (leftSize >= k)
        return kth(root->left, k);
    if (leftSize + 1 == k)
        return root;
    return kth(root->right, k - leftSize - 1);
}

int countLessThan(Node* root, KeyType key) {
    if (root == NULL) return 0;
    if (root->key < key) {
        int ls = root->left ? root->left->size : 0;
        return countLessThan(root->right, key) + ls + 1;
    }
    return countLessThan(root->left, key);
}


int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        Node* treap = NULL;
        int mov[50000];
        int orig[50000];
        for (int i = 0; i < n; ++i) {
            treap = insert(treap, i + 1);
            cin >> mov[i];
        }
        for (int i = n-1; i >= 0; --i) {
            orig[i] = kth(treap, treap->size - mov[i])->key;
            treap = erase(treap, orig[i]);
        }
        for (int i = 0; i < n; ++i)
            cout << orig[i] << " ";
        cout << endl;
    }
}

