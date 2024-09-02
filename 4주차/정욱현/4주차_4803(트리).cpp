#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 503

int n, m, x, y;
int vis[SIZE];
bool isTree;
vector<int> adj[SIZE]; //연결된 리스트로 간선을 표현 SIZE개의 요소를 담을 수 있는 adj 배열을 만듬
//안에 각각 요소는 vector<int> int를 요소로 가지는 동적배열 vector

void DFS(int now, int prev){ // 트리인지 아닌지를 판단하는 함수
    vis[now] = 1;
    for (int nxt : adj[now]) { // 범위기반 for루프 문법
        if(nxt == prev) continue; // 이전노드로의 역방향 탐지를 방지
        if(vis[nxt]){ // 이어진 노드가 이미 방문되었는가 즉 사이클이 있나
            isTree =  false;
            continue; // 사이클을 발견해 트리가 아닌것을 알아도 끝까지 탐색해야 함 트리개수를 새려면
        }
        DFS(nxt,now);
    }
}

int main(){
    fastio;
    while(1) {
        cin >> n >> m;
        if (!n && !m) break;
        for (int i = 1; i < SIZE; i++)
            adj[i].clear();
        fill(vis, vis + SIZE, 0);

        while(m--) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            isTree = true;
            DFS(i, -1);
            res += isTree;
        }
        cout << res << '\n';
    }
    return 0;
}
