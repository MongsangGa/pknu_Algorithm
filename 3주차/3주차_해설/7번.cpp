#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, m, k, res, vis[SIZE][SIZE][82];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
string s[SIZE], target;

int DFS(int x, int y, int dep) {
    if (dep == target.size() - 1) return 1;
    int &now = vis[x][y][dep];
    if (now != -1) return now;
    now = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < 4; j++) {
            int nx = x + (i * dx[j]), ny = y + (i * dy[j]);
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] != target[dep + 1]) continue;
            now += DFS(nx, ny, dep + 1);
        }
    return now;
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> target;
    memset(vis, -1, sizeof vis);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == target[0])
                res += DFS(i, j, 0);
    cout << res;
    return 0;
}

