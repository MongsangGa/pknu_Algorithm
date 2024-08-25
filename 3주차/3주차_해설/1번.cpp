#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1001

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
    fastio;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }
    DFS(1);
    cout << res - 1;
    return 0;
}

