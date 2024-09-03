#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define SIZE 10'002

int n, arr[SIZE], dp[SIZE][2];
bool vis[SIZE];
vector<int> adj[SIZE];

void DFS(int now, int prev) {
    vis[now] = 1;
    dp[now][1] = arr[now];
    for (int nxt: adj[now]) {
        if (vis[nxt] || nxt == prev) continue;
        DFS(nxt, now);
        dp[now][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[now][1] += dp[nxt][0];
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, -1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}
