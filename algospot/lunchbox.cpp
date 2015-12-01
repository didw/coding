#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Lunch
{
private:
public:
    Lunch() {}
    int GetMinTime(vector<int> micro, vector<int> eat)
    {
        vector<pair<int, int> > order;
        for (int i = 0; i < eat.size(); ++i)
        {
            order.push_back(make_pair(-eat[i], micro[i]));
        }
        sort(order.begin(), order.end());

        int begin_eat = 0, res = 0;
        for (int i = 0; i < order.size(); ++i)
        {
            begin_eat += order[i].second;
            res = max(res, begin_eat-order[i].first);
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
        vector<int> micro, eat;
        cin>>num;
        for (int i = 0; i < num; ++i)
        {
            int m;
            cin>>m;
            micro.push_back(m);
        }
        for (int i = 0; i < num; ++i)
        {
            int e;
            cin>>e;
            eat.push_back(e);
        }
        Lunch l;
        cout<<l.GetMinTime(micro, eat)<<endl;
    }
}
