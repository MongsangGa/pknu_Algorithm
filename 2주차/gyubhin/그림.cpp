#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1003

int n, m, vis[SIZE][SIZE], dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
char arr[SIZE][SIZE];
queue<pair<int, int>> q;

int bps(int a, int b) {
    int Mcnt = 1;
    q.push({ a,b }), vis[a][b] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '0' || vis[nx][ny] == 1)continue;
            q.push({ nx,ny }), vis[nx][ny] = 1, ++Mcnt;
        }
    }
    return Mcnt;
}


int main() {
    int cnt = 0, max = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %c", &arr[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '1' && vis[i][j] == 0) {
                int b = bps(i, j);
                ++cnt;
                if (max < b) max = b;
            }
        }
    }

    printf("%d\n%d", cnt, max);
    return 0;
}
