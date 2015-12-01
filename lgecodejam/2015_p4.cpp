#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
// 알고리즘 문제해결 전략 24장 구간트리편 코드 참고함
struct RMQ {
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n * 4);
        init(array, 0, n - 1, 1);
    }
    int init(const vector<int>& array, int left, int right, int node) {
        if (left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) return INT_MAX;
        if (left <= nodeLeft && nodeRight <= right)
            return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid),
            query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
};

const int MAX_N = 500001;
int n;
vector<int> child[MAX_N];
//vector<int> parent;
int parent[MAX_N];
int no2serial[MAX_N], serial2no[MAX_N];
int locInTrip[MAX_N], depth[MAX_N];
int nextSerial;

void traverse2(int here, int d, vector<int>& trip) {
    struct snapShot {
        int here, d, i;
        int stage;
    };

    stack<snapShot> snpt;

    snapShot snp;
    snp.here = here;
    snp.d = d;
    snp.i = 0;
    snp.stage = 0;

    snpt.push(snp);
    int remain = 1;
    while (remain) {
        snp = snpt.top();
        snpt.pop();
        remain--;

        switch (snp.stage) {
        case 0:
            no2serial[snp.here] = nextSerial;
            serial2no[nextSerial] = snp.here;
            ++nextSerial;
            depth[snp.here] = snp.d;
            locInTrip[snp.here] = trip.size();
            trip.push_back(no2serial[snp.here]);
            if (snp.i < child[snp.here].size()) {
                snp.stage = 1;
                snp.i++;
                snpt.push(snp);
                remain++;
                snapShot newsnp;
                newsnp.here = child[snp.here][snp.i-1];
                newsnp.d = snp.d + 1;
                newsnp.i = 0;
                newsnp.stage = 0;
                snpt.push(newsnp);
                remain++;
            }
            continue;
            break;
        case 1:
            trip.push_back(no2serial[snp.here]);
            if (snp.i < child[snp.here].size()) {
                snp.stage = 1;
                snp.i++;
                snpt.push(snp);
                remain++;
                snapShot newsnp;
                newsnp.here = child[snp.here][snp.i-1];
                newsnp.d = snp.d + 1;
                newsnp.i = 0;
                newsnp.stage = 0;
                snpt.push(newsnp);
                remain++;
            }
            continue;
            break;
        }
    }
}

void traverse(int here, int d, vector<int>& trip) {
    no2serial[here] = nextSerial;
    serial2no[nextSerial] = here;
    ++nextSerial;
    depth[here] = d;
    locInTrip[here] = trip.size();
    trip.push_back(no2serial[here]);
    for (int i = 0; i < child[here].size(); ++i) {
        traverse(child[here][i], d + 1, trip);
        trip.push_back(no2serial[here]);
    }
}

RMQ* prepareRMQ(int root) {
    nextSerial = 0;
    vector<int> trip;
    //traverse(root, 0, trip);
    traverse2(root, 0, trip);
    return new RMQ(trip);
}

int distance(RMQ* rmq, int u, int v) {
    int lu = locInTrip[u], lv = locInTrip[v];
    if (lu > lv) swap(lu, lv);
    int lca = serial2no[rmq->query(lu, lv)];
    return depth[u] + depth[v] - 2 * depth[lca];
}

int getParent2(int node, int dist) {
    while (dist != 0) {
        node = parent[node];
        dist--;
    }
    return node;
}

int getParent(int node, int dist) {
    if (dist == 0) return node;
    return getParent(parent[node], dist - 1);
}

int getMid(RMQ* rmq, int u, int v) {
    int dist = distance(rmq, u, v);
    if (depth[u] > depth[v])
        return getParent2(u, dist / 2);
    else
        return getParent2(v, (dist + 1) / 2);
}

void initialize() {
    for (int i = 0; i < MAX_N; ++i) {
        child[i].clear();
    }
}
#include <fstream>

int main() {
    int c;
    //ifstream is ("problem4.in");
    //is >> c;
    scanf("%d", &c);
    while (c--) {
        int n, k, root = 0;
        //is >> n >> k;
        scanf("%d %d", &n, &k);
        initialize();
        //cout << "N: " << n << ", K: " << k << endl;
        vector<bool> taken(n+1, false);
        //parent = vector<int>(n+1, 0);
        memset(parent, 0, sizeof(parent));
        for (int i = 0; i < n-1; ++i) {
            int a, b;
            //is >> a >> b;
            scanf("%d %d", &a, &b);
            if (!root) root = b;
            if (taken[a]) {
                child[a].push_back(b);
                parent[b] = a;
            }
            else {
                child[b].push_back(a);
                parent[a] = b;
            }
            taken[a] = taken[b] = true;
        }
        //cout << "READ DONE" << endl;
        RMQ* rmq = prepareRMQ(root);
        //cout << "prepareRMQ" << endl;
        for (int i = 0; i < k; ++i) {
            int a, b;
            //is >> a >> b;
            scanf("%d %d", &a, &b);
            int res = getMid(rmq, a, b);
            //cout << res << endl;
            printf("%d\n", res);
        }
        //cout << "END" << endl;
    }
}
