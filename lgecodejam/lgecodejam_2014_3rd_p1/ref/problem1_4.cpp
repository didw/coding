#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <string.h>
#include <vector>
#include <algorithm>

#define SAMPLE_SIZE 200001

using namespace std;

string areas[SAMPLE_SIZE];
string areas_visited[SAMPLE_SIZE];
int areas_size[SAMPLE_SIZE];

int find_leafnodes(int pos, string& res_str) {
    string str, tmp_str;
    int p, tmp_sz;

    // memoization..
    if( !areas_visited[pos].empty() ) {
//        cout << "already visited element for #" << pos << " -> " << areas_visited[pos] << "\n";
        res_str.append(areas_visited[pos]);
        return areas_size[pos];
    }

    // base condition..
    if( areas[pos].empty() ) {
//        cout << "can't find the element for #" << pos << "\n";
        char buf[10];
        sprintf(buf, "%d", pos);
        str = string(buf);
        str.append(" ");
        res_str.append(str);
        areas_visited[pos] = str;
        areas_size[pos] = 1;
        return 1;
    }

    // recursion..
    char cbuf[128];
    int sz = 0;
    sprintf(cbuf, "%s", areas[pos].c_str());
//    cout << "area[" << pos << "] = " << cbuf << "\n";
    char *pch, *end;
    pch = strtok_r(cbuf, " ", &end);
    tmp_str = res_str;
    res_str.clear();
    while(pch!=NULL) {
        p = atoi(pch);

        sz += find_leafnodes(p, res_str);
//        cout << "  find_leafnodes for #" << p << " sz = " << sz << "\n";
        pch = strtok_r(NULL, " ", &end);
    }
    areas_visited[pos] = res_str;
    areas_size[pos] = sz;

    tmp_str.append(res_str);
    res_str = tmp_str;
    tmp_str.clear();
//    cout << "areas_visited[" << pos << "] = " << areas_visited[pos] << " && size = " << areas_size[pos] << "\n";

    return sz;
}

int main()
{
    int n, m;
    int node;
    string edge;

    int tcases;
    cin >> tcases;
    while(tcases-->0) {
        cin >> n >> m;

        for(int i=1; i<n+1; i++) {
            areas[i].clear();
            areas_visited[i].clear();
            areas_size[i] = 0;
        }

        for(int i=1; i<n; i++) {
            cin >> node;
            cin.ignore();
            cin >> edge;
            cin.ignore();
            areas[node].append(edge);
            areas[node].append(" ");
        }

        int lhs, rhs;
        int lsz, rsz;
        string lstr, rstr;
        for(int i=0; i<m; i++) {
            cin >> lhs >> rhs;
            
//            cout << "[" << lhs << "]" << areas[lhs] << " vs " << "[" << rhs << "]" << areas[rhs] << "\n";
            lstr.clear();
            lsz = find_leafnodes(lhs, lstr);

            rstr.clear();
            rsz = find_leafnodes(rhs, rstr);


            if( lsz > rsz ) {
                if( lstr.find(rstr)!=string::npos ) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            } else {
                if( rstr.find(lstr)!=string::npos ) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }

        }
    }
}


