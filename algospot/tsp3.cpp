#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>


using namespace std;

const double INF = 1e200;
const int MAX = 20;
const int CACHED_DEPTH = 10;

class TSP
{
private:
    int n;
    double dist[MAX][MAX];
    double best;
    double minEdge[MAX];
    vector<int> nearest[MAX];
    map<int, double> cache[MAX][CACHED_DEPTH+1];

    bool pathReversePruning(const vector<int>& path)
    {
        if(path.size() < 4) return false;
        int q = path[path.size() - 1];
        int b = path[path.size() - 2];
        for(int i = 0; i < path.size() - 3; ++i)
        {
            int p = path[i];
            int a = path[i+1];
            if(dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q])
                return true;
        }
        return false;
    }

    double simpleHeuristic(int visited)
    {
        double ret = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!(visited & (1<<i)))
                ret += minEdge[i];
        }
        return ret;
    }

    double dp(int here, int visited)
    {
        if(visited == (1<<n)-1) return 0;
        int remaining = n - __builtin_popcount(visited);
        double& ret = cache[here][remaining][visited];
        if(ret>0) return ret;
        ret = INF;
        for(int next = 0; next < n; ++next)
        {
            if(visited & (1<<next)) continue;
            ret = min(ret,
                    dp(next, visited + (1<<next)) + dist[here][next]);
        }
        return ret;
    }

    void search(vector<int>& path, int visited,
                double currentLength)
    {
        // proving using simpleHeuristic()
        if(pathReversePruning(path)) return;
        if(best < currentLength + simpleHeuristic(visited)) return;
        int here = path.back();
        if(path.size() + CACHED_DEPTH >= n)
        {
            best = min(best, currentLength + dp(here, visited));
            return;
        }
        for(int i = 0; i < nearest[here].size(); ++i)
        {
            int next = nearest[here][i];
            if(visited & (1<<i)) continue;
            path.push_back(next);
            visited += (1<<i);
            search(path, visited, currentLength + dist[here][next]);
            visited -= (1<<i);
            path.pop_back();
        }
    }

public:
    TSP(int _n, double _dist[MAX][MAX])
    {
        n = _n;
        copy(&_dist[0][0], &_dist[MAX-1][MAX-1]+1, &dist[0][0]);
    }

    double solve()
    {
        // initialize nearest
        for(int node = 0; node < n; ++node)
        {
            vector<pair<double, int> > order;
            for(int next = 0; next < n; ++next)
            {
                if(node != next)
                    order.push_back(make_pair(dist[node][next], next));
            }
            sort(order.begin(), order.end());
            nearest[node].clear();
            for(int next = 0; next < n-1; ++next)
            {
                nearest[node].push_back(order[next].second);
            }
        }
        // Initialize minEdge for simpleHeuristic()
        for(int node = 0; node < n; ++node)
        {
            minEdge[node] = INF;
            for(int near = 0; near < n; ++near)
            {
                if(node == near) continue;
                minEdge[node] = min(minEdge[node], dist[node][near]);
            }
        }

        // Initialize cache
        for(int i = 0; i < MAX; ++i)
            for(int j = 0; j <= CACHED_DEPTH; ++j)
                cache[i][j].clear();

        best = INF;
        int visited = 0;
        vector<int> path;
        for(int here = 0; here < n; ++here)
        {
            visited += (1<<here);
            path.push_back(here);
            search(path, visited, 0); 
            path.pop_back(); 
            visited -= (1<<here);
        }
        return best;
    }
};

int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        const clock_t begin_time = clock();
        int num;
        cin>>num;
        double dist[MAX][MAX] = {0};
        for(int i = 0; i < num; ++i)
            for(int j = 0; j < num; ++j)
                cin>>dist[i][j];
        TSP t(num, dist);
        cout.precision(10);
        cout<<fixed<<t.solve()<<endl;
        cout<<float( clock() - begin_time) / CLOCKS_PER_SEC<<"sec"<<endl;
    }
}
