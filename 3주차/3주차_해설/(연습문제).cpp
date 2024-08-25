#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1001


int n, m, st, adj[SIZE][SIZE], vis[SIZE];
queue<int> q;

void BFS() {
    q.push(st), vis[st] = 1;
    while (!q.empty()) {
        auto now = q.front();
        cout << now << ' ';
        q.pop();
        for (int nxt = 1; nxt <= n; nxt++) {
            if (!adj[now][nxt] || vis[nxt]) continue;
            q.push(nxt), vis[nxt] = 1;
        }
    }
}

void DFS(int now) {
    vis[now] = 1;
    cout << now << ' ';
    for (int nxt = 1; nxt <= n; nxt++) {
        if (!adj[now][nxt] || vis[nxt]) continue;
        DFS(nxt);
    }
}

int main() {
    fastio;
    cin >> n >> m >> st;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }
    DFS(st);
    cout << '\n';
    fill(vis, vis + SIZE, 0);
    BFS();
    return 0;
}

