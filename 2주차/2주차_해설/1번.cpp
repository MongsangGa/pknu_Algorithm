#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 505

int n, m, arr[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int cnt, maxS;
queue<pair<int, int>> q;


int BFS(int x, int y) {
    int c = 1;
    q.push({x, y}), arr[x][y] = 0;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || !arr[nx][ny]) continue;
            q.push({nx, ny}), arr[nx][ny] = 0, ++c;
        }
    }
    return c;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                int nowS = BFS(i, j);
                maxS = max(maxS, nowS);
                ++cnt;
            }
        }
    cout << cnt << '\n' << maxS;
    return 0;
}

