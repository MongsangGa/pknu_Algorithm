#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 503
using namespace std;

int n, m, dp[SIZE][SIZE], grid[SIZE][SIZE];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int DFS(int x, int y) {
    if (x == n - 1 && y == m - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[x][y] > grid[nx][ny]) {
            dp[x][y] += DFS(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    fastio;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << DFS(0, 0) << "\n";
    return 0;
}
