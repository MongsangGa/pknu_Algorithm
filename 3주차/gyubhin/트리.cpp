#include <bits/stdc++.h>

using namespace std;

#define SIZE 100001

int n, vis[SIZE], res[SIZE];
vector <int> adj[SIZE];

void DFS(int now) {
    vis[now] = 1;
    
    for (auto nxt : adj[now]) 
        if (vis[nxt]) continue;
        else vis[nxt] = 1,res[nxt]=now, DFS(nxt);
}


int main() {
    int x, y;

    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    DFS(1);

    for (int i = 2; i <= n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}