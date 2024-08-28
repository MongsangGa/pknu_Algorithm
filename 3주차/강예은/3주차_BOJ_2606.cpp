#include <bits/stdc++.h>

using namespace std;
#define SIZE 103

int n, m, vis[SIZE], cnt = 0;
vector<int> adj[SIZE];

void DFS(int now){
    vis[now] = 1;
    for(auto nxt : adj[now]){
        if(!vis[nxt]){
            cnt += 1;
            DFS(nxt); 
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    while (m--){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    DFS(1);
    
    printf("%d", cnt);

    return 0;
}
