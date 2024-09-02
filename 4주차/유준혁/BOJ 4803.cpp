#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 503
using namespace std;

int n, m, t = 0, vis[SIZE], tree_case = 0;
bool isTree = false;
vector<int> vec[SIZE];

void DFS(int now, int prev) {
    vis[now] = 1;
    for (auto nxt : vec[now]) {
        if (nxt == prev) continue;
        if (vis[nxt]) {
            isTree = false;
            continue;
        }
        DFS(nxt, now);
    }
}

int main() {
    fastio;
    while (++tree_case) {
        isTree = false;
        cin >> n >> m;
        if (!n && !m) break;
        fill(vis, vis + SIZE, 0);
        for (int i = 0; i < SIZE; i++) vec[i].clear();
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            isTree = true;
            DFS(i, -1);
            res += isTree;
        }
        cout << "Case " << tree_case << ": ";
        if (res == 0) cout << "No trees." << "\n";
        else if (res == 1) cout << "There is one tree." << "\n";
        else cout << "A forest of " << res << " trees." << "\n";
    }
    return 0;
}
