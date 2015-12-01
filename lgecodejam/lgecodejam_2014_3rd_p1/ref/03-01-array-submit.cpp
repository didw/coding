#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>

using namespace std;
int data[200000] = {0};
int cache[200000] = {0};

int query(int node1, int node2) {
    int parent;
    int target = node2;
    int check = 0;
    while (1) {
        parent = data[target];
        cache[target] = parent;
        if (0 == parent) return 0;
        if (node1 == parent) {
            check++; return check;
        }
        if (1 == parent) {
            return 0;
         }
        target = parent;
   }
   return check;
};

int query2(int node1, int node2) {
    int it;
    int target = node2;
    int check = 0;
    while (1) {
        it = data[target];
        if (0 == it) return 0;
        if (cache[it] != 0)
        {
            check++; return check;
        }
        if (node1 == it) {
            check++; return check;
        }
        if (1 == it) {
            return 0;
        }
        target = it;
   }
   return check;
};


int main() {
    int T, N, M;
    scanf("%d", &T);
    int parent, child = 0;
    int node1, node2 = 0;
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        //input
        memset(data,0,200000);
        for (int j = 0; j < N - 1; j++)
        {
            scanf("%d %d", &parent, &child);
            data[child] = parent;
        }
        //query
        for (int k = 0; k < M; k++) {
            scanf("%d %d", &node1, &node2);
            int check = 0;
            check += query(node1, node2);
            if (0 == check)
                //check += query(node2, node1);
                check += query2(node2, node1);

            if (check != 0)
                printf("1\n");
            else
                printf("0\n");
            memset(cache,0,200000);
        }
    }
    return 0;
}


