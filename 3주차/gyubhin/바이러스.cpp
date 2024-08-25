#include <bits/stdc++.h>

using namespace std;

#define SIZE 101

int n, m, adj[SIZE][SIZE], vis[SIZE], res;

void DFS(int now) {
    vis[now] = 1;
    ++res;
    for (int nxt = 1; nxt <= n; nxt++) {
        if (vis[nxt] || !adj[now][nxt]) continue;
        DFS(nxt);
    }
}

int main() {
    int x, y;

    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &x, &y);

        adj[x][y] = adj[y][x] = 1;
    }

    DFS(1);
    printf("%d", res - 1);
    return 0;
}