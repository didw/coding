#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Strjoin
{
private:
public:
    Strjoin() {}
    int GetMinLength(const vector<int>& strlen)
    {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < strlen.size(); ++i)
        {
            pq.push(strlen[i]);
        }
        int res = 0;
        while(pq.size()>1)
        {
            int l1 = pq.top();
            pq.pop();
            int l2 = pq.top();
            pq.pop();
            res += l1 + l2;
            pq.push(l1+l2);
        }
        return res;
    }
};

int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        int num;
        vector<int> str_length;
        cin>>num;
        for (int i = 0; i < num; ++i)
        {
            int len;
            cin>>len;
            str_length.push_back(len);
        }
        Strjoin s;
        cout<<s.GetMinLength(str_length)<<endl;
    }
}
