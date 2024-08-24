#include <bits/stdc++.h>
using namespace std;

#define SIZE 102

int n, m, vis[SIZE];
int a, b;
vector<int> adj[SIZE];
int res;


int DFS(int now, int depth){
    if(now==b) res=depth;
    vis[now] = 1;
    
    for(auto nxt:adj[now]){
        if(vis[nxt]) continue;
        DFS(nxt, depth+1);
    }
    
    if(!vis[b]) res=-1;
    
    return 0;
}


int main(){
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);

    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(a, 0);

    printf("%d", res);
    
    return 0;
}