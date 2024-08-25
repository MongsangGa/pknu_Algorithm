#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 303

int t, n, sx, sy, ex, ey, vis[SIZE][SIZE];;
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[8] = {2, -2, 1, -1, 2, -2, 1,
                                                   -1};
queue<pair<int, int> > q;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> sx >> sy >> ex >> ey;
        fill(vis[0], vis[SIZE], 0);
        q.push({sx, sy}), vis[sx][sy] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny] > 0) continue;
                vis[nx][ny] = vis[x][y] + 1;
                q.push({nx, ny});
            }
        }
        cout << vis[ex][ey] - 1 << '\n';
    }
    return 0;
}

