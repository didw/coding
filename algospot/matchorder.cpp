#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Match
{
private:
public:
    Match() {}
    int GetMaxWin(const vector<int>& russian,
                  const vector<int>& korean)
    {
        int win=0;
        multiset<int> ratings(korean.begin(), korean.end());
        for (int rus = 0; rus < russian.size(); ++rus)
        {
            if (russian[rus] > *ratings.rbegin())
            {
                ratings.erase(ratings.begin());
            }
            else
            {
                ratings.erase(ratings.lower_bound(russian[rus]));
                ++win;
            }
        }
        return win;
    }
};

int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        int num;
        vector<int> russian, korean;
        cin>>num;
        for (int i = 0; i < num; ++i)
        {
            int rus;
            cin>>rus;
            russian.push_back(rus);
        }
        for (int i = 0; i < num; ++i)
        {
            int kor;
            cin>>kor;
            korean.push_back(kor);
        }
        Match mc;
        cout<<mc.GetMaxWin(russian, korean)<<endl;
    }
}
