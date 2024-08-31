#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 50'003
using namespace std;

vector<int> vec[SIZE];
int n, m, vis[SIZE], res, depth[SIZE], parent[SIZE];

void DFS(int now, int prev, int dep) {
    vis[now] = 1;
    depth[now] = dep;
    for (auto nxt : vec[now]) {
        if (nxt == prev) continue;
        if (vis[nxt] == 1) continue;
        parent[nxt] = now;
        DFS(nxt, now, dep + 1);
    }
}

int find_par(int s, int e) {
    while (depth[s] != depth[e]) {
        if (depth[s] > depth[e]) s = parent[s]; // start¶û end ±íÀÌ ¸ÂÃß±â.
        else e = parent[e];
        //±íÀÌ ¸ÂÃç¼­ ÇØ´ç ±íÀÌ³¢¸® Á¶»ó ¸ÂÃß±â
    }
    while (s != e) {
        s = parent[s];
        e = parent[e];
    }
    return s;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    DFS(1, -1, 0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, m;
        cin >> u >> m;
        cout << find_par(u, m) << "\n";
    }

    return 0;
}
