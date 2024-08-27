#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103
using namespace std;

int n, vis[SIZE][SIZE], grid[SIZE][SIZE];
int res = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int> > q;

void DFS(int x, int y) {
    q.push({ x, y });
    vis[x][y] = 1;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] || grid[x][y] != grid[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
    ++res;
}

int main() {
    fastio;
    char rgb;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> rgb;
            if (rgb == 'R') grid[i][j] = 0;
            else if (rgb == 'G') grid[i][j] = 1;
            else grid[i][j] = 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j])
                DFS(i, j);
        }
    }
    cout << res << " ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) grid[i][j] = 0;
        }
    }
    memset(vis, 0, sizeof(vis));

    res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                DFS(i, j);
            }
        }
    }
    cout << res;

    return 0;
}
