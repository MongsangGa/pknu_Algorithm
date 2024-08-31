#include <bits/stdc++.h>

using namespace std;

#define SIZE 1002

vector<int> adj[SIZE];
bool vis[SIZE];

bool DFS(int now, int parent) {
    vis[now] = true;
    for (auto nxt : adj[now]) {
        if (!vis[nxt]) {
            if (!DFS(nxt, now)) return false;
        }
        else if (nxt != parent) return false; 
    }
    return true;
}

int main(void) {
    int n, m, x, y, cnt = 1;

    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break; 

        
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            vis[i] = false;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int T = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (DFS(i, -1)) ++T;
            }
        }

        if (T == 0) printf("Case %d: No trees.\n", cnt);
        else if (T == 1) printf("Case %d: There is one tree.\n", cnt);
        else printf("Case %d: A forest of %d trees.\n", cnt, T);

        ++cnt;
    }

    return 0;
}
