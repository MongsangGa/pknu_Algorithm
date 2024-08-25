#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 505

int n, res, arr[SIZE][SIZE], vis[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int DFS(int x, int y) {
    if (vis[x][y]) return vis[x][y];
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[x][y] >= arr[nx][ny]) continue;
        vis[x][y] = max(vis[x][y], DFS(nx, ny) + 1);
    }
    return vis[x][y];
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            DFS(i, j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res = max(res, vis[i][j]);
    cout << res;
    return 0;
}

