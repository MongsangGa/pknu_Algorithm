#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103
using namespace std;

int n, m, vis[SIZE], ans;
vector<int> vec[SIZE];

void DFS(int now) {
    vis[now] = 1;
    ++ans;
    for (auto nxt : vec[now]) {
        if (vis[nxt] == 1) continue;
        DFS(nxt);
    }
    return;
}


int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    DFS(1);
    cout << ans - 1;
    return 0;
}
