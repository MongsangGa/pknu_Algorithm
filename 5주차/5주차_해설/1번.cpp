#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define SIZE 32'003

int n, m, ind[SIZE];
vector<int> adj[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++ind[v];
    }
    for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << ' ';
        for (int nxt: adj[now]) {
            --ind[nxt];
            if (!ind[nxt]) q.push(nxt);
        }
    }
    return 0;
}
