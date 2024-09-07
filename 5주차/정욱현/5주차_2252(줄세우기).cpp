#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 32'003

int n, m;
int ind[SIZE]; // 진입차수
vector<int> adj[SIZE];
queue<int> q;

int main(){
    fastio;
    cin >> n >> m;
    while (m--) { // 입력을 받아 위상정령 만들기
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }

    for (int i = 1; i <= n; i++) // 위상정렬의 정의에 맞게 노드 하나씩 탐색하기
        if (!ind[i])// 진입차수가 0이라면 초기 출발노드들 큐에 넣기
            q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto nxt: adj[cur]) { //범위기반 for반복 이번에 출력한 노드와 연결된 모든 노드에 대해 반복
            ind[nxt]--; // 연결된 모든 노드의 차수를 1씩 줄임
            if (!ind[nxt]) q.push(nxt);
        }
    }
    return 0;
}
