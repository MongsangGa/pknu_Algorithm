#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 505

int n, m, arr[SIZE][SIZE], vis[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int DFS(int x, int y) {
    if (x == n - 1 && y == m - 1) return 1;
    if (vis[x][y] != -1) return vis[x][y];
    vis[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[x][y] <= arr[nx][ny]) continue;
        vis[x][y] += DFS(nx, ny);
    }
    return vis[x][y];
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    fill(vis[0], vis[SIZE], -1);
    cout << DFS(0, 0);
    return 0;
}

