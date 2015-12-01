#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

char pair_brackers(char in) {
    if (in == ')') return '(';
    if (in == '}') return '{';
    if (in == ']') return '[';
}
bool brakets2(string in) {
    stack<char> parenthesis;
    for (int i = 0; i < in.size(); ++i) {
        if (in[i] == '(' ||in[i] == '[' ||in[i] == '{')
            parenthesis.push(in[i]);
        else if(!parenthesis.empty())
            if (pair_brackers(in[i]) == parenthesis.top())
                parenthesis.pop();
            else
                return false;
        else
            return false;
    }
    if (parenthesis.size() == 0)
        return true;
    return false;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        string in;
        cin >> in;
        if (brakets2(in))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
