#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 102

using namespace std;

#define X first
#define Y second

int n;
int board[SIZE][SIZE]; // 지도
int island[SIZE][SIZE]; // 섬 번호 저장
bool vis[SIZE][SIZE]; // 방문 확인
int dist[SIZE][SIZE]; // 거리 저장
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int sx, int sy, int id) {
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    island[sx][sy] = id;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] == 1 && island[nx][ny] == 0) {
                island[nx][ny] = id;
                q.push({ nx, ny });
            }
        }
    }
}

int findShortestBridge() {
    int minDist = 10000;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (island[i][j] == 0) continue;

            memset(dist, -1, sizeof(dist));
            memset(vis, 0, sizeof(vis));

            queue<pair<int, int>> q;
            q.push({ i, j });
            vis[i][j] = true;
            dist[i][j] = 0;

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny]) continue;

                    if (island[nx][ny] != 0 && island[nx][ny] != island[i][j]) {
                        minDist = min(minDist, dist[x][y]);
                        break;
                    }

                    if (board[nx][ny] == 0) {
                        vis[nx][ny] = true;
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({ nx, ny });
                    }
                }
            }
        }
    }

    return minDist;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    int id = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1 && island[i][j] == 0) {
                bfs(i, j, id++);
            }
        }
    }

    cout << findShortestBridge() << '\n';

    return 0;
}
