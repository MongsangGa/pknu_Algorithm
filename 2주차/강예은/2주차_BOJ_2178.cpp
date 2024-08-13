#include <bits/stdc++.h>

using namespace std;
#define SIZE 103

int n, m, vis[SIZE][SIZE], cnt[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char arr[SIZE][SIZE];
queue<pair<int, int>> q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        scanf(" %c", &arr[i][j]);

    q.push({0, 0}), vis[0][0] = 1;
    cnt[0][0] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '0'|| vis[nx][ny])
                continue;
            q.push({nx, ny}), vis[nx][ny] = 1;
            cnt[nx][ny] = cnt[x][y] + 1;
        }
    }
    printf("%d",cnt[n-1][m-1]);
    return 0;
}