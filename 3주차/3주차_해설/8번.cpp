#include <bits/stdc++.h>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'002

int n, m, num, vis[SIZE];
vector<int> adj[SIZE];
vector<pair<int, int>> res;

int dfs(int X, int prev) {
    vis[X] = ++num;
    int now = vis[X];
    for (auto nxt: adj[X]) {
        if (nxt == prev) continue;
        if (!vis[nxt]) {
            int low = dfs(nxt, X);
            if (low > vis[X]) res.push_back({min(X, nxt), max(X, nxt)});
            now = min(now, low);
        } else now = min(now, vis[nxt]);
    }
    return now;
}

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto [x, y]: res) cout << x << ' ' << y << '\n';
    return 0;
}
