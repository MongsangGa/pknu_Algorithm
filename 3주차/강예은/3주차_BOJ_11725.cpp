#include <bits/stdc++.h>

using namespace std;
#define SIZE 100'003

int n, nn, vis[SIZE], arr[SIZE];
vector<int> adj[SIZE];

void DFS(int now){
    vis[now] = 1;
    for(auto nxt : adj[now]){
        if(!vis[nxt]){
            arr[nxt] = now;
            DFS(nxt);
        }
    }
}

int main(){
    scanf("%d", &n); nn=n, n--;
    while (n--){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    DFS(1);
    
    for(int i=2; i<=nn;i++)
    printf("%d\n",arr[i]);

    return 0;
}