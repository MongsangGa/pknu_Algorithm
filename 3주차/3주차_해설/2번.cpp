#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'002

int n, res[SIZE];
bool vis[SIZE];
vector<int> adj[SIZE];

void DFS(int now) {
    vis[now] = 1;
    for (auto nxt: adj[now]) {
        if (vis[nxt]) continue;
        res[nxt] = now;
        DFS(nxt);
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1);
    for (int i = 2; i <= n; i++)
        cout << res[i] << '\n';
    return 0;
}

