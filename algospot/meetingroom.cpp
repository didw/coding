#include <iostream>
#include <vector>

using namespace std;

class Meetring
{
private:

public:
    Meeting() {}

    int schedule(int n, int begin[100], int end[100])
    {
        vector<pair<int, int> >order;
        for (int i = 0; i < n; i++)
        {
            order.push_back(make_pair(end[i], begin[i]));
        }
        sort(order.begin(), order.end());

        int earliest = 0, selected = 0;
        for (int i = 0; i < order.size(); ++i)
        {
            int meetingBegin = order[i].second, meetingEnd = order[i].first;
            if (earliest < meetingBegin)
            {
                earliest = meetingEnd;
                selected++;
            }
        }
        return selected;
    }

    int schedule2(int n, int begin[100], int end[100])
    {
        vector<pair<int, int> >order;
        for (int i = 0; i < n; ++i)
        {
            order.push_back(make_pair(end[i], begin[i]));
        }
        sort(order.begin(), order.end());

        vector<int> before;
        for (int i = 0; i < order.size(); ++i)
        {
            int left = 0, right = order.size();
            int meetingBegin = order[i].second;
            while(left<right)
            {
                int mid = (left+right)/2;
                if (order[mid].first > meetingBegin)
                    right = mid;
                else
                    left = mid;
            }
            if (order[left].first>meetingBegin)
                left = -1;
            before.push_back(left);
        }

        return schedule3(order.size()-1);
    }

    int schedule3(int idx)
    {
        if (idx<0)
            return 0;
        return max(schedule3(idx-1), 1+schedule3(before[idx]));
    }
}

int main()
{
    Meeting mt;
}
