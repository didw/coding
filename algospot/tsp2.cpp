#include <iostream>
#include <algorithm>

#define INF 99999999999
#define MAX 15

using namespace std;

class TSP
{
private:
    int n;
    double dist[MAX][MAX];
    double cache[MAX][1<<MAX];
    double shortestPath2(int here, int visited)
    {
        if(visited == (1<<n)-1) return 0;
        double &ret = cache[here][visited];
        if(ret>0) return ret;
		ret = INF;
        for(int next = 0; next < n; ++next)
        {
            if(visited & (1<<next)) continue;
            double cand = dist[here][next] +
                        shortestPath2(next, visited+(1<<next));
            ret = min(ret, cand);
        }
        return ret;
    }
public:
    TSP(int _n, double _dist[MAX][MAX]) 
    {
        n = _n;
        fill(&cache[0][0], &cache[MAX-1][(1<<MAX)-1]+1, -1);
        copy(&_dist[0][0], &_dist[MAX-1][MAX-1]+1, &dist[0][0]);
    }
    double getShortestPath()
    {
        double ret = INF;
        for(int here = 0; here < n; ++here)
        {
            ret = min(ret, shortestPath2(here, 1<<here));
        }
        return ret;
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
        double dist[MAX][MAX] = {0};
        for(int i = 0; i < num; ++i)
            for(int j = 0; j < num; ++j)
                cin>>dist[i][j];
        TSP t(num, dist);
        cout.precision(10);
        cout<<fixed<<t.getShortestPath()<<endl;
    }
}
