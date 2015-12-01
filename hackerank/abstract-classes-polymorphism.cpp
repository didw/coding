//https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/abstract-classes-polymorphism
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {
protected:
    map<int, Node*> mp;
    int cp;
    Node* tail;
    Node* head;
    virtual void set(int, int) = 0;
    virtual int get(int) = 0;
};

class LRUCache : public Cache{
public:
    LRUCache(int c) { 
        cp = c;
    }
    void set(int key, int value) {
        if (mp[key] == 0) {
            Node *node = new Node(key, value);
            node->next = head;
            head->prev = node;
            head = node;
        }
        else {
            Node *node = mp[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            head = node;
        }
    }

    int get(int key) {
        if (mp[key] == 0) return -1;
        return mp[key]->value;
    }
};

int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}