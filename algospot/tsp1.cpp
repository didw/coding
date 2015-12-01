#include <iostream>
#include <vector>

#define INF 999999999999999

using namespace std;

class TSP
{
private:
    int n;
    double dist[20][20];
    double shortestPath(vector<int>& path, vector<bool>& visited,
                        double currentLength)
    {
        if(path.size()==n)
            return currentLength; 
        double ret = INF;
        for(int next = 0; next < n; ++next)
        {
            if (visited[next]) continue;
            int here = path.back();
            path.push_back(next);
            visited[next] = true;
            double cand = shortestPath(path, visited, currentLength +
                                        dist[here][next]);
            ret = min(ret, cand);
            visited[next] = false;
            path.pop_back();
        }
        return ret;
    }
public:
    TSP(int _n, double _dist[20][20]) 
    {
        n = _n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = _dist[i][j];
    }

    double GetShortestPath()
    {
        vector<int> path;
        vector<bool> visited(n, false);
        double res = INF;
        for(int i = 0; i < n; ++i)
        {
            path.push_back(i);
            visited[i] = true;
            res = min(res, shortestPath(path, visited, 0));
            path.pop_back();
            visited[i] = false;
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
        cin>>num;
        double dist[20][20];
        for (int j = 0; j < num; ++j)
        {
            for (int i = 0; i < num; ++i)
                cin>>dist[j][i];
        }
        TSP t(num, dist);
        cout.precision(10);
        cout<<fixed<<t.GetShortestPath()<<endl;
    }
}
