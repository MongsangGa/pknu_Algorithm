#include <iostream>
#include <vector>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'000'000
using namespace std;

int v, e, vis[SIZE], res;
vector<int> vec[SIZE];

void DFS(int now) {
    vis[now] = 1;
    for (auto nxt : vec[now]) {
        if (vis[nxt] == 1) continue;
        if (now == nxt) ++res;
        DFS(nxt);
    }
    return;
}


int main() {
    fastio;
    cin >> v >> e;
    while (v--) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for (int i = 1; i <= v; ++i) {
        if (!vis[i])
            DFS(i);
    }
    cout << res;
    return 0;
}
