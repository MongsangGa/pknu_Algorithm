#include <bits/stdc++.h>
using namespace std;

#define SIZE 100002

int n, vis[SIZE], par[SIZE];
vector<int> adj[SIZE];

void DFS(int now){
    vis[now] = 1;

    for(auto nxt : adj[now]){
        if(!vis[nxt]){
            par[nxt] = now;
            DFS(nxt); 
        }
    }
}


int main(){
    scanf("%d", &n);
    int NewN = n-1;


    while(NewN--){
        int x, y;
        scanf("%d %d", &x, &y);

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DFS(1);

    for(int i = 2; i <= n; i++){
        if(par[i]!=0) printf("%d\n", par[i]);
    }

    return 0;
}
