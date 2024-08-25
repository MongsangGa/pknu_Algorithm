#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

int n, res1, res2, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
bool vis[SIZE][SIZE];
string s[SIZE];
queue<pair<int, int>> q;

void BFS(int sx, int sy) {
    q.push({sx, sy}), vis[sx][sy] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] || s[sx][sy] != s[nx][ny]) continue;
            q.push({nx, ny}), vis[nx][ny] = 1;
        }
    }

}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            BFS(i, j), ++res1;
        }
    fill(vis[0], vis[SIZE], 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] == 'R')
                s[i][j] = 'G';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            BFS(i, j), ++res2;
        }
    cout << res1 << ' ' << res2;
    return 0;
}

