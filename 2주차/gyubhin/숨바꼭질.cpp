#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103

int n, m, vis[SIZE][SIZE], dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
char arr[SIZE][SIZE];
queue<pair<int, int>> q;

int main() {
    fastio;
    fill(vis[0], vis[SIZE - 1], 1000000);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    q.push({ 0, 0 }), vis[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] <= vis[x][y] + 1 || arr[nx][ny] == '0') continue;
            q.push({ nx, ny });
            vis[nx][ny] = vis[x][y] + 1;
        }
    }

    cout << vis[n - 1][m - 1];
    return 0;
}

