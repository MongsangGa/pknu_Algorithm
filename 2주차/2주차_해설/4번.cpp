#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'002

int n, m, arr[SIZE][SIZE], vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, res;
queue<pair<int, int>> q;

bool Check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j])
                return false;
    return true;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) vis[i][j] = 1;
            if (arr[i][j] == 1) q.push({i, j}), vis[i][j] = 1;
        }
    while (!q.empty()) {
        ++res;
        int qS = q.size();
        for (int k = 0; k < qS; k++) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) continue;
                q.push({nx, ny}), vis[nx][ny] = 1;
            }
        }
    }
    if (Check()) cout << res - 1;
    else cout << -1;
    return 0;
}

