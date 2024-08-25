#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'003
using namespace std;

int n, m, vis[SIZE], ans[SIZE];
vector<int> vec[SIZE];

void DFS(int now) {
    vis[now] = 1;
    for (auto nxt : vec[now]) {
        if (vis[nxt] == 1) continue;
        ans[nxt] = now;
        DFS(nxt);
    }
    return;
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
    DFS(1);
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
