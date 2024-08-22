#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103

int n, m, vis[SIZE][SIZE], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, dis[SIZE][SIZE]; 
char arr[SIZE][SIZE];
queue<pair<int, int>> q; // 큐

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j]; // 배열 받기

    q.push({0, 0}), vis[0][0] = 1, dis[0][0] = 1; // 1로 방문 표시 

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || arr[nx][ny] == '0') continue;
            // 배열 범위 밖으로 나가지 않게 하기 위한 조건문, 이미 방문했거나 0일 때는 경로에 넣지 않음

            q.push({nx, ny}), vis[nx][ny] = 1, dis[nx][ny] = dis[x][y] + 1; // 거리 업데이트
        }
    }

    cout << dis[n-1][m-1]; // 최종 거리

    return 0;
}
