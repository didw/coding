#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int> > > rotations;
int blockSize;

vector<string> rotate(const vector<string>& arr)
{
    vector<string> ret(arr[0].size(), string(arr.size(), ' '));
    for(int i = 0; i < arr.size(); ++i)
    {
        for(int j = 0; j < arr[0].size(); ++j)
        {
            ret[j][arr.size()-i-1] = arr[i][j];
        }
    }
    return ret;
}

void generateRotations(vector<string> block)
{
    rotations.clear();
    rotations.resize(4);
    for(int rot = 0; rot < 4; ++rot)
    {
        int originY = -1, originX = -1;
        // insert block into rotation[rot]
        for(int i = 0; i < block.size(); ++i)
        {
            for(int j = 0; j < block[i].size(); ++j)
            {
                if(block[i][j] == '#')
                {
                    if(originY == -1)
                    {
                        originX = j;
                        originY = i;
                    }
                    rotations[rot].push_back(make_pair(i-originY, j-originX));
                }
            }
        }
        block = rotate(block);
    }
    // remove duplicated block
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()),
                    rotations.end());
    
    blockSize = rotations[0].size();
}

int boardH, boardW;
vector<string> board;
int covered[10][10];
int best;

bool set(int y, int x, const vector<pair<int, int> >& block, int delta)
{
    if(delta == 1)
    {
        for(int i = 0; i < blockSize; ++i)
        {
            if(covered[block[i].first + y][block[i].second + x] == 1)
                return false;
        }
        for(int i = 0; i < blockSize; ++i)
        {
            covered[block[i].first + y][block[i].second + x] = 1;
        }
        return true;
    }
    else if(delta == -1)
    {
        for(int i = 0; i < blockSize; ++i)
        {
            if(covered[block[i].first + y][block[i].second + x] == 0)
                return false;
        }
        for(int i = 0; i < blockSize; ++i)
        {
            covered[block[i].first + y][block[i].second + x] = 0;
        }
        return true;
    }
    else
        return false;
}

void search(int placed)
{
    int y = -1, x = -1;
    for(int i = 0; i < boardH; ++i)
    {
        for(int j = 0; j < boardW; ++j)
        {
            if(covered[i][j] == 0)
            {
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1)
            break;
    }
    // base case
    if(y == -1)
    {
        best = max(best, placed);
        return;
    }
    for(int i = 0; i < rotations.size(); ++i)
    {
        if(set(y, x, rotations[i], 1))
        {
            search(placed+1);
            set(y, x, rotations[i], -1);
        }
    }
    covered[y][x] = 1;
    search(placed);
    covered[y][x] = 0;
}

int solve()
{
    best = 0;
    for(int i = 0; i < boardH; ++i)
    {
        for(int j = 0; j < boardW; ++j)
        {
            covered[i][j] = (board[i][j] == '#' ? 1 : 0);
        }
    }
    search(0);
    return best;
}

int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        int R, C;
        cin>>boardH>>boardW>>R>>C;
        for(int i = 0; i < boardH; ++i)
        {
            char strin[10];
            cin>>strin;
            board.push_back(strin);
        }
        vector<string> block;
        for(int i = 0; i < R; ++i)
        {
            char strin[10];
            cin>>strin;
            block.push_back(strin);
        }
        generateRotations(block);
        cout<<solve();
    }
    return 0;
}
