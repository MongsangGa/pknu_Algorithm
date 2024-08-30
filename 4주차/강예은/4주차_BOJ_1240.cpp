#include <bits/stdc++.h>

using namespace std;
#define SIZE 1003

int n, m;
vector<pair<int, int>> adj[SIZE];

int DFS(int x, int y, int dist, vector<bool>& vis) {
    if (x == y) return dist;
    vis[x] = true;
    for (auto nxt : adj[x]) {
        if (!vis[nxt.first]) {
            int result = DFS(nxt.first, y, dist + nxt.second, vis);
            if (result != -1) return result;
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m); n--;
    while (n--) {
        int x, y, dist;
        scanf("%d %d %d", &x, &y, &dist);
        adj[x].push_back({y, dist});
        adj[y].push_back({x, dist});
    }
    
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        vector<bool> vis(SIZE, false);
        int dist = DFS(a, b, 0, vis);
        printf("%d\n", dist);
    }    
    return 0;
}
