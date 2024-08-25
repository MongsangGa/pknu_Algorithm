#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103
using namespace std;

int n, m, vis[SIZE], dist[SIZE];
vector<int> vec[SIZE];

void DFS(int tx, int ty) {
    vis[tx] = 1;
    for (auto nxt : vec[tx]) {
        if (vis[nxt] == 1) continue;
        if (nxt == ty) {
            vis[nxt] = 1;
            dist[nxt] = dist[tx] + 1;
            return;
        }
        dist[nxt] = dist[tx] + 1;
        DFS(nxt, ty);
    }
    return;
}

int main() {
    fastio;
    cin >> n;
    int tx, ty;
    cin >> tx >> ty;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    DFS(tx, ty);

    if (vis[ty] == 0) cout << "-1";
    else cout << dist[ty];
    return 0;
}
