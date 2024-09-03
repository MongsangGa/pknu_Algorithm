#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 505

int n, m, x, y, res, vis[SIZE];
vector<int> adj[SIZE];
bool isTree;

void DFS(int now, int parent) {
    for (int nxt: adj[now]) {
        if (nxt == parent) continue;
        if (vis[nxt]) {
            isTree = 0;
            continue;
        }
        vis[nxt] = 1;
        DFS(nxt, now);
    }
}

int main() {
    fastio;
    for (int t = 1;; t++) {
        cin >> n >> m;
        if (!n && !m) break;
        res = 0;
        fill(vis, vis + SIZE, 0);
        for (int i = 1; i < SIZE; i++) adj[i].clear();
        while (m--) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            vis[i] = true, isTree = 1;
            DFS(i, -1);
            res += isTree;
        }
        if (!res) cout << "Case " << t << ": " << "No trees.";
        else if (res == 1) cout << "Case " << t << ": " << "There is one tree.";
        else cout << "Case " << t << ": " << "A forest of " << res << " trees.";
        cout << '\n';
    }
    return 0;
}

