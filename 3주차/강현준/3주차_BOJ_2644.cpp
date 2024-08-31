#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, m, tx, ty, vis[SIZE];
vector<int> adj[SIZE];
int dis[SIZE];

void DFS(int now, int chon){
    vis[now] = 1;
    dis[now]=chon;
    
    for(auto nxt : adj[now]){
        if(vis[nxt] == 1) continue;
        
        DFS(nxt,chon+1);

 }
}

int main(){
    fastio;

    cin >> n >> tx >> ty >> m;
    while(m--){
        int x,y;

        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(dis, -1, sizeof(dis)); // dis값 -1로 초기화

DFS(tx, 0);

if (dis[ty] == -1) {
    cout << -1 << '\n'; // 촌수 계산 불가능
} else {
    cout << dis[ty] << '\n'; // 촌수 출력
}



}