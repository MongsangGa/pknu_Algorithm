#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, m, vis[SIZE];//노드, 간선 방문지
int res = 0; // 결과 변수
vector<int> adj[SIZE]; //간선벡터: 사이즈 만큼 벡터 행이 만들어짐

void DFS(int now){
    vis[now] = 1;
    res++;

    for(auto nxt : adj[now]){
        if(vis[nxt] == 1) continue;
        DFS(nxt); 
        
    }
}
/* for(int i=0; i < adj[now].size(); i++){
       int nxt = adj[now][i];
}*/

int main(){
    fastio;
    cin >> n >> m;
    while (m--){
        //간선 연결
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y); // x 벡터에 y 값을 넣음
        adj[y].push_back(x); // y 벡터에 x 값을 넣음

    }

    DFS(1);

    cout << res-1;
}