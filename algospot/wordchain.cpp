#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// adj[i][j] = i에서 j로 가는 간선
vector<vector<int> > adj;
// graph[i][j] = i로 시작해서 j로 끝나는 word
vector<string> graph[26][26];
// indegree[i] = i 점으로 들어가는 간선의 개수
// outdegree[i] = i 점으로 들어가는 간선의 개수
vector<int> indegree, outdegree;

// 주어진 words를 이용해 그래프를 만든다
void makeGraph(const vector<string>& words) {
    // 전역변수의 초기화
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            graph[i][j].clear();
    adj = vector<vector<int> >(26, vector<int>(26, 0));
    indegree = outdegree = vector<int>(26, 0);

    // 모든 words를 순회하며 그래프를 계산
    for (int i = 0; i < words.size(); ++i) {
        int a = words[i][0] - 'a';
        int b = words[i][words[i].size()-1] - 'a';
        adj[a][b]++;
        graph[a][b].push_back(words[i]);
        indegree[b]++;
        outdegree[a]++;
    }
}

// 주어진 그래프를 이용해 오일러 서킷이나 트레일을 계산한다.
void getEulerCircuit(int here, vector<int>& circuit) {
    for (int there = 0; there < adj.size(); ++there) {
        while (adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

// 오일러 트레일이나 서킷을 계산
vector<int> getEulerTrailOrCircuit() {
    vector<int> circuit;
    // 트레일이 존재하는지 확인
    for (int i = 0; i < 26; ++i) {
        // 나가는 간선이 들어오는 간선보다 하나 더 많으면 출발점
        if (outdegree[i] == indegree[i] + 1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    // 트레일이 존재하지 않으면 서킷이나 나가는 간선을 출발점으로 서킷을 만든다.
    for (int i = 0; i < 26; ++i) {
        if (outdegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    // 존재하지 않으면 빈 배열을 반환한다.
    return circuit;
}

// 각 정점의 in, out 간선을 이용해 오일로 서킷이나 트레일이 존재하는지 확인
bool checkEuler() {
    int plus1 = 0, minus1 = 0;
    for (int i = 0; i < 26; ++i) {
        int delta = outdegree[i] - indegree[i];
        // in, out 간선의 차는 0, -1, 또는 1이어야 한다.
        if (delta < -1 || delta > 1) return false;
        if (delta == 1) plus1++;
        if (delta == -1) minus1++;
    }
    // 간선의 차가 1인 쌍이 있거나 없다면 오일러 서킷/트레일이 존재한다.
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

// 주어진 word를 이용해 만든 오일러 서킷으로 조합 가능한 문자열을 만들어 반환
string solve(const vector<string>& words) {
    makeGraph(words);
    // 주어진 words로 오일러 서킷을 만들 수 없다면 실패
    if (!checkEuler()) return "IMPOSSIBLE";
    // 오일러 서킷을 계산
    vector<int> circuit = getEulerTrailOrCircuit();
    // 모든 간선을 지나지 않았다면 실패
    if (circuit.size() != words.size() + 1) return "IMPOSSIBLE";
    // 계산한 간선을 역배열하여 간선을 지날 수 있는 단어를 조합
    reverse(circuit.begin(), circuit.end());
    string res;
    for (int i = 1; i < circuit.size(); ++i) {
        if (res.size()) res += " ";
        int a = circuit[i-1], b = circuit[i];
        res += graph[a][b].back();
        graph[a][b].pop_back();
    }
    return res;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        vector<string> words;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string a;
            cin >> a;
            words.push_back(a);
        }
        cout << solve(words) << endl;
    }
}
