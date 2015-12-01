#include <iostream>
#include <vector>

using namespace std;

class Maxsum
{
    private:
    int get_max_boundary(int begin, int mid, int end, vector<int> num)
    {
        int sum=0, res=0;
        for (int i = mid; i >= begin; --i)
        {
            sum += num[i];
            res = max(sum, res);
        }
        sum = res;
        for (int i = mid+1; i <= end; ++i)
        {
            sum += num[i];
            res = max(sum, res);
        }
        return res;
    }
    int maxsum_div_con(int begin, int end, vector<int> num)
    {
        if (begin==end) return num[begin];
        int mid = (begin+end)/2;
        int res=0;
       
        res = max(maxsum_rec(begin, mid, num), maxsum_rec(mid+1, end, num));
        res = max(res, get_max_boundary(begin, mid, end, num));
        return res;
    }

    public:
    Maxsum() {}
    int GetMaxsum(vector<int> num)
    {
        // divide and counqure
        return maxsum_div_con(0, num.size()-1, num);
    }
};

int main()
{
    Maxsum MS;
    int C;
    cin>>C;
    while(C--)
    {
        int size;
        vector<int> num;
        cin>>size;
        while(size--)
        {
            int in_num;
            cin>>in_num;
            num.push_back(in_num);
        }
        cout<<(MS.GetMaxsum(num));
    }
}
